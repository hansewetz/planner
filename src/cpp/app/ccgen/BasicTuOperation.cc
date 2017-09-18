#include "BasicTuOperation.h"
#include "ccgen/StandardTranslationUnit.h"
#include "ccgen/HeaderCodeGen.h"
#include <boost/log/trivial.hpp>
#include <iostream>
using namespace std;
namespace po=boost::program_options;
namespace ccgen{

// ctor
BasicTuOperation::BasicTuOperation(std::string const&progname,int argc,char*argv[]):
    Operation(progname,"nop"),options_(string("usage: -h")){
  // parse command line parameter for 'nop' operation
  parseCmdLine(argc,argv);
}
// parse command line parameters and set a number of parameters in base class
void BasicTuOperation::parseCmdLine(int argc,char*argv[]){
  // add standard commandline options
  addStandardCmdlineOptions(options_);

  // add options specific to this operation
  options_.add_options()("name,n",po::value<string>(),"name of translation unit(mandatory)");
  options_.add_options()("namespace,s",po::value<string>(),"namespace for class in translation unit (mandatory)");

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

  // get parameters
  if(!vm.count("name"))apperror("missing 'name' parameter");
  name_=vm["name"].as<string>();
  if(!vm.count("namespace"))apperror("missing 'namespace' parameter");
  nspace_=vm["namespace"].as<string>();
}
// print usage info and exit
void BasicTuOperation::usage()const{
  std::cerr<<options_;
  std::exit(1);
}
// print cmdline parameters and exit
void BasicTuOperation::printAux()const{
}
// execute operation
void BasicTuOperation::executeAux()const{
  // create basic tu and generate code for it
  auto tu=make_shared<StandardTranslationUnit>(name_,nspace_);
  shared_ptr<CodeGen>hgen=make_shared<HeaderCodeGen>(cout);
  hgen->generate(tu);
  cout<<endl;
}
}
