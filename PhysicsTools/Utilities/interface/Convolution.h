#ifndef PhysicsTools_Utilities_Convolution_h
#define PhysicsTools_Utilities_Convolution_h
#include "FWCore/Utilities/interface/EDMException.h"

namespace function {
  template<typename A, typename B>
  class ConvolutionStruct {
   public:
    static const unsigned int arguments = 1;
    // min and max are defined in the domain of b
    ConvolutionStruct(const A& a, const B& b, 
		double min, double max, size_t steps) : 
      a_(a), b_(b), min_(min), max_(max), 
      delta_((max-min)/(steps-1)), steps_(steps) { 
      if(max < min)
	throw edm::Exception(edm::errors::Configuration)
	  << "Convolution: min must be smaller than max\n"; 
    }
    double operator()(double x) const;  
   private:
    A a_;
    B b_;
    double min_, max_, delta_;
    size_t steps_;
  };

  template<typename A, typename B>
  double ConvolutionStruct<A, B>::operator()(double x) const {
    double f = 0; 
    // x - max < y < x - min
    double y0 = x - max_;
    for(size_t n = 0; n < steps_; ++n) {
      double y = y0 + n*delta_;
      f += a_(y) * b_(x - y);
    }   
    return f * delta_;
  }

  template<typename A, typename B>
  struct Convolution {
    typedef ConvolutionStruct<A, B> type;
    static type compose(const A& a, const B& b) {
      return type(a, b);
    }
  };

  template<typename A, typename B>
  inline typename function::Composition<A, B>::type conv(const A& a, const B& b) {
    return function::Composition<A, B>::compose(a, b);
  }

}



#endif
