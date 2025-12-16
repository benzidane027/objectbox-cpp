#define OBX_CPP_FILE // Put this define in one file only before including

#include <iostream>
#include <objectbox.hpp>
#include "objectbox-model.h"
#include "task.obx.hpp"
#include <ctime>
#include <QApplication>
#include <QWidget>
#include <QLabel>

const std::string DB_PATH = std::string(PROJECT_SOURCE_DIR).append("/data/database");

using namespace std;

int main(int argc, char *argv[])
{
     cout << "******** starting ********" << endl
          << endl;

     QApplication app(argc, argv);
     QWidget window;                // Main window
     

     window.show(); // Show the window

     // OBX_model *model = create_obx_model();
     // obx::Options OPTIONS(model);
     // OPTIONS.directory(DB_PATH);
     // obx::Store store(OPTIONS);

     // obx::Box<Task> box(store);

     // Task _task;
     // _task.title = "hello";
     // _task.description = "bla bla bla ...";
     // _task.date_created = (int64_t)std::time(nullptr);

     // obx_id id = box.put(_task); // Create

     // std::vector<unique_ptr<Task>> data = box.getAll();

     // for_each(data.begin(), data.end(), [](const std::unique_ptr<Task> &t)
     //          { cout << "Task ID: " << t->id << ", Title: " << t->title << ", Description: " << t->description
     //                 << ", Date Created: " << t->date_created << endl; });

     cout << endl
          << "******** ending ********" << endl
          << endl;
     return app.exec();
}
