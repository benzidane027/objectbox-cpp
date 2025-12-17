#include "ui.h"

UI::UI()
{
    setWindowTitle("Task Manager");
    resize(800, 600);
    buildTable();
    show();
}
void UI::setup()
{
}

void UI::buildTable()
{
    auto table = new QTableWidget(this);
    table->setRowCount(1);
    table->setColumnCount(3);
    table->setHorizontalHeaderLabels({"ID", "Name","create"});
    table->horizontalHeader()->setStretchLastSection(true);
    auto *layout = new QVBoxLayout(this);
    layout->addWidget(table);
    setLayout(layout);
}
