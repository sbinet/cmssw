#include <iomanip>
#include <ostream>
#include <sstream>
#include <cstring>
#include "EventFilter/SiStripRawToDigi/interface/SiStripFEDBufferComponents.h"
#include "FWCore/Utilities/interface/CRC16.h"

namespace sistrip {

  void printHexValue(const uint8_t value, std::ostream& os)
  {
    const std::ios_base::fmtflags originalFormatFlags = os.flags();
    os << std::hex << std::setfill('0') << std::setw(2);
    os << uint16_t(value);
    os.flags(originalFormatFlags);
  }

  void printHexWord(const uint8_t* pointer, const size_t lengthInBytes, std::ostream& os)
  {
    size_t i = lengthInBytes-1;
    do{
      printHexValue(pointer[i],os);
      if (i != 0) os << " ";
    } while (i-- != 0);
  }

  void printHex(const void* pointer, const size_t lengthInBytes, std::ostream& os)
  {
    const uint8_t* bytePointer = reinterpret_cast<const uint8_t*>(pointer);
    //if there is one 64 bit word or less, print it out
    if (lengthInBytes <= 8) {
      printHexWord(bytePointer,lengthInBytes,os);
    }
    //otherwise, print word numbers etc
    else {
      //header
      os << "word\tbyte\t                       \t\tbyte" << std::endl;;
      const size_t words = lengthInBytes/8;
      const size_t extraBytes = lengthInBytes - 8*words;
      //print full words
      for (size_t w = 0; w < words; w++) {
	const size_t startByte = w*8;
	os << w << '\t' << startByte+8 << '\t';
	printHexWord(bytePointer+startByte,8,os);
	os << "\t\t" << startByte << std::endl;
      }
      //print part word, if any
      if (extraBytes) {
	const size_t startByte = words*8;
	os << words << '\t' << startByte+8 << '\t';
	//padding
	size_t p = 8;
	while (p-- > extraBytes) {
	  os << "00 ";
	}
	printHexWord(bytePointer+startByte,extraBytes,os);
	os << "\t\t" << startByte << std::endl;
      }
      os << std::endl;
    }
  }
  
  
  uint16_t calculateFEDBufferCRC(const uint8_t* buffer, const size_t lengthInBytes)
  {
    uint16_t crc = 0xFFFF;
    for (size_t i = 0; i < lengthInBytes-8; i++) {
      crc = evf::compute_crc_8bit(crc,buffer[i^7]);
    }
    for (size_t i=lengthInBytes-8; i<lengthInBytes; i++) {
      uint8_t byte;
      //set CRC bytes to zero since these were not set when CRC was calculated
      if (i==lengthInBytes-4 || i==lengthInBytes-3)
	byte = 0x00;
      else
	byte = buffer[i^7];
      crc = evf::compute_crc_8bit(crc,byte);
    }
    return crc;
  }


  std::ostream& operator<<(std::ostream& os, const FEDBufferFormat& value)
  {
    switch (value) {
    case BUFFER_FORMAT_OLD_VME:
      os << "Old VME";
      break;
    case BUFFER_FORMAT_OLD_SLINK:
      os << "Old S-Link";
      break;
    case BUFFER_FORMAT_NEW:
      os << "New";
      break;
    case BUFFER_FORMAT_INVALID:
      os << "Invalid";
      break;
    default:
      os << "Unrecognized";
      os << " (";
      printHexValue(value,os);
      os << ")";
      break;
    }
    return os;
  }

  std::ostream& operator<<(std::ostream& os, const FEDHeaderType& value)
  {
    switch (value) {
    case HEADER_TYPE_FULL_DEBUG:
      os << "Full debug";
      break;
    case HEADER_TYPE_APV_ERROR:
      os << "APV error";
      break;
    case HEADER_TYPE_INVALID:
      os << "Invalid";
      break;
    default:
      os << "Unrecognized";
      os << " (";
      printHexValue(value,os);
      os << ")";
      break;
    }
    return os;
  }

  std::ostream& operator<<(std::ostream& os, const FEDReadoutMode& value)
  {
    switch (value) {
    case READOUT_MODE_SCOPE:
      os << "Scope mode";
      break;
    case READOUT_MODE_VIRGIN_RAW:
      os << "Virgin raw";
      break;
    case READOUT_MODE_PROC_RAW:
      os << "Processed raw";
      break;
    case READOUT_MODE_ZERO_SUPPRESSED:
      os << "Zero suppressed";
      break;
    case READOUT_MODE_ZERO_SUPPRESSED_LITE:
      os << "Zero suppressed lite";
      break;
    case READOUT_MODE_INVALID:
      os << "Invalid";
      break;
    default:
      os << "Unrecognized";
      os << " (";
      printHexValue(value,os);
      os << ")";
      break;
    }
    return os;
  }

  std::ostream& operator<<(std::ostream& os, const FEDDataType& value)
  {
    switch (value) {
    case DATA_TYPE_REAL:
      os << "Real data";
      break;
    case DATA_TYPE_FAKE:
      os << "Fake data";
      break;
    default:
      os << "Unrecognized";
      os << " (";
      printHexValue(value,os);
      os << ")";
      break;
    }
    return os;
  }

  std::ostream& operator<<(std::ostream& os, const FEDDAQEventType& value)
  {
    switch (value) {
    case DAQ_EVENT_TYPE_PHYSICS:
      os << "Physics trigger";
      break;
    case DAQ_EVENT_TYPE_CALIBRATION:
      os << "Calibration trigger";
      break;
    case DAQ_EVENT_TYPE_TEST:
      os << "Test trigger";
      break;
    case DAQ_EVENT_TYPE_TECHNICAL:
      os << "Technical trigger";
      break;
    case DAQ_EVENT_TYPE_SIMULATED:
      os << "Simulated event";
      break;
    case DAQ_EVENT_TYPE_TRACED:
      os << "Traced event";
      break;
    case DAQ_EVENT_TYPE_ERROR:
      os << "Error";
      break;
    case DAQ_EVENT_TYPE_INVALID:
      os << "Unknown";
      break;
    default:
      os << "Unrecognized";
      os << " (";
      printHexValue(value,os);
      os << ")";
      break;
    }
    return os;
  }

