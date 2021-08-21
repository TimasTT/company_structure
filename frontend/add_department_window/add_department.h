#ifndef ADD_DEPARTMENT_H
#define ADD_DEPARTMENT_H

#include <QDialog>

namespace Ui {
class add_department;
}

class add_department : public QDialog
{
    Q_OBJECT

public:
    explicit add_department(QWidget *parent = nullptr);
    ~add_department();

    std::string& getName();

private slots:
    void on_pushButton_clicked();

private:
    Ui::add_department *ui;

    std::string name;
};

#endif // ADD_DEPARTMENT_H
