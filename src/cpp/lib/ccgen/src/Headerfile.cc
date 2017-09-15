#include "ccgen/Headerfile.h"
#include <iostream>
using namespace std;
namespace ccgen{

// debug print operator
ostream&operator<<(ostream&os,Headerfile const&m){
  os<<"name: "<<m.name();
  return os;
}
// ctor
Headerfile::Headerfile(string const&name,bool local):
    name_(name),local_(local){
}
// getters
string const&Headerfile::name()const noexcept{return name_;}
bool Headerfile::islocal()const noexcept{return local_;}
}
