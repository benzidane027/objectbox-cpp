#define OBX_CPP_FILE // Put this define in one file only before including

#include <QApplication>
#include "widget/ui.h"

using namespace std;

int main(int argc, char *argv[])
{
     QApplication app(argc, argv);
     UI ui;
     return  app.exec();
}
