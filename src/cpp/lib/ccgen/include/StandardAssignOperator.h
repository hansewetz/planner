#pragma once
#include <vector>
#include <iosfwd>
namespace ccgen{

// class representing a 'type' for code generation
class StandardAssignOperator{
public:
  // debug print operator
  friend std::ostream&operator<<(std::ostream&os,StandardAssignOperator const&ctor);

  // type of assign operator implementation
  enum class impl_t:int{impl=0,def=1,del=3};

  // ctors,assign,dtor
  StandardAssignOperator(bool iscopy,impl_t impl);
  StandardAssignOperator(StandardAssignOperator const&)=default;
  StandardAssignOperator(StandardAssignOperator&&)=default;
  StandardAssignOperator&operator=(StandardAssignOperator const&)=default;
  StandardAssignOperator&operator=(StandardAssignOperator&&)=default;
  ~StandardAssignOperator()=default;

  // getters
  bool iscopy()const noexcept;
  impl_t impl()const noexcept;

  // convert impl type to string
  static std::string const&impl2string(impl_t impl);
private:
  bool const iscopy_;
  impl_t impl_;
};
}
