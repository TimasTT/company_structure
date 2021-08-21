#ifndef CHANGE_DEPARTMENT_NAME_H
#define CHANGE_DEPARTMENT_NAME_H

#include <QDialog>

namespace Ui {
class change_department_name;
}

class change_department_name : public QDialog
{
    Q_OBJECT

public:
    explicit change_department_name(QWidget *parent = nullptr);
    ~change_department_name();

    std::string& getDepartmentLastName();

    std::string& getDepartmentNewName();

private slots:
    void on_pushButton_clicked();

private:
    Ui::change_department_name *ui;

    std::string departmentNewName;

    std::string departmentLastName;
};

#endif // CHANGE_DEPARTMENT_NAME_H
