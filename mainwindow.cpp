#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QList>
#include <QFileDialog>
#include <QJsonObject>
#include <QJsonArray>
#include <QDebug>
#include <QInputDialog>

#include "jsonimport.h"
#include "jsonexport.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    this->fileWrapper = new FileWrapper();

    ui->setupUi(this);
    ui->treeWidget->header()->close();

    QList<QAction*> actions = ui->menuFile->actions();
    for(int x = 0; x < actions.length(); x++) {
        QAction *action = actions.at(x);
        if(action->text() == "Open") {
            connect(action, SIGNAL(triggered()), this, SLOT(menuOpen()));
        } else if(action->text() == "Save") {
            connect(action, SIGNAL(triggered()), this, SLOT(menuSave()));
        } else if(action->text() == "Exit") {
            connect(action, SIGNAL(triggered()), this, SLOT(menuExit()));
        }
    }

    ui->treeWidget->setContextMenuPolicy(Qt::ActionsContextMenu);
    QAction *editAction = new QAction("Edit", ui->treeWidget);
    QAction *insertAction = new QAction("Insert child", ui->treeWidget);

    connect(editAction, SIGNAL(triggered()), this, SLOT(contextEdit()));
    connect(insertAction, SIGNAL(triggered()), this, SLOT(contextInsert()));

    ui->treeWidget->addAction(editAction);
    ui->treeWidget->addAction(insertAction);
}

MainWindow::~MainWindow()
{
    delete ui;
}

/* Menubar slots */

void MainWindow::menuOpen() {
    QString filename = QFileDialog::getOpenFileName();
    this->fileWrapper->setFilePath(filename);

    JsonImport *importer = new JsonImport(this->ui->treeWidget);
    importer->populateTree(this->fileWrapper->getJSONDocument());
}

void MainWindow::menuSave() {
    QString filename = QFileDialog::getSaveFileName();
    this->fileWrapper->setFilePath(filename);

    JsonExport exporter = JsonExport(this->ui->treeWidget);
    this->fileWrapper->saveJSONDocument(exporter.exportTree());
}

void MainWindow::menuExit() {
    this->close();
}

/* Context menu slots */

void MainWindow::contextEdit() {
    QList<QTreeWidgetItem*> selected = this->ui->treeWidget->selectedItems();

    if(selected.length() < 1) {
        return;
    }

    QTreeWidgetItem *item = selected.at(0);
    QString newValue = QInputDialog::getText(this, "New value", "", QLineEdit::Normal, item->text(0));
    if(newValue != "")
        item->setText(0, newValue);
}

void MainWindow::contextInsert() {
    QList<QTreeWidgetItem*> selected = this->ui->treeWidget->selectedItems();

    if(selected.length() < 1) {
        return;
    }

    QTreeWidgetItem *item = selected.at(0);
    QTreeWidgetItem *child = new QTreeWidgetItem(item);
    child->setText(0, "new child");
    item->addChild(child);
}
