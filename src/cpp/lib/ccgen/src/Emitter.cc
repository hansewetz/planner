#include "ccgen/Emitter.h"
#include <iostream>
#include <ctype.h>
using namespace std;
namespace ccgen{

// debug print operator
ostream&operator<<(ostream&os,Emitter const&em){
  return os;
}
// ctor
Emitter::Emitter(ostream&os):os_(os),lastchar_('&'){
}
// getters
ostream&Emitter::os()noexcept{return os_;}
char Emitter::lastchar()const noexcept{return lastchar_;}

// check if  we can write any character after the last one
// (example: if last char is 'l' sbreak() returns false)
// (example: if last char is '&' sbreak() returns true)
bool Emitter::isbreak()const{
  if(isalnum(lastchar_))return false;
  return true;
}
// functional
ostream&Emitter::emit(std::string const&str){
  if(str.size()==0)return os_;
  if(!isbreak()&&isalnum(str[0]))os_<<" ";
  lastchar_=str[str.size()-1];
  return os_<<str;
}
}
