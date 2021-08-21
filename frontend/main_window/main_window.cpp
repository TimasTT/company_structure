#include <qaction.h>

#include "main_window.h"
#include "./ui_main_window.h"
#include "commands_pool.hpp"
#include "commands_tasks.hpp"
#include "add_department_window/add_department.h"
#include "delete_department_window/delete_department.h"

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
    add_department addDepartmentWindow;
    addDepartmentWindow.setModal(true);
    addDepartmentWindow.exec();

    pool->addDepartment(addDepartmentWindow.getName());
}


void MainWindow::on_pushButton_2_clicked()
{
    delete_department deleteDepartmentWindow;
    deleteDepartmentWindow.setModal(true);
    deleteDepartmentWindow.exec();

    pool->deleteDepartment(deleteDepartmentWindow.getName());
}

