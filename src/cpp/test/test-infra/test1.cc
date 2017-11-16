#include "task/TaskManager.h"
#include "task/Task.h"
#include "task-persist-sqlite3/TaskPersistManagerSqlite3.h"
#include "sqlite3-utils/Sqlite3Utils.h"
#include "sqlite-modern/sqlite3.h"
#include <iostream>
using namespace std;
using namespace planner;

/*
NOTE!
(1) add namespace for sqlite3 stuff
(2) create separate directory fro sqlite (modern + utils)
*/

// test program for infrastructure
int main(){
  // NOTE! must add utils to open database
  auto db=openDb("junk.db");

  shared_ptr<TaskPersistManager>pmgr=make_shared<TaskPersistManagerSqlite3>(db);
  auto tmgr=make_shared<TaskManager>(pmgr);
  cout<<*tmgr<<endl;
}
