#pragma once
#include <memory>
#include <string>
#include <iosfwd>
namespace ccgen{

// forward decl
class Type;

// class representing a 'type' for code generation
class Attribute{
public:
  // debug print operator
  friend std::ostream&operator<<(std::ostream&os,Attribute const&attr);

  // ctors,assign,dtor
  Attribute(std::string const&name,bool ismutable,std::shared_ptr<Type>type);
  Attribute(Attribute const&)=default;
  Attribute(Attribute&&)=default;
  Attribute&operator=(Attribute const&)=default;
  Attribute&operator=(Attribute&&)=default;
  ~Attribute()=default;

  // getters
  std::string const&name()const noexcept;
  std::shared_ptr<Type>type()const;
  bool ismutable()const noexcept;
private:
  	std::string const name_;
  	bool ismutable_;
    std::shared_ptr<Type>type_;
};
}
