#include "persist/task-persist-sqlite3/TaskPersistManagerSqlite3.h"
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
      ret=createTaskAux(id,true);
    };
  BOOST_LOG_TRIVIAL(debug)<<"TaskPersistManagerSqlite3Impl::getTaskById: loaded task: "<<boolalpha<<(ret?true:false);
  return ret;
}
}
