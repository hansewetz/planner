#pragma once
#include "ccgen/CodeGen.h"
#include "ccgen/Emitter.h"
#include "ccgen/Class.h"
#include <string>
#include <iosfwd>
#include <memory>
#include <vector>
namespace ccgen{

// class representing a 'code-generator' for header files
class HeaderCodeGen:public CodeGen{
public:
  // ctors,assign,dtor
  HeaderCodeGen(std::ostream&os);
  HeaderCodeGen(HeaderCodeGen const&)=delete;
  HeaderCodeGen(HeaderCodeGen&&)=delete;
  HeaderCodeGen&operator=(HeaderCodeGen const&)=delete;
  HeaderCodeGen&operator=(HeaderCodeGen&&)=delete;
  virtual~HeaderCodeGen()=default;
protected:
  // debug print method executed in derived class
  virtual std::ostream&print(std::ostream&os)const override;
private:
  // generate code to an output stream
  virtual void generate(std::shared_ptr<Type>type)override;
  virtual void generate(std::shared_ptr<Attribute>attr,std::string const&classname)override;
  virtual void generate(std::shared_ptr<Parameter>param)override;
  virtual void generate(std::shared_ptr<Function>func)override;
  virtual void generate(std::shared_ptr<Method>meth,std::string const&classname)override;
  virtual void generate(std::shared_ptr<Constructor>ctor,std::string const&classname)override;
  virtual void generate(std::shared_ptr<StandardConstructor>ctor,std::string const&classname)override;
  virtual void generate(std::shared_ptr<Destructor>dtor,std::string const&classname)override;
  virtual void generate(std::shared_ptr<StandardAssignOperator>a,std::string const&classname)override;
  virtual void generate(std::shared_ptr<Class>cl)override;
  virtual void generate(std::shared_ptr<TranslationUnit>tu)override;
private:
  // helper methods
  void generateCtors(std::shared_ptr<Class>cl,Class::visibility_t vis);
  void generateMethods(std::shared_ptr<Class>cl,Class::visibility_t vis);
  void generateAttributes(std::shared_ptr<Class>cl,Class::visibility_t vis);
  void generateStandardAssignops(std::shared_ptr<Class>cl,Class::visibility_t vis);
  void generateStdctors(std::shared_ptr<Class>cl,Class::visibility_t vis);
  void generateClassVisibilitySection(std::shared_ptr<Class>cl,Class::visibility_t vis);
  void generateParamlist(std::vector<std::shared_ptr<Parameter>>params);

  // private data
  Emitter em_;
};
}
