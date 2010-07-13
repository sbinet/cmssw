// -*- C++ -*-
//
// Package:     Fireworks/Eve
// Class  :     EveService
// 
// Implementation:
//     [Notes on implementation]
//
// Original Author:  Matevz Tadel
//         Created:  Fri Jun 25 18:57:39 CEST 2010
// $Id: EveService.cc,v 1.5 2010/07/08 19:43:44 matevz Exp $
//

// system include files
#include <iostream>

// user include files
#include "Fireworks/Eve/interface/EveService.h"

#include "FWCore/ParameterSet/interface/ParameterSet.h"
#include "FWCore/ServiceRegistry/interface/ActivityRegistry.h"

// To extract coil current from ConditionsDB
#include "FWCore/Framework/interface/EventSetup.h"
#include "FWCore/Framework/interface/ESHandle.h"
#include "CondFormats/RunInfo/interface/RunInfo.h"
#include "CondFormats/DataRecord/interface/RunSummaryRcd.h"

// To extract coil current from ConditionsInEdm
#include <FWCore/Framework/interface/Run.h>
#include <DataFormats/Common/interface/Handle.h>
#include "DataFormats/Common/interface/ConditionsInEdm.h"

#include "TROOT.h"
#include "TSystem.h"
#include "TRint.h"
#include "TEveManager.h"
#include "TEveEventManager.h"
#include "TEveTrackPropagator.h"

// GUI widgets
#include "TEveBrowser.h"
#include "TGFrame.h"
#include "TGButton.h"

namespace
{
   class CmsEveMagField : public TEveMagField
   {
   private:
      Float_t fField;
      Float_t fFieldMag;

   public:

      CmsEveMagField() : TEveMagField(), fField(-3.8), fFieldMag(3.8) {}
      virtual ~CmsEveMagField() {}

      // set current
      void SetFieldByCurrent(Float_t avg_current)
      {
         fField    = -3.8 * avg_current / 18160.0;
         fFieldMag = TMath::Abs(fField);
      }

      // get field values
      virtual Float_t GetMaxFieldMag() const
      {
         return fFieldMag;
      }

      virtual TEveVector GetField(Float_t x, Float_t y, Float_t z) const
      {
         static const Float_t barrelFac = 1.2 / 3.8;
         static const Float_t endcapFac = 2.0 / 3.8;

         const Float_t R    = sqrt(x*x+y*y);
         const Float_t absZ = TMath::Abs(z);

         //barrel
         if (absZ < 724.0f)
         {
            //inside solenoid
            if (R < 300.0f) return TEveVector(0, 0, fField);

            // outside solinoid
            if ((R > 461.0f && R < 490.5f) ||
                (R > 534.5f && R < 597.5f) ||
                (R > 637.0f && R < 700.0f))
            {
               return TEveVector(0, 0, -fField*barrelFac);
            }
         } else {
            if ((absZ > 724.0f && absZ < 786.0f) ||
                (absZ > 850.0f && absZ < 910.0f) ||
                (absZ > 975.0f && absZ < 1003.0f))
            {
               const Float_t fac = (z >= 0 ? fField : -fField) * endcapFac / R;
               return TEveVector(x*fac, y*fac, 0);
            }
         }
         return TEveVector(0, 0, 0);
      }
   };
}

//
// constants, enums and typedefs
//

//
// static data member definitions
//

//==============================================================================
// constructors and destructor
//==============================================================================

EveService::EveService(const edm::ParameterSet&, edm::ActivityRegistry& ar) :
   m_EveManager(0), m_Rint(0),
   m_MagField(0),
   m_NextButton(0)
{
   printf("EveService::EveService CTOR\n");

   std::cout <<" gApplication "<< gApplication <<std::endl;
   std::cout <<" is batch "    << gROOT->IsBatch() <<std::endl;
   std::cout <<" display "     << gSystem->Getenv("DISPLAY") <<std::endl;

   const char* dummyArgvArray[] = {"cmsRun"};
   char**      dummyArgv = const_cast<char**>(dummyArgvArray);
   int         dummyArgc = 1;

   m_Rint = new TRint("App", &dummyArgc, dummyArgv);
   assert(TApplication::GetApplications()->GetSize());
  
   gROOT->SetBatch(kFALSE);
   std::cout<<"calling NeedGraphicsLibs()"<<std::endl;
   TApplication::NeedGraphicsLibs();

   m_EveManager = TEveManager::Create();

   m_EveManager->AddEvent(new TEveEventManager("Event", "Event Data"));

   m_MagField = new CmsEveMagField();

   createEventNavigationGUI();

   // ----------------------------------------------------------------

   ar.watchPostBeginJob(this, &EveService::postBeginJob);
   ar.watchPostEndJob  (this, &EveService::postEndJob);

   ar.watchPostBeginRun(this, &EveService::postBeginRun);

   ar.watchPostProcessEvent(this, &EveService::postProcessEvent);
}

