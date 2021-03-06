// Author : Samvel Khalatian (samvel at fnal dot gov)
// Created: 07/15/07
// License: GPL

#include <istream>
#include <ostream>

#include <boost/archive/binary_iarchive.hpp>
#include <boost/archive/binary_oarchive.hpp>

#include <boost/archive/text_iarchive.hpp>
#include <boost/archive/text_oarchive.hpp>

#include "CalibTracker/SiStripRunSummary/interface/RegisterFlagTxt.h"

#include "CalibTracker/SiStripRunSummary/interface/SerializeTxt.h"

// --[ TEXT ARCHIVE MANAGER ]--------------------------------------------------
//                                                  --[ PUBLIC ]--

//                                                  --[ PRIVATE ]--
void SerializeTxt::writeFlag( std::ostream  &roOut, 
                              const FlagTxt &roFLAGTXT) const
{
  boost::archive::text_oarchive oAOut( roOut);

  oAOut << roFLAGTXT;
}

void SerializeTxt::readFlag( FlagTxt *poFlagTxt, std::istream &roIn) {
  boost::archive::text_iarchive oAIn( roIn);

  oAIn >> ( *poFlagTxt);
}

// --[ BINARY ARCHIVE MANAGER ]------------------------------------------------
//                                                  --[ PUBLIC ]--

//                                                  --[ PRIVATE ]--
void SerializeBin::writeFlag( std::ostream  &roOut, 
                              const FlagTxt &roFLAGTXT) const
{
  boost::archive::binary_oarchive oAOut( roOut);

  oAOut << roFLAGTXT;
}

void SerializeBin::readFlag( FlagTxt *poFlagTxt, std::istream &roIn) {
  boost::archive::binary_iarchive oAIn( roIn);

  oAIn >> ( *poFlagTxt);
}