  std::ostream& operator<<(std::ostream& os, const FEDTTSBits& value)
  {
    switch (value) {
    case TTS_DISCONNECTED0:
      os << "Disconected 0";
      break;
    case TTS_WARN_OVERFLOW:
      os << "Warning overflow";
      break;
    case TTS_OUT_OF_SYNC:
      os << "Out of sync";
      break;
    case TTS_BUSY:
      os << "Busy";
      break;
    case TTS_READY:
      os << "Ready";
      break;
    case TTS_ERROR:
      os << "Error";
      break;
    case TTS_INVALID:
      os << "Invalid";
      break;
    case TTS_DISCONNECTED1:
      os << "Disconected 1";
      break;
    default:
      os << "Unrecognized";
      os << " (";
      printHexValue(value,os);
      os << ")";
      break;
    }
    return os;
  }

  std::ostream& operator<<(std::ostream& os, const FEDBufferState& value)
  {
    switch (value) {
    case BUFFER_STATE_UNSET:
      os << "Unset";
      break;
    case BUFFER_STATE_EMPTY:
      os << "Empty";
      break;
    case BUFFER_STATE_PARTIAL_FULL:
      os << "Partial Full";
      break;
    case BUFFER_STATE_FULL:
      os << "Full";
      break;
    default:
      os << "Unrecognized";
      os << " (";
      printHexValue(value,os);
      os << ")";
      break;
    }
    return os;
  }

  std::ostream& operator<<(std::ostream& os, const FEDChannelStatus& value)
  {
    if (!(value&CHANNEL_STATUS_LOCKED)) os << "Unlocked ";
    if (!(value&CHANNEL_STATUS_IN_SYNC)) os << "Out-of-sync ";
    if (!(value&CHANNEL_STATUS_APV1_ADDRESS_GOOD)) os << "APV 1 bad address ";
    if (!(value&CHANNEL_STATUS_APV1_NO_ERROR_BIT)) os << "APV 1 error ";
    if (!(value&CHANNEL_STATUS_APV0_ADDRESS_GOOD)) os << "APV 0 bad address ";
    if (!(value&CHANNEL_STATUS_APV0_NO_ERROR_BIT)) os << "APV 0 error ";
    if (value == CHANNEL_STATUS_NO_PROBLEMS) os << "No errors";
    return os;
  }
  
  FEDBufferFormat fedBufferFormatFromString(const std::string& bufferFormatString)
  {
    if ( (bufferFormatString == "OLD_VME") ||
         (bufferFormatString == "BUFFER_FORMAT_OLD_VME") ||
         (bufferFormatString == "Old VME") ) {
      return BUFFER_FORMAT_OLD_VME;
    }
    if ( (bufferFormatString == "OLD_SLINK") ||
         (bufferFormatString == "BUFFER_FORMAT_OLD_SLINK") ||
         (bufferFormatString == "Old S-Link") ) {
      return BUFFER_FORMAT_OLD_SLINK;
    }
    if ( (bufferFormatString == "NEW") ||
         (bufferFormatString == "BUFFER_FORMAT_NEW") ||
         (bufferFormatString == "New") ) {
      return BUFFER_FORMAT_NEW;
    }
    //if it was none of the above then return invalid
    return BUFFER_FORMAT_INVALID;
  }
  
  FEDHeaderType fedHeaderTypeFromString(const std::string& headerTypeString)
  {
    if ( (headerTypeString == "FULL_DEBUG") ||
         (headerTypeString == "HEADER_TYPE_FULL_DEBUG") ||
         (headerTypeString == "Full debug") ) {
      return HEADER_TYPE_FULL_DEBUG;
    }
    if ( (headerTypeString == "APV_ERROR") ||
         (headerTypeString == "HEADER_TYPE_APV_ERROR") ||
         (headerTypeString == "APV error") ) {
      return HEADER_TYPE_APV_ERROR;
    }
    //if it was none of the above then return invalid
    return HEADER_TYPE_INVALID;
  }
  
  FEDReadoutMode fedReadoutModeFromString(const std::string& readoutModeString)
  {
    if ( (readoutModeString == "READOUT_MODE_SCOPE") ||
         (readoutModeString == "SCOPE") ||
         (readoutModeString == "SCOPE_MODE") ||
         (readoutModeString == "Scope mode") ) {
      return READOUT_MODE_SCOPE;
    }
    if ( (readoutModeString == "READOUT_MODE_VIRGIN_RAW") ||
         (readoutModeString == "VIRGIN_RAW") ||
         (readoutModeString == "Virgin raw") ) {
      return READOUT_MODE_VIRGIN_RAW;
    }
    if ( (readoutModeString == "READOUT_MODE_PROC_RAW") ||
         (readoutModeString == "PROC_RAW") ||
         (readoutModeString == "Processed raw") ) {
      return READOUT_MODE_PROC_RAW;
    }
    if ( (readoutModeString == "READOUT_MODE_ZERO_SUPPRESSED") ||
         (readoutModeString == "ZERO_SUPPRESSED") ||
         (readoutModeString == "Zero suppressed") ) {
      return READOUT_MODE_ZERO_SUPPRESSED;
    }
    if ( (readoutModeString == "READOUT_MODE_ZERO_SUPPRESSED_LITE") ||
         (readoutModeString == "ZERO_SUPPRESSED_LITE") ||
         (readoutModeString == "Zero suppressed lite") ) {
      return READOUT_MODE_ZERO_SUPPRESSED_LITE;
    }
    //if it was none of the above then return invalid
    return READOUT_MODE_INVALID;
  }
  
  FEDDataType fedDataTypeFromString(const std::string& dataTypeString)
  {
    if ( (dataTypeString == "REAL") ||
         (dataTypeString == "DATA_TYPE_REAL") ||
         (dataTypeString == "Real data") ) {
      return DATA_TYPE_REAL;
    }
    if ( (dataTypeString == "FAKE") ||
         (dataTypeString == "DATA_TYPE_FAKE") ||
         (dataTypeString == "Fake data") ) {
      return DATA_TYPE_FAKE;
    }
    //if it was none of the above then throw an exception (there is no invalid value for the data type since it is represented as a single bit in the buffer)
    std::ostringstream ss;
    ss << "Trying to convert to a FEDDataType from an invalid string: " << dataTypeString;
    throw cms::Exception("FEDDataType") << ss.str();
  }
  
