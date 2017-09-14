#include "ccgen/Attribute.h"
#include "ccgen/Type.h"
#include <boost/lexical_cast.hpp>
#include <boost/log/trivial.hpp>
#include <iostream>
using namespace std;
namespace ccgen{

// debug print operator
ostream&operator<<(ostream&os,Attribute const&attr){
  return os<<"name: "<<attr.name()<<", ismutable: "<<boolalpha<<attr.ismutable()<<
             ", isstatic: "<<attr.isstatic()<<", type: ["<<*attr.type()<<"]";
}
// ctor
Attribute::Attribute(string const&name,bool ismutable,bool isstatic,shared_ptr<Type>type):
    name_(name),ismutable_(ismutable),isstatic_(isstatic),type_(type){
}
// getters
string const&Attribute::name()const noexcept{return name_;}
bool Attribute::ismutable()const noexcept{return ismutable_;}
bool Attribute::isstatic()const noexcept{return isstatic_;}
shared_ptr<Type>Attribute::type()const{return type_;}
}
