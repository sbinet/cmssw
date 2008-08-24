// -*- C++ -*-
//
// Package:     Core
// Class  :     FWExpressionValidator
// 
// Implementation:
//     <Notes on implementation>
//
// Original Author:  Chris Jones
//         Created:  Fri Aug 22 20:42:51 EDT 2008
// $Id$
//

// system include files
#include <ctype.h>
#include <algorithm>
#include "Reflex/Type.h"
#include "Reflex/Member.h"

// user include files
#include "Fireworks/Core/src/FWExpressionValidator.h"


//
// constants, enums and typedefs
//
typedef std::vector<boost::shared_ptr<fireworks::OptionNode> > Options;

namespace fireworks {
   template< class T>
   struct OptionNodePtrCompare {
      bool operator()(const T& iLHS,
                      const T& iRHS) const
      {
         return *iLHS < *iRHS;
      }
   };
   
   class OptionNode {
   public:
      OptionNode(const ROOT::Reflex::Member& );
      OptionNode(const std::string& iDescription,
                 unsigned long iSubstitutionEnd,
                 const ROOT::Reflex::Type& iType);
      
      const std::string& description() const {
         return m_description;
      }
      unsigned long substitutionEnd() const {
         return m_endOfName;
      }
      const std::vector<boost::shared_ptr<OptionNode> >& options() const {
         if(m_hasSubOptions && m_subOptions.empty()) {
            fillOptionForType(m_type, m_subOptions);
         }
         return m_subOptions;
      }
      
      bool operator<(const OptionNode& iRHS) const {
         return m_description.substr(0,m_endOfName) < iRHS.m_description.substr(0,iRHS.m_endOfName);
      }
      
      static void fillOptionForType( const ROOT::Reflex::Type&,
                                    std::vector<boost::shared_ptr<OptionNode> >& );
   private:
      ROOT::Reflex::Type m_type;
      mutable std::string m_description;
      mutable std::string::size_type m_endOfName;
      mutable std::vector<boost::shared_ptr<OptionNode> > m_subOptions;
      bool m_hasSubOptions;
      static bool typeHasOptions(const ROOT::Reflex::Type& iType);
   };
   
   OptionNode::OptionNode(const std::string& iDescription,
                          unsigned long iSubstitutionEnd,
                          const ROOT::Reflex::Type& iType):
   m_type(iType),
   m_description(iDescription),
   m_endOfName(iSubstitutionEnd),
   m_hasSubOptions(typeHasOptions(iType) )
   {
   }
   
   OptionNode::OptionNode(const ROOT::Reflex::Member& ) {
   }

   
   void OptionNode::fillOptionForType( const ROOT::Reflex::Type& iType,
                                      std::vector<boost::shared_ptr<OptionNode> >& )
   {
   }
   
   bool OptionNode::typeHasOptions(const ROOT::Reflex::Type& iType) {
      return false;
   }

}

//
// static data member definitions
//

//
// constructors and destructor
//
#define FUN1(_fun_) \
m_builtins.push_back(boost::shared_ptr<OptionNode>( new OptionNode( #_fun_ "(float):float", strlen( #_fun_ )+1,s_float)))

#define FUN2(_fun_) \
m_builtins.push_back(boost::shared_ptr<OptionNode>( new OptionNode( #_fun_ "(float,float):float", strlen( #_fun_ )+1,s_float)))

FWExpressionValidator::FWExpressionValidator()
{
   using  fireworks::OptionNode;
   static const ROOT::Reflex::Type s_float(ROOT::Reflex::Type::ByTypeInfo(typeid(float)));
   FUN1(abs);
   FUN1(acos);
   FUN1(asin);
   FUN1(atan);
   FUN1(cos);
   FUN1(cosh);
   FUN1(exp);
   FUN1(log);
   FUN1(log10);
   FUN1(sin);
   FUN1(sinh);
   FUN1(sqrt);
   FUN1(tan);
   FUN1(tanh);
   FUN2(atan2);
   FUN2(chi2prob);
   FUN2(pow);
   FUN2(min);
   FUN2(max);
   std::sort(m_builtins.begin(),m_builtins.end(),
             fireworks::OptionNodePtrCompare<boost::shared_ptr<OptionNode> >());

}

// FWExpressionValidator::FWExpressionValidator(const FWExpressionValidator& rhs)
// {
//    // do actual copying here;
// }

FWExpressionValidator::~FWExpressionValidator()
{
}

//
// assignment operators
//
// const FWExpressionValidator& FWExpressionValidator::operator=(const FWExpressionValidator& rhs)
// {
//   //An exception safe implementation is
//   FWExpressionValidator temp(rhs);
//   swap(rhs);
//
//   return *this;
// }

//
// member functions
//
void 
FWExpressionValidator::setType(const ROOT::Reflex::Type& iType)
{
   using fireworks::OptionNode;
   m_type=iType;
   m_options.clear();
   m_options=m_builtins;
   OptionNode::fillOptionForType(iType, m_options);
}

//
// const member functions
//
namespace {
   void dummyDelete(void*) {}
   
   void findTypeDelimiters(const char*& ioBegin,
                           const char* iEnd,
                           std::vector<const char*>& oDelimeters)
   {
      oDelimeters.clear();
      if(ioBegin==iEnd) { return; }
      const char* it = iEnd-1;
      const char* itEnd = ioBegin-1;
      for(; it != itEnd; --it) {
         if(isalnum(*it)) { continue;}
         bool shouldStop=false;
         switch(*it) {
            case '_': break;
            case '.':
               oDelimeters.push_back(it);
               break;
            default:
               shouldStop=true;
         }
         if(shouldStop) { break;}
      }
      ioBegin = it+1;
      std::reverse(oDelimeters.begin(),oDelimeters.end());
   }
}

void 
FWExpressionValidator::fillOptions(const char* iBegin, const char* iEnd, 
                                   std::vector<std::pair<boost::shared_ptr<std::string>, std::string> >& oOptions) const
{
   using fireworks::OptionNode;
   oOptions.clear();
   std::vector<const char*> delimeters;
   findTypeDelimiters(iBegin, iEnd, delimeters);
   //must find correct OptionNode
   const Options* nodes = & m_options;
   const char* begin = iBegin;
   for(std::vector<const char*>::iterator it = delimeters.begin(), itEnd = delimeters.end();
       it != itEnd; ++it) {
      OptionNode temp(std::string(begin,*it),
                      *it-begin,
                      ROOT::Reflex::Type());
      
      boost::shared_ptr<OptionNode> comp(&temp, dummyDelete); 
      Options::const_iterator itFind =std::lower_bound(nodes->begin(),
                                                         nodes->end(),
                                                         comp,
                                                         fireworks::OptionNodePtrCompare<boost::shared_ptr<OptionNode> >());
      
      if(itFind == nodes->end() ||  *comp < *(*itFind) ) {
         //no match so we have an error
         return;
      }
      nodes = &((*itFind)->options());
      begin = (*it)+1;
   }
   
   //only use add items which begin with the part of the member we are trying to match
   std::string part(begin,iEnd);
   unsigned int part_size = part.size();
   for(Options::const_iterator it = nodes->begin(), itEnd = nodes->end();
       it != itEnd;
       ++it) {
      if(part == (*it)->description().substr(0,part_size) ) {
         oOptions.push_back(std::make_pair(boost::shared_ptr<std::string>(const_cast<std::string*>(&((*it)->description())), dummyDelete),
                                           (*it)->description().substr(part_size,(*it)->substitutionEnd()-part_size)));
      }
   }
}

//
// static member functions
//