  FEDDAQEventType fedDAQEventTypeFromString(const std::string& daqEventTypeString)
  {
    if ( (daqEventTypeString == "PHYSICS") ||
         (daqEventTypeString == "DAQ_EVENT_TYPE_PHYSICS") ||
         (daqEventTypeString == "Physics trigger") ) {
      return DAQ_EVENT_TYPE_PHYSICS;
    }
    if ( (daqEventTypeString == "CALIBRATION") ||
         (daqEventTypeString == "DAQ_EVENT_TYPE_CALIBRATION") ||
         (daqEventTypeString == "Calibration trigger") ) {
      return DAQ_EVENT_TYPE_CALIBRATION;
    }
    if ( (daqEventTypeString == "TEST") ||
         (daqEventTypeString == "DAQ_EVENT_TYPE_TEST") ||
         (daqEventTypeString == "Test trigger") ) {
      return DAQ_EVENT_TYPE_TEST;
    }
    if ( (daqEventTypeString == "TECHNICAL") ||
         (daqEventTypeString == "DAQ_EVENT_TYPE_TECHNICAL") ||
         (daqEventTypeString == "Technical trigger") ) {
      return DAQ_EVENT_TYPE_TECHNICAL;
    }
    if ( (daqEventTypeString == "SIMULATED") ||
         (daqEventTypeString == "DAQ_EVENT_TYPE_SIMULATED") ||
         (daqEventTypeString == "Simulated trigger") ) {
      return DAQ_EVENT_TYPE_SIMULATED;
    }
    if ( (daqEventTypeString == "TRACED") ||
         (daqEventTypeString == "DAQ_EVENT_TYPE_TRACED") ||
         (daqEventTypeString == "Traced event") ) {
      return DAQ_EVENT_TYPE_TRACED;
    }
    if ( (daqEventTypeString == "ERROR") ||
         (daqEventTypeString == "DAQ_EVENT_TYPE_ERROR") ||
         (daqEventTypeString == "Error") ) {
      return DAQ_EVENT_TYPE_ERROR;
    }
    //if it was none of the above then return invalid
    return DAQ_EVENT_TYPE_INVALID;
  }




  void FEDStatusRegister::printFlags(std::ostream& os) const
  {
    if (slinkFullFlag()) os << "SLINK_FULL ";
    if (trackerHeaderMonitorDataReadyFlag()) os << "HEADER_MONITOR_READY ";
    if (qdrMemoryFullFlag()) os << "QDR_FULL ";
    if (qdrMemoryPartialFullFlag()) os << "QDR_PARTIAL_FULL ";
    if (qdrMemoryEmptyFlag()) os << "QDR_EMPTY ";
    if (l1aBxFIFOFullFlag()) os << "L1A_FULL ";
    if (l1aBxFIFOPartialFullFlag()) os << "L1A_PARTIAL_FULL ";
    if (l1aBxFIFOEmptyFlag()) os << "L1A_EMPTY ";
    for (uint8_t iFE = 0; iFE < FEUNITS_PER_FED; iFE++) {
      if (feDataMissingFlag(iFE)) os << "FEUNIT" << uint16_t(iFE) << "MISSING ";
    }
  }
  
  FEDBufferState FEDStatusRegister::qdrMemoryState() const
  {
    uint8_t result(0x00);
    if (qdrMemoryFullFlag()) result |= BUFFER_STATE_FULL;
    if (qdrMemoryPartialFullFlag()) result |= BUFFER_STATE_PARTIAL_FULL;
    if (qdrMemoryEmptyFlag()) result |= BUFFER_STATE_EMPTY;
    return FEDBufferState(result);
  }
  
  FEDBufferState FEDStatusRegister::l1aBxFIFOState() const
  {
    uint8_t result(0x00);
    if (l1aBxFIFOFullFlag()) result |= BUFFER_STATE_FULL;
    if (l1aBxFIFOPartialFullFlag()) result |= BUFFER_STATE_PARTIAL_FULL;
    if (l1aBxFIFOEmptyFlag()) result |= BUFFER_STATE_EMPTY;
    return FEDBufferState(result);
  }
  
  void FEDStatusRegister::setBit(const uint8_t num, const bool bitSet)
  {
    const uint16_t mask = (0x0001 << num);
    if (bitSet) data_ |= mask;
    else data_ &= (~mask);
  }
  
  FEDStatusRegister& FEDStatusRegister::setQDRMemoryBufferState(const FEDBufferState state)
  {
    switch (state) {
    case BUFFER_STATE_FULL:
    case BUFFER_STATE_PARTIAL_FULL:
    case BUFFER_STATE_EMPTY:
    case BUFFER_STATE_UNSET:
      break;
    default:
      std::ostringstream ss;
      ss << "Invalid buffer state: ";
      printHex(&state,1,ss);
      throw cms::Exception("FEDBuffer") << ss.str();
    }
    setQDRMemoryFullFlag(state & BUFFER_STATE_FULL);
    setQDRMemoryPartialFullFlag(state & BUFFER_STATE_PARTIAL_FULL);
    setQDRMemoryEmptyFlag(state & BUFFER_STATE_EMPTY);
    return *this;
  }
  
  FEDStatusRegister& FEDStatusRegister::setL1ABXFIFOBufferState(const FEDBufferState state)
  {
    switch (state) {
    case BUFFER_STATE_FULL:
    case BUFFER_STATE_PARTIAL_FULL:
    case BUFFER_STATE_EMPTY:
    case BUFFER_STATE_UNSET:
      break;
    default:
      std::ostringstream ss;
      ss << "Invalid buffer state: ";
      printHex(&state,1,ss);
      throw cms::Exception("FEDBuffer") << ss.str();
    }
    setL1ABXFIFOFullFlag(state & BUFFER_STATE_FULL);
    setL1ABXFIFOPartialFullFlag(state & BUFFER_STATE_PARTIAL_FULL);
    setL1ABXFIFOEmptyFlag(state & BUFFER_STATE_EMPTY);
    return *this;
  }




