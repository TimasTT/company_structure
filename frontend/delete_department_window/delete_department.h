#ifndef DELETE_DEPARTMENT_H
#define DELETE_DEPARTMENT_H

#include <QDialog>

namespace Ui {
class delete_department;
}

class delete_department : public QDialog
{
    Q_OBJECT

public:
    explicit delete_department(QWidget *parent = nullptr);
    ~delete_department();

    std::string& getName();

private slots:
    void on_pushButton_clicked();

private:
    Ui::delete_department *ui;

    std::string name;
};

#endif // DELETE_DEPARTMENT_H
