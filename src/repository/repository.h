#ifndef USERREPOSITORY_H
#define USERREPOSITORY_H

#include <QString>
#include <QVector>

struct Task
{
    int id;
    QString name;
    QString create;
};

class Repository{
    public:
    QVector<Task> fetchTasks();
};

#endif
