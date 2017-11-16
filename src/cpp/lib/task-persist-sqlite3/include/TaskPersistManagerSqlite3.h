#pragma once
#include "task/TaskPersistManager.h"
#include <memory>
#include<iosfwd>

// forward decl
namespace sqlite{class database;}

namespace planner{

// forward decl
class TaskPersistManagerImpl;

// TaskPersistManagerSqlite3 class
class TaskPersistManagerSqlite3:public TaskPersistManager{
friend std::ostream&operator<<(std::ostream&os,TaskPersistManagerSqlite3 const&pmgr);
public:
  TaskPersistManagerSqlite3(std::shared_ptr<sqlite::database>db);
  TaskPersistManagerSqlite3(TaskPersistManagerSqlite3 const&)=delete;
  TaskPersistManagerSqlite3(TaskPersistManagerSqlite3&&)=delete;
  TaskPersistManagerSqlite3&operator=(TaskPersistManagerSqlite3 const&)=delete;
  TaskPersistManagerSqlite3&operator=(TaskPersistManagerSqlite3&&)=delete;
  virtual~TaskPersistManagerSqlite3();
private:
  // implementation
  std::unique_ptr<TaskPersistManager>impl_;
};
}
