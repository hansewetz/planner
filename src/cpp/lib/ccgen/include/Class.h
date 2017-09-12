#pragma once
#include <string>
#include <vector>
#include <map>
#include <memory>
#include <iosfwd>
namespace ccgen{

// forward decl
class Method;

// class representing a 'type' for code generation
class Class{
public:
  // debug print operator
  friend std::ostream&operator<<(std::ostream&os,Class const&type);

  // type of reference
  enum class visibility_t:int{vpublic=0,vprotected=1,vprivate=2};

  // ctors,assign,dtor
  Class(std::string const&name);
  Class(Class const&)=default;
  Class(Class&&)=default;
  Class&operator=(Class const&)=default;
  Class&operator=(Class&&)=default;
  ~Class()=default;

  // getters
  std::string const&name()const noexcept;
  std::vector<std::shared_ptr<Method>>const&methods(visibility_t vis)const;

  // add method
  void addMethod(std::shared_ptr<Method>meth,visibility_t vis);

  // convert a visibility value to a string
  static std::string const&visibility2string(visibility_t vis);
private:
  std::string const name_;
  std::map<visibility_t,std::vector<std::shared_ptr<Method>>>methods_;
};
}
