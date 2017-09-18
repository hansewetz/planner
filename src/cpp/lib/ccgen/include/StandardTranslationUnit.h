#pragma once
#include "ccgen/TranslationUnit.h"
#include <string>
namespace ccgen{

// class representing a 'type' for code generation
class StandardTranslationUnit:public TranslationUnit{
public:
  // ctors,assign,dtor
  StandardTranslationUnit(std::string const&classname);
  StandardTranslationUnit(std::string const&classname,std::string const&nspace);
  StandardTranslationUnit(StandardTranslationUnit const&)=default;
  StandardTranslationUnit(StandardTranslationUnit&&)=default;
  StandardTranslationUnit&operator=(StandardTranslationUnit const&)=default;
  StandardTranslationUnit&operator=(StandardTranslationUnit&&)=default;
  ~StandardTranslationUnit()=default;
private:
  // helper functions
  void addStandardFunctions(std::string const&classname);
};
}
