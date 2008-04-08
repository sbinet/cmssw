#include "FWCore/Services/src/InitRootHandlers.h"
#include "FWCore/ParameterSet/interface/ParameterSet.h"
#include "FWCore/MessageLogger/interface/MessageLogger.h"
#include "FWCore/MessageLogger/interface/ELseverityLevel.h"
#include "FWCore/Utilities/interface/EDMException.h"
#include "FWCore/RootAutoLibraryLoader/interface/RootAutoLibraryLoader.h"

#include <string.h>
#include <sstream>

#include "TSystem.h"
#include "TError.h"

namespace {
void RootErrorHandler(int level, bool die, const char* location, const char* message)
{
// Translate ROOT severity level to MessageLogger severity level

  edm::ELseverityLevel el_severity = edm::ELseverityLevel::ELsev_info;

  if (level >= kFatal) {
    el_severity = edm::ELseverityLevel::ELsev_fatal;
    die = true;
  }
  else if (level >= kSysError) {
    el_severity = edm::ELseverityLevel::ELsev_severe;
    die = true;
  }
  else if (level >= kError) {
    el_severity = edm::ELseverityLevel::ELsev_error;
    die = true;
  }
  else if (level >= kWarning) {
    el_severity = edm::ELseverityLevel::ELsev_error;
    die = true;
  }

// Adapt C-strings to std::strings
// Arrange to report the error location as furnished by Root

  std::string el_location = "@SUB=?";
  if (location != 0) el_location = std::string("@SUB=")+std::string(location);

  std::string el_message  = "?";
  if (message != 0)  el_message  = message;

// Try to create a meaningful id string using knowledge of ROOT error messages
//
// id ==     "ROOT-ClassName" where ClassName is the affected class
//      else "ROOT/ClassName" where ClassName is the error-declaring class
//      else "ROOT"

  std::string el_identifier = "ROOT";

  std::string precursor("class ");
  size_t index1 = el_message.find(precursor);
  if (index1 != std::string::npos) {
    size_t index2 = index1 + precursor.length();
    size_t index3 = el_message.find_first_of(" :", index2);
    if (index3 != std::string::npos) {
      size_t substrlen = index3-index2;
      el_identifier += "-";
      el_identifier += el_message.substr(index2,substrlen);
    }
  } else {
    index1 = el_location.find("::");
    if (index1 != std::string::npos) {
      el_identifier += "/";
      el_identifier += el_location.substr(0, index1);
    }
  }

// Intercept some messages and downgrade the severity

    if (el_message.find("dictionary") != std::string::npos) {
      el_severity = edm::ELseverityLevel::ELsev_info;
      die = false;
    }

    if (el_message.find("already in TClassTable") != std::string::npos) {
      el_severity = edm::ELseverityLevel::ELsev_info;
      die = false;
    }

// Intercept some messages and upgrade the severity

    if ((el_location.find("TBranchElement::Fill") != std::string::npos)
     && (el_message.find("fill branch") != std::string::npos)
     && (el_message.find("address") != std::string::npos)
     && (el_message.find("not set") != std::string::npos)) {
      el_severity = edm::ELseverityLevel::ELsev_fatal;
      die = true;
    }

    if ((el_message.find("Tree branches") != std::string::npos)
     && (el_message.find("different numbers of entries") != std::string::npos)) {
      el_severity = edm::ELseverityLevel::ELsev_fatal;
      die = true;
    }

// Feed the message to the MessageLogger... let it choose to suppress or not.

  if (el_severity == edm::ELseverityLevel::ELsev_fatal && !die) {
    edm::LogError("Root_Fatal") << el_location << el_message;
  }
  else if (el_severity == edm::ELseverityLevel::ELsev_severe && !die) {
    edm::LogError("Root_Severe") << el_location << el_message;
  }
  else if (el_severity == edm::ELseverityLevel::ELsev_error && !die) {
    edm::LogError("Root_Error") << el_location << el_message;
  }
  else if (el_severity == edm::ELseverityLevel::ELsev_warning && !die) {
    edm::LogWarning("Root_Warning") << el_location << el_message ;
  }
  else if (el_severity == edm::ELseverityLevel::ELsev_info && !die) {
    edm::LogInfo("Root_Information") << el_location << el_message ;
  }

// Root has declared a fatal error.  Throw an EDMException.

   if (die) {
// Throw an edm::Exception instead of just aborting
     std::ostringstream sstr;
     sstr << "Fatal Root Error: " << el_location << "\n" << el_message << '\n';
     edm::Exception except(edm::errors::FatalRootError, sstr.str());
     throw except;
   }
}
}  // end of unnamed namespace

namespace edm {
namespace service {
InitRootHandlers::InitRootHandlers (edm::ParameterSet const& pset, edm::ActivityRegistry & activity)
  : unloadSigHandler_(pset.getUntrackedParameter<bool> ("UnloadRootSigHandler", false)),
    resetErrHandler_(pset.getUntrackedParameter<bool> ("ResetRootErrHandler", true)),
    autoLibraryLoader_(pset.getUntrackedParameter<bool> ("AutoLibraryLoader", true))
{

  if(unloadSigHandler_) {
  // Deactivate all the Root signal handlers and restore the system defaults
    gSystem->ResetSignal(kSigChild);
    gSystem->ResetSignal(kSigBus);
    gSystem->ResetSignal(kSigSegmentationViolation);
    gSystem->ResetSignal(kSigIllegalInstruction);
    gSystem->ResetSignal(kSigSystem);
    gSystem->ResetSignal(kSigPipe);
    gSystem->ResetSignal(kSigAlarm);
    gSystem->ResetSignal(kSigUrgent);
    gSystem->ResetSignal(kSigFloatingException);
    gSystem->ResetSignal(kSigWindowChanged);
  }

  if(resetErrHandler_) {

  // Replace the Root error handler with one that uses the MessageLogger
    SetErrorHandler(RootErrorHandler);
  }

  // Enable automatic Root library loading.
  if(autoLibraryLoader_) {
    RootAutoLibraryLoader::enable();
  }
}

InitRootHandlers::~InitRootHandlers () {}

}  // end of namespace service
}  // end of namespace edm
