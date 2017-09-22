#ifndef __TYPE_UTILS_HH__
#define __TYPE_UTILS_HH__
#include <string>
#include <cxxabi.h>
namespace utils{

template<typename T>
string type2string(T t){
  int status;
  return std::string("(")+abi::__cxa_demangle(typeid(T).name(),0,0,&status)+")";
}
}
#endif
