#ifndef FILEWRAPPER_H
#define FILEWRAPPER_H

#include <QString>
#include <QJsonDocument>

class FileWrapper
{
private:
    QString filepath;
public:
    FileWrapper();
    ~FileWrapper();

    void setFilePath(QString path);
    QJsonDocument getJSONDocument();
    void saveJSONDocument(QJsonDocument document);
};

#endif // FILEWRAPPER_H
