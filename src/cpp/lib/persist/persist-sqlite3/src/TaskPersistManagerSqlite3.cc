#include "persist/persist-sqlite3/TaskPersistManagerSqlite3.h"
#include "business/task/Task.h"
#include "general/sqlite-modern/sqlite_modern_cpp.h"
#include <boost/log/trivial.hpp>
#include <string>
#include <iostream>
using namespace std;
namespace planner{

// debug print function
ostream&operator<<(ostream&os,TaskPersistManagerSqlite3 const&task){
  return os<<"TaskPersistManagerSqlite3";
}
// ctor
TaskPersistManagerSqlite3::TaskPersistManagerSqlite3(shared_ptr<sqlite::database>db):
    db_(db){
}
// load task by id
shared_ptr<Task>TaskPersistManagerSqlite3::getTaskById(string const&id){
  BOOST_LOG_TRIVIAL(debug)<<"TaskPersistManagerSqlite3Impl::getTaskById: loading task by id: "<<id;
  string sql="select box, type, isrt_tmstmp, lst_upd_tmstmp from task where id = ?;";
  BOOST_LOG_TRIVIAL(debug)<<"TaskPersistManagerSqlite3Impl::getTaskById: executing sql: "<<sql;
  shared_ptr<Task>ret;
  *db_<<sql<<id>>[this,&ret,id](string box,int type,string isrttmstmp,string lstupdtmstmp){
      BOOST_LOG_TRIVIAL(debug)<<"read data for task-id: "<<id<<" --> "<<"box: "<<box<<", type: "<<type<<
                                ", isrt_tmstmp: "<<isrttmstmp<<"lst_upd_tmstmp: "<<lstupdtmstmp;
      ret=createTaskAux(id,true,static_cast<Task::type_t>(type));
    };
  BOOST_LOG_TRIVIAL(debug)<<"TaskPersistManagerSqlite3Impl::getTaskById: loaded task: "<<boolalpha<<(ret?true:false);
  return ret;
}
// save a task
void TaskPersistManagerSqlite3::saveAux(shared_ptr<Task>task){
  if(task->indb()){
    BOOST_LOG_TRIVIAL(debug)<<"TaskPersistManagerSqlite3Impl::save: updating task, id: "<<task->id();
    // NOTE! Not yet done
  }else{
    BOOST_LOG_TRIVIAL(debug)<<"TaskPersistManagerSqlite3Impl::save: inserting task, id: "<<task->id();
    string sql="insert into task (id,box,type,isrt_tmstmp,lst_upd_tmstmp) values (?,?,?,CURRENT_TIMESTAMP,CURRENT_TIMESTAMP);";
// NOTE! hard coded data
    *db_<<sql<<task->id()<<static_cast<int>(task->type())<<9;
  }
}
// get all tasks sitting in a specific box
vector<shared_ptr<Task>>TaskPersistManagerSqlite3::getTasksByBox(int boxid){
  // NOTE! Not yet done
  return vector<shared_ptr<Task>>{};
}
}
