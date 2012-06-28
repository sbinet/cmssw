#ifndef EVENTFILTER_GOODIES_IDIE_H
#define EVENTFILTER_GOODIES_IDIE_H

#include "EventFilter/Utilities/interface/Exception.h"
#include "EventFilter/Utilities/interface/TriggerReportDef.h"

#include "xdata/String.h"
#include "xdata/UnsignedInteger32.h"
#include "xdata/ActionListener.h"

#include "xoap/MessageReference.h"
#include "xoap/MessageFactory.h"
#include "xoap/Method.h"

#include "xgi/Utils.h"
#include "xgi/Input.h"
#include "xgi/Output.h"
#include "xgi/Method.h"

#include "xdaq/Application.h"

#include "toolbox/net/URN.h"
#include "toolbox/fsm/exception/Exception.h"


#include <vector>
#include <queue>

#include <sys/time.h>

#include "TFile.h"
#include "TTree.h"

#include "FWCore/Framework/interface/EventProcessor.h"
#include "DQMServices/Core/src/DQMService.h"
#include "DQMServices/Core/interface/DQMStore.h"
#include "DQMServices/Core/interface/MonitorElement.h"

#define MODLZSIZE 25
#define MODLZSIZELUMI 20
#define MOD_OCC_THRESHOLD 5

namespace evf {

  int modlistSortFunction( const void *a, const void *b);

  namespace internal{
   struct fu{
      time_t tstamp;
      unsigned int ccount;
      std::vector<pid_t> cpids;
      std::vector<std::string> signals;
      std::vector<std::string> stacktraces;
    };
   struct rate{
     int nproc;
     int nsub;
     int nrep;
     int npath;
     int nendpath;
     int ptimesRun[evf::max_paths];
     int ptimesPassedPs[evf::max_paths];
     int ptimesPassedL1[evf::max_paths];
     int ptimesPassed[evf::max_paths];
     int ptimesFailed[evf::max_paths];
     int ptimesExcept[evf::max_paths];
     int etimesRun[evf::max_endpaths];
     int etimesPassedPs[evf::max_endpaths];
     int etimesPassedL1[evf::max_endpaths];
     int etimesPassed[evf::max_endpaths];
     int etimesFailed[evf::max_endpaths];
     int etimesExcept[evf::max_endpaths];
   };

  }
  typedef std::map<std::string,internal::fu> fmap;
  typedef fmap::iterator ifmap;
  
