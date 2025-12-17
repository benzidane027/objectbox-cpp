#ifndef UI_H
#define UI_H
#include <QWidget>
#include <QTableWidget>
#include <QVBoxLayout>
#include <QHeaderView>


class UI :public QWidget
{
public:
    UI();
    void setup();
    void buildTable();
};

#endif 
