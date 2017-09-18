#include "Operation.h"
#include <iostream>
using namespace std;
namespace po=boost::program_options;
namespace ccgen{

// ctor
Operation::Operation(string const&progname,string operation):
    progname_(progname),operation_(operation){
}
// get debug level
int Operation::getDebug()const noexcept{
  return debug_;
}
// get print info
bool Operation::getPrint()const noexcept{
  return print_;
}
// get program name
string Operation::getProgname()const noexcept{
  return operation_;
}
string Operation::getOperation()const noexcept{
  return operation_;
}
// warning
void Operation::appwarning(std::string const&msg){
  std::cerr<<"warning: "<<msg<<endl;
}
// error
void Operation::apperror(std::string const&msg){
  std::cerr<<"error: "<<msg<<endl;
  exit(1);
}
// add standard commandline options
void Operation::addStandardCmdlineOptions(po::options_description&options){
  options.add_options()("help,h","help (optional)");
  options.add_options()("debug,d",po::value<int>(),"debug level 1, 2, 3, default: 1 (optional)");
  options.add_options()("print,p","print all command line parameters (optional)");
}
// parse standard command line arguments
void Operation::parseStandardCmdline(po::variables_map&vm){
  // get some general command line parameters
  if(vm.count("help"))usage();
  if(vm.count("print"))print_=true; 
  if(vm.count("debug")){
    debug_=vm["debug"].as<int>();
    if(debug_<0||debug_>3)apperror("invalid debug level specified");
  }
}

// get name of program
string const&Operation::progname()const noexcept{
  return progname_;
}
// print command line arguments
void Operation::print()const{
  cout<<"-------------------- cmdline parameters (start) ---------------"<<endl;
  cout<<"debug: "<<getDebug()<<endl;
  cout<<"print: "<<boolalpha<<getPrint()<<endl;
  printAux();
  cout<<"-------------------- cmdline parameters (end) ---------------"<<endl;
}
// execute operation
void Operation::execute()const{
  executeAux();
}
}
