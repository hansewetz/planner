#include "ccgen/HeaderCodeGen.h"
#include "ccgen/Type.h"
#include "ccgen/Attribute.h"
#include "ccgen/Parameter.h"
#include "ccgen/Function.h"
#include "ccgen/Constructor.h"
#include "ccgen/Destructor.h"
#include "ccgen/Method.h"
#include "ccgen/Class.h"
#include "ccgen/StandardAssignOperator.h"
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
  if(type->hasnspace()){
    em_.emit(type->nspace());
    em_.emit("::");
  }
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
void HeaderCodeGen::generate(shared_ptr<Attribute>attr,string const&classname){
  if(attr->isstatic())em_.emit("static");
  if(attr->ismutable())em_.emit("mutable");
  generate(attr->type());
  em_.emit(attr->name());
  em_.emit(";");
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
  generateParamlist(func->params());
}
// generate code for a constructor in header file
void HeaderCodeGen::generate(shared_ptr<Constructor>ctor,string const&classname){
  em_.emit(classname);
  generateParamlist(ctor->params());
  em_.emit(";");
}
// generate code for a destructor in header file
void HeaderCodeGen::generate(shared_ptr<Destructor>dtor,string const&classname){
  if(dtor->isvirtual())em_.emit("virtual");
  em_.emit("~");
  em_.emit(classname);
  em_.emit("();");
}
// generate code for a assignment operator in header file
void HeaderCodeGen::generate(shared_ptr<StandardAssignOperator>a,string const&classname){
  em_.emit(classname);
  em_.emit("&operator=(");
  em_.emit(classname);
  if(a->iscopy())em_.emit("const&");
  else em_.emit("&&");
  em_.emit(")");
  if(a->impl()==StandardAssignOperator::impl_t::def){
    em_.emit("=default");
  }else
  if(a->impl()==StandardAssignOperator::impl_t::del){
    em_.emit("=delete");
  };
  em_.emit(";");
}
// generate code for a method in header file
void HeaderCodeGen::generate(shared_ptr<Method>meth,string const&classname){
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

  // public section
  em_.emit("public:",true);
  em_.nl();
  generateCtors(cl,Class::visibility_t::vpublic);
  generateStandardAssignops(cl,Class::visibility_t::vpublic);
  if(cl->dtor(Class::visibility_t::vpublic)){
    generate(cl->dtor(Class::visibility_t::vpublic),cl->name());
    em_.nl();
  }
  generateMethods(cl,Class::visibility_t::vpublic);
  generateAttributes(cl,Class::visibility_t::vpublic);
  
// NOTE! Not yet done

  em_.decind();
  em_.emit("};");
}
// generate ctors
void HeaderCodeGen::generateCtors(shared_ptr<Class>cl,Class::visibility_t vis){
  for(auto const&ctor:cl->ctors(vis)){
    generate(ctor,cl->name());
    em_.nl();
  }
}
// generate methods
void HeaderCodeGen::generateMethods(shared_ptr<Class>cl,Class::visibility_t vis){
  for(auto const&method:cl->methods(vis)){
    generate(method,cl->name());
    em_.nl();
  }
}
// generate attributes
void HeaderCodeGen::generateAttributes(shared_ptr<Class>cl,Class::visibility_t vis){
  for(auto const&attr:cl->attributes(vis)){
    generate(attr,cl->name());
    em_.nl();
  }
}
// generate assign operations
void HeaderCodeGen::generateStandardAssignops(shared_ptr<Class>cl,Class::visibility_t vis){
  for(auto const&assignop:cl->assignops(vis)){
    generate(assignop,cl->name());
    em_.nl();
  }
}
// genera a list of parameters
void HeaderCodeGen::generateParamlist(vector<shared_ptr<Parameter>>params){
  em_.emit("(");
  for(auto it=begin(params);it!=end(params);++it){
    generate(*it);
    if(next(it)!=end(params))em_.emit(",");
  }
  em_.emit(")");
}
}
