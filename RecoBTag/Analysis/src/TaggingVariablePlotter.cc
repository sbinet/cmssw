#include "RecoBTag/Analysis/interface/TaggingVariablePlotter.h"

using namespace std;
using namespace edm;
using namespace reco;

TaggingVariablePlotter::VariableConfig::VariableConfig(
		const string &name, const ParameterSet &pSet, bool update,
		const string &category) :
	var(getTaggingVariableName(name)),
	nBins(pSet.getParameter<unsigned int>("nBins")),
	min(pSet.getParameter<double>("min")),
	max(pSet.getParameter<double>("max"))
{
	if (var == btau::lastTaggingVariable)
		throw cms::Exception("Configuration")
			<< "Tagging variable \"" << name
			<< "\" does not exist." << endl;

	if (pSet.exists("logScale"))
		logScale = pSet.getParameter<bool>("logScale");
	else
		logScale = false;

	std::vector<unsigned int> indices;
	if (pSet.exists("indices"))
		indices = pSet.getParameter< vector<unsigned int> >("indices");
	else
		indices.push_back(0);

	for(std::vector<unsigned int>::const_iterator iter = indices.begin();
	    iter != indices.end(); iter++) {
		Plot plot;
		plot.histo.reset(new FlavourHistograms<double>(
			name.c_str() + (*iter ? Form("%d", *iter) : TString())
			             + (category.empty() ? TString()
			              		: (TString("_") + category)),
			TaggingVariableDescription[var], nBins, min, max,
			false, logScale, true, "b", update));
		plot.index = *iter;
		plots.push_back(plot);
	}
}

TaggingVariablePlotter::TaggingVariablePlotter(const TString &tagName,
	const EtaPtBin &etaPtBin, const ParameterSet &pSet, bool update,
	const string &category) : BaseTagInfoPlotter(tagName, etaPtBin)
{
	if (update) {
		TString dir = "TaggingVariable" + theExtensionString;
		gFile->cd();
		gFile->cd(dir);
	}

	vector<string> pSets = pSet.getParameterNames();
	for(vector<string>::const_iterator iter = pSets.begin();
	    iter != pSets.end(); iter++) {
		VariableConfig var(*iter,
		                   pSet.getParameter<ParameterSet>(*iter),
		                   update, category);
		variables.push_back(var);
	}
}


TaggingVariablePlotter::~TaggingVariablePlotter ()
{
}


void TaggingVariablePlotter::analyzeTag (const BaseTagInfo *baseTagInfo,
	const int &jetFlavour)
{
	analyzeTag(baseTagInfo->taggingVariables(), jetFlavour);
}

void TaggingVariablePlotter::analyzeTag (const TaggingVariableList &vars,
	const int &jetFlavour)
{
	for(vector<VariableConfig>::const_iterator iter = variables.begin();
	    iter != variables.end(); iter++) {
		std::vector<TaggingValue> values =
					vars.getList(iter->var, false);
		if (values.empty())
			continue;

		unsigned int size = values.size();
		for(std::vector<VariableConfig::Plot>::const_iterator plot =
						iter->plots.begin();
		    plot != iter->plots.end(); plot++) {
			if (plot->index == 0) {
				for(unsigned int i = 0; i < size; i++)
					plot->histo->fill(jetFlavour, values[i]);
			} else if (plot->index - 1 < size)
				plot->histo->fill(jetFlavour,
				                  values[plot->index - 1]);
		}
	}
}

void TaggingVariablePlotter::finalize()
{
}

void TaggingVariablePlotter::psPlot(const TString &name)
{
}

void TaggingVariablePlotter::write(const bool allHisto)
{
	TString dir = "TaggingVariable" + theExtensionString;
	gFile->cd();
	if (!gFile->Get(dir))
		gFile->mkdir(dir);
	gFile->cd(dir);

	for(vector<VariableConfig>::const_iterator iter = variables.begin();
	    iter != variables.end(); iter++) {
		for(std::vector<VariableConfig::Plot>::const_iterator plot =
							iter->plots.begin();
		    plot != iter->plots.end(); plot++)
			plot->histo->write(allHisto);
	}

	gFile->cd();
}

void TaggingVariablePlotter::epsPlot(const TString &name)
{
}
