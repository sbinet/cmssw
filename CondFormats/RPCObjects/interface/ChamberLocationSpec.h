#ifndef CondFormatsRPCObjectsChamberLocationSpec_H
#define CondFormatsRPCObjectsChamberLocationSpec_H
#include<string>

/* \class ChamberLocationSpec
 * Chamber Location specification as in online DB
 */

class FebSpec;

struct ChamberLocationSpec {
  int diskOrWheel;
  int layer;
  int sector;
  std::string subsector;
  std::string chamberLocationName;
  std::string febZOrnt;
  std::string febZRadOrnt;
  std::string barrelOrEndcap; 

  /// debug printout
  void print( int depth = 0) const;
};
#endif
