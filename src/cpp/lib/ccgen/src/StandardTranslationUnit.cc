#include "ccgen/StandardTranslationUnit.h"
#include "ccgen/Class.h"
#include "ccgen/StandardConstructor.h"
#include "ccgen/StandardAssignOperator.h"
#include "ccgen/Destructor.h"
#include "ccgen/Headerfile.h"
#include "ccgen/Type.h"
#include "ccgen/Function.h"
#include "ccgen/Parameter.h"
#include <iostream>
using namespace std;
namespace ccgen{

// ctor
StandardTranslationUnit::StandardTranslationUnit(string const&classname):
    TranslationUnit(classname){
  addStandardFunctions(classname);
}
// ctor
StandardTranslationUnit::StandardTranslationUnit(string const&classname,string const&nspace):
    TranslationUnit(classname,nspace){
  addStandardFunctions(classname);
}
// helper function
void StandardTranslationUnit::addStandardFunctions(string const&classname){
  // add header file for iosfwd
  add(make_shared<Headerfile>("iosfwd",false));

  // create class
  auto cl=make_shared<Class>(classname);
  auto vpublic=Class::visibility_t::vpublic;

  // standard ctors
  cl->add(make_shared<StandardConstructor>(StandardConstructor::type_t::copy,StandardConstructor::impl_t::def),vpublic);
  cl->add(make_shared<StandardConstructor>(StandardConstructor::type_t::move,StandardConstructor::impl_t::def),vpublic);

  // standard assign
  cl->add(make_shared<StandardAssignOperator>(true,StandardAssignOperator::impl_t::def),vpublic);
  cl->add(make_shared<StandardAssignOperator>(false,StandardAssignOperator::impl_t::def),vpublic);

  // dtor
  cl->add(make_shared<Destructor>(false,Destructor::impl_t::def),vpublic);

  // add friend function operator<<(...)
  {
  auto rettype=make_shared<Type>("ostream",Type::reftype_t::lvalref,false);
  auto t1=make_shared<Type>("ostream",Type::reftype_t::lvalref,false);
  auto param1=make_shared<Parameter>("os",make_shared<Type>("ostream",Type::reftype_t::lvalref,false));
  auto param2=make_shared<Parameter>("classname",make_shared<Type>("type",Type::reftype_t::lvalref,true));
  auto fss=make_shared<Function>("operator<<",rettype,vector<shared_ptr<Parameter>>{param1,param2});
  cl->add(fss);
  }
  // add class
  add(cl);
}
}
