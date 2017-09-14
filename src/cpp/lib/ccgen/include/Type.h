#pragma once
#include <string>
#include <iosfwd>
namespace ccgen{

// class representing a 'type' for code generation
class Type{
public:
  // debug print operator
  friend std::ostream&operator<<(std::ostream&os,Type const&type);

  // type of reference
  enum class reftype_t:int{value=0,lvalref=1,rvalref=2};

  // ctors,assign,dtor
  Type(std::string const&name,reftype_t reftype,bool isconst);
  Type(std::string const&nspace,std::string const&name,reftype_t reftype,bool isconst);
  Type(Type const&)=default;
  Type(Type&&)=default;
  Type&operator=(Type const&)=default;
  Type&operator=(Type&&)=default;
  ~Type()=default;

  // getters
  bool hasnspace()const noexcept;
  std::string const&nspace()const noexcept;
  std::string const&name()const noexcept;
  reftype_t reftype()const noexcept;
  bool isconst()const noexcept;

  // convert reftype to a string
  static std::string const&reftype2string(reftype_t reftype);
private:
  bool hasnspace_;
  std::string const nspace_;
  std::string const name_;
  reftype_t const reftype_;
  bool const isconst_;
};
}
