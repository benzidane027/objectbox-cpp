#ifndef UI_H
#define UI_H

#include <QWidget>
#include <QFrame>
#include <QString>
#include <QTableWidget>
#include <QVBoxLayout>
#include <QHeaderView>
#include <QFormLayout>
#include <QPushButton>
#include <QLineEdit>
#include <QMenu>
#include <QProcess>
#include "../repository/repository.h"


class UI : public QWidget
{
    // Q_OBJECT
public:
    UI();
    void buildUi();
    void ButtonClick(QLineEdit*,QLineEdit*);
    void fillTable();
    void testFunc(const QPoint&);
    void testButton();

private:
    QTableWidget *table;
    Repository *repo;
};

#endif
