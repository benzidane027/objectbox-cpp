#ifndef USERREPOSITORY_H
#define USERREPOSITORY_H

#include <jsoncpp/json/json.h>
#include "task.obx.hpp"
#include <QString>
#include <ctime>
#include "../database/database.h"
#include <iomanip>


class Repository
{
public:
    Repository();
    void addItem(QString, QString);
    void unlinkItem(std::vector<QString>);
    std::vector<Json::Value> dataTable();

private:
    Database *db;
};

#endif
