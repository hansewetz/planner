#include "ccgen/HeaderCodeGen.h"
#include "ccgen/Type.h"
#include "ccgen/Attribute.h"
#include "ccgen/Parameter.h"
#include "ccgen/Function.h"
#include "ccgen/Method.h"
#include "ccgen/Class.h"
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
// ctor
HeaderCodeGen::HeaderCodeGen(ostream&os):em_(os){
}
// generate code for a type in header file
void HeaderCodeGen::generate(shared_ptr<Type>type){
  em_.emit(type->nspace());
  em_.emit("::");
  em_.emit(type->name());
  if(type->isconst())em_.emit("const");
  if(type->reftype()==Type::reftype_t::lvalref){
    em_.emit("&");
  }else
  if(type->reftype()==Type::reftype_t::rvalref){
    em_.emit("&&");
  }
}
// generate code for an attribute  in header file
void HeaderCodeGen::generate(shared_ptr<Attribute>attr){
  if(attr->ismutable())em_.emit("mutable");
  generate(attr->type());
  em_.emit(attr->name());
}
// generate code for a parameter  in header file
void HeaderCodeGen::generate(shared_ptr<Parameter>param){
  generate(param->type());
  em_.emit(param->name());
}
// generate code for a function in header file
void HeaderCodeGen::generate(shared_ptr<Function>func){
  generate(func->rettype());
  em_.emit(func->name());
  em_.emit("(");
  auto const&params=func->params();
  for(auto it=begin(params);it!=end(params);++it){
    generate(*it);
    if(next(it)!=end(params))em_.emit(",");
  }
  em_.emit(")");
}
// generate code for a method in header file
void HeaderCodeGen::generate(shared_ptr<Method>meth){
  // virtual/override
  if(meth->vtype()==Method::virtual_t::pure||
     meth->vtype()==Method::virtual_t::override||
     meth->vtype()==Method::virtual_t::plainvirt){
    em_.emit("virtual");
  }
  generate(static_pointer_cast<Function>(meth));

  // constness
  if(meth->isconst())em_.emit("const");

  // noexcept
  if(meth->isnoexcept())em_.emit("noexcept");

  // virtual/override
  if(meth->vtype()==Method::virtual_t::pure){
    em_.emit("=0");
  }else
  if(meth->vtype()==Method::virtual_t::override){
    em_.emit("override");
  }
  em_.emit(";");
}
// generate code for a class in header file
void HeaderCodeGen::generate(shared_ptr<Class>cl){
  em_.emit("class");
  em_.emit(cl->name());
  em_.emit("{");
  em_.nl();
  em_.incind();

  // emit methods
  auto const&publicMethods=cl->methods(Class::visibility_t::vpublic);
  if(publicMethods.size()){
    em_.emit("public:",true);
    em_.nl();
    for(auto const&meth:publicMethods){
      generate(meth);
      em_.nl();
    }
  }


/* NOTE!
  auto const&protectedMethods=c->methods(Class::visibility_t::vpublic);
  auto const&privateMethods=c->methods(Class::visibility_t::vpublic);
*/
  em_.decind();
  em_.emit("};");
}
}
