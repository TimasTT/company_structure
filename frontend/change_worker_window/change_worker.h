#ifndef CHANGE_WORKER_H
#define CHANGE_WORKER_H

#include <QDialog>

namespace Ui {
    class change_worker;
}

class STaskPool;

class change_worker: public QDialog {
    Q_OBJECT

public:
    explicit change_worker(QWidget* parent = nullptr, STaskPool* pool_ = nullptr);

    change_worker(STaskPool* pool_);

    ~change_worker();

private
    slots: void on_pushButton_4_clicked();

    void on_changeName_clicked();

    void on_changePosition_clicked();

    void on_ChangeSalary_clicked();

private:
    Ui::change_worker* ui;

    STaskPool* pool;

    std::string departmentName;

    std::string workerName;

    std::string workerNewName;

    std::string workerNewPosition;

    int workerNewSalary;
};

#endif // CHANGE_WORKER_H
