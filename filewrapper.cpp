#include <QFile>
#include <QDebug>

#include "filewrapper.h"

FileWrapper::FileWrapper()
{
    this->filepath = "";
}

FileWrapper::~FileWrapper()
{

}

void FileWrapper::setFilePath(QString path) {
    this->filepath = path;
}

QJsonDocument FileWrapper::getJSONDocument() {
    QFile *file = new QFile(this->filepath);
    file->open(QFile::ReadOnly);
    QString fileContents = file->readAll();
    file->close();

    QJsonDocument jsondoc = QJsonDocument::fromJson(fileContents.toUtf8());
    return jsondoc;
}

void FileWrapper::saveJSONDocument(QJsonDocument document) {
    QString json = document.toJson();
    qDebug() << json;

    QFile *file = new QFile(this->filepath);
    file->open(QFile::WriteOnly);
    file->write(json.toUtf8());
    file->close();
}
