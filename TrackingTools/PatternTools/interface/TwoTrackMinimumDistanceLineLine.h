/* $Id: TwoTrackMinimumDistanceLineLine.h,v 1.2 2007/03/08 10:18:41 speer Exp $ */
#ifndef _Tracker_TwoTrackMinimumDistanceLineLine_H_
#define _Tracker_TwoTrackMinimumDistanceLineLine_H_

#include "DataFormats/GeometryVector/interface/GlobalPoint.h"
#include <string>
#include <sstream>
#include <utility>

using namespace std;

/** \class TwoTrackMinimumDistanceLineLine
 *  This is a helper class for TwoTrackMinimumDistance.
 *  No user should need direct access to this class.
 *  Exact solution.
 */

class GlobalTrajectoryParameters;

class TwoTrackMinimumDistanceLineLine {

public:
  /**
   * Calculates the point of closest approach on the two tracks.
   * \return false in case of success<br>
   * true in case of failure. Possible failures:<br>
   *   - Either of the Trajectories are charged
   *   - Either of the Trajectories is of zero momentum
   *   - Trajectories are parallel
   */

  bool calculate( const GlobalTrajectoryParameters &,
      const GlobalTrajectoryParameters &); // retval=true? error occured.

  pair <GlobalPoint, GlobalPoint> points() const;
  pair <double, double> pathLength() const;

  double firstAngle() const {return phiG;}
  double secondAngle() const {return phiH;}
private:
  double phiH, phiG;
  double pathG, pathH;
  GlobalPoint gPos, hPos;
};
#endif
