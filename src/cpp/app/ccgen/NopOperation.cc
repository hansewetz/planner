#include "NopOperation.h"
#include <boost/log/trivial.hpp>
#include <iostream>
using namespace std;
namespace po=boost::program_options;
namespace ccgen{

// ctor
NopOperation::NopOperation(std::string const&progname,int argc,char*argv[]):
    Operation(progname,"nop"),options_(string("usage: -h")){
  // parse command line parameter for 'nop' operation
  parseCmdLine(argc,argv);
}
// parse command line parameters and set a number of parameters in base class
void NopOperation::parseCmdLine(int argc,char*argv[]){
  // add standard commandline options
  addStandardCmdlineOptions(options_);

  // setup for processing command line parameters + process command line parameters
  po::variables_map vm;
  po::options_description cmdline_options("all command line options");

  // consolidate all options into one description so we can parse command line
  cmdline_options.add(options_);
  po::store(po::command_line_parser(argc,argv).options(cmdline_options).run(),vm);

  // compile process options
  po::notify(vm);

  // parse standard cmd line params
  parseStandardCmdline(vm);
}
// print usage info and exit
void NopOperation::usage()const{
  std::cerr<<options_;
  std::exit(1);
}
// print cmdline parameters and exit
void NopOperation::printAux()const{
}
// execute operation
void NopOperation::executeAux()const{
  BOOST_LOG_TRIVIAL(debug)<<"NopOperation::execute: executing 'nop'";
}
}
