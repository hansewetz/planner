#include "ccgen/HeaderCodeGen.h"
#include "ccgen/Type.h"
#include "ccgen/Attribute.h"
#include "ccgen/Parameter.h"
#include "ccgen/Method.h"
#include <boost/lexical_cast.hpp>
#include <boost/log/trivial.hpp>
#include <iostream>
using namespace std;
namespace ccgen{

// debug print method executed in derived class
ostream&HeaderCodeGen::print(ostream&os)const{
  this->CodeGen::print(os);
  return os;
}
// generate code for a type in header file
ostream&HeaderCodeGen::generate(ostream&os,shared_ptr<Type>type){
  os<<type->nspace()<<"::"<<type->name();
  if(type->isconst())os<<" const";
  if(type->reftype()==Type::reftype_t::value){
    os<<" ";
  }else
  if(type->reftype()==Type::reftype_t::lvalref){
    os<<"&";
  }else{
    os<<"&&";
  }
  return os;
}
// generate code for an attribute  in header file
std::ostream&HeaderCodeGen::generate(ostream&os,shared_ptr<Attribute>attr){
  if(attr->ismutable())os<<"mutable ";
  generate(os,attr->type());
  return os<<attr->name();
}
// generate code for a parameter  in header file
std::ostream&HeaderCodeGen::generate(ostream&os,shared_ptr<Parameter>param){
  return generate(os,param->type())<<param->name();
}
// generate code for a method in header file
std::ostream&HeaderCodeGen::generate(ostream&os,shared_ptr<Method>meth){
  generate(os,meth->rettype())<<meth->name()<<"(";
  auto const&params=meth->params();
  for(auto it=begin(params);it!=end(params);++it){
    generate(os,*it);
    if(next(it)!=end(params))os<<",";
  }
  os<<")";
  if(meth->isconst())os<<"const;";
  return os;
}
}
