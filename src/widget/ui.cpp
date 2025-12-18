#include "ui.h"
#include <algorithm>

UI::UI()
{
    repo = new Repository();
    setWindowTitle("Task Manager");
    resize(800, 600);
    buildTable();
    fillTable();
    show();
}

void UI::fillTable()
{
    int rowIndex = 0;
    repo->dataTable();

    std::vector<Json::Value> data = repo->dataTable();
    std::for_each(data.begin(), data.end(), [&](auto &item)
                  {
    int index=0;
    std::cout << item.toStyledString()<<"\n";
    table->insertRow(rowIndex);
    table->setItem(rowIndex, index++, new QTableWidgetItem(QString::fromStdString(item["id"].asString())));
    table->setItem(rowIndex, index++, new QTableWidgetItem(QString::fromStdString(item["title"].asString())));
    table->setItem(rowIndex, index++, new QTableWidgetItem(QString::fromStdString(item["description"].asString())));
    table->setItem(rowIndex, index++, new QTableWidgetItem(QString::fromStdString(item["date_created"].asString())));
    rowIndex++; });
}

void UI::buildTable()
{
    table = new QTableWidget(this);
    table->setColumnCount(4);
    table->setHorizontalHeaderLabels({"ID", "Title", "Description", "Create Date"});
    table->horizontalHeader()->setStretchLastSection(true);
    auto layout = new QVBoxLayout(this);
    layout->addWidget(table);
    setLayout(layout);
}