  void FEDBackendStatusRegister::printFlags(std::ostream& os) const
  {
    if (internalFreezeFlag()) os << "INTERNAL_FREEZE ";
    if (slinkDownFlag()) os << "SLINK_DOWN ";
    if (slinkFullFlag()) os << "SLINK_FULL ";
    if (backpressureFlag()) os << "BACKPRESSURE ";
    if (ttcReadyFlag()) os << "TTC_READY ";
    if (trackerHeaderMonitorDataReadyFlag()) os << "HEADER_MONITOR_READY ";
    printFlagsForBuffer(qdrMemoryState(),"QDR",os);
    printFlagsForBuffer(frameAddressFIFOState(),"FRAME_ADDRESS",os);
    printFlagsForBuffer(totalLengthFIFOState(),"TOTAL_LENGTH",os);
    printFlagsForBuffer(trackerHeaderFIFOState(),"TRACKER_HEADER",os);
    printFlagsForBuffer(l1aBxFIFOState(),"L1ABX",os);
    printFlagsForBuffer(feEventLengthFIFOState(),"FE_LENGTH",os);
    printFlagsForBuffer(feFPGABufferState(),"FE",os);
  }
  
  void FEDBackendStatusRegister::printFlagsForBuffer(const FEDBufferState bufferState, const std::string name, std::ostream& os) const
  {
    if (bufferState&BUFFER_STATE_EMPTY) os << name << "_EMPTY ";
    if (bufferState&BUFFER_STATE_PARTIAL_FULL) os << name << "_PARTIAL_FULL ";
    if (bufferState&BUFFER_STATE_FULL) os << name << "_FULL ";
    if (bufferState == BUFFER_STATE_UNSET) os << name << "_UNSET ";
  }
  
  FEDBufferState FEDBackendStatusRegister::getBufferState(const uint8_t bufferPosition) const
  {
    uint8_t result = 0x00;
    if (getBit(bufferPosition+STATE_OFFSET_EMPTY)) result |= BUFFER_STATE_EMPTY;
    if (getBit(bufferPosition+STATE_OFFSET_PARTIAL_FULL)) result |= BUFFER_STATE_PARTIAL_FULL;
    if (getBit(bufferPosition+STATE_OFFSET_FULL)) result |= BUFFER_STATE_FULL;
    return FEDBufferState(result);
  }
  
  void FEDBackendStatusRegister::setBufferSate(const uint8_t bufferPosition, const FEDBufferState state)
  {
    switch (state) {
    case BUFFER_STATE_FULL:
    case BUFFER_STATE_PARTIAL_FULL:
    case BUFFER_STATE_EMPTY:
    case BUFFER_STATE_UNSET:
      break;
    default:
      std::ostringstream ss;
      ss << "Invalid buffer state: ";
      printHex(&state,1,ss);
      throw cms::Exception("FEDBuffer") << ss.str();
    }
    setBit(bufferPosition+STATE_OFFSET_EMPTY, state&BUFFER_STATE_EMPTY);
    setBit(bufferPosition+STATE_OFFSET_PARTIAL_FULL, state&BUFFER_STATE_PARTIAL_FULL);
    setBit(bufferPosition+STATE_OFFSET_FULL, state&BUFFER_STATE_FULL);
  }
  
  void FEDBackendStatusRegister::setBit(const uint8_t num, const bool bitSet)
  {
    const uint32_t mask = (0x00000001 << num);
    if (bitSet) data_ |= mask;
    else data_ &= (~mask);
  }
  
  FEDBackendStatusRegister::FEDBackendStatusRegister(const FEDBufferState qdrMemoryBufferState,
                                                     const FEDBufferState frameAddressFIFOBufferState,
                                                     const FEDBufferState totalLengthFIFOBufferState,
                                                     const FEDBufferState trackerHeaderFIFOBufferState,
                                                     const FEDBufferState l1aBxFIFOBufferState,
                                                     const FEDBufferState feEventLengthFIFOBufferState,
                                                     const FEDBufferState feFPGABufferState,
                                                     const bool backpressure, const bool slinkFull,
                                                     const bool slinkDown, const bool internalFreeze,
                                                     const bool trackerHeaderMonitorDataReady, const bool ttcReady)
    : data_(0)
  {
    setInternalFreezeFlag(internalFreeze);
    setSLinkDownFlag(slinkDown);
    setSLinkFullFlag(slinkFull);
    setBackpressureFlag(backpressure);
    setTTCReadyFlag(ttcReady);
    setTrackerHeaderMonitorDataReadyFlag(trackerHeaderMonitorDataReady);
    setQDRMemoryState(qdrMemoryBufferState);
    setFrameAddressFIFOState(frameAddressFIFOBufferState);
    setTotalLengthFIFOState(totalLengthFIFOBufferState);
    setTrackerHeaderFIFOState(trackerHeaderFIFOBufferState);
    setL1ABXFIFOState(l1aBxFIFOBufferState);
    setFEEventLengthFIFOState(feEventLengthFIFOBufferState);
    setFEFPGABufferState(feFPGABufferState);
  }




  TrackerSpecialHeader::TrackerSpecialHeader(const uint8_t* headerPointer)
  {
    //the buffer format byte is one of the valid values if we assume the buffer is not swapped
    const bool validFormatByteWhenNotWordSwapped = ( (headerPointer[BUFFERFORMAT] == BUFFER_FORMAT_CODE_NEW) ||
						     (headerPointer[BUFFERFORMAT] == BUFFER_FORMAT_CODE_OLD) );
    //the buffer format byte is the old value if we assume the buffer is swapped
    const bool validFormatByteWhenWordSwapped = (headerPointer[BUFFERFORMAT^4] == BUFFER_FORMAT_CODE_OLD);
    //if the buffer format byte is valid if the buffer is not swapped or it is never valid
    if (validFormatByteWhenNotWordSwapped || (!validFormatByteWhenNotWordSwapped && !validFormatByteWhenWordSwapped) ) {
      memcpy(specialHeader_,headerPointer,8);
      wordSwapped_ = false;
    } else {
      memcpy(specialHeader_,headerPointer+4,4);
      memcpy(specialHeader_+4,headerPointer,4);
      wordSwapped_ = true;
    }
  }

  FEDBufferFormat TrackerSpecialHeader::bufferFormat() const
  {
    if (bufferFormatByte() == BUFFER_FORMAT_CODE_NEW) return BUFFER_FORMAT_NEW;
    else if (bufferFormatByte() == BUFFER_FORMAT_CODE_OLD) {
      if (wordSwapped_) return BUFFER_FORMAT_OLD_VME;
      else return BUFFER_FORMAT_OLD_SLINK;
    }
    else return BUFFER_FORMAT_INVALID;
  }

