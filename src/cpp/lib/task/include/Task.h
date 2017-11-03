#pragma once
#include <string>
#include<iosfwd>
namespace planner{

// Task class
class Task{
friend std::ostream&operator<<(std::ostream&os,Task const&task);
friend class TaskManager;
public:
  Task(Task const&)=delete;
  Task(Task&&)=delete;
  Task&operator=(Task const&)=delete;
  Task&operator=(Task&&)=delete;
  ~Task()=default;

  // getters
  std::string const&id()const noexcept;
private:
  // tasks only created by TaskManager
  Task(std::string const&id);

  // private attr
  std::string const&id_;
};
}
