#ifndef __NOP_OPERATION_H__
#define __NOP_OPERATION_H__
#include "Operation.h"
#include <boost/program_options.hpp>
namespace ccgen{

// nop operation for queue manager
class NopOperation:public Operation{
public:
  // ctors,assign,dtor
  NopOperation(std::string const&progname,int argc,char*argv[]);
  NopOperation(NopOperation const&)=delete;
  NopOperation(NopOperation&&)=delete;
  NopOperation&operator=(NopOperation const&)=delete;
  NopOperation&operator=(NopOperation&&)=delete;
  virtual~NopOperation()=default;

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
};
}
#endif
