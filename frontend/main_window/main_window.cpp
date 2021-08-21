#include <qaction.h>

#include "main_window.h"
#include "./ui_main_window.h"
#include "commands_pool.hpp"
#include "commands_tasks.hpp"
#include "add_department_window/add_department.h"
#include "delete_department_window/delete_department.h"
#include "add_worker_window/add_worker_window.h"
#include "delete_worker_window/delete_worker.h"
#include "change_department_name_window/change_department_name.h"

MainWindow::MainWindow(STaskPool* pool_, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow) {
    ui->setupUi(this);
    pool = pool_;
    pool->setWidget(ui->listWidget);
    QList<QAction*> list;
    list.push_back(pool->getUndoCommand());
    list.push_back(pool->getRedoCommand());
    ui->menuEdit->addActions(list);
}

MainWindow::~MainWindow() {
    delete ui;
}


void MainWindow::on_pushButton_clicked() {
    add_department addDepartmentWindow;
    addDepartmentWindow.setModal(true);
    addDepartmentWindow.exec();

    pool->addDepartment(addDepartmentWindow.getName());
}


void MainWindow::on_pushButton_2_clicked() {
    delete_department deleteDepartmentWindow;
    deleteDepartmentWindow.setModal(true);
    deleteDepartmentWindow.exec();

    pool->deleteDepartment(deleteDepartmentWindow.getName());
}


void MainWindow::on_pushButton_3_clicked() {
    add_worker_window addWorkerWindow;
    addWorkerWindow.setModal(true);
    addWorkerWindow.exec();

    pool->addWorker(addWorkerWindow.getDepartmentName(), addWorkerWindow.getWorkerName(),
                    addWorkerWindow. getWorkerPosition(), addWorkerWindow.getWorkerSalary());
}


void MainWindow::on_pushButton_4_clicked()
{
    delete_worker deleteWorkerWindow;
    deleteWorkerWindow.setModal(true);
    deleteWorkerWindow.exec();

    pool->deleteWorker(deleteWorkerWindow.getDepartmentName(), deleteWorkerWindow.getWorkerName());
}


void MainWindow::on_pushButton_5_clicked()
{
    change_department_name changeDepartmentNameWindow;
    changeDepartmentNameWindow.setModal(true);
    changeDepartmentNameWindow.exec();

    pool->changeDepartmentName(changeDepartmentNameWindow.getDepartmentLastName(), changeDepartmentNameWindow.getDepartmentNewName());
}

