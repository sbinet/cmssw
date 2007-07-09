// File: SiPixelSCurveCalibrationAnalysis.cc
// Description:  see SiPixelSCurveCalibrationAnalysis.h
// Author: Jason Keller (University of Nebraska)
//--------------------------------------------


#include "CalibTracker/SiPixelSCurveCalibration/interface/SiPixelSCurveCalibrationAnalysis.h"
#include "FWCore/ServiceRegistry/interface/Service.h"
#include "PhysicsTools/UtilAlgos/interface/TFileService.h"
#include "DataFormats/Common/interface/DetSetVector.h"
#include "DataFormats/SiPixelDigi/interface/PixelDigi.h" 
#include "Geometry/TrackerGeometryBuilder/interface/TrackerGeometry.h"
#include "Geometry/Records/interface/TrackerDigiGeometryRecord.h"
#include "Geometry/TrackerGeometryBuilder/interface/PixelGeomDetUnit.h"
#include "Geometry/Records/interface/TrackerDigiGeometryRecord.h"
#include "Geometry/TrackerGeometryBuilder/interface/PixelTopologyBuilder.h"
#include "Geometry/TrackerTopology/interface/RectangularPixelTopology.h"
#include "DataFormats/SiPixelDetId/interface/PixelBarrelName.h"
#include "DataFormats/SiPixelDetId/interface/PixelEndcapName.h"
#include "FWCore/MessageLogger/interface/MessageLogger.h"
#include "CondFormats/DataRecord/interface/SiPixelFedCablingMapRcd.h"
#include "CondFormats/SiPixelObjects/interface/SiPixelFrameConverter.h"

#include <TFile.h>
#include <TMath.h>
#include <TH1F.h>

#include <iostream>
#include <sstream>

SiPixelSCurveCalibrationAnalysis::SiPixelSCurveCalibrationAnalysis(const edm::ParameterSet& conf) :
  conf_(conf),
  pixsrc_(conf.getUntrackedParameter<std::string>("src", "source")),
  evtnum_(0),
  inputcalibfile_(conf.getParameter<std::string>("inputCalibFile")),
  fedid_(conf.getUntrackedParameter<unsigned int>("fedid", 33)),
  histoNum_(0)
  {
    calib_ = new PixelCalib(inputcalibfile_);
    vcalmin_ = calib_->vcal_first();
    vcalmax_ = calib_->vcal_last();
    vcalstep_ = calib_->vcal_step();
    ntriggers_ = calib_->nTriggersPerPattern();
    fitfunc_ = new TF1("fit", "0.5*[0]*(1+TMath::Erf((x-[1])/([2]*sqrt(2))))", vcalmin_, vcalmax_);
    fitfunc_->SetParameters(1.0, 15.0, 0.2);
    meanhistos_ = new TObjArray();
    sigmahistos_ = new TObjArray();
  }

SiPixelSCurveCalibrationAnalysis::~SiPixelSCurveCalibrationAnalysis()
{
  delete calib_;
}

void SiPixelSCurveCalibrationAnalysis::beginJob(const edm::EventSetup& iSetup)
{
  using namespace edm;
  LogInfo("SCurve Calibration") << "The starting Vcal value is " << vcalmin_;
  LogInfo("SCurve Calibration") << "The ending Vcal value is " << vcalmax_;
  LogInfo("SCurve Calibration") << "Vcal will be incremented in steps of " << vcalstep_;
  LogInfo("SCurve Calibration") << "The number of triggers is " << ntriggers_; 
  iSetup.get<SiPixelFedCablingMapRcd>().get(map_);
}

void SiPixelSCurveCalibrationAnalysis::analyze(const edm::Event& e, const edm::EventSetup& es)
{
  using namespace edm;
  unsigned int vcal = calib_->vcal_fromeventno(evtnum_);
  ++evtnum_;

  Handle<DetSetVector<PixelDigi> > pixelDigis;
  e.getByLabel(pixsrc_, pixelDigis );
  DetSetVector<PixelDigi>::const_iterator digiiter;
  for(digiiter = pixelDigis->begin() ; digiiter != pixelDigis->end(); ++digiiter)
  {
    unsigned int detid = digiiter->id;
    DetId detector(detid);
    std::map<unsigned int, SCurveContainer>::const_iterator test = detIdMap_.find(detid);
    if(test == detIdMap_.end())
    {
      ESHandle<TrackerGeometry> geom;
      es.get<TrackerDigiGeometryRecord>().get( geom );
      const TrackerGeometry& theTracker(*geom);
      const PixelGeomDetUnit *theGeomDet = dynamic_cast<const PixelGeomDetUnit*>                                             (theTracker.idToDet(detector));
      unsigned int rows = theGeomDet->specificTopology().nrows();
      unsigned int cols = theGeomDet->specificTopology().ncolumns();
      histoNum_ += rows * cols;
      SCurveContainer temp(vcalmin_, vcalmax_, vcalstep_,
                           ntriggers_, rows, cols, detid);
      detIdMap_.insert(std::make_pair(detid, temp));
    }

    DetSet<PixelDigi>::const_iterator pixiter;
    for(pixiter = digiiter->data.begin(); pixiter != digiiter->data.end(); ++pixiter)
    {
      int adc = pixiter->adc();
      int row = pixiter->row();
      int col = pixiter->column();
      detIdMap_[detid].setEff(adc, vcal, row, col);
    }  
  }
}

