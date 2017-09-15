#pragma once
#include <string>
#include <vector>
#include <iosfwd>
namespace ccgen{

// class representing a headerfile
class Headerfile{
public:
  // debug print operator
  friend std::ostream&operator<<(std::ostream&os,Headerfile const&h);

  // ctors,assign,dtor
  Headerfile(std::string const&name,bool local);
  Headerfile(Headerfile const&)=default;
  Headerfile(Headerfile&&)=default;
  Headerfile&operator=(Headerfile const&)=default;
  Headerfile&operator=(Headerfile&&)=default;
  ~Headerfile()=default;

  // getters
  std::string const&name()const noexcept;
  bool islocal()const noexcept;
private:
  std::string const name_;
  bool local_;  // if true, use '"' to include
};
}
