#pragma once
#include <string>
namespace utils{

// log levels
enum class UtilsLogLevel{TRACE=0,DEBUG=1,NORMAL=2};

// initialize logging
void initBoostFileLogging(UtilsLogLevel level,std::string const&path,std::string const&basename,std::size_t maxsize,std::size_t maxfiles);
void initBoostLogging(UtilsLogLevel level);
void initBoostLogging(bool debug);
}
