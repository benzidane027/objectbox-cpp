#define OBX_CPP_FILE // Put this define in one file only before including

#include <iostream>
#include <objectbox.hpp>
#include "objectbox-model.h"
#include "task.obx.hpp"
#include <ctime>

#include "database.h"

using namespace std;

const std::string DB_PATH = std::string(PROJECT_SOURCE_DIR).append("/data/database");

Database::Database()
{
     connect();
}

void Database::connect()
{
     OBX_model *model = create_obx_model();
     obx::Options OPTIONS(model);
     OPTIONS.directory(DB_PATH);
     obx::Store store(OPTIONS);
}
