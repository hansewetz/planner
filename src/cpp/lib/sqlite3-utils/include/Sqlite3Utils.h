#pragma once
#include "boost/filesystem.hpp"
#include <string>
#include <memory>

// forward decl
namespace sqlite{class database;}

namespace fs=boost::filesystem;
namespace planner{
// open an existing database
std::shared_ptr<sqlite::database>openDb(std::string const&dbfile);
}
