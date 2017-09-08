#pragma once
#include <memory>
#include <string>
#include <iosfwd>
namespace ccgen{

// forward decl
class Type;

// class representing a 'type' for code generation
class Parameter{
public:
  // debug print operator
  friend std::ostream&operator<<(std::ostream&os,Parameter const&param);

  // ctors,assign,dtor
  Parameter(std::string const&name,std::shared_ptr<Type>type);
  Parameter(Parameter const&)=default;
  Parameter(Parameter&&)=default;
  Parameter&operator=(Parameter const&)=default;
  Parameter&operator=(Parameter&&)=default;
  ~Parameter()=default;

  // getters
  std::string const&name()const noexcept;
  std::shared_ptr<Type>type()const;
private:
  std::string const name_;
  std::shared_ptr<Type>type_;
};
}
