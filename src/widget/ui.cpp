#include "ui.h"

UI::UI()
{
    setWindowTitle("Task Manager");
    resize(800, 600);
    buildTable();
    fillTable();
    show();
}
void UI::setup()
{
}

void UI::fillTable()
{
    std::cout << "hello ******************\n";
    // if(table == nullptr) return;
    std::cout << "hello";
    //int row = table->rowCount();

    // table->insertRow(row);
    // table->setItem(row, 0, new QTableWidgetItem("Version"));
    // table->setItem(row, 1, new QTableWidgetItem("1.0"));
}

void UI::buildTable()
{
    //table = new QTableWidget(this);

    // table->setColumnCount(4);
    // table->setHorizontalHeaderLabels({"ID", "Title", "Description", "Create Date"});
    // table->horizontalHeader()->setStretchLastSection(true);
    // auto layout = new QVBoxLayout(this);
    // layout->addWidget(table);
    // setLayout(layout);
}
