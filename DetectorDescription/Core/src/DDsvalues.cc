#include "DetectorDescription/Core/interface/DDsvalues.h"
#include "DetectorDescription/Core/interface/DDValue.h"

#include<iostream>
namespace {

  struct Counter {
    int empty;
    int begin;
    int end;
    int middle;
    int mixed;
    ~Counter() {
      std::cout << "Merging stats "
		<< empty << " " << begin << " " << end << " "
		<< middle << " " << mixed << std::endl;
    }

  };


}


void merge(DDsvalues_type & target, DDsvalues_type const & sv, bool sortit /* =true */) {
  static Counter counter = {0,0,0,0,0};
  if (target.empty()) {
    ++counter.empty;
    target = sv; 
    return;
  }
  DDsvalues_type::const_iterator sit = sv.begin();
  DDsvalues_type::const_iterator sed = sv.end();
  // fast merge
  if (target.back()<sv.front()) {
    ++counter.end;
    target.insert(target.end(),sit,sed);
    return;
  }
  if (sv.back()<target.front()) {
    ++counter.begin;
    target.insert(target.begin(),sit,sed);
    return;
  }
  {
    DDsvalues_type::iterator it = std::lower_bound(target.begin(),target.end(),sv.front()); 
    if (it == std::lower_bound(target.begin(),target.end(),sv.back())) {
      ++counter.middle; 
      target.insert(it,sit,sed);
      return;
    }
  }
  // it nevers arrives here...
  ++counter.mixed;
  target.reserve(target.size()+sv.size());
  DDsvalues_type::const_iterator ted = target.end();
  for (; sit != sed; ++sit) {
    DDsvalues_type::const_iterator it = find(target.begin(),ted, (*sit).first);
    if (it!=ted) const_cast<DDsvalues_Content_type&>(*it).second = (*sit).second;
    else target.push_back(*sit);
  }
  if (sortit) std::sort(target.begin(),target.end());
}


std::ostream & operator<<(std::ostream & os , const DDsvalues_type & s)
{
  DDsvalues_type::const_iterator it = s.begin();
  for(; it != s.end(); ++it)  {
    os << it->second; 
    /*
    os << DDValue(it->first).name() << " = ";
    for (unsigned int i=0; i<it->second.size(); ++i) {
       os << it->second[i] << ' ';
    }    
    os << std::endl;
    */
  }  
  return os;
}


std::ostream & operator<<(std::ostream & os , const std::vector<const DDsvalues_type*> & v)
{
   for (unsigned int i=0; i<v.size() ; ++i) {
     os << *(v[i]); // << std::endl;
   }
   
   return os;
}

/** Example:
   \code
   std::vector<std::string> myFunction(const DDsvalues_type * svalptr, const std::string & name) 
   {
      static std::vector<std::string> v; // empty std::vector, for zero result
      DDValue val(name);
      if (DDfetch(svalptr,val)) {
        return val.std::strings(); 
      } else {
       return v;
      } 	 
   }
   \endcode
*/
bool DDfetch(const DDsvalues_type * p, DDValue & v)
{
  bool result = false;
  DDsvalues_type::const_iterator it = find(*p, v);
  if (it != p->end()) {
    result = true;
    v = it->second;
  }
  return result;
}


unsigned int DDfetch(const std::vector<const DDsvalues_type *> & sp, DDValue & toFetch, std::vector<DDValue> & result)
{
   unsigned int count = 0;
   std::vector<const DDsvalues_type *>::const_iterator it(sp.begin()), ed(sp.end());
   for (; it != ed; ++it) {
     if (DDfetch(*it, toFetch)) {
       result.push_back(toFetch);
       ++count;
     }
   }    
   return count;
}

/*
DDValue DDsvalues_type::operator[](const unsigned int& i) const
{
    return DDValue(i);
}
*/
