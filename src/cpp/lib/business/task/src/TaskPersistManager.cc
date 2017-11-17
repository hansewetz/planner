#include "business/task/TaskPersistManager.h"
#include "business/task/Task.h"
#include <iostream>
using namespace std;
namespace planner{

// debug print function
ostream&operator<<(ostream&os,TaskPersistManager const&pmgr){
  return os;
}
// create a task object (new or existing)
shared_ptr<Task>TaskPersistManager::createTaskAux(string const&id,bool indb){
  // cannot use 'make_shared<...>)()' since it is not a friend of Task
  return shared_ptr<Task>(new Task(id,indb));
}
}
