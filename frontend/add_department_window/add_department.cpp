#include "add_department.h"
#include "ui_add_department.h"

add_department::add_department(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::add_department)
{
    ui->setupUi(this);
}

add_department::~add_department()
{
    delete ui;
}

void add_department::on_pushButton_clicked()
{
    name = ui->departmentName->text().toStdString();
    close();
}

std::string& add_department::getName() {
    return name;
}