  class iDie : public xdaq::Application,
    public xdata::ActionListener
  {
  public:
    //
    // xdaq instantiator macro
    //
    XDAQ_INSTANTIATOR();
  
    
    //
    // construction/destruction
    //
    iDie(xdaq::ApplicationStub *s);
    virtual ~iDie();
    //UI
    void defaultWeb(xgi::Input *in,xgi::Output *out)
      throw (xgi::exception::Exception);
    void summaryTable(xgi::Input *in,xgi::Output *out)
      throw (xgi::exception::Exception);
    void detailsTable(xgi::Input *in,xgi::Output *out)
      throw (xgi::exception::Exception);
    void dumpTable(xgi::Input *in,xgi::Output *out)
      throw (xgi::exception::Exception);
    void updater(xgi::Input *in,xgi::Output *out)
      throw (xgi::exception::Exception);
    void iChoke(xgi::Input *in,xgi::Output *out)
      throw (xgi::exception::Exception);
    void iChokeMiniInterface(xgi::Input *in,xgi::Output *out)
      throw (xgi::exception::Exception);
    void spotlight(xgi::Input *in,xgi::Output *out)
      throw (xgi::exception::Exception);
    //AI
    void postEntry(xgi::Input*in,xgi::Output*out)
      throw (xgi::exception::Exception);
    void postEntryiChoke(xgi::Input*in,xgi::Output*out)
      throw (xgi::exception::Exception);
    
    // *fake* fsm soap command callback
    xoap::MessageReference fsmCallback(xoap::MessageReference msg)
      throw (xoap::exception::Exception);

    // xdata:ActionListener interface
    void actionPerformed(xdata::Event& e);


  private:

    struct sorted_indices{
      sorted_indices(const std::vector<int> &arr) : arr_(arr)
      {
	ind_.resize(arr_.size(),0);
	unsigned int i = 0;
	while(i<ind_.size()) {ind_[i] = i; i++;}
	std::sort(ind_.rbegin(),ind_.rend(),*this);
      }
      int operator[](size_t ind) const {return arr_[ind_[ind]];}
      
      bool operator()(const size_t a, const size_t b) const
      {
	return arr_[a]<arr_[b];
      }
      int ii(size_t ind){return ind_[ind];}
      std::vector<int> ind_;
      const std::vector<int> &arr_;
    };
    //
    // private member functions
    //
    
    void reset();
    void parseModuleLegenda(std::string);
    void parseModuleHisto(const char *, unsigned int);
    void parsePathLegenda(std::string);
    void parsePathHisto(const unsigned char *, unsigned int);
    void initFramework();
    void deleteFramework();
    void initMonitorElements();
    void fillDQMStatHist(int nbsIdx, unsigned int lsid, float rate, float time, float busy, float rateErr, float timeErr);
    void fillDQMModFractionHist(int nbsIdx, unsigned int lsid, unsigned int nonIdle,
		                 std::vector<std::pair<unsigned int, unsigned int>> offenders);
    void updateRollingHistos(unsigned int lsid,unsigned int rate, float ms, float busy, unsigned int nbsIdx);
    void doFlush();
    void perLumiFileSaver(unsigned int lsid);
    //
    // member data
    //

    // message logger
    Logger                          log_;
		
    // monitored parameters
    xdata::String                   url_;
    xdata::String                   class_;
    xdata::UnsignedInteger32        instance_;
    xdata::String                   hostname_;
    xdata::UnsignedInteger32        runNumber_;
    xdata::String                   dqmCollectorHost_;
    xdata::String                   dqmCollectorPort_;
    fmap                            fus_;
    
    unsigned int                    totalCores_;
    unsigned int                    nstates_;   
    std::vector<int>                cpuentries_;
    std::vector<std::vector<int> >  cpustat_;
    std::vector<std::string>        mapmod_;
    unsigned int                    last_ls_;
    std::vector<TriggerReportStatic>trp_;
    std::vector<int>                trpentries_;
    std::vector<std::string>        mappath_;
    //root stuff
    TFile                          *f_;
    TTree                          *t_;
    TBranch                        *b_;
    TBranch                        *b1_;
    TBranch                        *b2_;
    TBranch                        *b3_;
    TBranch                        *b4_;
    int                            *datap_;
    TriggerReportStatic            *trppriv_;
    internal::rate                  r_;

    //message statistics 
    int                             nModuleLegendaMessageReceived_;
    int                             nPathLegendaMessageReceived_;
    int                             nModuleLegendaMessageWithDataReceived_;
    int                             nPathLegendaMessageWithDataReceived_;
    int                             nModuleHistoMessageReceived_;
    int                             nPathHistoMessageReceived_;
    timeval                         runStartDetectedTimeStamp_;
    timeval                         lastModuleLegendaMessageTimeStamp_;
    timeval                         lastPathLegendaMessageTimeStamp_;

    //DQM histogram statistics
    std::vector<unsigned int> epInstances;
    std::vector<unsigned int> epMax;
    std::vector<float> epThreshold;
    std::vector<float> epThresholdTheor;
    std::vector<float> HTInveff;
    std::vector<unsigned int> nbMachines;

    class commonLsStat {
      
      public:
      unsigned int ls_;
      std::vector<float> busyVec_;
      std::vector<float> busyVecTheor_;
      std::vector<unsigned int> nbMachines;
      commonLsStat(unsigned int lsid,unsigned int classes) {
        for (size_t i=0;i<classes;i++) {
	  busyVec_.push_back(0.);
	  busyVecTheor_.push_back(0.);
	  nbMachines.push_back(0);
	}
	ls_=lsid;
      }
      void setBusyForClass(unsigned int classIdx,float busy,float busyTheor, unsigned int nMachineReports) {
	busyVec_[classIdx]=busy;
	busyVecTheor_[classIdx]=busyTheor;
	nbMachines[classIdx]=nMachineReports;
      }

      float getBusyTotalFrac() {
	float sum=0;
	float sumMachines=0;
	for (size_t i=0;i<busyVec_.size();i++) {
	  sum+=nbMachines.at(i)*busyVec_[i];
	  sumMachines+=nbMachines.at(i);
	}
	if (sumMachines>0)
	  return sum/sumMachines;
	else return 0.;
      }

      float getBusyTotalFracTheor(std::vector<unsigned int> &epInstances, std::vector<unsigned int> &epMax) {
	float sum=0;
	float sumMachines=0;
	for (size_t i=0;i<busyVecTheor_.size() && i<nbMachines.size();i++) {
	  if (epMax[i])
	    sum+=((float)epInstances[i]/epMax[i])*nbMachines.at(i)*busyVecTheor_[i];
	  sumMachines+=nbMachines.at(i);
	}
	if (sumMachines>0)
	  return sum/sumMachines;
	else return 0.;
      }
    };

    class lsStat {
      public:
      unsigned int ls_;
      bool updated_;
      unsigned int nbSubs_;
      unsigned int nSampledNonIdle_;
      unsigned int nSampledNonIdle2_;
      unsigned int nSampledIdle_;
      unsigned int nSampledIdle2_;
      unsigned int nProc_;
      unsigned int nProc2_;
      unsigned int nReports_;
      unsigned int nMaxReports_;
      double rateAvg;
      double rateErr;
      double evtTimeAvg;
      double evtTimeErr;
      double fracWaitingAvg;
      unsigned int nmodulenames_;
      std::pair<unsigned int,unsigned int> *moduleSamplingSums;

      lsStat(unsigned int ls, unsigned int nbSubs,unsigned int maxreps,unsigned int nmodulenames):
	ls_(ls),updated_(false),nbSubs_(nbSubs),
	nSampledNonIdle_(0),nSampledNonIdle2_(0),nSampledIdle_(0),nSampledIdle2_(0),
	nProc_(0),nProc2_(0),nReports_(0),nMaxReports_(maxreps),nmodulenames_(nmodulenames)
      {
        moduleSamplingSums = new std::pair<unsigned int,unsigned int>[nmodulenames_];
	for (unsigned int i=0;i<nmodulenames_;i++) {
	  moduleSamplingSums[i].first=i;
	  moduleSamplingSums[i].second=0;
	}
      }

      void update(unsigned int nSampledNonIdle,unsigned int nSampledIdle, unsigned int nProc) {
	nReports_++;
	nSampledNonIdle_+=nSampledNonIdle;
	nSampledNonIdle2_+=pow(nSampledNonIdle,2);
	nSampledIdle_+=nSampledIdle;
	nSampledIdle2_+=pow(nSampledIdle,2);
	nProc_+=nProc;
	nProc2_+=pow(nProc,2);
	updated_=true;
      }

      std::pair<unsigned int,unsigned int> * getModuleSamplingPtr() {
        return moduleSamplingSums;
      }

      void deleteModuleSamplingPtr() {
        delete moduleSamplingSums;
	moduleSamplingSums=nullptr;
        nmodulenames_=0;
      }

      void calcStat()
      {
	if (!updated_) return;
	rateAvg=nProc_ / 23.;
	rateErr=sqrt(fabs(nProc2_ - pow(nProc_,2))) / 23.;
	if (rateAvg==0.) {rateErr=0.;evtTimeAvg=0.;evtTimeErr=0.;fracWaitingAvg=0;}
	else {
	  if (nSampledNonIdle_+nSampledIdle_!=0) {
	    fracWaitingAvg= nSampledIdle_/(1.0*nSampledNonIdle_+nSampledIdle_);
	    double nSampledIdleErr2=fabs(nSampledIdle2_ - pow(nSampledIdle_,2));
	    double nSampledNonIdleErr2=fabs(nSampledNonIdle2_ - pow(nSampledNonIdle_,2));
	    double fracWaitingAvgErr= sqrt(
			            (pow(nSampledIdle_,2)*nSampledNonIdleErr2
				     + pow(nSampledNonIdle_,2)*nSampledIdleErr2)
				    / pow(nSampledNonIdle_+nSampledIdle_,2));
	    evtTimeAvg=nbSubs_* fracWaitingAvg / rateAvg;
	    evtTimeErr = nbSubs_ * ((fracWaitingAvg*rateErr)/pow(rateAvg,2) + fracWaitingAvgErr/rateAvg);
	  }
	}
	updated_=false;
      }

      float getRate() {
	if (updated_) calcStat();
	return rateAvg;
      }

      float getRateErr() {
	if (updated_) calcStat();
	return rateErr;
      }

      float getEvtTime() {
	if (updated_) calcStat();
	return evtTimeAvg;
      }

      float getEvtTimeErr() {
	if (updated_) calcStat();
	return evtTimeErr;
      }

      unsigned int getNSampledNonIdle() {
	if (updated_) calcStat();
        return nSampledNonIdle_;
      }

      float getFracBusy() {
	if (updated_) calcStat();
	return 1.-fracWaitingAvg;
      }

      std::vector<std::pair<unsigned int, unsigned int>> getOffendersVector() {
        std::vector<std::pair<unsigned int, unsigned int>> ret;
	if (updated_) calcStat();
	if (moduleSamplingSums) {
          std::qsort((void *)moduleSamplingSums, nmodulenames_,
	             sizeof(std::pair<unsigned int,unsigned int>), modlistSortFunction);
	  unsigned int count=0;
	  unsigned int saveidx=0;
	  while (saveidx < MODLZSIZE && count<nmodulenames_ && saveidx<MODLZSIZE)
	  {
            if (moduleSamplingSums[count].first==2) {count++;continue;}
            ret.push_back(moduleSamplingSums[count]);
	    saveidx++;
	    count++;
	  }
	}
        return ret;
      }
    };


    //DQM
    boost::shared_ptr<std::vector<edm::ParameterSet> > pServiceSets_;
    edm::ServiceToken               serviceToken_;
    edm::EventProcessor             *evtProcessor_;
    DQMService                      *dqmService_;
    DQMStore                        *dqmStore_;
    std::string                     configString_;
    bool                            dqmDisabled_;

    std::map<unsigned int,int> nbSubsList;
    std::map<int,unsigned int> nbSubsListInv;
    unsigned int nbSubsClasses;
    std::vector<MonitorElement*> meVecRate_;
    std::vector<MonitorElement*> meVecTime_;
    std::vector<MonitorElement*> meVecOffenders_;
    MonitorElement * rateSummary_;
    MonitorElement * timingSummary_;
    MonitorElement * busySummary_;
    MonitorElement * daqBusySummary_;
    unsigned int summaryLastLs_;
    std::map<unsigned int, unsigned int> occupancyNameMap;
    //1 queue per number of subProcesses (and one common)
    std::queue<commonLsStat> commonLsHistory;
    std::queue<lsStat> *lsHistory;

    std::vector<unsigned int> currentLs_;

    xdata::UnsignedInteger32 saveLsInterval_;
    unsigned int ilumiprev_;
    std::list<std::string> pastSavedFiles_;
    xdata::String dqmSaveDir_;
    unsigned int savedForLs_;
    std::string fileBaseName_;
    bool writeDirectoryPresent_;
  }; // class iDie

  int modlistSortFunction( const void *a, const void *b)
  {
    std::pair<unsigned int,unsigned int> intOne = *((std::pair<unsigned int,unsigned int>*)a);
    std::pair<unsigned int,unsigned int> intTwo = *((std::pair<unsigned int,unsigned int>*)b);
    if (intOne.second > intTwo.second)
      return -1;
    if (intOne.second == intTwo.second)
      return 0;
    return 1;
  }


} // namespace evf


#endif
