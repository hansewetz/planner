#include "task/TaskManager.h"
#include "task/Task.h"
#include "task-persist-sqlite3/TaskPersistManagerSqlite3.h"
#include <iostream>
using namespace std;
using namespace planner;

// test program for infrastructure
int main(){
  shared_ptr<TaskPersistManager>pmgr=make_shared<TaskPersistManagerSqlite3>();
}