  FEDHeaderType TrackerSpecialHeader::headerType() const
  {
    if ( (headerTypeNibble() == HEADER_TYPE_FULL_DEBUG) || 
	 (headerTypeNibble() == HEADER_TYPE_APV_ERROR) )
      return FEDHeaderType(headerTypeNibble());
    else return HEADER_TYPE_INVALID;
  }

  FEDReadoutMode TrackerSpecialHeader::readoutMode() const
  {
    const uint8_t eventTypeNibble = trackerEventTypeNibble();
    //if it is scope mode then return as is (it cannot be fake data)
    if (eventTypeNibble == READOUT_MODE_SCOPE) return FEDReadoutMode(eventTypeNibble);
    //if not then ignore the last bit which indicates if it is real or fake
    else {
      const uint8_t mode = (eventTypeNibble & 0xE);
      switch(mode) {
      case READOUT_MODE_VIRGIN_RAW:
      case READOUT_MODE_PROC_RAW:
      case READOUT_MODE_ZERO_SUPPRESSED:
      case READOUT_MODE_ZERO_SUPPRESSED_LITE:
	return FEDReadoutMode(mode);
      default:
	return READOUT_MODE_INVALID;
      }
    }   
  }

  FEDDataType TrackerSpecialHeader::dataType() const
  {
    const uint8_t eventTypeNibble = trackerEventTypeNibble();
    //if it is scope mode then it is always real
    if (eventTypeNibble == READOUT_MODE_SCOPE) return DATA_TYPE_REAL;
    //in other modes it is the lowest order bit of event type nibble
    else return FEDDataType(eventTypeNibble & 0x1);
  }
  
  TrackerSpecialHeader& TrackerSpecialHeader::setBufferFormat(const FEDBufferFormat newBufferFormat)
  {
    //check if order in buffer is different
    if ( ( (bufferFormat()==BUFFER_FORMAT_OLD_VME) && (newBufferFormat!=BUFFER_FORMAT_OLD_VME) ) ||
         ( (bufferFormat()!=BUFFER_FORMAT_OLD_VME) && (newBufferFormat==BUFFER_FORMAT_OLD_VME) ) ) {
      wordSwapped_ = !wordSwapped_;
    }
    //set appropriate code
    switch (newBufferFormat) {
    case BUFFER_FORMAT_OLD_VME:
    case BUFFER_FORMAT_OLD_SLINK:
      specialHeader_[BUFFERFORMAT] = BUFFER_FORMAT_CODE_OLD;
      break;
    case BUFFER_FORMAT_CODE_OLD:
      specialHeader_[BUFFERFORMAT] = BUFFER_FORMAT_CODE_NEW;
      break;
    default:
      std::ostringstream ss;
      ss << "Invalid buffer format: ";
      printHex(&newBufferFormat,1,ss);
      throw cms::Exception("FEDBuffer") << ss.str();
    }
    return *this;
  }
  
  TrackerSpecialHeader& TrackerSpecialHeader::setHeaderType(const FEDHeaderType headerType)
  {
    switch(headerType) {
    case HEADER_TYPE_FULL_DEBUG:
    case HEADER_TYPE_APV_ERROR:
      setHeaderTypeNibble(headerType);
      return *this;
    default:
      std::ostringstream ss;
      ss << "Invalid header type: ";
      printHex(&headerType,1,ss);
      throw cms::Exception("FEDBuffer") << ss.str();
    }
  }
  
  TrackerSpecialHeader& TrackerSpecialHeader::setReadoutMode(const FEDReadoutMode readoutMode)
  {
    switch(readoutMode) {
    case READOUT_MODE_SCOPE:
      //scope mode is always real
      setReadoutModeBits(readoutMode);
      setDataTypeBit(true);
    case READOUT_MODE_VIRGIN_RAW:
    case READOUT_MODE_PROC_RAW:
    case READOUT_MODE_ZERO_SUPPRESSED:
    case READOUT_MODE_ZERO_SUPPRESSED_LITE:
      setReadoutModeBits(readoutMode);
      break;
    default:
      std::ostringstream ss;
      ss << "Invalid readout mode: ";
      printHex(&readoutMode,1,ss);
      throw cms::Exception("FEDBuffer") << ss.str();
    }
    return *this;
  }
  
  TrackerSpecialHeader& TrackerSpecialHeader::setDataType(const FEDDataType dataType)
  {
    //if mode is scope then this bit can't be changed
    if (readoutMode() == READOUT_MODE_SCOPE) return *this;
    switch (dataType) {
    case DATA_TYPE_REAL:
    case DATA_TYPE_FAKE:
      setDataTypeBit(dataType);
      return *this;
    default:
      std::ostringstream ss;
      ss << "Invalid data type: ";
      printHex(&dataType,1,ss);
      throw cms::Exception("FEDBuffer") << ss.str();
    }
  }
  
  TrackerSpecialHeader& TrackerSpecialHeader::setAPVAddressErrorForFEUnit(const uint8_t internalFEUnitNum, const bool error)
  {
    const uint8_t mask = 0x1 << internalFEUnitNum;
    const uint8_t result = ( (apvAddressErrorRegister() & (~mask)) | (error?mask:0x00) );
    setAPVEAddressErrorRegister(result);
    return *this;
  }
  
  TrackerSpecialHeader& TrackerSpecialHeader::setFEEnableForFEUnit(const uint8_t internalFEUnitNum, const bool enabled)
  {
    const uint8_t mask = 0x1 << internalFEUnitNum;
    const uint8_t result = ( (feEnableRegister() & (~mask)) | (enabled?mask:0x00) );
    setFEEnableRegister(result);
    return *this;
  }
  
  TrackerSpecialHeader& TrackerSpecialHeader::setFEOverflowForFEUnit(const uint8_t internalFEUnitNum, const bool overflow)
  {
    const uint8_t mask = 0x1 << internalFEUnitNum;
    const uint8_t result = ( (feOverflowRegister() & (~mask)) | (overflow?mask:0x00) );
    setFEEnableRegister(result);
    return *this;
  }
  
