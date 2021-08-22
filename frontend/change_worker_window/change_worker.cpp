#include "change_worker.h"
#include "ui_change_worker.h"
#include "commands_pool.hpp"
#include "commands_tasks.hpp"

change_worker::change_worker(QWidget* parent, STaskPool* pool_)
        : QDialog(parent), ui(new Ui::change_worker), pool(pool_) {
    ui->setupUi(this);
}

change_worker::change_worker(STaskPool* pool_)
        : ui(new Ui::change_worker), pool(pool_) {
    ui->setupUi(this);
}

change_worker::~change_worker() {
    delete ui;
}

void change_worker::on_pushButton_4_clicked() {
    departmentName = ui->departmentName->text().toStdString();
    workerName = ui->workerLastName->text().toStdString();
    workerNewName = ui->nameWorkerNew->text().toStdString();
    workerNewPosition = ui->positionWorkerNew->text().toStdString();
    workerNewSalary = ui->salaryWorkerNew->text().toInt();

    pool->changeWorkerAll(departmentName, workerName, workerNewName, workerNewPosition, workerNewSalary);
    close();
}

void change_worker::on_changeName_clicked() {
    departmentName = ui->departmentName->text().toStdString();
    workerName = ui->workerLastName->text().toStdString();
    workerNewName = ui->nameWorkerNew->text().toStdString();

    pool->changeWorkerName(departmentName, workerName, workerNewName);
    close();
}

void change_worker::on_changePosition_clicked() {
    departmentName = ui->departmentName->text().toStdString();
    workerName = ui->workerLastName->text().toStdString();
    workerNewPosition = ui->positionWorkerNew->text().toStdString();

    pool->changeWorkerPosition(departmentName, workerName, workerNewPosition);
    close();
}

void change_worker::on_ChangeSalary_clicked() {
    departmentName = ui->departmentName->text().toStdString();
    workerName = ui->workerLastName->text().toStdString();
    workerNewSalary = ui->salaryWorkerNew->text().toInt();

    pool->changeWorkerSalary(departmentName, workerName, workerNewSalary);
    close();
}

