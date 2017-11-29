#pragma once
#include <business/task/Task.h>
#include <string>
#include <vector>
#include <memory>
#include <iosfwd>
namespace planner{

// TaskPersistManager class
class TaskPersistManager{
friend std::ostream&operator<<(std::ostream&os,TaskPersistManager const&pmgr);
friend class TaskPersistManagerManager;
public:
  TaskPersistManager()=default;
  TaskPersistManager(TaskPersistManager const&)=default;
  TaskPersistManager(TaskPersistManager&&)=default;
  TaskPersistManager&operator=(TaskPersistManager const&)=default;
  TaskPersistManager&operator=(TaskPersistManager&&)=default;
  virtual~TaskPersistManager()=default;

  // create functions
  std::shared_ptr<Task>create(Task::type_t type);

  // load functions
  virtual std::shared_ptr<Task>getTaskById(std::string const&id)=0;
  virtual std::vector<std::shared_ptr<Task>>getTasksByBox(int boxid)=0;

  // save functions
  virtual void save(std::shared_ptr<Task>task);
protected:
  // create a task object (new or existing)
  std::shared_ptr<Task>createTaskAux(std::string const&id,bool indb,Task::type_t type);

  // save task in database (update or insert)
  virtual void saveAux(std::shared_ptr<Task>task)=0;
private:
};
}
