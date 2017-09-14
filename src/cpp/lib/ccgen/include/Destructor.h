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

  // ctors,assign,dtor
  Destructor(bool isvirtual);
  Destructor(Destructor const&)=default;
  Destructor(Destructor&&)=default;
  Destructor&operator=(Destructor const&)=default;
  Destructor&operator=(Destructor&&)=default;
  ~Destructor()=default;

  // getters
  bool isvirtual()const noexcept;
private:
  bool const isvirtual_;
};
}
