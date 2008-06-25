// Here are the necessary incantations to declare your module to the
// framework, so it can be referenced in a cmsRun file.
//
#include "FWCore/PluginManager/interface/ModuleDef.h"
#include "FWCore/Framework/interface/MakerMacros.h"
#include "FWCore/Framework/interface/SourceFactory.h"

#include "HLTrigger/HLTanalyzers/interface/HLTrigReport.h"

#include "DataFormats/EgammaCandidates/interface/ElectronFwd.h"
#include "DataFormats/EgammaCandidates/interface/Electron.h"

#include "DataFormats/EgammaCandidates/interface/PhotonFwd.h"
#include "DataFormats/EgammaCandidates/interface/Photon.h"

#include "HLTrigger/HLTanalyzers/interface/HLTAnalyzer.h"
#include "HLTrigger/HLTanalyzers/interface/HLTGetDigi.h"
#include "HLTrigger/HLTanalyzers/interface/HLTGetRaw.h"

DEFINE_FWK_MODULE(HLTrigReport);

DEFINE__FWK_MODULE(HLTAnalyzer);
DEFINE__FWK_MODULE(HLTGetDigi);
DEFINE__FWK_MODULE(HLTGetRaw);
