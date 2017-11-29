#pragma once
#include <string>
#include <sstream>
#include <stdexcept>
namespace utils{

// throw macro for exceptions
#define THROW_RUNTIME(x){\
  std::stringstream strm;\
  strm<<__FILE__":#"<<__LINE__<<": "<<x;\
    std::string s{strm.str()};\
    throw std::runtime_error(s);\
}
}
