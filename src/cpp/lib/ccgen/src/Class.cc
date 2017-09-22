#include "ccgen/Class.h"
#include "ccgen/Method.h"
#include "ccgen/Attribute.h"
#include "ccgen/Function.h"
#include "utils/throw.h"
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
  os<<"name: "<<c.name();
  return os;
}
// ctor
Class::Class(string const&name):name_(name){
  // add slots to ctor map
  ctors_[visibility_t::vpublic];
  ctors_[visibility_t::vprotected];
  ctors_[visibility_t::vprivate];

  // add slots to standard ctor map
  stdctors_[visibility_t::vpublic];
  stdctors_[visibility_t::vprotected];
  stdctors_[visibility_t::vprivate];

  // add slots to methods map
  methods_[visibility_t::vpublic];
  methods_[visibility_t::vprotected];
  methods_[visibility_t::vprivate];

  // add slots to attribute map
  attributes_[visibility_t::vpublic];
  attributes_[visibility_t::vprotected];
  attributes_[visibility_t::vprivate];

  // add slots to assignops map
  assignops_[visibility_t::vpublic];
  assignops_[visibility_t::vprotected];
  assignops_[visibility_t::vprivate];

  // set dtor to null
  dtor_=make_pair(visibility_t::vpublic,nullptr);
}
// getters
string const&Class::name()const noexcept{return name_;}
vector<shared_ptr<Constructor>>const&Class::ctors(visibility_t vis)const{return ctors_.find(vis)->second;}
vector<shared_ptr<StandardConstructor>>const&Class::stdctors(visibility_t vis)const{return stdctors_.find(vis)->second;}
shared_ptr<Destructor>Class::dtor(visibility_t vis)const{if(vis==dtor_.first)return dtor_.second;else return nullptr;}
vector<shared_ptr<Method>>const&Class::methods(visibility_t vis)const{return methods_.find(vis)->second;}
vector<shared_ptr<Attribute>>const&Class::attributes(visibility_t vis)const{return attributes_.find(vis)->second;}
vector<shared_ptr<StandardAssignOperator>>const&Class::assignops(visibility_t vis)const{return assignops_.find(vis)->second;}
vector<shared_ptr<Function>>const&Class::friendfuncs()const noexcept{return friendfuncs_;}

// add ctor
void Class::add(shared_ptr<Constructor>ctor,visibility_t vis){
  ctors_[vis].push_back(ctor);
}
// add standard ctor
void Class::add(shared_ptr<StandardConstructor>ctor,visibility_t vis){
  stdctors_[vis].push_back(ctor);
}
// add dtor
void Class::add(shared_ptr<Destructor>dtor,visibility_t vis){
  dtor_=make_pair(vis,dtor);
}
// add method
void Class::add(shared_ptr<Method>method,visibility_t vis){
  methods_[vis].push_back(method);
}
// add attribute
void Class::add(shared_ptr<Attribute>attr,visibility_t vis){
  attributes_[vis].push_back(attr);
}
// add assign operator
void Class::add(shared_ptr<StandardAssignOperator>attr,visibility_t vis){
  assignops_[vis].push_back(attr);
}
// add friend function
void Class::add(shared_ptr<Function>func){
  friendfuncs_.push_back(func);
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
