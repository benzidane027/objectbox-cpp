#ifndef USERREPOSITORY_H
#define USERREPOSITORY_H

#include <jsoncpp/json/json.h>
#include "task.obx.hpp"
#include "../database/database.h"

class Repository
{
public:
    Repository();
    std::vector<Json::Value> dataTable();

private:
    Database *db;
};

#endif
