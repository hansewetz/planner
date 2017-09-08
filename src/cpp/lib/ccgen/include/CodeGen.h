#pragma once
#include <string>
#include <iosfwd>
#include <boost/filesystem.hpp>
namespace ccgen{

// class representing a 'type' for code generation
class CodeGen{
public:
  // debug print operator
  friend std::ostream&operator<<(std::ostream&os,CodeGen const&cc);

  // ctors,assign,dtor
  CodeGen(boost::filesystem::path const&dir);
  CodeGen(CodeGen const&)=default;
  CodeGen(CodeGen&&)=default;
  CodeGen&operator=(CodeGen const&)=default;
  CodeGen&operator=(CodeGen&&)=default;
  virtual~CodeGen()=default;

  // getters
  boost::filesystem::path const&dir()const noexcept;

  // debug print method executed in derived class
  virtual std::ostream&print(std::ostream&os)const=0;
private:
  boost::filesystem::path dir_;
};
}
