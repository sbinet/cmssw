
#include "CondFormats/EcalObjects/interface/EcalGainRatios.h"
#include "CondTools/Ecal/interface/EcalGainRatiosXMLTranslator.h"
#include "CondTools/Ecal/interface/EcalCondHeader.h"

#include "CondCore/Utilities/interface/PayLoadInspector.h"
#include "CondCore/Utilities/interface/InspectorPythonWrapper.h"

#include <string>
#include <fstream>

namespace cond {

  template<>
  class ValueExtractor<EcalGainRatios>: public  BaseValueExtractor<EcalGainRatios> {
  public:

    typedef EcalGainRatios Class;
    typedef ExtractWhat<Class> What;
    static What what() { return What();}

    ValueExtractor(){}
    ValueExtractor(What const & what)
    {
      // here one can make stuff really complicated...
    }
    void compute(Class const & it){
    }
  private:
  
  };


  template<>
  std::string
  PayLoadInspector<EcalGainRatios>::dump() const {
    

    std::stringstream ss;    
    EcalCondHeader header;
    ss<<EcalGainRatiosXMLTranslator::dumpXML(header,object());
    return ss.str();

  }
  
  template<>
  std::string PayLoadInspector<EcalGainRatios>::summary() const {

    std::stringstream ss;   
    return ss.str();
  }
  

  template<>
  std::string PayLoadInspector<EcalGainRatios>::plot(std::string const & filename,
						   std::string const &, 
						   std::vector<int> const&, 
						   std::vector<float> const& ) const {
    std::string fname = filename + ".png";
    std::ofstream f(fname.c_str());
    return fname;
  }


}

PYTHON_WRAPPER(EcalGainRatios,EcalGainRatios);
