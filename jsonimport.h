#ifndef JSONIMPORT_H
#define JSONIMPORT_H

#include <QObject>
#include <QTreeWidget>

class JsonImport
{
public:
    JsonImport(QTreeWidget* widget);
    ~JsonImport();

    void populateTree(QJsonDocument document);

private:
    QTreeWidget *widget;
    void addItemTree(QJsonDocument document, QJsonValue value, QTreeWidgetItem *parent = NULL);
};

#endif // JSONIMPORT_H
