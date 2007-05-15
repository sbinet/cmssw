// -*- C++ -*-
//
// Package:     Discriminator
// Class  :     Interceptor
// 

// Implementation:
//     Pseudo variable processor that just intercepts all the incoming
//     variables and forwards them to the calibration class.
//
// Author:      Christophe Saout
// Created:     Sat May 05 09:05 CEST 2007
// $Id$
//

#include <vector>
#include <algorithm>

#include "PhysicsTools/MVAComputer/interface/VarProcessor.h"
#include "PhysicsTools/MVAComputer/interface/Variable.h"

#include "PhysicsTools/MVATrainer/interface/Interceptor.h"

using namespace PhysicsTools;

class Interceptor : public VarProcessor {
    public:
	typedef VarProcessor::Registry::Registry<Interceptor,
					Calibration::Interceptor> Registry;

	Interceptor(const char *name,
	            const Calibration::Interceptor *calib,
	            const MVAComputer *computer);
	virtual ~Interceptor();

	virtual void configure(ConfIterator iter, unsigned int n);
	virtual void eval(ValueIterator iter, unsigned int n) const;

    private:
	Calibration::Interceptor	*interceptor;
	std::vector<double>		*values;
};

static Interceptor::Registry registry("Interceptor");

Interceptor::Interceptor(const char *name,
                         const Calibration::Interceptor *calib,
                         const MVAComputer *computer) :
	VarProcessor(name, calib, computer),
	interceptor(const_cast<Calibration::Interceptor*>(calib)),
	values(0)
{
}

Interceptor::~Interceptor()
{
	delete[] values;
}

void Interceptor::configure(ConfIterator iter, unsigned int n)
{
	std::vector<Variable::Flags> flags =
					interceptor->configure(computer, n);
	if (flags.size() != n)
		return;

	for(unsigned int i = 0; i < n; i++)
		iter++(flags[i]);

	iter << Variable::FLAG_NONE;

	values = new std::vector<double>[n];
}

void Interceptor::eval(ValueIterator iter, unsigned int n) const
{
	std::vector<double> *var = values;

//std::cout << "-------------" << std::endl;
	for(unsigned int i = 0; i < n; i++) {
//std::cout << i << std::endl;
		var->resize(iter.size());
		std::copy(iter.begin(), iter.end(), var->begin());
//for(unsigned int j = 0; j < var->size(); j++)
//	std::cout << var->at(j) << std::endl;
		iter++;
		var++;
	}

	interceptor->intercept(values);

	iter(0.0);
}
