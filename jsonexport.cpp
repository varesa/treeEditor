#include "jsonexport.h"

#include <QObject>

#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>
#include <QJsonArray>

#include <QTreeWidget>
#include <QTreeWidgetItem>

#include <QDebug>

JsonExport::JsonExport(QTreeWidget* widget)
{
    this->widget = widget;
}

JsonExport::~JsonExport()
{

}

QJsonDocument JsonExport::exportTree() {
    QTreeWidgetItem * item = this->widget->topLevelItem(0);

    QJsonObject *rootObject = new QJsonObject();
    createQuestion(item, "1", rootObject);
    QJsonDocument doc = QJsonDocument(*rootObject);

    qDebug() << doc;
    return doc;
}

void JsonExport::createQuestion(QTreeWidgetItem * item, QString id, QJsonObject * rootObject) {
    qDebug() << "Q " << rootObject;
    QJsonObject object = QJsonObject();

    QString text = item->text(0);
    QJsonObject options = QJsonObject();
    for(int x = 0; x < item->childCount(); x++) {
        options[QString::number(x+1)] = createOption(item->child(x), id + QString::number(x), rootObject);
    }
    object["text"] = text;
    object["options"] = options;
    (*rootObject)[id] = QJsonValue(object);
}

QJsonObject JsonExport::createOption(QTreeWidgetItem * item, QString id, QJsonObject * rootObject) {
    qDebug() << "O " << rootObject;
    QString text = item->text(0).right(item->text(0).size()-3);

    QJsonObject object = QJsonObject();
    object["text"] = text;
    object["goto"] = id;

    if(item->childCount())
        createQuestion(item->child(0), id, rootObject);

    return object;
}
