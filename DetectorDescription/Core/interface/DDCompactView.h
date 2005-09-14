#ifndef DDCompactView_h
#define DDCompactView_h

//

#include <vector>
//#include "DetectorDescription/Core/interface/tree.h"
#include "DetectorDescription/Core/interface/DDLogicalPart.h"
#include "DetectorDescription/Core/interface/DDPosPart.h"
//#include "DetectorDescription/Core/interface/DDPosData.h"
#include "DetectorDescription/Base/interface/Ptr.h"
#include "DetectorDescription/CoreImpl/src/DDCompactViewImpl.h"
//#include "DetectorDescription/Core/interface/DDPath.h"
#include "DetectorDescription/Core/interface/adjgraph.h" 
#include "DetectorDescription/Core/interface/graphwalker.h"


class DDPartSelector;
class DDPhysicalPart;
;

/**
  Navigation through the compact view of the detector ...
*/
//FIXME: DDCompactView: check for proper acyclic directed graph structure!!
//FIXME:
//FIXME:         X          [A-X] ... LogicalPart
//FIXME:        / \             | ... PosPart (directed parten to child)
//FIXME:       A   A
//FIXME:       |   | 
//FIXME:       B   C      
//FIXME:
//FIXME:    THIS IS NOT ALLOWED, but currently can be specified using DDL ....
//FIXME:

//typedef TreeNode<DDPhysicalPart,int> expnode_t;
//! type of data representation of DDCompactView
typedef graph<DDLogicalPart,DDPosData*> graph_type; //:typedef Graph<DDLogicalPart,DDPosData*> graph_type;

//! Compact representation of the geometrical detector hierarchy
/** A DDCompactView represents the detector as an acyclic directed multigraph.
    The nodes are instances of DDLogicalPart while the edges are pointers to
    DDPosData. Edges are directed from parent-node to child-node. 
    Edges represented by DDPosData are the relative translation and rotation
    accompanied by a copy-number of the child-node towards the parent-node.
    
    One node is explicitly marked as the root node. It is the DDLogicalPart which
    defines the base coordinate system for the detector. All subdetectors are
    directly or inderectly positioned inside the root-node. 
    
    Example:
    
    The figureshows a compact-view graph consisting of 16 DDLogicalParts 
    interconnected by 20 edges represented by pointers to DDPosData.
    \image html compact-view.gif
    \image latex compact-view.eps
    
    The compact-view also serves as base for calculating nodes in the expanded
    view. Paths through the compact-view can be viewed as nodes in the expanded-view
    (expansion of an acyclic directed multigraph into a tree). In the figure there are
    5 different paths from CMS to Module2 (e.g. CMS-Pos1->Ecal-Pos4->EEndcap-Pos21->Module2)
    thus there will be 5 nodes of Module2 in the expanded view.
*/
class DDCompactView
{
 
public:
  //! container-type of children of a given node in the compact-view
  typedef std::vector<DDLogicalPart> logchild_type;
  
  //! container-type of pairs of children nodes and their relative position data of a given node in the compact-view
  typedef std::vector< std::pair<DDLogicalPart,DDPosData*> > poschildren_type;
  
  //! pair ...
  typedef std::pair<DDLogicalPart,DDPosData*> pos_type;
  
  //! not used
  //:typedef GraphWalker<DDLogicalPart,DDPosData*> walker_type;
  typedef graphwalker<DDLogicalPart,DDPosData*> walker_type;
  
  //! not used
  //:typedef walker_type::value_type value_type;
  
  //! type of representation of the compact-view (acyclic directed multigraph)
  /** Nodes are instances of DDLogicalPart, edges are pointers to instances of DDPosData */
  typedef graph<DDLogicalPart,DDPosData*> graph_type;//:typedef Graph<DDLogicalPart,DDPosData*> graph_type;
 // typedef GraphWalker<DDLogicalPart,DDPosData*> walker_t;
    
  //! Creates a compact-view 
  explicit DDCompactView();
  
  //! \b EXPERIMENTAL! Creates a compact-view using a different root of the geometrical hierarchy
  explicit DDCompactView(const DDLogicalPart & rootnodedata);
  
  ~DDCompactView();
  
  //! Provides read-only access to the data structure of the compact-view.
  const graph_type & graph() const;

  //! returns the DDLogicalPart representing the root of the geometrical hierarchy
  const DDLogicalPart & root() const;

  //! for faster read-operations when using a graph-walker.
  void optimize();
  
  //! preliminary printing ...  
  void print(std::ostream & os) const;   
  
  //! Prototype version of calculating the weight of a detector component
  double weight(const DDLogicalPart & p) const;

  
  // ************************************************************************
  // UNSTABLE STUFF below! DON'T USE!
  // ************************************************************************
  
  //! Prototypish cleaning up, WILL CLEAN THE COMPLETE DDD TRANSIENT STORE
  void clear();
  
  /*      
  std::pair<bool,DDPhysicalPart> goTo(const DDPartSelector & path) const 
   { return rep_->goTo(path); }
  */

  //! \b don't \b use : interface not stable ....
  void global();
  
  //! \b don't \b use : interface not stable ....
  void setRoot(const DDLogicalPart & root);

  //! \b don't \b use ! 
  poschildren_type::size_type children(poschildren_type & result) const;
  
  //! \b don't \b use ! 
  logchild_type::size_type children(logchild_type & result) const;

  //! \b dont't \b use ! Proper implementation missing ...
  walker_type walker() const;

  /* Not Yet      
  bool firstChild(DDLogicalPart & result) // modifies current child
   { exit(1); return 0; 
     return rep_->firstChild(result); 
   } 
   
  bool nextChild(DDLogicalPart & result) // modifies current child
   { exit(1); return 0; 
     // return rep_->nextChild(result); 
   }
*/

  // ---------------------------------------------------------------
  // +++ DDCore INTERNAL USE ONLY ++++++++++++++++++++++++++++++++++
  
  // ctor only needed by DDPos 
  explicit DDCompactView(bool add);
  
  // to modify the structure! DDCore internal!
  graph_type & writeableGraph();
  
protected:
  Ptr<DDCompactViewImpl> rep_;
 // static DDCompactViewImpl*  global_; 

};

//! global type for a compact-view walker
typedef DDCompactView::walker_type walker_type;
#endif
