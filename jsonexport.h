#ifndef JSONEXPORT_H
#define JSONEXPORT_H

#include <QObject>

#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>

#include <QTreeWidget>
#include <QTreeWidgetItem>

class JsonExport
{
public:
    JsonExport(QTreeWidget * widget);
    ~JsonExport();

    QJsonDocument exportTree();

private:
    QTreeWidget *widget;
    void createQuestion(QTreeWidgetItem * item, QString id, QJsonObject * rootObject);
    QJsonObject createOption(QTreeWidgetItem * item, QString id, QJsonObject * rootObject);
};

#endif // JSONEXPORT_H
