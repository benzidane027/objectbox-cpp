#ifndef UI_H
#define UI_H

#include <QWidget>
#include <QString>
#include <QTableWidget>
#include <QVBoxLayout>
#include <QHeaderView>
#include <iostream>
#include "../repository/repository.h"

class UI :public QWidget
{
    //Q_OBJECT
public:
    UI();
    void buildTable();
    void fillTable();
private:
    QTableWidget* table;
    Repository* repo;

};

#endif 
