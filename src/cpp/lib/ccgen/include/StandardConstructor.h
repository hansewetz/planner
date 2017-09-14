#pragma once
#include <vector>
#include <iosfwd>
namespace ccgen{

// class representing a 'type' for code generation
class StandardConstructor{
public:
  // debug print operator
  friend std::ostream&operator<<(std::ostream&os,StandardConstructor const&ctor);

  // type of constructor 
  enum class type_t:int{def=0,copy=1,move=2};

  // type of constructor implementation
  enum class impl_t:int{impl=0,def=1,del=3};

  // ctors,assign,dtor
  StandardConstructor(type_t type,impl_t impl);
  StandardConstructor(StandardConstructor const&)=default;
  StandardConstructor(StandardConstructor&&)=default;
  StandardConstructor&operator=(StandardConstructor const&)=default;
  StandardConstructor&operator=(StandardConstructor&&)=default;
  ~StandardConstructor()=default;

  // getters
  type_t type()const noexcept;
  impl_t impl()const noexcept;

  // convert types to string
  static std::string const&impl2string(impl_t impl);
  static std::string const&type2string(type_t ctor);
private:
  type_t type_;
  impl_t impl_;
};
}
