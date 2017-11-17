#include "business/task/Task.h"
#include <iostream>
using namespace std;
namespace planner{

// debug print function
ostream&operator<<(ostream&os,Task const&task){
  return os<<"id: "<<task.id()<<", indb: "<<boolalpha<<task.indb();
}
// ctor
Task::Task(string const&id,bool indb):
    id_(id),indb_(indb){
}
// getters
string const&Task::id()const noexcept{return id_;}
bool Task::indb()const noexcept{return indb_;}
}