  TrackerSpecialHeader::TrackerSpecialHeader(const FEDBufferFormat bufferFormat, const FEDReadoutMode readoutMode,
                                             const FEDHeaderType headerType, const FEDDataType dataType,
                                             const uint8_t address, const uint8_t addressErrorRegister,
                                             const uint8_t feEnableRegister, const uint8_t feOverflowRegister,
                                             const FEDStatusRegister fedStatusRegister)
  {
    //determine if order is swapped in real buffer
    wordSwapped_ = (bufferFormat == BUFFER_FORMAT_OLD_VME);
    //set fields
    setBufferFormat(bufferFormat);
    setReadoutMode(readoutMode);
    setHeaderType(headerType);
    setDataType(dataType);
    setAPVEAddress(address);
    setAPVEAddressErrorRegister(addressErrorRegister);
    setFEEnableRegister(feEnableRegister);
    setFEOverflowRegister(feOverflowRegister);
    setFEDStatusRegister(fedStatusRegister);
  }




  FEDDAQEventType FEDDAQHeader::eventType() const
  {
    switch(eventTypeNibble()) {
    case DAQ_EVENT_TYPE_PHYSICS:
    case DAQ_EVENT_TYPE_CALIBRATION:
    case DAQ_EVENT_TYPE_TEST:
    case DAQ_EVENT_TYPE_TECHNICAL:
    case DAQ_EVENT_TYPE_SIMULATED:
    case DAQ_EVENT_TYPE_TRACED:
    case DAQ_EVENT_TYPE_ERROR:
      return FEDDAQEventType(eventTypeNibble());
    default:
      return DAQ_EVENT_TYPE_INVALID;
    }
  }
  
  FEDDAQHeader& FEDDAQHeader::setEventType(const FEDDAQEventType evtType)
  {
    header_[7] = ((header_[7] & 0xF0) | evtType);
    return *this;
  }
  
  FEDDAQHeader& FEDDAQHeader::setL1ID(const uint32_t l1ID)
  {
    header_[4] = (l1ID & 0x000000FF);
    header_[5] = ( (l1ID & 0x0000FF00) >> 8);
    header_[6] = ( (l1ID & 0x00FF0000) >> 16);
    return *this;
  }
  
  FEDDAQHeader& FEDDAQHeader::setBXID(const uint16_t bxID)
  {
    header_[3] = ( (bxID & 0x0FF0) >> 4);
    header_[2] = ( (header_[2] & 0x0F) | ( (bxID & 0x000F) << 4) );
    return *this;
  }
  
  FEDDAQHeader& FEDDAQHeader::setSourceID(const uint16_t sourceID)
  {
    header_[2] = ( (header_[2] & 0xF0) | ( (sourceID & 0x0F00) >> 8) );
    header_[1] = (sourceID & 0x00FF);
    return *this;
  }
  
  FEDDAQHeader::FEDDAQHeader(const uint32_t l1ID, const uint16_t bxID, const uint16_t sourceID, const FEDDAQEventType evtType)
  {
    //clear everything (FOV,H,x,$ all set to 0)
    memset(header_,0x0,8);
    //set the BoE nibble to indicate this is the last fragment
    header_[7] = 0x50;
    //set variable fields vith values supplied
    setEventType(evtType);
    setL1ID(l1ID);
    setBXID(bxID);
    setSourceID(sourceID);
  }




  FEDTTSBits FEDDAQTrailer::ttsBits() const
  {
    switch(ttsNibble()) {
    case TTS_DISCONNECTED0:
    case TTS_WARN_OVERFLOW:
    case TTS_OUT_OF_SYNC:
    case TTS_BUSY:
    case TTS_READY:
    case TTS_ERROR:
    case TTS_DISCONNECTED1:
      return FEDTTSBits(ttsNibble());
    default:
      return TTS_INVALID;
    }
  }
  
  FEDDAQTrailer::FEDDAQTrailer(const uint32_t eventLengthIn64BitWords, const uint16_t crc, const FEDTTSBits ttsBits,
                               const bool slinkTransmissionError, const bool badFEDID, const bool slinkCRCError,
                               const uint8_t eventStatusNibble)
  {
    //clear everything (T,x,$ all set to 0)
    memset(trailer_,0x0,8);
    //set the EoE nibble to indicate this is the last fragment
    trailer_[7] = 0xA0;
    //set variable fields vith values supplied
    setEventLengthIn64BitWords(eventLengthIn64BitWords);
    setEventStatusNibble(eventStatusNibble);
    setTTSBits(ttsBits);
    setCRC(crc);
    setSLinkTransmissionErrorBit(slinkTransmissionError);
    setBadSourceIDBit(badFEDID);
    setSLinkCRCErrorBit(slinkCRCError);
  }
  
  FEDDAQTrailer& FEDDAQTrailer::setEventLengthIn64BitWords(const uint32_t eventLengthIn64BitWords)
  {
    trailer_[4] = (eventLengthIn64BitWords & 0x000000FF);
    trailer_[5] = ( (eventLengthIn64BitWords & 0x0000FF00) >> 8);
    trailer_[6] = ( (eventLengthIn64BitWords & 0x00FF0000) >> 16);
    return *this;
  }
  
  FEDDAQTrailer& FEDDAQTrailer::setCRC(const uint16_t crc)
  {
    trailer_[2] = (crc & 0x00FF);
    trailer_[3] = ( (crc & 0xFF00) << 8);
    return *this;
  }
  
  FEDDAQTrailer& FEDDAQTrailer::setSLinkTransmissionErrorBit(const bool bitSet)
  {
    if (bitSet) trailer_[1] |= 0x80;
    else trailer_[1] &= (~0x80);
    return *this;
  }
  
  FEDDAQTrailer& FEDDAQTrailer::setBadSourceIDBit(const bool bitSet)
  {
    if (bitSet) trailer_[1] |= 0x40;
    else trailer_[1] &= (~0x40);
    return *this;
  }
  
  FEDDAQTrailer& FEDDAQTrailer::setSLinkCRCErrorBit(const bool bitSet)
  {
    if (bitSet) trailer_[0] |= 0x04;
    else trailer_[0] &= (~0x40);
    return *this;
  }
  
  FEDDAQTrailer& FEDDAQTrailer::setEventStatusNibble(const uint8_t eventStatusNibble)
  {
    trailer_[1] = ( (trailer_[1] & 0xF0) | (eventStatusNibble & 0x0F) );
    return *this;
  }
  
  FEDDAQTrailer& FEDDAQTrailer::setTTSBits(const FEDTTSBits ttsBits)
  {
    trailer_[0] = ( (trailer_[0] & 0x0F) | (ttsBits & 0xF0) );
    return *this;
  }




