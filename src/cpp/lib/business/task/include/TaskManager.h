#pragma once
#include<memory>
#include<iosfwd>
namespace planner{

// forward decl
class TaskPersistManager;

// TaskManager class
class TaskManager{
friend std::ostream&operator<<(std::ostream&os,TaskManager const&mgr);
friend class TaskManagerManager;
public:
  TaskManager(std::shared_ptr<TaskPersistManager>pmgr);
  TaskManager(TaskManager const&)=default;
  TaskManager(TaskManager&&)=default;
  TaskManager&operator=(TaskManager const&)=default;
  TaskManager&operator=(TaskManager&&)=default;
  virtual~TaskManager()=default;
private:
  std::shared_ptr<TaskPersistManager>pmgr_;
};
}
