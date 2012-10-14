#include "TauAnalysis/MCEmbeddingTools/plugins/L1ExtraMixerPluginT.h"

#include "FWCore/Utilities/interface/Exception.h"

#include "DataFormats/Common/interface/Handle.h"

#include <TMath.h>

const size_t maxNumL1ExtraObjects = 4;

template <typename T>
L1ExtraMixerPluginT<T>::L1ExtraMixerPluginT(const edm::ParameterSet& cfg)
  : L1ExtraMixerPluginBase(cfg)
{}

template <typename T>
void L1ExtraMixerPluginT<T>::registerProducts(edm::EDProducer& producer)
{
  producer.produces<l1ExtraCollection>(instanceLabel_); 
}

namespace
{
  template <typename T>
  struct higherPtT
  {
    bool operator() (const T& t1, const T& t2)
    {
      return (t1.pt() > t2.pt());
    }
  };
}

template <typename T>
void L1ExtraMixerPluginT<T>::produce(edm::Event& evt, const edm::EventSetup& es)
{
  edm::Handle<l1ExtraCollection> l1ExtraObjects1;
  evt.getByLabel(src1_, l1ExtraObjects1);
  
  edm::Handle<l1ExtraCollection> l1ExtraObjects2;
  evt.getByLabel(src2_, l1ExtraObjects2);
  
  l1ExtraCollection l1ExtraObjects_sorted;
  l1ExtraObjects_sorted.insert(l1ExtraObjects_sorted.end(), l1ExtraObjects1->begin(), l1ExtraObjects1->end());
  l1ExtraObjects_sorted.insert(l1ExtraObjects_sorted.end(), l1ExtraObjects2->begin(), l1ExtraObjects2->end());
  higherPtT<T> higherPt;
  std::sort(l1ExtraObjects_sorted.begin(), l1ExtraObjects_sorted.end(), higherPt);

  std::auto_ptr<l1ExtraCollection> l1ExtraObjects_output(new l1ExtraCollection());

  size_t numL1ExtraObjects = l1ExtraObjects_sorted.size();
  for ( size_t iObject = 0; iObject < TMath::Min(numL1ExtraObjects, maxNumL1ExtraObjects); ++iObject ) {
    l1ExtraObjects_output->push_back(l1ExtraObjects_sorted.at(iObject));
  }

  evt.put(l1ExtraObjects_output, instanceLabel_);
}

#include "DataFormats/L1Trigger/interface/L1EmParticle.h"
#include "DataFormats/L1Trigger/interface/L1MuonParticle.h"
#include "DataFormats/L1Trigger/interface/L1JetParticle.h"

typedef L1ExtraMixerPluginT<l1extra::L1EmParticle> L1ExtraEmParticleMixerPlugin;
typedef L1ExtraMixerPluginT<l1extra::L1MuonParticle> L1ExtraMuonParticleMixerPlugin;
typedef L1ExtraMixerPluginT<l1extra::L1JetParticle> L1ExtraJetParticleMixerPlugin;

#include "FWCore/Framework/interface/MakerMacros.h"

DEFINE_EDM_PLUGIN(L1ExtraMixerPluginFactory, L1ExtraEmParticleMixerPlugin, "L1ExtraEmParticleMixerPlugin");
DEFINE_EDM_PLUGIN(L1ExtraMixerPluginFactory, L1ExtraMuonParticleMixerPlugin, "L1ExtraMuonParticleMixerPlugin");
DEFINE_EDM_PLUGIN(L1ExtraMixerPluginFactory, L1ExtraJetParticleMixerPlugin, "L1ExtraJetParticleMixerPlugin");
