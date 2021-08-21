#include "change_department_name.h"
#include "ui_change_department_name.h"

change_department_name::change_department_name(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::change_department_name)
{
    ui->setupUi(this);
}

change_department_name::~change_department_name()
{
    delete ui;
}

void change_department_name::on_pushButton_clicked()
{
    departmentLastName = ui->departmentLastName->text().toStdString();
    departmentNewName = ui->departmentNewName->text().toStdString();

    close();
}

std::string& change_department_name::getDepartmentLastName() {
    return departmentLastName;
}

std::string& change_department_name::getDepartmentNewName() {
    return departmentNewName;
}

