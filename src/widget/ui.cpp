#include "ui.h"
#include <algorithm>
#include <qlineedit.h>

UI::UI()
{
    repo = new Repository();
    setWindowTitle("Task Manager");
    resize(800, 600);
    buildUi();
    fillTable();
    show();
}

void UI::fillTable()
{
    table->setRowCount(0);
    int rowIndex = 0;

    std::vector<std::map<std::string, std::string>> data = repo->dataTable();

    std::for_each(data.begin(), data.end(), [&](auto &item)
                  {
    int index=0;
    //std::cout << item.toStyledString()<<"\n";
    table->insertRow(rowIndex);
    table->setItem(rowIndex, index++, new QTableWidgetItem(QString::fromStdString(item["id"])));
    table->setItem(rowIndex, index++, new QTableWidgetItem(QString::fromStdString(item["title"])));
    table->setItem(rowIndex, index++, new QTableWidgetItem(QString::fromStdString(item["description"])));
    table->setItem(rowIndex, index++, new QTableWidgetItem(QString::fromStdString(item["date_created"])));
    rowIndex++; });
}

void UI::buildUi()
{
    QFrame *formFrame = new QFrame;
    formFrame->setFrameShape(QFrame::StyledPanel);
    QFormLayout *formLayout = new QFormLayout(formFrame);
    static QLineEdit *titleEdit = new QLineEdit;
    static QLineEdit *descriptionEdit = new QLineEdit;
    QPushButton *addBtn = new QPushButton("Add");
    QPushButton *removeBtn = new QPushButton("Remove");

    formLayout->addRow(titleEdit);
    formLayout->addRow(descriptionEdit);
    formLayout->addRow(addBtn);
    formLayout->addRow(removeBtn);

    table = new QTableWidget(this);
    table->setColumnCount(4);
    table->setHorizontalHeaderLabels({"ID", "Title", "Description", "Create Date"});
    table->horizontalHeader()->setStretchLastSection(true);
    table->setEditTriggers(QAbstractItemView::NoEditTriggers);

    auto layout = new QVBoxLayout(this);

    layout->addWidget(table);
    layout->addWidget(formFrame);
    setLayout(layout);
    QObject::connect(addBtn, &QPushButton::clicked, this, [&]()
                     { ButtonClick(titleEdit, descriptionEdit); });
    QObject::connect(removeBtn, &QPushButton::clicked, this, [&]()
                     { 
        QModelIndexList rows = table->selectionModel()->selectedRows();
        std::vector<QString> ids;
        std::transform(rows.begin(),rows.end(),std::back_inserter(ids),[&](auto item){
            return table->item(item.row(),0)->text();
        });
        repo->unlinkItem(ids);  
        fillTable(); });
}

void UI::ButtonClick(QLineEdit *title, QLineEdit *description)
{
    repo->addItem(title->text(), description->text());
    fillTable();
}