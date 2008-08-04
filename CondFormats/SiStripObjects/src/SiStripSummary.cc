#include "CondFormats/SiStripObjects/interface/SiStripSummary.h"
#include "FWCore/MessageLogger/interface/MessageLogger.h"

		
SiStripSummary::SiStripSummary(std::vector<std::string>& userDBContent, std::string tag)
{
  userDBContent_ = userDBContent;
  tag_ = tag;
  runNr_ = 0;
  timeValue_ = 0;
}


SiStripSummary::SiStripSummary(const SiStripSummary& input)
{
  userDBContent_ = input.getUserDBContent();
  runNr_ = input.getTimeValue();
  timeValue_ = input.getRunNr();
  v_sum_.clear();
  indexes_.clear();
  v_sum_.insert(v_sum_.end(),input.v_sum_.begin(),input.v_sum_.end());
  indexes_.insert(indexes_.end(),input.indexes_.begin(),input.indexes_.end());
}


bool SiStripSummary::put(const uint32_t& DetId, InputVector &input, std::vector<std::string>& userContent ) 
{
  Registry::iterator p 	= std::lower_bound(indexes_.begin(),indexes_.end(),DetId,SiStripSummary::StrictWeakOrdering());
  
  if(p==indexes_.end() || p->detid!=DetId){
    //First request for the given DetID
    //Create entries for all the declared userDBContent
    //and fill for the provided userContent
 
    DetRegistry detregistry;
    detregistry.detid  = DetId;
    detregistry.ibegin = v_sum_.size();
    indexes_.insert(p,detregistry);
    InputVector tmp(userDBContent_.size(),-9999);

    for(size_t i=0;i<userContent.size();++i)
      tmp[getPosition(userContent[i])]=input[i];
    
    v_sum_.insert(v_sum_.end(),tmp.begin(),tmp.end());
  } else {

    if (p->detid==DetId){
      //I should already find the entries 
      //fill for the provided userContent

      for(size_t i=0;i<userContent.size();++i)
	v_sum_[p->ibegin+getPosition(userContent[i])]=input[i];
    }
  }
	
  return true;
}


bool SiStripSummary::put(TrackerRegion region, InputVector &input, std::vector<std::string>& userContent ) {

  uint32_t fakeDet = region;
  return put(fakeDet, input, userContent);
}


const SiStripSummary::Range SiStripSummary::getRange(const uint32_t& DetId) const 
{

  RegistryIterator p = std::lower_bound(indexes_.begin(),indexes_.end(),DetId,SiStripSummary::StrictWeakOrdering());
  if (p==indexes_.end()|| p->detid!=DetId) 
    return SiStripSummary::Range(v_sum_.end(),v_sum_.end()); 
  else 
    return SiStripSummary::Range(v_sum_.begin()+p->ibegin,v_sum_.begin()+userDBContent_.size());
}


std::vector<uint32_t> SiStripSummary::getDetIds() const 
{
  // returns vector of DetIds in map
  std::vector<uint32_t> DetIds_;
  SiStripSummary::RegistryIterator begin = indexes_.begin();
  SiStripSummary::RegistryIterator end   = indexes_.end();
  for (SiStripSummary::RegistryIterator p=begin; p != end; ++p) {
    DetIds_.push_back(p->detid);
  }
  return DetIds_;
}



const short SiStripSummary::getPosition(std::string elementName) const
{
  // returns position of elementName in UserDBContent_
  std::vector<std::string>::const_iterator it = find(userDBContent_.begin(),userDBContent_.end(),elementName);  
  short pos = -1;
  if (it != userDBContent_.end()) pos = it - userDBContent_.begin();
  else edm::LogError("SiStripSummary") << "attempting to retrieve non existing historic DB object : "<< elementName <<std::endl;
  return pos;  
}   



void  SiStripSummary::setObj(const uint32_t& detID, std::string elementName, float value) 
{
  // modifies value of info "elementName" for the given detID
  // requires that an entry has be defined beforehand for detId in DB
  RegistryIterator p = std::lower_bound(indexes_.begin(),indexes_.end(),detID,SiStripSummary::StrictWeakOrdering());
  if (p==indexes_.end()|| p->detid!=detID) 
    {
      throw cms::Exception("")
	<<"not allowed to modify "<< elementName << " in historic DB - SummaryObj needs to be available first !";
    }

  const SiStripSummary::Range range = getRange(detID);
   
  std::vector<float>::const_iterator it = range.first+getPosition(elementName);
  std::vector<float>::difference_type pos = -1;
  if (it != v_sum_.end()){ 
    pos = it - v_sum_.begin();
    v_sum_.at(pos) = value; }  
}


float SiStripSummary::getSummaryObj(uint32_t& detID, std::string elementName) const
{
  const SiStripSummary::Range range = getRange(detID);
  const short pos =  getPosition(elementName);
  if (pos != -1) return *((range.first)+getPosition(elementName));
   
  else return -999;
}


std::vector<float> SiStripSummary::getSummaryObj(uint32_t& detID, std::vector<std::string> list) const
{  
  std::vector<float> SummaryObj;
  const SiStripSummary::Range range = getRange(detID);
  for (unsigned int i=0; i<list.size(); i++){ 
    const size_t pos=getPosition(list.at(i));
    if (pos!=-1) 
      SummaryObj.push_back(*((range.first)+pos));
    else 
      SummaryObj.push_back(-999.);
  }
  return SummaryObj;
}



std::vector<float> SiStripSummary::getSummaryObj(uint32_t& detID) const
{  
  std::vector<float> SummaryObj;
  const SiStripSummary::Range range = getRange(detID);
  for (unsigned int i=0; i<userDBContent_.size(); i++) SummaryObj.push_back(*((range.first)+i));
  return SummaryObj;
}



std::vector<float> SiStripSummary::getSummaryObj() const
{
  return v_sum_;
}


std::vector<float> SiStripSummary::getSummaryObj(std::string elementName) const
{
  std::vector<float> vSumElement;
  std::vector<uint32_t> DetIds_ = getDetIds();
  int pos = getPosition(elementName);
   
  if (pos !=-1)
    {
      for (unsigned int i=0; i<DetIds_.size(); i++){
	const SiStripSummary::Range range = getRange(DetIds_.at(i));
	vSumElement.push_back(*((range.first)+pos));}
    }
   
  return vSumElement;
}


void  SiStripSummary::print() 
{
  std::cout << "Nr. of detector elements in SiStripSummary object is " << indexes_.size() 
	    << " RunNr= " << runNr_ 
	    << " timeValue= " << timeValue_ 
	    << std::endl;
}

