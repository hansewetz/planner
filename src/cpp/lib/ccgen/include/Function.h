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
class Function{
public:
  // debug print operator
  friend std::ostream&operator<<(std::ostream&os,Function const&func);

  // ctors,assign,dtor
  Function(std::string const&name,std::shared_ptr<Type>rettype,std::vector<std::shared_ptr<Parameter>>const&params);
  Function(Function const&)=default;
  Function(Function&&)=default;
  Function&operator=(Function const&)=default;
  Function&operator=(Function&&)=default;
  ~Function()=default;

  // getters
  std::string const&name()const noexcept;
  std::shared_ptr<Type>rettype()const;
  std::vector<std::shared_ptr<Parameter>>const&params()const noexcept;
private:
  std::string const name_;
  std::shared_ptr<Type>const rettype_;
  std::vector<std::shared_ptr<Parameter>>const params_;
};
}
