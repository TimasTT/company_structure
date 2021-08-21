#include "add_worker_window.h"
#include "ui_add_worker_window.h"

add_worker_window::add_worker_window(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::add_worker_window)
{
    ui->setupUi(this);
}

add_worker_window::~add_worker_window()
{
    delete ui;
}

void add_worker_window::on_pushButton_clicked()
{
    departmentName = ui->departmentName->text().toStdString();
    workerName = ui->workerName->text().toStdString();
    workerPosition = ui->workerPosition->text().toStdString();
    workerSalary = ui->workerSalary->text().toInt();

    close();
}

std::string& add_worker_window::getDepartmentName() {
    return departmentName;
}

std::string& add_worker_window::getWorkerName() {
    return workerName;
}

std::string& add_worker_window::getWorkerPosition() {
    return workerPosition;
}

int add_worker_window::getWorkerSalary() {
    return workerSalary;
}

