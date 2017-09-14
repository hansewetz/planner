#include "ccgen/Type.h"
#include "utils/utility.h"
#include <boost/lexical_cast.hpp>
#include <boost/log/trivial.hpp>
#include <map>
#include <iostream>
using namespace std;
namespace ccgen{

namespace{
// mapping from reftype --> name (string)
map<Type::reftype_t,string>const reftype2stringmap{
  {Type::reftype_t::value,"value"},
  {Type::reftype_t::lvalref,"lvalref"},
  {Type::reftype_t::rvalref,"rvalref"}
};
}
// debug print operator
ostream&operator<<(ostream&os,Type const&type){
  if(type.hasnspace())os<<"nspace: "<<type.nspace()<<", ";
  os<<"name: "<<type.name()<<", reftype: "<<
                  type.reftype2string(type.reftype())<<", isconst: "<<boolalpha<<type.isconst();
  return os;
}
// ctor
Type::Type(string const&name,reftype_t reftype,bool isconst):
    hasnspace_(false),nspace_(""),name_(name),reftype_(reftype),isconst_(isconst){
}
// ctor
Type::Type(string const&nspace,string const&name,reftype_t reftype,bool isconst):
    hasnspace_(true),nspace_(nspace),name_(name),reftype_(reftype),isconst_(isconst){
}
// getters
bool Type::hasnspace()const noexcept{return hasnspace_;}
string const&Type::nspace()const noexcept{return nspace_;}
string const&Type::name()const noexcept{return name_;}
Type::reftype_t Type::reftype()const noexcept{return reftype_;}
bool Type::isconst()const noexcept{return isconst_;}

// convert reftype to a string
string const&Type::reftype2string(reftype_t reftype){
  auto it=reftype2stringmap.find(reftype);
  if(it==end(reftype2stringmap)){
    string errstr="Type::reftype2string: internal application error, invalid reftype: "s+boost::lexical_cast<string>(static_cast<int>(reftype));
    BOOST_LOG_TRIVIAL(error)<<errstr;
    THROW_RUNTIME(errstr);
  }
  return it->second;
}
}
