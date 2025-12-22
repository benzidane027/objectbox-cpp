#include "repository.h"
#include "task.obx.hpp"

Repository::Repository()
{
    db = new Database();
}

std::vector<std::map<std::string, std::string>> Repository::dataTable()
{
    std::vector<std::map<std::string, std::string>> data;
    auto result = db->getAllItems<Task>();

    std::for_each(result.begin(), result.end(), [&](auto &item)
                  {
        std::map<std::string, std::string> obj;
        std::tm tm = *std::localtime(&(item->date_created));
        std::ostringstream oss;
        // Use std::put_time to format into the string stream
        oss << std::put_time(&tm, "%H:%M %d-%b-%Y ");
        
        obj["id"] = std::to_string(item->id);
        obj["title"] = item->title;
        obj["description"] = item->description;
        obj["date_created"] =oss.str();

        data.push_back(obj); });
    return data;
}

void Repository::addItem(QString title, QString description)
{
    Task _task;
    _task.id = 0;
    _task.title = title.toStdString();
    _task.description = description.toStdString();
    _task.date_created = std::time(nullptr);
    db->putItem(_task);
}

void Repository::unlinkItem(std::vector<QString> items)
{

    std::vector<uint64_t> _temp = {};
    for (auto &item : items)
        _temp.push_back(item.toUInt());

    db->deleteItem<Task>(_temp);
}
