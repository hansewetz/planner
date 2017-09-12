// NOTE!
#include "ccgen/Method.h"
#include "ccgen/Type.h"
#include "ccgen/Parameter.h"
#include "ccgen/Method.h"
#include "ccgen/Attribute.h"
#include "ccgen/HeaderCodeGen.h"

// boost
#include <boost/program_options.hpp>
#include <boost/log/trivial.hpp>

// std
#include <iostream>
#include <stdexcept>

// namespace stuff
using namespace std;
using namespace ccgen;
namespace po=boost::program_options;

// NOTE! Should go into a library
namespace{
// print usage information and exit
void usage(po::options_description const&options){
  cerr<<options;
  exit(1);
}
}
// cmd line parameters
namespace{
  string progname;                         // name of this program
  bool help=false;                         // print help info and exit
  bool debug=false;                        // set debug level (1,2,3)
  bool print=false;                        // print cmd line parameters

  // program options
  po::options_description options{string("usage: -h")};
}
namespace{
// print all command line parameters
void printCmdlineParameters(){
  cout<<"-------------------- cmdline parameters (start) ---------------"<<endl;
  cout<<"debug: "<<boolalpha<<debug<<endl;
  cout<<"print: "<<boolalpha<<print<<endl;
  cout<<"-------------------- cmdline parameters (end) ---------------"<<endl;
}
// parse cmd line parameters
void processCmdLineParams(int argc,char**argv){
  // add help option
  options.add_options()("help,h",po::bool_switch(&help),"help, default: false (optional)");
  options.add_options()("debug,d",po::bool_switch(&debug),"debug on/off, default: false (optional)");
  options.add_options()("print,p",po::bool_switch(&print),"print all command line parameters (optional)");

  // process cmd line parameters
  po::variables_map vm;
  po::store(po::command_line_parser(argc,argv).options(options).run(),vm);
  po::notify(vm);

  // if help, print help and exit
  if(help)usage(options);
}
}
// main program
int main(int argc,char**argv){
  progname=argv[0];
  try{
    // process cmd line options
    processCmdLineParams(argc,argv);

    // print cmd line parameters if erquested
    if(print)printCmdlineParameters();

    // NOTE! Not yet done
    auto rettype=make_shared<Type>("std","string",Type::reftype_t::value,true);
    auto paramtype=make_shared<Type>("std","string",Type::reftype_t::lvalref,true);
    auto param=make_shared<Parameter>("foo",paramtype);
    auto attr=make_shared<Attribute>("attr",true,paramtype);
    auto meth=make_shared<Method>("foo","bar",rettype,vector<shared_ptr<Parameter>>{param},true,Method::virtual_t::pure,true);

    // NOTE! test generation of code
    shared_ptr<CodeGen>hgen=make_shared<HeaderCodeGen>(cout);
    hgen->generate(meth);
    cout<<endl;
  }
  catch(exception const&e){
    BOOST_LOG_TRIVIAL(error)<<"caught exception: "<<e.what();
    return 1;
  }
}
