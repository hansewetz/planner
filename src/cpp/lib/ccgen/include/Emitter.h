#pragma once
#include <string>
#include <iosfwd>
namespace ccgen{

// class representing an object emitting code to an output stream
class Emitter{
public:
  // debug print operator
  friend std::ostream&operator<<(std::ostream&os,Emitter const&type);

  // some constants
  constexpr static int const DEFAULT_INDENTATION_LEVEL=2;

  // type of reference
  enum class reftype_t:int{value=0,lvalref=1,rvalref=2};

  // ctors,assign,dtor
  Emitter(std::ostream&os,int indstep=DEFAULT_INDENTATION_LEVEL);
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
  std::ostream&emit(std::string const&str,bool zeroindent=false);
  std::ostream&nl();
  void incind();
  void decind();
private:
  std::ostream&os_;
  int const indstep_;         // #of spaces for each indentation level
  char lastchar_;             // last char that was written
  bool indent_;               // should we indent - true if we just wrte a NL, false otherwise
  int indlevel_;              // current level of indentation
};
}
