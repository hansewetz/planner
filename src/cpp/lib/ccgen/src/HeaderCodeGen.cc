#include "ccgen/HeaderCodeGen.h"
#include "ccgen/Type.h"
#include "ccgen/Attribute.h"
#include "ccgen/Parameter.h"
#include "ccgen/Function.h"
#include "ccgen/Constructor.h"
#include "ccgen/StandardConstructor.h"
#include "ccgen/Destructor.h"
#include "ccgen/Method.h"
#include "ccgen/Class.h"
#include "ccgen/TranslationUnit.h"
#include "ccgen/StandardAssignOperator.h"
#include "ccgen/Headerfile.h"
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
// generate code for a standard constructor in header file
void HeaderCodeGen::generate(shared_ptr<StandardConstructor>ctor,string const&classname){
  em_.emit(classname);
  em_.emit("(");
  if(ctor->type()==StandardConstructor::type_t::copy){
    em_.emit(classname);
    em_.emit("const&");
  }else{
    em_.emit(classname);
    em_.emit("&&");
  }
  em_.emit(")");
  if(ctor->impl()==StandardConstructor::impl_t::def){
    em_.emit("=default");
  }else
  if(ctor->impl()==StandardConstructor::impl_t::del){
    em_.emit("=delete");
  };
  em_.emit(";");
}
// generate code for a destructor in header file
void HeaderCodeGen::generate(shared_ptr<Destructor>dtor,string const&classname){
  if(dtor->isvirtual())em_.emit("virtual");
  em_.emit("~");
  em_.emit(classname);
  em_.emit("()");
  if(dtor->impl()==Destructor::impl_t::def){
    em_.emit("=default");
  }else
  if(dtor->impl()==Destructor::impl_t::del){
    em_.emit("=delete");
  }
  em_.emit(";");

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
  // start class
  em_.emit("class");
  em_.emit(cl->name());
  em_.emit("{");
  em_.nl();

  // generate friend functions
  for(auto const&ff:cl->friendfuncs()){
    em_.emit("friend");
    generate(ff);
    em_.emit(";");
    em_.nl();
  }
  // public/protected/private section
  em_.incind();
  generateClassVisibilitySection(cl,Class::visibility_t::vpublic);
  generateClassVisibilitySection(cl,Class::visibility_t::vprotected);
  generateClassVisibilitySection(cl,Class::visibility_t::vprivate);

  em_.decind();
  em_.emit("};");
}
// generate code for translation unit in header file
void HeaderCodeGen::generate(std::shared_ptr<TranslationUnit>tu){
  em_.indlevel(0);
  em_.emit("#pragma once");
  em_.nl();
  // headerfile(s)
  for(auto const&h:tu->headerfiles()){
    em_.emit("#include");
    if(h->islocal())em_.emit("\"");
    else em_.emit("<");
    em_.emit(h->name());
    if(h->islocal())em_.emit("\"");
    else em_.emit(">");
    em_.nl();
  }
  // namespace
  if(tu->hasnamespace()){
    em_.emit("namespace");
    em_.emit(tu->namespacestring());
    em_.emit("{");
    em_.nl();
    em_.nl();
  }
  // class(s)
  for(auto cl:tu->classes()){
    em_.emit("// "s+cl->name());
    em_.nl();
    generate(cl);
  }
  // end of namespace
  if(tu->hasnamespace()){
    em_.nl();
    em_.emit("}");  
  }
  // NOTE! Not yet done
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
// generate stndard ctors operations
void HeaderCodeGen::generateStdctors(shared_ptr<Class>cl,Class::visibility_t vis){
  for(auto const&stdctor:cl->stdctors(vis)){
    generate(stdctor,cl->name());
    em_.nl();
  }
}
// gc/protected/private section
void HeaderCodeGen::generateClassVisibilitySection(shared_ptr<Class>cl,Class::visibility_t vis){
  // check if we have anything to emit
  if(cl->ctors(vis).size()||cl->stdctors(vis).size()||cl->dtor(vis)||cl->methods(vis).size()||
     cl->attributes(vis).size()||cl->assignops(vis).size()){
    em_.emit(Class::visibility2string(vis),true);
    em_.emit(":",true);
    em_.nl();

    // generate rest of class
    generateCtors(cl,vis);
    generateStdctors(cl,vis);
    generateStandardAssignops(cl,vis);
    if(cl->dtor(vis)){
      generate(cl->dtor(vis),cl->name());
      em_.nl();
    }
    generateMethods(cl,vis);
    generateAttributes(cl,vis);
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
