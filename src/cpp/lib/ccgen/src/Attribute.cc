#include "ccgen/Attribute.h"
#include "ccgen/Type.h"
#include "utils/utility.h"
#include <boost/lexical_cast.hpp>
#include <boost/log/trivial.hpp>
#include <map>
#include <iostream>
using namespace std;
namespace ccgen{

// debug print operator
ostream&operator<<(ostream&os,Attribute const&attr){
  return os<<"name: "<<attr.name()<<", ismutable: "<<boolalpha<<attr.ismutable()<<", type: ["<<*attr.type()<<"]";
}
// ctor
Attribute::Attribute(string const&name,bool ismutable,shared_ptr<Type>type):
    name_(name),ismutable_(ismutable),type_(type){
}
// getters
string const&Attribute::name()const noexcept{return name_;}
bool Attribute::ismutable()const noexcept{return ismutable_;}
shared_ptr<Type>Attribute::type()const{return type_;}
}
