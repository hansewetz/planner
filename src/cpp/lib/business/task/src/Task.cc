#include "business/task/Task.h"
#include <iostream>
using namespace std;
namespace planner{

// debug print function
ostream&operator<<(ostream&os,Task const&task){
  return os<<"id: "<<task.id();
}
// ctor
Task::Task(string const&id):id_(id){
}
// getters
string const&Task::id()const noexcept{return id_;}
}
