#pragma once
#include "task/TaskPersistManager.h"
#include<iosfwd>
namespace planner{

// TaskPersistManagerSqlite3 class
class TaskPersistManagerSqlite3:public TaskPersistManager{
friend std::ostream&operator<<(std::ostream&os,TaskPersistManagerSqlite3 const&pmgr);
public:
  TaskPersistManagerSqlite3()=default;
  TaskPersistManagerSqlite3(TaskPersistManagerSqlite3 const&)=default;
  TaskPersistManagerSqlite3(TaskPersistManagerSqlite3&&)=default;
  TaskPersistManagerSqlite3&operator=(TaskPersistManagerSqlite3 const&)=default;
  TaskPersistManagerSqlite3&operator=(TaskPersistManagerSqlite3&&)=default;
  virtual~TaskPersistManagerSqlite3()=default;
private:
  // NOTE! Not yet done
};
}
