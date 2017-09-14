#pragma once
#include "ccgen/Function.h"
#include <memory>
#include <string>
#include <vector>
#include <iosfwd>
namespace ccgen{

// forward decl
class Type;
class Parameter;
class Function;

// class representing a 'type' for code generation
class Method:public Function{
public:
  // debug print operator
  friend std::ostream&operator<<(std::ostream&os,Method const&meth);

  // type of virtual
  enum class virtual_t:int{none=0,pure=1,override=2,plainvirt=3};

  // ctors,assign,dtor
  Method(std::string const&name,std::shared_ptr<Type>rettype,std::vector<std::shared_ptr<Parameter>>const&params,
         bool isconst,virtual_t vtype,bool isnoexcept);
  Method(Method const&)=default;
  Method(Method&&)=default;
  Method&operator=(Method const&)=default;
  Method&operator=(Method&&)=default;
  ~Method()=default;

  // getters
  bool isconst()const noexcept;
  virtual_t vtype()const;
  bool isnoexcept()const noexcept;

  // convert virtual_t to a string
  static std::string const&vtype2string(virtual_t vtype);
private:
  bool const isconst_;
  virtual_t vtype_;
  bool isnoexcept_;
};
}
