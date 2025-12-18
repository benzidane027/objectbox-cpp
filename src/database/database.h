#ifndef DATABASE_H
#define DATABASE_H

#include <ctime>
#include <objectbox.hpp>
#include "objectbox-model.h"
#include <iostream>

const std::string DB_PATH = std::string(PROJECT_SOURCE_DIR).append("/data/database");

using namespace std;

class Database
{
public:
    Database()
    {
        connect();
    };
    void connect()
    {
        OBX_model *model = create_obx_model();
        obx::Options options(model);
        options.directory(DB_PATH);
        store = std::make_unique<obx::Store>(options);
    }

    template <typename T>
    std::unique_ptr<T> getItem(int id)
    {
        obx::Box<T> box(*store);
        return box.get(id);
    }

    template <typename T>
    obx_id putItem(T item)
    {
        obx::Box<T> box(*store);
        return box.put(item);
    }

    template <typename T>
    std::vector<std::unique_ptr<T>> getAllItems()
    {
        obx::Box<T> box(*store);
        return box.getAll();
    }

private:
    std::unique_ptr<obx::Store> store;
};

#endif
