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
Emitter::Emitter(ostream&os,int indstep):
    os_(os),indstep_(indstep),lastchar_('&'),indent_(false),indlevel_(0){
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
ostream&Emitter::emit(std::string const&str,bool zeroindent){
  // check if we should indent
  if(!zeroindent&&indent_){
    string str(indstep_*indlevel_,' ');
    cout<<str;
    indent_=false;
  }
  // write code
  if(str.size()==0)return os_;
  if(!isbreak()&&isalnum(str[0]))os_<<" ";
  lastchar_=str[str.size()-1];
  return os_<<str;
}
// emit a new line
ostream&Emitter::nl(){
  indent_=true;
  return os_<<endl;
}
// increment ind level
void Emitter::incind(){
  ++indlevel_;
}
// decrement ind level
void Emitter::decind(){
  --indlevel_;
}
}
