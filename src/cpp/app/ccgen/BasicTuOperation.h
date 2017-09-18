#ifndef __BASIC_TU_OPERATION_H__
#define __BASIC_TU_OPERATION_H__
#include "Operation.h"
#include <boost/program_options.hpp>
namespace ccgen{

// nop operation for queue manager
class BasicTuOperation:public Operation{
public:
  // ctors,assign,dtor
  BasicTuOperation(std::string const&progname,int argc,char*argv[]);
  BasicTuOperation(BasicTuOperation const&)=delete;
  BasicTuOperation(BasicTuOperation&&)=delete;
  BasicTuOperation&operator=(BasicTuOperation const&)=delete;
  BasicTuOperation&operator=(BasicTuOperation&&)=delete;
  virtual~BasicTuOperation()=default;

  // methods
  virtual void usage()const override;
private:
  // methods used by base class
  virtual void printAux()const override;
  virtual void executeAux()const override;

  // helper methods
  void parseCmdLine(int argc,char*argv[]);

  // attrinutes
  boost::program_options::options_description options_;
  std::string name_;
  std::string nspace_;
};
}
#endif
