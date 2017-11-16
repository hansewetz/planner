#include "task-persist-sqlite3/TaskPersistManagerSqlite3.h"
#include "sqlite-modern/sqlite3.h"
#include <iostream>
using namespace std;
namespace planner{

// ------------------- impl
class TaskPersistManagerSqlite3Impl:public TaskPersistManager{
public:
  TaskPersistManagerSqlite3Impl(shared_ptr<sqlite::database>db):db_(db){}
  ~TaskPersistManagerSqlite3Impl(){}
private:
  shared_ptr<sqlite::database>db_;
};
// ------------------- interface
// debug print function
ostream&operator<<(ostream&os,TaskPersistManagerSqlite3 const&task){
  return os<<"TaskPersistManagerSqlite3";
}
// ctor
TaskPersistManagerSqlite3::TaskPersistManagerSqlite3(shared_ptr<sqlite::database>db):
    impl_(make_unique<TaskPersistManagerSqlite3Impl>(TaskPersistManagerSqlite3Impl(db))){
}
// dtor
TaskPersistManagerSqlite3::~TaskPersistManagerSqlite3(){
}
}
