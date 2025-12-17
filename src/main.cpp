#define OBX_CPP_FILE // Put this define in one file only before including

#include <iostream>
#include <QApplication>
#include "database/database.h"
#include "widget/ui.h"
using namespace std;

int main(int argc, char *argv[])
{
     Database db;
     
     QApplication app(argc, argv);
     UI ui;
     ui.setup();

     return  app.exec();
}
