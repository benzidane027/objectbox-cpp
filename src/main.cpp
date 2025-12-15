#define OBX_CPP_FILE // Put this define in one file only before including

#include <iostream>
#include <objectbox.hpp>
#include "objectbox-model.h"
#include "task.obx.hpp"


const std::string DB_PATH = std::string(PROJECT_SOURCE_DIR).append("/data/mydb");


using namespace std;


int main()
{
    cout << "******** starting ********" << endl
         << endl;
    OBX_model *model = create_obx_model();
    
    obx::Options options(model);
    options.directory(DB_PATH);
    obx::Store store(options);

    obx::Box<Task> box(store);
    obx_id id = box.put({.text = "Buy milk"}); // Create
    std::unique_ptr<Task> task = box.get(id);
    if (task)
    {
        cout << task->id << endl; // Read
    }
    cout << endl
         << "******** ending ********" << endl
         << endl;
    return 0;
}
