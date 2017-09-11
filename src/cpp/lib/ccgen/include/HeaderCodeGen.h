#pragma once
#include "ccgen/CodeGen.h"
#include <string>
#include <iosfwd>
#include <memory>
namespace ccgen{

// forward decl
class Type;
class Attribute;
class Parameter;
class Method;

// class representing a 'code-generator' for header files
class HeaderCodeGen:public CodeGen{
public:
  // ctors,assign,dtor
  HeaderCodeGen()=default;
  HeaderCodeGen(HeaderCodeGen const&)=default;
  HeaderCodeGen(HeaderCodeGen&&)=default;
  HeaderCodeGen&operator=(HeaderCodeGen const&)=default;
  HeaderCodeGen&operator=(HeaderCodeGen&&)=default;
  virtual~HeaderCodeGen()=default;
protected:
  // debug print method executed in derived class
  virtual std::ostream&print(std::ostream&os)const override;
private:
  // generate code to an output stream
  virtual std::ostream&generate(std::ostream&os,std::shared_ptr<Type>type)override;
  virtual std::ostream&generate(std::ostream&os,std::shared_ptr<Attribute>attr)override;
  virtual std::ostream&generate(std::ostream&os,std::shared_ptr<Parameter>param)override;
  virtual std::ostream&generate(std::ostream&os,std::shared_ptr<Method>meth)override;
};
}
