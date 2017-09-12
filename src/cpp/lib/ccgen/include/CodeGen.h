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
class Function;
class Method;

// class representing a 'code-generator' 
class CodeGen{
public:
  // debug print operator
  friend std::ostream&operator<<(std::ostream&os,CodeGen const&cc);

  // ctors,assign,dtor
  CodeGen()=default;
  CodeGen(CodeGen const&)=delete;
  CodeGen(CodeGen&&)=delete;
  CodeGen&operator=(CodeGen const&)=delete;
  CodeGen&operator=(CodeGen&&)=delete;
  virtual~CodeGen()=default;

  // functional methods
  virtual void generate(std::shared_ptr<Type>type)=0;
  virtual void generate(std::shared_ptr<Attribute>attr)=0;
  virtual void generate(std::shared_ptr<Parameter>param)=0;
  virtual void generate(std::shared_ptr<Function>func)=0;
  virtual void generate(std::shared_ptr<Method>meth)=0;

  // getters
  std::ostream&os()noexcept;
protected:
  // debug print method executed in derived class
  virtual std::ostream&print(std::ostream&os)const;
};
}
