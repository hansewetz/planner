#pragma once
#include <string>
#include<iosfwd>
namespace planner{

// Task class
class Task{
friend std::ostream&operator<<(std::ostream&os,Task const&task);
friend class TaskPersistManager;
public:
  Task(Task const&)=delete;
  Task(Task&&)=delete;
  Task&operator=(Task const&)=delete;
  Task&operator=(Task&&)=delete;
  ~Task()=default;

  // getters
  std::string const&id()const noexcept;
  bool indb()const noexcept;
private:
  // methods called only by persist-manager
  Task(std::string const&id,bool persisted);
  void setIndb();

  // private attr
  std::string const id_;
  bool indb_;
};
}
