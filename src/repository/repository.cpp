#include "repository.h"

Repository::Repository()
{
    db = new Database();
}

 std::vector<Json::Value> Repository::dataTable()
{
    std::vector<Json::Value> data;
    auto result = db->getAllItems<Task>();

    std::for_each(result.begin(), result.end(), [&](auto &item)
                  {
        Json::Value obj;
        obj["id"] = item->id;
        obj["title"] = item->title;
        obj["description"] = item->description;
        obj["date_created"] = item->date_created;

        data.push_back(obj); });
    return data;
}
