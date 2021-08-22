#include "delete_worker.h"
#include "ui_delete_worker.h"

delete_worker::delete_worker(QWidget* parent)
        : QDialog(parent), ui(new Ui::delete_worker) {
    ui->setupUi(this);
}

delete_worker::~delete_worker() {
    delete ui;
}

void delete_worker::on_pushButton_clicked() {
    departmentName = ui->departmentName->text().toStdString();
    workerName = ui->workerName->text().toStdString();

    close();
}

std::string &delete_worker::getDepartmentName() {
    return departmentName;
}

std::string &delete_worker::getWorkerName() {
    return workerName;
}

