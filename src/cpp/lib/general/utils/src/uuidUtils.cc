#include "general/utils/uuidUtils.h"
#include <boost/lexical_cast.hpp>
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>
#include <string>
using namespace std;
namespace utils{

// generate a uuid
string generateUuid(){
   return boost::lexical_cast<string>(boost::uuids::random_generator()());
 }
}

