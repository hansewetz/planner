#pragma once
#include "business/task/TaskPersistManager.h"
#include <memory>
#include<iosfwd>

// forward decl
namespace sqlite{class database;}

namespace planner{

// forward decl
class Task;

// TaskPersistManagerSqlite3 class
class TaskPersistManagerSqlite3:public TaskPersistManager{
friend std::ostream&operator<<(std::ostream&os,TaskPersistManagerSqlite3 const&pmgr);
public:
  TaskPersistManagerSqlite3(std::shared_ptr<sqlite::database>db);
  TaskPersistManagerSqlite3(TaskPersistManagerSqlite3 const&)=delete;
  TaskPersistManagerSqlite3(TaskPersistManagerSqlite3&&)=delete;
  TaskPersistManagerSqlite3&operator=(TaskPersistManagerSqlite3 const&)=delete;
  TaskPersistManagerSqlite3&operator=(TaskPersistManagerSqlite3&&)=delete;
  virtual~TaskPersistManagerSqlite3()=default;

  // load functions
  virtual std::shared_ptr<Task>getTaskById(std::string const&id)override;

  // save functions
  virtual void saveAux(std::shared_ptr<Task>task)override;
private:
  std::shared_ptr<sqlite::database>db_;
};
}
