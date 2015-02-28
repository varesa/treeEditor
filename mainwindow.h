#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QJsonValue>
#include <QTreeWidgetItem>
#include "filewrapper.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    FileWrapper *fileWrapper;

public slots:
    void menuOpen();
    void menuSave();
    void menuExit();

    void contextEdit();
    void contextInsert();

};

#endif // MAINWINDOW_H
