#include "ccgen/StandardConstructor.h"
#include "general/utils/throw.h"
#include <boost/lexical_cast.hpp>
#include <boost/log/trivial.hpp>
#include <map>
#include <iostream>
using namespace std;
namespace ccgen{

namespace{
// mapping from impl_t --> name (string)
map<StandardConstructor::impl_t,string>const impl2stringmap{
  {StandardConstructor::impl_t::impl,"impl"},
  {StandardConstructor::impl_t::def,"def"},
  {StandardConstructor::impl_t::del,"del"}
};
// mapping from type_t --> name (string)
map<StandardConstructor::type_t,string>const type2stringmap{
  {StandardConstructor::type_t::def,"def"},
  {StandardConstructor::type_t::copy,"copy"},
  {StandardConstructor::type_t::move,"move"}
};
}
// debug print operator
ostream&operator<<(ostream&os,StandardConstructor const&c){
  os<<"type: "<<StandardConstructor::type2string(c.type())<<", impl: "<<StandardConstructor::impl2string(c.impl());
  return os;
}
// ctor
StandardConstructor::StandardConstructor(type_t type,impl_t impl):
    type_(type),impl_(impl){
}
// getters
StandardConstructor::type_t StandardConstructor::type()const noexcept{return type_;}
StandardConstructor::impl_t StandardConstructor::impl()const noexcept{return impl_;}

// convert ctor type to string
string const&StandardConstructor::type2string(type_t type){
  auto it=type2stringmap.find(type);
  if(it==end(type2stringmap)){
    string errstr="StandardConstructor::impl2string: internal application error, invalid type: "s+boost::lexical_cast<string>(static_cast<int>(type));
    BOOST_LOG_TRIVIAL(error)<<errstr;
    THROW_RUNTIME(errstr);
  }
  return it->second;
}
// convert impl type to string
string const&StandardConstructor::impl2string(impl_t impl){
  auto it=impl2stringmap.find(impl);
  if(it==end(impl2stringmap)){
    string errstr="StandardConstructor::impl2string: internal application error, invalid impl: "s+boost::lexical_cast<string>(static_cast<int>(impl));
    BOOST_LOG_TRIVIAL(error)<<errstr;
    THROW_RUNTIME(errstr);
  }
  return it->second;
}
}
