#pragma once
#include <string>
#include<iosfwd>
namespace planner{

// Task class
class Task{
friend std::ostream&operator<<(std::ostream&os,Task const&task);
friend class TaskPersistManager;
public:
  enum class type_t:int{oneshot=0};

  Task(Task const&)=delete;
  Task(Task&&)=delete;
  Task&operator=(Task const&)=delete;
  Task&operator=(Task&&)=delete;
  ~Task()=default;

  // getters
  std::string const&id()const noexcept;
  bool indb()const noexcept;
  Task::type_t type()const noexcept;

  // convert a type_t to a printable string
  static std::string type2string(type_t type);
private:
  // methods called only by persist-manager
  Task(std::string const&id,bool persisted,Task::type_t type);
  void setIndb();

  // private attr
  std::string const id_;
  bool indb_;
  Task::type_t type_;
};
}
