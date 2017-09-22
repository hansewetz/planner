#include "ccgen/Constructor.h"
#include "ccgen/Parameter.h"
#include "utils/throw.h"
#include <boost/lexical_cast.hpp>
#include <boost/log/trivial.hpp>
#include <map>
#include <iostream>
using namespace std;
namespace ccgen{

// debug print operator
ostream&operator<<(ostream&os,Constructor const&m){
  os<<"params: [";
  for(auto const&p:m.params())os<<"["<<*p<<"]";
  os<<"]";
  return os;
}
// ctor
Constructor::Constructor(vector<shared_ptr<Parameter>>const&params):
    params_(params){
}
// getters
vector<shared_ptr<Parameter>>const&Constructor::params()const noexcept{return params_;}
}
