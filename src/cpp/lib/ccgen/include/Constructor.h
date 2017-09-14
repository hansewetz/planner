#pragma once
#include <memory>
#include <string>
#include <vector>
#include <iosfwd>
namespace ccgen{

// forward decl
class Parameter;

// class representing a 'type' for code generation
class Constructor{
public:
  
  // debug print operator
  friend std::ostream&operator<<(std::ostream&os,Constructor const&ctor);

  // ctors,assign,dtor
  Constructor(std::vector<std::shared_ptr<Parameter>>const&params);
  Constructor(Constructor const&)=default;
  Constructor(Constructor&&)=default;
  Constructor&operator=(Constructor const&)=default;
  Constructor&operator=(Constructor&&)=default;
  ~Constructor()=default;

  // getters
  std::vector<std::shared_ptr<Parameter>>const&params()const noexcept;
private:
  std::vector<std::shared_ptr<Parameter>>const params_;
};
}
