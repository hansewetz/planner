#include "general/sqlite3-utils/Sqlite3Utils.h"
#include "general/utils/throw.h"
#include "general/sqlite-modern/sqlite_modern_cpp.h"
#include "boost/filesystem.hpp"
#include <cstdlib>
namespace fs=boost::filesystem;
using namespace std;
namespace planner{

// open a an existing database
shared_ptr<sqlite::database>openDb(string const&dbfile){
  // check that file exist
  if(!fs::exists(dbfile))THROW_RUNTIME("openDb: file does not exist: "<<dbfile);

  // open database
  return make_shared<sqlite::database>(dbfile);
}
}
