// internal
#include "NopOperation.h"
#include "BasicTuOperation.h"

// boost
#include <boost/log/trivial.hpp>

// std
#include <iostream>
#include <stdexcept>

// namespace stuff
using namespace std;
using namespace ccgen;
namespace po=boost::program_options;

// ----------------------- operations that can be performed ----------------------------
namespace{
string OP_NOP="nop";
string OP_BASIC_TU="btu";

// name of this program
string progname;

// print usage information and exit
void usage(){
  cerr<<"usage: "<<progname<<" [nop|btu] params ... [--help]"<<endl;
  exit(1);
}
// set debug level
void setDebugLevel(int level){
  // get log level
  utils::UtilsLogLevel utilLevel;
  if(level==1){
    utilLevel=utils::UtilsLogLevel::NORMAL;
  }else
  if(level==2){
    utilLevel=utils::UtilsLogLevel::DEBUG;
  }else{
    utilLevel=utils::UtilsLogLevel::TRACE;
  }
  utils::initBoostLogging(utilLevel);
}
} 
// main program
int main(int argc,char**argv){
  progname=argv[0];
  if(argc<2)usage();
  try{
    // check which operatikon to execute
    // create operation object
    shared_ptr<Operation>op;
    string operation=argv[1];
    if(operation==OP_NOP){
      op=make_shared<NopOperation>(progname,argc-1,argv+1);
    }else
    if(operation==OP_BASIC_TU){
      op=make_shared<BasicTuOperation>(progname,argc-1,argv+1);
    }else{
      usage();
    }
    setDebugLevel(op->getDebug());
    if(op->getPrint())op->print();
    op->execute();
  }
  catch(exception const&e){
    BOOST_LOG_TRIVIAL(error)<<"caught exception: "<<e.what();
    return 1;
  }
}
