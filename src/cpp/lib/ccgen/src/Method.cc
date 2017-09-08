#include "ccgen/Method.h"
#include "ccgen/Type.h"
#include "ccgen/Parameter.h"
#include "utils/utility.h"
#include <boost/lexical_cast.hpp>
#include <boost/log/trivial.hpp>
#include <map>
#include <iostream>
using namespace std;
namespace ccgen{

// debug print operator
ostream&operator<<(ostream&os,Method const&m){
  os<<"name: "<<m.name()<<", rettype: ["<<*m.rettype()<<"], params: [";
  for(auto const&p:m.params())os<<"["<<*p<<"]";
  os<<"]";
  os<<", isconst: "<<boolalpha<<m.isconst();
  return os;
}
// ctor
Method::Method(string const&name,shared_ptr<Type>rettype,vector<shared_ptr<Parameter>>const&params,bool isconst):
    name_(name),rettype_(rettype),params_(params),isconst_(isconst){
}
// getters
string const&Method::name()const noexcept{return name_;}
shared_ptr<Type>Method::rettype()const{return rettype_;}
vector<shared_ptr<Parameter>>const&Method::params()const noexcept{return params_;}
bool Method::isconst()const noexcept{return isconst_;}
}
