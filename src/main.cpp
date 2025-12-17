#define OBX_CPP_FILE // Put this define in one file only before including


#include <iostream>
#include <QApplication>
#include "widget/ui.h"
#include "repository/repository.h"

using namespace std;

int main(int argc, char *argv[])
{
     Repository re;
     QApplication app(argc, argv);
     UI ui;

     ui.setup();

     return  app.exec();
}
