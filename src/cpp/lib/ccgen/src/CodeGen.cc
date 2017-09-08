#include "ccgen/CodeGen.h"
#include <boost/lexical_cast.hpp>
#include <boost/log/trivial.hpp>
#include <iostream>
using namespace std;
namespace fs=boost::filesystem;
namespace ccgen{

// debug print operator
ostream&operator<<(ostream&os,CodeGen const&cc){
  return os<<"dir: "<<cc.dir().string();
}
// ctor
CodeGen::CodeGen(fs::path const&dir):dir_(dir){
}
// getters
fs::path const&CodeGen::dir()const noexcept{return dir_;}
}
