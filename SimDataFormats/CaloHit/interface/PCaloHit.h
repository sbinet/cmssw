#ifndef _SimDataFormats_SimCaloHit_PCaloHit_h_
#define _SimDataFormats_SimCaloHit_PCaloHit_h_


/**

   \class PCaloHit

   Simple class to encapsulate a Geant hit for ORCA.
*/

class PCaloHit 
{ 
public: 

  /** 
      \fn PCaloHit(float e, float t, int i)

      \brief Default constructor, which
      takes myEnergy(e), time of the hit(t) and track number(i)
  */
  PCaloHit(float e = 0., float t = 0., int i = 0) : 
    myEnergy (e), myTime (t), myItra (i) { }

  PCaloHit(unsigned int id, float e = 0., float t = 0., int i = 0) : 
    myEnergy (e), myTime (t), myItra (i), myId(id) { }


  //Names
  static const char *name() { return "Hit"; }

  /** 
      \fn char *getName() const

      \brief Name of the hit (default "Hit") 
  */
  const char * getName() const { return name (); }

  //Energy deposit of the Hit
  double energy() const { return myEnergy; }

  //Time of the deposit
  double time() const { return myTime; }

  //G3 track number
  
  /** 
      \fn int g3itra() const

      \brief Geant 3 track number
  */
  int geantTrackId() const { return myItra; }


  unsigned int  id() const { return myId; }
  

  //Comaprisons

  /** 
      \fn bool operator<(const PCaloHit &) const

      \brief Askes, whether hit energy is smaller than the one provided.

      Useful for sorting in energy.
  */
  bool operator<(const PCaloHit &d) const 
  { return myEnergy < d.myEnergy; }
  
  //Same Hit (by value)
  /** 
      \fn bool operator==(const PCaloHit &) const
      
      \brief Compares by value on equality.

      
  */
  bool operator==(const PCaloHit &d) const 
  { return myEnergy == d.myEnergy && myId == d.myId; }
  


protected: 
  float myEnergy; 
  float myTime; 
  int myItra; 
  unsigned int myId; 
}; 

#include<iosfwd>
std::ostream &operator<<(std::ostream &, const PCaloHit &); 


#endif // _SimDataFormats_SimCaloHit_PCaloHit_h_
