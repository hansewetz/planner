#include "ccgen/CodeGen.h"
#include <boost/lexical_cast.hpp>
#include <boost/log/trivial.hpp>
#include <iostream>
using namespace std;
namespace ccgen{

// debug print operator
ostream&operator<<(ostream&os,CodeGen const&cc){
  return cc.print(os);
}
// debug print method executed in derived class
ostream&CodeGen::print(ostream&os)const{
  return os;
}
}
