#include "FastSimulation/Event/interface/FBaseSimEvent.h"
#include "FastSimulation/Event/interface/FSimTrack.h"
#include "FastSimulation/Event/interface/FSimVertex.h"

  /// Default constructor
FSimVertex::FSimVertex() : SimVertex(), mom_(0), id_(-1) {;}
  
  /// constructor from the embedded vertex index in the FBaseSimEvent
FSimVertex::FSimVertex(const HepLorentzVector& v, int im, int id, FBaseSimEvent* mom) : 
    SimVertex(v.vect(),v.e(),im), mom_(mom), id_(id) {;}

std::ostream& operator <<(std::ostream& o , const FSimVertex& t) {
  return o << t;
}
