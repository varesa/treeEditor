#include "jsonimport.h"

#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>

#include <QTreeWidget>
#include <QTreeWidgetItem>

JsonImport::JsonImport(QTreeWidget* widget)
{
    this->widget = widget;
}

JsonImport::~JsonImport()
{

}

void JsonImport::populateTree(QJsonDocument document) {
    this->widget->clear();
    QJsonValue origin = document.object().value("1");
    addItemTree(document, origin);
}

void JsonImport::addItemTree(QJsonDocument document, QJsonValue value, QTreeWidgetItem *parent) {
    QTreeWidgetItem *item_q;

    if(parent == NULL) {
        item_q = new QTreeWidgetItem(this->widget);
        this->widget->addTopLevelItem(item_q);
    } else {
        item_q = new QTreeWidgetItem(parent);
        parent->addChild(item_q);
    }
    QJsonObject object = value.toObject();

    item_q->setText(0, object["text"].toString());


    QStringList keys = object["options"].toObject().keys();
    for(int x = 0; x < keys.length(); x++) {
        QJsonObject option = object["options"].toObject().value(keys[x]).toObject();

        QTreeWidgetItem *item_option = new QTreeWidgetItem(item_q);
        item_option->setText(0, keys[x] + ": " + option["text"].toString());
        item_q->addChild(item_option);

        if(option.contains("goto")) {
            QJsonValue option_goto = document.object().value(QString::number(option["goto"].toInt()));
            addItemTree(document, option_goto, item_option);
        }
    }
}