  FEDAPVErrorHeader::~FEDAPVErrorHeader()
  {
  }

  size_t FEDAPVErrorHeader::lengthInBytes() const
  {
    return APV_ERROR_HEADER_SIZE_IN_BYTES;
  }

  void FEDAPVErrorHeader::print(std::ostream& os) const
  {
    printHex(header_,APV_ERROR_HEADER_SIZE_IN_BYTES,os);
  }
  
  FEDAPVErrorHeader* FEDAPVErrorHeader::clone() const
  {
    return new FEDAPVErrorHeader(*this);
  }

  bool FEDAPVErrorHeader::checkStatusBits(const uint8_t internalFEDChannelNum, const uint8_t apvNum) const
  {
    //3 bytes per FE unit, channel order is reversed in FE unit data, 2 bits per channel
    const uint16_t bitNumber = (internalFEDChannelNum/FEDCH_PER_FED)*24 + (FEDCH_PER_FED-1-(internalFEDChannelNum%FEDCH_PER_FED))*2+apvNum;
    //bit high means no error
    return (!(header_[bitNumber/8] & (0x01<<(bitNumber%8)) ));
  }

  bool FEDAPVErrorHeader::checkChannelStatusBits(const uint8_t internalFEDChannelNum) const
  {
    return (checkStatusBits(internalFEDChannelNum,0) && checkStatusBits(internalFEDChannelNum,1));
  }
  
  const uint8_t* FEDAPVErrorHeader::data() const
  {
    return header_;
  }
  
  FEDAPVErrorHeader::FEDAPVErrorHeader(const std::vector<bool> apvsGood)
  {
    memset(header_,0x00,APV_ERROR_HEADER_SIZE_IN_BYTES);
    for (uint8_t iCh = 0; iCh < FEDCH_PER_FED; iCh++) {
      setAPVStatusBit(iCh,0,apvsGood[iCh*2]);
      setAPVStatusBit(iCh,1,apvsGood[iCh*2+1]);
    }
  }
  
  FEDAPVErrorHeader& FEDAPVErrorHeader::setAPVStatusBit(const uint8_t internalFEDChannelNum, const uint8_t apvNum, const bool apvGood)
  {
    //3 bytes per FE unit, channel order is reversed in FE unit data, 2 bits per channel
    const uint16_t bitNumber = (internalFEDChannelNum/FEDCH_PER_FED)*24 + (FEDCH_PER_FED-1-(internalFEDChannelNum%FEDCH_PER_FED))*2+apvNum;
    const uint8_t byteNumber = bitNumber/8;
    const uint8_t bitInByte = bitNumber%8;
    const uint8_t mask = (0x01 << bitInByte);
    header_[byteNumber] = ( (header_[byteNumber] & (~mask)) | (apvGood?mask:0x00) );
    return *this;
  }
  
  void FEDAPVErrorHeader::setChannelStatus(const uint8_t internalFEDChannelNum, const FEDChannelStatus status)
  {
    //if channel is unlocked then set both APV bits bad
    if ( (!(status & CHANNEL_STATUS_LOCKED)) || (!(status & CHANNEL_STATUS_IN_SYNC)) ) {
      setAPVStatusBit(internalFEDChannelNum,0,false);
      setAPVStatusBit(internalFEDChannelNum,1,false);
      return;
    } else {
      if ( (status & CHANNEL_STATUS_APV0_ADDRESS_GOOD) && (status & CHANNEL_STATUS_APV0_NO_ERROR_BIT) ) {
        setAPVStatusBit(internalFEDChannelNum,0,true);
      } else {
        setAPVStatusBit(internalFEDChannelNum,0,false);
      }
      if ( (status & CHANNEL_STATUS_APV1_ADDRESS_GOOD) && (status & CHANNEL_STATUS_APV1_NO_ERROR_BIT) ) {
        setAPVStatusBit(internalFEDChannelNum,1,true);
      } else {
        setAPVStatusBit(internalFEDChannelNum,1,false);
      }
    }
  }
  
  //These methods do nothing as the values in question are in present in the APV Error header.
  //The methods exist so that users of the base class can set the values without caring which type of header they have and so if they are needed.
  void FEDAPVErrorHeader::setFEUnitMajorityAddress(const uint8_t internalFEUnitNum, const uint8_t address)
  {
    return;
  }
  void FEDAPVErrorHeader::setBEStatusRegister(const FEDBackendStatusRegister beStatusRegister)
  {
    return;
  }
  void FEDAPVErrorHeader::setFEUnitLength(const uint8_t internalFEUnitNum, const uint16_t length)
  {
    return;
  }
  
  
  FEDFullDebugHeader::~FEDFullDebugHeader()
  {
  }

  size_t FEDFullDebugHeader::lengthInBytes() const
  {
    return FULL_DEBUG_HEADER_SIZE_IN_BYTES;
  }

  void FEDFullDebugHeader::print(std::ostream& os) const
  {
    printHex(header_,FULL_DEBUG_HEADER_SIZE_IN_BYTES,os);
  }
  
  FEDFullDebugHeader* FEDFullDebugHeader::clone() const
  {
    return new FEDFullDebugHeader(*this);
  }
  
  bool FEDFullDebugHeader::checkStatusBits(const uint8_t internalFEDChannelNum, const uint8_t apvNum) const
  {
    return ( !unlockedFromBit(internalFEDChannelNum) &&
             !outOfSyncFromBit(internalFEDChannelNum) &&
             !apvError(internalFEDChannelNum,apvNum) &&
             !apvAddressError(internalFEDChannelNum,apvNum) );
  }

  bool FEDFullDebugHeader::checkChannelStatusBits(const uint8_t internalFEDChannelNum) const
  {
    //return ( !unlockedFromBit(internalFEDChannelNum) &&
    //         !outOfSyncFromBit(internalFEDChannelNum) &&
    //         !apvErrorFromBit(internalFEDChannelNum,0) &&
    //         !apvAddressErrorFromBit(internalFEDChannelNum,0) &&
    //         !apvErrorFromBit(internalFEDChannelNum,1) &&
    //         !apvAddressErrorFromBit(internalFEDChannelNum,1) );
    return (getChannelStatus(internalFEDChannelNum) == CHANNEL_STATUS_NO_PROBLEMS);
  }

