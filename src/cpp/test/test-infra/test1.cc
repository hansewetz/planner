#include "business/task/TaskManager.h"
#include "business/task/Task.h"
#include "persist/persist-sqlite3/TaskPersistManagerSqlite3.h"
#include "general/sqlite3-utils/Sqlite3Utils.h"
#include "general/sqlite-modern/sqlite3.h"
#include <iostream>
using namespace std;
using namespace planner;

// test program for infrastructure
int main(){
  // create a task persist manager
  auto db=openDb("test1.db");
  shared_ptr<TaskPersistManager>pmgr=make_shared<TaskPersistManagerSqlite3>(db);

  // get a task
/*
  auto task=pmgr->getTaskById("Hello");
  cout<<"task: "<<*task<<endl;
*/

  // create a task and save it
  auto task=pmgr->create(Task::type_t::oneshot);
  pmgr->save(task);

  // create a task manager
  auto tmgr=make_shared<TaskManager>(pmgr);
}
