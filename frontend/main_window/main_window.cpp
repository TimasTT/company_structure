#include "main_window.h"
#include "./ui_main_window.h"
#include "commands_pool.hpp"
#include "commands_tasks.hpp"

#include <qaction.h>

MainWindow::MainWindow(STaskPool* pool_, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    pool = pool_;
    pool->setWidget(ui->listWidget);
    QList<QAction*> list;
    list.push_back(pool->getUndoCommand());
    list.push_back(pool->getRedoCommand());
    ui->menuEdit->addActions(list);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    pool->addDepartment("std::string(");
}

