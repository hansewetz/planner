#include "business/task/Task.h"
#include "general/utils/throw.h"
#include <boost/log/trivial.hpp>
#include <boost/lexical_cast.hpp>
#include <iostream>
using namespace std;
namespace planner{

// debug print function
ostream&operator<<(ostream&os,Task const&task){
  return os<<"id: "<<task.id()<<", indb: "<<boolalpha<<task.indb()<<", type: "<<Task::type2string(task.type());
}
// ctor
Task::Task(string const&id,bool indb,type_t type):
    id_(id),indb_(indb),type_(type){
}
// getters
string const&Task::id()const noexcept{return id_;}
bool Task::indb()const noexcept{return indb_;}
Task::type_t Task::type()const noexcept{return type_;}

// setters
void Task::setIndb(){indb_=true;}

// convert a type_t to a printable string
string Task::type2string(type_t type){
  if(type==Task::type_t::oneshot){
    return "oneshot"s;
  }else{
    string err="Task::type2string: internal error - invalid Task::type_t: "s+boost::lexical_cast<string>(static_cast<int>(type));
    BOOST_LOG_TRIVIAL(error)<<err;
    THROW_RUNTIME(err);
  }
}
}
