#ifndef USERREPOSITORY_H
#define USERREPOSITORY_H

#include "task.obx.hpp"
#include <QString>
#include <ctime>
#include "../database/database.h"
#include <iomanip>
#include <map>


class Repository
{
public:
    Repository();
    void addItem(QString, QString);
    void unlinkItem(std::vector<QString>);
    std::vector<std::map<std::string, std::string>> dataTable();

private:
    Database *db;
};

#endif