  FEDChannelStatus FEDFullDebugHeader::getChannelStatus(const uint8_t internalFEDChannelNum) const
  {
    const uint8_t* pFEWord = feWord(internalFEDChannelNum/FEDCH_PER_FEUNIT);
    const uint8_t feUnitChanNum = internalFEDChannelNum % FEDCH_PER_FEUNIT;
    const uint8_t startByteInFEWord = (FEDCH_PER_FEUNIT-1 - feUnitChanNum) * 6 / 8;
    switch (feUnitChanNum % 4) {
    case 0:
      return FEDChannelStatus( pFEWord[startByteInFEWord] & 0x3F );
    case 1:
      return FEDChannelStatus( ((pFEWord[startByteInFEWord] & 0xC0) >> 6) | ((pFEWord[startByteInFEWord+1] & 0x0F) << 2) );
    case 2:
      return FEDChannelStatus( ((pFEWord[startByteInFEWord] & 0xF0) >> 4) | ((pFEWord[startByteInFEWord+1] & 0x03) << 4) );
    case 3:
      return FEDChannelStatus( (pFEWord[startByteInFEWord] & 0xFC) >> 2 );
    //stop compiler warning
    default:
      return FEDChannelStatus(0);
    }
    /*const uint8_t feUnitChanNum = internalFEDChannelNum / FEDCH_PER_FEUNIT;
    const uint8_t* pFEWord = feWord(feUnitChanNum);
    const uint8_t startByteInFEWord = feUnitChanNum * 3 / 4;
    //const uint8_t shift = ( 6 - ((feUnitChanNum-1)%4) );
    //const uint16_t mask = ( 0x003F << shift );
    //uint8_t result = ( (pFEWord[startByteInFEWord] & (mask&0x00FF)) >> shift );
    //result |= ( (pFEWord[startByteInFEWord+1] & (mask>>8)) << (8-shift) );
    switch (feUnitChanNum % 4) {
    case 0:
      return FEDChannelStatus( pFEWord[startByteInFEWord] & 0x3F );
    case 1:
      return FEDChannelStatus( ((pFEWord[startByteInFEWord] & 0xC0) >> 6) | ((pFEWord[startByteInFEWord+1] & 0x0F) << 2) );
    case 2:
      return FEDChannelStatus( ((pFEWord[startByteInFEWord] & 0xF0) >> 4) | ((pFEWord[startByteInFEWord+1] & 0x03) << 4) );
    case 3:
      return FEDChannelStatus( (pFEWord[startByteInFEWord] & 0xFC) >> 2 );
    //stop compiler warning
    default:
      return FEDChannelStatus(0);
    }*/
  }
  
  const uint8_t* FEDFullDebugHeader::data() const
  {
    return header_;
  }
  
  FEDFullDebugHeader::FEDFullDebugHeader(const std::vector<uint16_t> feUnitLengths, const std::vector<uint8_t> feMajorityAddresses,
                                         const std::vector<FEDChannelStatus> channelStatus, const FEDBackendStatusRegister beStatusRegister,
                                         const uint32_t daqRegister, const uint32_t daqRegister2)
  {
    memset(header_,0x00,FULL_DEBUG_HEADER_SIZE_IN_BYTES);
    setBEStatusRegister(beStatusRegister);
    setDAQRegister(daqRegister);
    setDAQRegister2(daqRegister2);
    for (uint8_t iFE = 0; iFE < FEUNITS_PER_FED; iFE++) {
      setFEUnitLength(iFE,feUnitLengths[iFE]);
      setFEUnitMajorityAddress(iFE,feMajorityAddresses[iFE]);
    }
    for (uint8_t iCh = 0; iCh < FEDCH_PER_FED; iCh++) {
      setChannelStatus(iCh,channelStatus[iCh]);
    }
  }
  
  void FEDFullDebugHeader::setChannelStatus(const uint8_t internalFEDChannelNum, const FEDChannelStatus status)
  {
    setUnlocked(internalFEDChannelNum, !(status&CHANNEL_STATUS_LOCKED) );
    setOutOfSync(internalFEDChannelNum, !(status&CHANNEL_STATUS_IN_SYNC) );
    setAPVAddressError(internalFEDChannelNum,1, !(status&CHANNEL_STATUS_APV1_ADDRESS_GOOD) );
    setAPVAddressError(internalFEDChannelNum,0, !(status&CHANNEL_STATUS_APV0_ADDRESS_GOOD) );
    setAPVError(internalFEDChannelNum,1, !(status&CHANNEL_STATUS_APV1_NO_ERROR_BIT) );
    setAPVError(internalFEDChannelNum,0, !(status&CHANNEL_STATUS_APV0_NO_ERROR_BIT) );
  }
  
  void FEDFullDebugHeader::setFEUnitMajorityAddress(const uint8_t internalFEUnitNum, const uint8_t address)
  {
    feWord(internalFEUnitNum)[9] = address;
  }
  
  void FEDFullDebugHeader::setBEStatusRegister(const FEDBackendStatusRegister beStatusRegister)
  {
    set32BitWordAt(feWord(0)+10,beStatusRegister);
  }
  
  void FEDFullDebugHeader::setDAQRegister(const uint32_t daqRegister)
  {
    set32BitWordAt(feWord(7)+10,daqRegister);
  }
  
  void FEDFullDebugHeader::setDAQRegister2(const uint32_t daqRegister2)
  {
    set32BitWordAt(feWord(6)+10,daqRegister2);
  }
  
  void FEDFullDebugHeader::setFEUnitLength(const uint8_t internalFEUnitNum, const uint16_t length)
  {
    feWord(internalFEUnitNum)[15] = ( (length & 0xFF00) >> 8);
    feWord(internalFEUnitNum)[14] = (length & 0x00FF);
  }
  
  void FEDFullDebugHeader::setBit(const uint8_t internalFEDChannelNum, const uint8_t bit, const bool value)
  {
    const uint8_t bitInFeWord = (FEDCH_PER_FEUNIT-1 - (internalFEDChannelNum%FEDCH_PER_FEUNIT)) * 6 + bit;
    uint8_t& byte = *(feWord(internalFEDChannelNum / FEDCH_PER_FEUNIT)+(bitInFeWord/8));
    const uint8_t mask = (0x1 << bitInFeWord%8);
    byte = ( (byte & (~mask)) | (value?mask:0x0) );
  }

  FEDFEHeader::~FEDFEHeader()
  {
  }
  
}
