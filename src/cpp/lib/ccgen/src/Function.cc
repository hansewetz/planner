#include "ccgen/Function.h"
#include "ccgen/Type.h"
#include "ccgen/Parameter.h"
#include <boost/log/trivial.hpp>
#include <iostream>
using namespace std;
namespace ccgen{

// debug print operator
ostream&operator<<(ostream&os,Function const&m){
  os<<"name: "<<m.name()<<", rettype: ["<<*m.rettype()<<"], params: [";
  for(auto const&p:m.params())os<<"["<<*p<<"]";
  os<<"]";
  return os;
}
// ctor
Function::Function(string const&name,shared_ptr<Type>rettype,vector<shared_ptr<Parameter>>const&params):
    name_(name),rettype_(rettype),params_(params){
}
// getters
string const&Function::name()const noexcept{return name_;}
shared_ptr<Type>Function::rettype()const{return rettype_;}
vector<shared_ptr<Parameter>>const&Function::params()const noexcept{return params_;}
}
