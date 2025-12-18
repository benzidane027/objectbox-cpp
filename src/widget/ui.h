#ifndef UI_H
#define UI_H

#include <QWidget>
#include <QTableWidget>
#include <QVBoxLayout>
#include <QHeaderView>
#include <iostream>

class UI :public QWidget
{
    //Q_OBJECT
public:
    UI();
    void setup();
    void buildTable();
    void fillTable();
// private:
//     QTableWidget* table;
};

#endif 
