#pragma once
#include <string>
#include <iosfwd>
#include <memory>
namespace ccgen{

// forward decl
class Type;
class Attribute;
class Parameter;
class Attribute;
class Method;

// class representing a 'code-generator' 
class CodeGen{
public:
  // debug print operator
  friend std::ostream&operator<<(std::ostream&os,CodeGen const&cc);

  // ctors,assign,dtor
  CodeGen()=default;
  CodeGen(CodeGen const&)=default;
  CodeGen(CodeGen&&)=default;
  CodeGen&operator=(CodeGen const&)=default;
  CodeGen&operator=(CodeGen&&)=default;
  virtual~CodeGen()=default;

  // functional methods
  virtual std::ostream&generate(std::ostream&os,std::shared_ptr<Type>type)=0;
  virtual std::ostream&generate(std::ostream&os,std::shared_ptr<Attribute>attr)=0;
  virtual std::ostream&generate(std::ostream&os,std::shared_ptr<Parameter>param)=0;
  virtual std::ostream&generate(std::ostream&os,std::shared_ptr<Method>meth)=0;
protected:
  // debug print method executed in derived class
  virtual std::ostream&print(std::ostream&os)const;
};
}
