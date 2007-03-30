#include "RecoMuon/MuonIsolation/interface/IsolatorByNominalEfficiency.h"
#include "RecoMuon/MuonIsolation/src/NominalEfficiencyThresholds.h"
#include "DataFormats/MuonReco/interface/MuIsoDeposit.h"
#include "FWCore/ParameterSet/interface/FileInPath.h"

using namespace muonisolation;
using namespace std;

double IsolatorByNominalEfficiency::ConeSizes::size(int i) const
{ if (i >= 0 && i< DIM) return cone_dr[i]; else return 0.; }

int IsolatorByNominalEfficiency::ConeSizes::index(float dr) const
{
 for(int i=DIM; i>=1; i--) if (cone_dr[i-1] < dr) return i;
 return 0;
}

float IsolatorByNominalEfficiency::ConeSizes::cone_dr[]=
{ 0.001, 0.02, 0.045, 0.09, 0.13, 0.17, 0.20, 0.24, 0.28, 0.32, 0.38, 0.45, 0.5, 0.6, 0.7};

IsolatorByNominalEfficiency::IsolatorByNominalEfficiency(const string & thrFile, 
    const vector<string> & ceff, const vector<double>& weights) : theWeights(weights){
  thresholds        = new NominalEfficiencyThresholds(findPath(thrFile));
  coneForEfficiency = cones(ceff);
}

IsolatorByNominalEfficiency::~IsolatorByNominalEfficiency()
{
  delete thresholds;
}

IsolatorByNominalEfficiency::mapNomEff_Cone
    IsolatorByNominalEfficiency::cones(const vector<string>& usrVec) {
  mapNomEff_Cone result;
  for (vector<string>::const_iterator is = usrVec.begin();
         is != usrVec.end(); is++) {
    char * evp = 0;
    int  cone = strtol( (*is).c_str(), &evp, 10);
    float effic = strtod(evp+1, &evp);
    result.insert(make_pair(effic,cone));
  }
  return result;
}

string IsolatorByNominalEfficiency::findPath(const string&  fileName)
{
  // FIXME
  edm::FileInPath f(fileName);
  return f.fullPath();
}

float
IsolatorByNominalEfficiency::result(DepositContainer deposits) const{

  if (deposits.size()==0) {
    cout << "IsolatorByNominalEfficiency: no deposit" << endl;
    return -999.; //FIXME
  }

  // To determine the threshold, the direction of the cone of the first
  // set of deposits is used.
  // For algorithms where different cone axis definitions are used
  // for different types deposits (eg. HCAL and ECAL deposits for
  // calorimeter isolation), the first one is used to determine the threshold
  // value!
//  float theEta = deposits.front()->dirCone().eta();
  float theEta = deposits.back()->eta();

  // Try descending efficiency values to find the point where the candidate
  // becomes non isolated

  float nominalEfficiency = 1.;
  const float deltaeff=0.005;
  const float mineff=deltaeff;
  for (float eff=.995; eff>mineff; eff-=deltaeff) {
    int cone = bestConeForEfficiencyIndex(eff);
    float coneSize = theConesInfo.size(cone);
    NominalEfficiencyThresholds::ThresholdLocation location = {theEta,cone};
    float thres  = thresholds->thresholdValueForEfficiency(location, eff);
    float sumDep = weightedSum(deposits,coneSize);
//      cout << "   Eff=" << eff
//         << " eta=" << theEta
//         << " cone=" << cone
//         << " dR=" << coneSize
//         << " thres=" << thres
//         << " deposit=" << sumDep
//         << " isolated=" << (sumDep < thres)
//         << endl;
    if (sumDep > thres) break;
    nominalEfficiency = eff;
  }
  return nominalEfficiency;
}

int IsolatorByNominalEfficiency::bestConeForEfficiencyIndex(float eff_thr) const
{

  //FIXME use upper_bound
  int best_cone;
  if (coneForEfficiency.size() != 0) {
    best_cone = (--(coneForEfficiency.end()))->second;
  } else return 0;

   mapNomEff_Cone::const_reverse_iterator it;
  for (it = coneForEfficiency.rbegin();
       it != coneForEfficiency.rend(); it++) {
    if (eff_thr <= (*it).first) best_cone = (*it).second;
  }
  return best_cone;
}


double IsolatorByNominalEfficiency::weightedSum(const DepositContainer& deposits,
                                    float dRcone) const {
  double sumDep=0;

  assert(deposits.size()==theWeights.size());

  vector<double>::const_iterator w = theWeights.begin();
  for (DepositContainer::const_iterator dep = deposits.begin();
       dep != deposits.end(); dep++) {
    sumDep += (*dep)->depositWithin(dRcone) * (*w);
    if (sumDep <0.) sumDep = 0.;
    w++;
  }
  return sumDep;
}

Cuts IsolatorByNominalEfficiency::cuts(float nominalEfficiency) const
{
  vector<double>  etaBounds = thresholds->bins();
  vector<double>  coneSizes;
  vector<double>  cutvalues;
  for (vector<double>::const_iterator it=etaBounds.begin(),itEnd=etaBounds.end();it < itEnd;++it){
    float eta = (*it);
    int icone = bestConeForEfficiencyIndex(nominalEfficiency);
    coneSizes.push_back( theConesInfo.size(icone));
    NominalEfficiencyThresholds::ThresholdLocation location = {eta-1.e-3, icone};
    cutvalues.push_back( thresholds->thresholdValueForEfficiency(location, nominalEfficiency));
  }
  return Cuts(etaBounds,coneSizes,cutvalues);
}
