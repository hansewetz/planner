#ifndef __OPERAION_H__
#define __OPERAION_H__
#include "utils/logUtils.h"
#include <boost/program_options.hpp>
#include <string>
#include <memory>
namespace ccgen{

// base class for queue managare operations
class Operation{
public:
  // ctors,assign,dtor
  Operation(std::string const&progname,std::string operation);
  Operation(Operation const&)=delete;
  Operation(Operation&&)=delete;
  Operation&operator=(Operation const&)=delete;
  Operation&operator=(Operation&&)=delete;
  virtual~Operation()=default;

  // getters
  int getDebug()const noexcept;
  bool getPrint()const noexcept;
  std::string getProgname()const noexcept;
  std::string getOperation()const noexcept;

  // main methods
  virtual void usage()const=0;         // print usage info
  void print()const;                   // print cmd line parameters
  void execute()const;                 // execute operation
protected:
  // utility functions used by derived class
  void appwarning(std::string const&msg);
  void apperror(std::string const&msg);
  void addStandardCmdlineOptions(boost::program_options::options_description&options);
  void parseStandardCmdline(boost::program_options::variables_map&vm);
  std::string const&progname()const noexcept;
private:
  // pure virtual functions called from base class
  virtual void printAux()const=0;
  virtual void executeAux()const=0;

  // attributes
  bool help_=false;
  int debug_=static_cast<int>(utils::UtilsLogLevel::NORMAL);
  bool print_=false;
  std::string progname_;
  std::string operation_;
};
}
#endif
