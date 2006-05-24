#ifndef Common_ValueMap_h
#define Common_ValueMap_h
/** \class edm::ValueMap
 *
 * one-to-one reference to value associative map using EDM references
 * 
 * \author Luca Lista, INFN
 *
 * $Id: ValueMap.h,v 1.5 2006/05/23 11:01:07 llista Exp $
 *
 */
#include "DataFormats/Common/interface/RefProd.h"
#include "DataFormats/Common/interface/Ref.h"
#include "DataFormats/Common/interface/RefVector.h"
#include "DataFormats/Common/interface/KeyVal.h"
#include "FWCore/Utilities/interface/EDMException.h"
#include <map>
#include <vector>

namespace edm {

  template<typename CKey, typename Val, 
	   typename index = unsigned long>
  struct ValueMap {
    /// self type
    typedef ValueMap<CKey, Val, index> self;
    /// reference to "key" collection
    typedef edm::RefProd<CKey> KeyRefProd;
    /// reference to an object in "key" collection
    typedef edm::Ref<CKey> KeyRef;
    /// map type
    typedef typename std::map<index, Val> map_type;
    /// size type
    typedef typename map_type::size_type size_type;
    /// key/val pair
    typedef KeyVal<edm::Ref<CKey>, Val> KeyVal;
    /// value type
    typedef KeyVal value_type;
    /// transient map type
    typedef typename std::map<index, value_type> transient_map_type;

    /// default constructor
    ValueMap() { }
    /// constructor from product references
    ValueMap( const KeyRefProd & k ) :
      keyRef_( k ) {
    }
    /// map size
    size_type size() const { return map_.size(); }
    /// return true if empty
    bool empty() const { return map_.empty(); }
    /// insert an association
    void insert( const KeyRef & k, const Val & v ) {
      if ( k.isNull() )
	throw edm::Exception( edm::errors::InvalidReference )
	  << "can't insert null references in ValueMap";
      if ( keyRef_.isNull() ) {
	keyRef_ = KeyRefProd( k ); 
      }
      checkKey( k );
      index ik = index( k.index() );
      map_[ ik ] = v;
    }
    /// const iterator
    struct const_iterator {
      typedef KeyVal value_type;
      typedef ptrdiff_t difference_type;
      typedef KeyVal * pointer;
      typedef KeyVal & reference;
      typedef typename map_type::const_iterator::iterator_category iterator_category;
      const_iterator() { }
      const_iterator( const self * map, 
		      typename map_type::const_iterator mi ) : 
	map_( map ), i( mi ) { }
      const_iterator & operator=( const const_iterator & it ) { 
	map_ = it.map_; i = it.i;  return *this; 
      }
      const_iterator& operator++() { ++i; return *this; }
      const_iterator operator++( int ) { const_iterator ci = *this; ++i; return ci; }
      const_iterator& operator--() { --i; return *this; }
      const_iterator operator--( int ) { const_iterator ci = *this; --i; return ci; }
      bool operator==( const const_iterator& ci ) const { return i == ci.i; }
      bool operator!=( const const_iterator& ci ) const { return i != ci.i; }
      const KeyVal & operator *() const { return (*map_)[ i->first ]; }
      const KeyVal * operator->() const { return & operator *(); } 
    private:
      const self * map_;
      typename map_type::const_iterator i;
    };
    
    /// first iterator over the map (read only)
    const_iterator begin() const { return const_iterator( this, map_.begin() );  }
    /// last iterator over the map (read only)
    const_iterator end() const { return const_iterator( this, map_.end() );  }
    /// find an entry in the map
    const_iterator find( const KeyRef & k ) const {
      checkKey( k );
      typename map_type::const_iterator f = map_.find( k.index() );
      return const_iterator( this, f );
    }
    /// return element with key i
    const KeyVal & operator[]( size_type i ) const {
      typename transient_map_type::const_iterator tf = transientMap_.find( i );
      if ( f == transientMap_.end() ) {
	typename map_type::const_iterator f = map_.find( i );
	if ( f == map_.end() ) 
	  throw edm::Exception( edm::errors::InvalidReference )
	    << "can't find reference in AssociationMap at position " << i;
	std::pair<bool, typename transient_map_type::const_iterator> ins =
	  transientMap_.insert( make_pair( i, KeyVal( KeyRef( keyRef_, i ), f->second ) ) );
	return ins.second->second;
      } else {
	return tf->second; 
      }
    } 

  private:
    /// throw if k hasn't the same if as keyRef_
    void checkKey( const KeyRef & k ) const {
      if ( k.id() != keyRef_.id() )
	throw edm::Exception( edm::errors::InvalidReference, "invalid key reference" );
    }
    /// reference to "key" collection
    KeyRefProd keyRef_;
    /// index map
    map_type map_;
    /// transient reference map
    mutable transient_map_type transientMap_;
  };

  namespace refhelper {
    template<typename VM>
    struct FindInValueMap : 
      public std::binary_function< const VM&, typename VM::size_type, const typename VM::value_type *> {
      typedef FindInValueMap<VM> self;
      typename self::result_type operator()( typename self::first_argument_type iContainer,
					     typename self::second_argument_type iIndex ) {
	return & iContainer[ iIndex ];
      }
    };

    template<typename CKey, typename Val, typename index>
    struct FindTrait<ValueMap<CKey, Val, index>, 
		     typename ValueMap<CKey, Val, index>::value_type> {
      typedef FindInValueMap<ValueMap<CKey, Val, index> > value;
    };
  }
}

#endif
