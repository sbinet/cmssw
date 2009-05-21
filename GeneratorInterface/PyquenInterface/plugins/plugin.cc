//
// $Id: plugin.cc,v 1.3 2009/05/20 23:15:30 yilmaz Exp $
//

#include "FWCore/Framework/interface/InputSourceMacros.h"
#include "FWCore/Framework/interface/MakerMacros.h"
#include "GeneratorInterface/PyquenInterface/interface/PyquenSource.h"
#include "GeneratorInterface/PyquenInterface/interface/PyquenProducer.h"
#include "GeneratorInterface/PyquenInterface/interface/PyquenGeneratorFilter.h"

using edm::PyquenSource;
using edm::PyquenProducer;
using gen::PyquenGeneratorFilter;

DEFINE_FWK_INPUT_SOURCE(PyquenSource);
DEFINE_FWK_MODULE(PyquenProducer);
DEFINE_FWK_MODULE(PyquenGeneratorFilter);
