#include "ccgen/Class.h"
#include "ccgen/Method.h"
#include "utils/utility.h"
#include <boost/lexical_cast.hpp>
#include <boost/log/trivial.hpp>
#include <iostream>
using namespace std;
namespace ccgen{

namespace{
// mapping from visibility-type --> name (string)
map<Class::visibility_t,string>const visibility2stringmap{
  {Class::visibility_t::vpublic,"public"},
  {Class::visibility_t::vprotected,"protected"},
  {Class::visibility_t::vprivate,"private"}
};
}
// debug print operator
ostream&operator<<(ostream&os,Class const&c){
  os<<"name: "<<c.name()<<", methods[";
  for(auto p:visibility2stringmap){
    auto vis=p.first;
    os<<p.second<<": {";
    for(auto const&meth:c.methods(vis)){
      os<<"["<<*meth<<"]";
    }
    os<<"}";
  }
  return os;
}
// ctor
Class::Class(string const&name):name_(name){
  methods_[visibility_t::vpublic];
  methods_[visibility_t::vprotected];
  methods_[visibility_t::vprivate];
}
// getters
string const&Class::name()const noexcept{return name_;}
vector<shared_ptr<Method>>const&Class::methods(visibility_t vis)const{return methods_.find(vis)->second;}

// add method
void Class::addMethod(shared_ptr<Method>meth,visibility_t vis){
  methods_[vis].push_back(meth);
}
// convert reftype to a string
string const&Class::visibility2string(visibility_t vis){
  auto it=visibility2stringmap.find(vis);
  if(it==end(visibility2stringmap)){
    string errstr="Class::visibility2string: internal application error, invalid visibility type: "s+boost::lexical_cast<string>(static_cast<int>(vis));
    BOOST_LOG_TRIVIAL(error)<<errstr;
    THROW_RUNTIME(errstr);
  }
  return it->second;
}
}
