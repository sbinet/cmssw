#include "FWCore/Framework/interface/MakerMacros.h"

#include "EcalTPGParamBuilder.h"
#include "testEcalTPGScale.h"
#include "EcalTPGDBCopy.h"

DEFINE_SEAL_MODULE();
DEFINE_ANOTHER_FWK_MODULE(EcalTPGParamBuilder);
DEFINE_ANOTHER_FWK_MODULE(EcalTPGDBCopy);
DEFINE_ANOTHER_FWK_MODULE(testEcalTPGScale);