void SiPixelSCurveCalibrationAnalysis::endJob()
{
  using namespace edm;
  LogInfo("SCurve Calibration") << "Making approximately " << histoNum_ << " histograms.";
  std::map<unsigned int, SCurveContainer>::iterator siter;
  int i = 1;
  for(siter = detIdMap_.begin(); siter != detIdMap_.end(); ++siter)
  {
    DetId holder(siter->first);
    int rows = siter->second.getRowMax();
    int cols = siter->second.getColMax(); 
    SiPixelFrameConverter convert(map_.product(), fedid_);
    for(int j = 0 ; j != rows; ++j)
    {
      for(int k = 0; k != cols; ++k)
      { 
        SiPixelFrameConverter::DetectorIndex detind = {siter->first, j, k};
        SiPixelFrameConverter::CablingIndex cable;
        int status = convert.toCabling(cable, detind);
        std::string meanname = "Mean" + makeRocName(j, k, holder, cable.roc);
        TH1F* tempmean = (TH1F*)meanhistos_->FindObject(meanname.c_str());
        if(!tempmean)
        {
          std::string meantitle = "Mean for " + makeRocName(j, k, holder, cable.roc);
          tempmean = fs_->make<TH1F>(meanname.c_str(), meantitle.c_str(), vcalmax_*10, vcalmin_, vcalmax_);
          meanhistos_->Add(tempmean);
        }

        std::string sigmaname = "Sigma" + makeRocName(j, k, holder, cable.roc); 
        TH1F* tempsigma = (TH1F*)sigmahistos_->FindObject(sigmaname.c_str());
        if(!tempsigma)
        {
          std::string sigmatitle = "Sigma for " + makeRocTitle(j, k, holder, cable.roc);
          tempsigma = fs_->make<TH1F>(sigmaname.c_str(), sigmatitle.c_str(), 100, 0.0, 1.0);
          sigmahistos_->Add(tempsigma);
        }
        makeHistogram(siter->second, j, k);
        tempmean->Fill(fitfunc_->GetParameter(1));
        tempsigma->Fill(fitfunc_->GetParameter(2));
        if(i % 1000 == 0)
          LogInfo("SCurve Calibration") << "Making histogram " << i << " out of " << histoNum_;
        ++i;
      }
    }
  }
  
  int entries = meanhistos_->GetEntriesFast();
  for(int j = 0; j != entries; ++j)
  {
    TH1F* tempmean = ((TH1F*)(*meanhistos_)[j]);
    TH1F* tempsigma = ((TH1F*)(*sigmahistos_)[j]);
    tempmean->Fit("gaus");
    tempsigma->Fit("gaus");
  }
  
}

std::string SiPixelSCurveCalibrationAnalysis::makeName(const int& row, const int& col, const DetId& pixdet)
{
  std::stringstream name("");
  if(pixdet.subdetId() == 1)
  {
    PixelBarrelName barrel(pixdet);
    name  << barrel.name() << "r" << row << "c" << col;
  }

  else
  {
    PixelEndcapName endcap(pixdet);
    name << endcap.name() << "r" << row << "c" << col;
  }

  return name.str();
} 

std::string SiPixelSCurveCalibrationAnalysis::makeRocName(const int& row, const int& col, const DetId& pixdet, const int& roc)
{
  std::stringstream name("");
  if(pixdet.subdetId() == 1)
  {
    PixelBarrelName barrel(pixdet);
    name << barrel.name() << "ROC " << roc;
  }

  else
  {
    PixelEndcapName endcap(pixdet);
    name << endcap.name() << "ROC " << roc;
  }

  return name.str();
}

std::string SiPixelSCurveCalibrationAnalysis::makeTitle(const int& row, const int& col, const DetId& pixdet)
{
  std::stringstream title("");

  if(pixdet.subdetId() == 1)
  {
    PixelBarrelName barrel(pixdet);
    title << "SCurve for" << barrel.name() << " Row " << row << " Col " << col;
  }

  else
  {
    PixelEndcapName endcap(pixdet);
    title << "SCurve for" << endcap.name() << " Row " << row << " Col " << col;
  }
  return title.str();
} 

std::string SiPixelSCurveCalibrationAnalysis::makeRocTitle(const int& row, const int& col, const DetId& pixdet, const int& roc)
{
  std::stringstream title("");

  if(pixdet.subdetId() == 1)
  {
    PixelBarrelName barrel(pixdet);
    title << barrel.name() << " ROC " << roc;
  }

  else
  {
    PixelEndcapName endcap(pixdet);
    title << endcap.name() << " ROC " << roc;
  }
  return title.str();
} 

void SiPixelSCurveCalibrationAnalysis::makeHistogram(const SCurveContainer& sc, const int& row, const int& col)
{
  DetId detector(sc.getRawId());
  std::string name = makeName(row, col, detector);
  std::string title = makeTitle(row, col, detector); 
  TH1F* histo = fs_->make<TH1F>(name.c_str(), title.c_str(), calib_->nVcal(), vcalmin_, vcalmax_);
  histo->GetXaxis()->SetTitle("Vcal");
  histo->GetYaxis()->SetTitle("Efficiency");
  for(int l = vcalmin_; l != vcalmax_ + vcalstep_; l += vcalstep_)
  {
    double tempy = sc.getEff(l, row, col);
    histo->Fill(l, tempy);
  } 
  fitfunc_->SetParameters(1.0, 15.0, 0.2);
  histo->Fit("fit", "RQ0");
  //histo->Write();
  delete histo;
}

