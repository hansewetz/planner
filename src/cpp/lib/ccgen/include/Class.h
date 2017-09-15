#pragma once
#include <string>
#include <vector>
#include <map>
#include <memory>
#include <iosfwd>
namespace ccgen{

// forward decl
class Constructor;
class StandardConstructor;
class Destructor;
class Destructor;
class Method;
class Attribute;
class StandardAssignOperator;
class Function;

// class representing a 'type' for code generation
class Class{
public:
  // debug print operator
  friend std::ostream&operator<<(std::ostream&os,Class const&type);

  // type of reference
  enum class visibility_t:int{vpublic=0,vprotected=1,vprivate=2};

// NOTE! Add type for ctor, bool for dtor and type for assign

  // ctors,assign,dtor
  Class(std::string const&name);
  Class(Class const&)=default;
  Class(Class&&)=default;
  Class&operator=(Class const&)=default;
  Class&operator=(Class&&)=default;
  ~Class()=default;

  // getters
  std::string const&name()const noexcept;
  std::vector<std::shared_ptr<Constructor>>const&ctors(visibility_t vis)const;
  std::vector<std::shared_ptr<StandardConstructor>>const&stdctors(visibility_t vis)const;
  std::shared_ptr<Destructor>dtor(visibility_t vis)const;
  std::vector<std::shared_ptr<Method>>const&methods(visibility_t vis)const;
  std::vector<std::shared_ptr<Attribute>>const&attributes(visibility_t vis)const;
  std::vector<std::shared_ptr<StandardAssignOperator>>const&assignops(visibility_t vis)const;
  std::vector<std::shared_ptr<Function>>const&friendfuncs()const noexcept;


  // modifyers
  void add(std::shared_ptr<Constructor>ctor,visibility_t vis);
  void add(std::shared_ptr<StandardConstructor>ctor,visibility_t vis);
  void add(std::shared_ptr<Destructor>dtor,visibility_t vis);
  void add(std::shared_ptr<Method>method,visibility_t vis);
  void add(std::shared_ptr<Attribute>method,visibility_t vis);
  void add(std::shared_ptr<StandardAssignOperator>assignop,visibility_t vis);
  void add(std::shared_ptr<Function>func);

  // convert a visibility value to a string
  static std::string const&visibility2string(visibility_t vis);
private:
  std::string const name_;
  std::map<visibility_t,std::vector<std::shared_ptr<Constructor>>>ctors_;
  std::map<visibility_t,std::vector<std::shared_ptr<StandardConstructor>>>stdctors_;
  std::pair<visibility_t,std::shared_ptr<Destructor>>dtor_;
  std::map<visibility_t,std::vector<std::shared_ptr<Method>>>methods_;
  std::map<visibility_t,std::vector<std::shared_ptr<Attribute>>>attributes_;
  std::map<visibility_t,std::vector<std::shared_ptr<StandardAssignOperator>>>assignops_;
  std::vector<std::shared_ptr<Function>>friendfuncs_;
};
}
