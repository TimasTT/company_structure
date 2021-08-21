#include "delete_department.h"
#include "ui_delete_department.h"

delete_department::delete_department(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::delete_department)
{
    ui->setupUi(this);
}

delete_department::~delete_department()
{
    delete ui;
}

void delete_department::on_pushButton_clicked()
{
    name = ui->departmentName->text().toStdString();
    close();
}

std::string& delete_department::getName() {
    return name;
}
