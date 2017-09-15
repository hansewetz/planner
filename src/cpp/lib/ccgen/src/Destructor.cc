#include "ccgen/Destructor.h"
#include <iostream>
using namespace std;
namespace ccgen{

// debug print operator
ostream&operator<<(ostream&os,Destructor const&d){
  os<<"isvirtual: "<<boolalpha<<d.isvirtual();
  return os;
}
// ctor
Destructor::Destructor(bool isvirtual,impl_t impl):
    isvirtual_(isvirtual),impl_(impl){
}
// getters
bool Destructor::isvirtual()const noexcept{return isvirtual_;}
Destructor::impl_t Destructor::impl()const noexcept{return impl_;}
}
