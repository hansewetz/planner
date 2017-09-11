#pragma once
#include <memory>
#include <string>
#include <vector>
#include <iosfwd>
namespace ccgen{

// forward decl
class Type;
class Parameter;

// class representing a 'type' for code generation
// NOTE! Should derive froim function and just add const + virtual
class Method{
public:
  
  // debug print operator
  friend std::ostream&operator<<(std::ostream&os,Method const&meth);

  // type of virtual
  enum class virtual_t:int{none=0,pure=1,override=2,plainvirt=3};

  // ctors,assign,dtor
  Method(std::string const&name,std::shared_ptr<Type>rettype,std::vector<std::shared_ptr<Parameter>>const&params,bool isconst,virtual_t vtype);
  Method(Method const&)=default;
  Method(Method&&)=default;
  Method&operator=(Method const&)=default;
  Method&operator=(Method&&)=default;
  ~Method()=default;

  // getters
  std::string const&name()const noexcept;
  std::shared_ptr<Type>rettype()const;
  std::vector<std::shared_ptr<Parameter>>const&params()const noexcept;
  bool isconst()const noexcept;
  virtual_t vtype()const;

  // convert virtual_t to a string
  static std::string const&vtype2string(virtual_t vtype);
private:
  std::string const name_;
  std::shared_ptr<Type>const rettype_;
  std::vector<std::shared_ptr<Parameter>>params_;
  bool const isconst_;
  virtual_t vtype_;
};
}
