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
class Method{
public:
  // debug print operator
  friend std::ostream&operator<<(std::ostream&os,Method const&meth);

  // ctors,assign,dtor
  Method(std::string const&name,std::shared_ptr<Type>rettype,std::vector<std::shared_ptr<Parameter>>const&params,bool isconst);
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
private:
  std::string const name_;
  std::shared_ptr<Type>const rettype_;
  std::vector<std::shared_ptr<Parameter>>params_;
  bool const isconst_;
};
}
