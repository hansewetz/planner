#include "ccgen/StandardAssignOperator.h"
#include "general/utils/throw.h"
#include <boost/lexical_cast.hpp>
#include <boost/log/trivial.hpp>
#include <map>
#include <iostream>
using namespace std;
namespace ccgen{

namespace{
// mapping from impl_t --> name (string)
map<StandardAssignOperator::impl_t,string>const impl2stringmap{
  {StandardAssignOperator::impl_t::impl,"impl"},
  {StandardAssignOperator::impl_t::def,"def"},
  {StandardAssignOperator::impl_t::del,"del"}
};
}
// debug print operator
ostream&operator<<(ostream&os,StandardAssignOperator const&a){
  os<<"iscopy: "<<boolalpha<<a.iscopy()<<", impl: "<<StandardAssignOperator::impl2string(a.impl());
  return os;
}
// ctor
StandardAssignOperator::StandardAssignOperator(bool iscopy,impl_t impl):
    iscopy_(iscopy),impl_(impl){
}
// getters
bool StandardAssignOperator::iscopy()const noexcept{return iscopy_;}
StandardAssignOperator::impl_t StandardAssignOperator::impl()const noexcept{return impl_;}

// convert impl type to string
string const&StandardAssignOperator::impl2string(impl_t impl){
  auto it=impl2stringmap.find(impl);
  if(it==end(impl2stringmap)){
    string errstr="StandardAssignOperator::impl2string: internal application error, invalid impl: "s+boost::lexical_cast<string>(static_cast<int>(impl));
    BOOST_LOG_TRIVIAL(error)<<errstr;
    THROW_RUNTIME(errstr);
  }
  return it->second;
}
}