EveService::~EveService()
{
   printf("EveService::~EveService DTOR\n");

   delete m_MagField;
}


//==============================================================================
// Service watchers
//==============================================================================

void EveService::postBeginJob()
{
   printf("EveService::postBeginJob\n");

   // Show the GUI ...
   gSystem->ProcessEvents();
}

void EveService::postEndJob()
{
   printf("EveService::postEndJob\n");

   TEveManager::Terminate();
}

//------------------------------------------------------------------------------

void EveService::postBeginRun(const edm::Run& iRun, const edm::EventSetup& iSetup)
{
   float current = 18160.0f;

   edm::Handle<edm::ConditionsInRunBlock> runCond;
   bool res = iRun.getByType(runCond);
   //bool res = run.getByLabel("conditionsInEdm", runCond, "", "");
   if (res && runCond.isValid())
   {
      printf("Got current from conds in edm %f\n", runCond->BAvgCurrent);
      current = runCond->BAvgCurrent;
   }
   else
   {
      printf("Could not extract run-conditions get-result=%d, is-valid=%d\n", res, runCond.isValid());

      edm::ESHandle<RunInfo> sum;
      iSetup.get<RunInfoRcd>().get(sum);

      current = sum->m_avg_current;
      printf("Got current from RunInfoRcd %f\n", sum->m_avg_current);
   }

   static_cast<CmsEveMagField*>(m_MagField)->SetFieldByCurrent(current);
}

//------------------------------------------------------------------------------

void EveService::postProcessEvent(const edm::Event&, const edm::EventSetup&)
{
   printf("EveService::postProcessEvent: Starting GUI loop.\n");

   m_NextButton->SetText("Next Event");

   gEve->Redraw3D();

   m_Rint->Run(kTRUE);

   gEve->GetCurrentEvent()->DestroyElements();
}

//------------------------------------------------------------------------------

void EveService::display()
{
   // Display whatever was registered so far, wait until user presses
   // the "Step" button.

   m_NextButton->SetText("Step");

   gEve->Redraw3D();

   m_Rint->Run(kTRUE);
}

//==============================================================================
// Getters for cleints
//==============================================================================

TEveManager* EveService::getManager()
{
   gEve = m_EveManager;
   return m_EveManager;
}

TEveMagField* EveService::getMagField()
{
   return m_MagField;
}
void EveService::setupFieldForPropagator(TEveTrackPropagator* prop)
{
   prop->SetMagFieldObj(m_MagField, kFALSE);
}


//==============================================================================
// GUI Builders and callback slots
//==============================================================================

namespace
{
   TGTextButton*
   MkTxtButton(TGCompositeFrame* p, const char* txt, Int_t width=0,
               Int_t lo=0, Int_t ro=0, Int_t to=0, Int_t bo=0)
   {
      // Create a standard button.
      // If width is not zero, the fixed-width flag is set.

      TGTextButton* b = new TGTextButton(p, txt);
      if (width > 0) {
         b->SetWidth(width);
         b->ChangeOptions(b->GetOptions() | kFixedWidth);
      }
      p->AddFrame(b, new TGLayoutHints(kLHintsNormal, lo,ro,to,bo));
      return b;
   }
}

void EveService::createEventNavigationGUI()
{
   const TString cls("EveService");

   TEveBrowser *browser = gEve->GetBrowser();
   browser->StartEmbedding(TRootBrowser::kBottom);

   TGMainFrame *mf = new TGMainFrame(gClient->GetRoot(), 400, 100, kVerticalFrame);

   TGHorizontalFrame* f = new TGHorizontalFrame(mf);
   mf->AddFrame(f, new TGLayoutHints(kLHintsExpandX, 0,0,2,2));

   m_NextButton = MkTxtButton(f, "Next Event", 100, 2, 2);
   m_NextButton->Connect("Clicked()", cls, this, "slotNextEvent()");
   
   MkTxtButton(f, "Exit", 100, 2, 2)->
      Connect("Clicked()", cls, this, "slotExit()");

   mf->SetCleanup(kDeepCleanup);
   mf->Layout();
   mf->MapSubwindows();
   mf->MapWindow();

   browser->StopEmbedding("EventCtrl");
}

void EveService::slotNextEvent()
{
   gSystem->ExitLoop();
}

void EveService::slotExit()
{
   throw cms::Exception("UserTerminationRequest");
}
