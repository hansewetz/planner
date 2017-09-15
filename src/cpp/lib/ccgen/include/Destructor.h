#pragma once
#include <iosfwd>
namespace ccgen{

// forward decl
class Parameter;

// class representing a 'type' for code generation
class Destructor{
public:
  // debug print operator
  friend std::ostream&operator<<(std::ostream&os,Destructor const&ctor);

  // type of constructor implementation
  enum class impl_t:int{impl=0,def=1,del=3};

  // ctors,assign,dtor
  Destructor(bool isvirtual,impl_t impl);
  Destructor(Destructor const&)=default;
  Destructor(Destructor&&)=default;
  Destructor&operator=(Destructor const&)=default;
  Destructor&operator=(Destructor&&)=default;
  ~Destructor()=default;

  // getters
  bool isvirtual()const noexcept;
  impl_t impl()const noexcept;
private:
  bool const isvirtual_;
  impl_t impl_;
};
}
