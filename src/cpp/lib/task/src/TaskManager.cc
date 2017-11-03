#include "task/TaskManager.h"
#include <iostream>
using namespace std;
namespace planner{

// debug print function
ostream&operator<<(ostream&os,TaskManager const&mgr){
  return os;
}
// ctor
TaskManager::TaskManager(shared_ptr<TaskPersistManager>pmgr):pmgr_(pmgr){
}
}
