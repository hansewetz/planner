#include "ccgen/Parameter.h"
#include "ccgen/Type.h"
#include <boost/lexical_cast.hpp>
#include <boost/log/trivial.hpp>
#include <iostream>
using namespace std;
namespace ccgen{

// debug print operator
ostream&operator<<(ostream&os,Parameter const&param){
  return os<<"name: "<<param.name()<<", type: ["<<*param.type()<<"]";
}
// ctor
Parameter::Parameter(string const&name,shared_ptr<Type>type):
    name_(name),type_(type){
}
// getters
string const&Parameter::name()const noexcept{return name_;}
shared_ptr<Type>Parameter::type()const{return type_;}
}
