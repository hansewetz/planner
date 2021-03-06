#include "ccgen/Method.h"
#include "ccgen/Type.h"
#include "ccgen/Parameter.h"
#include "general/utils/throw.h"
#include <boost/lexical_cast.hpp>
#include <boost/log/trivial.hpp>
#include <map>
#include <iostream>
using namespace std;
namespace ccgen{

namespace{
// mapping from virtual_t --> name (string)
map<Method::virtual_t,string>const virtual2stringmap{
  {Method::virtual_t::none,"none"},
  {Method::virtual_t::pure,"pure"},
  {Method::virtual_t::override,"override"},
  {Method::virtual_t::plainvirt,"plainvirt"}
};
}
// debug print operator
ostream&operator<<(ostream&os,Method const&m){
  os<<"name: "<<m.name()<<", rettype: ["<<*m.rettype()<<"], params: [";
  for(auto const&p:m.params())os<<"["<<*p<<"]";
  os<<"]";
  os<<", isconst: "<<boolalpha<<m.isconst()<<", ";
  os<<", vtype: "<<Method::vtype2string(m.vtype())<<", ";
  os<<", isnoexcept: "<<boolalpha<<m.isnoexcept();
  return os;
}
// ctor
Method::Method(string const&name,shared_ptr<Type>rettype,vector<shared_ptr<Parameter>>const&params,bool isconst,
               virtual_t vtype,bool isnoexcept):
    Function(name,rettype,params),isconst_(isconst),vtype_(vtype),isnoexcept_(isnoexcept){
}
// getters
bool Method::isconst()const noexcept{return isconst_;}
Method::virtual_t Method::vtype()const{return vtype_;}
bool Method::isnoexcept()const noexcept{return isnoexcept_;}

// convert virtual_t to a string
string const&Method::vtype2string(Method::virtual_t vtype){
  auto it=virtual2stringmap.find(vtype);
  if(it==end(virtual2stringmap)){
    string errstr="Method::virtual2stringmap: internal application error, invalid virtual_t: "s+boost::lexical_cast<string>(static_cast<int>(vtype));
    BOOST_LOG_TRIVIAL(error)<<errstr;
    THROW_RUNTIME(errstr);
  }
  return it->second;
}
}
