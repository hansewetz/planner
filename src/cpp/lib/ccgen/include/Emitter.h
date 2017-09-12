#pragma once
#include <string>
#include <iosfwd>
namespace ccgen{

// class representing an object emitting code to an output stream
class Emitter{
public:
  // debug print operator
  friend std::ostream&operator<<(std::ostream&os,Emitter const&type);

  // type of reference
  enum class reftype_t:int{value=0,lvalref=1,rvalref=2};

  // ctors,assign,dtor
  Emitter(std::ostream&os);
  Emitter(Emitter const&)=delete;
  Emitter(Emitter&&)=delete;
  Emitter&operator=(Emitter const&)=delete;
  Emitter&operator=(Emitter&&)=delete;
  ~Emitter()=default;

  // getters
  std::ostream&os()noexcept;
  char lastchar()const noexcept;
  bool isbreak()const;

  // functional
  std::ostream&emit(std::string const&str);
private:
  std::ostream&os_;
  char lastchar_;
};
}
