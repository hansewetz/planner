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
Destructor::Destructor(bool isvirtual):isvirtual_(isvirtual){
}
// getters
bool Destructor::isvirtual()const noexcept{return isvirtual_;}
}
