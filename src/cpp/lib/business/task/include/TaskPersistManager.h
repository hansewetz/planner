#pragma once
#include<iosfwd>
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
private:
};
}
