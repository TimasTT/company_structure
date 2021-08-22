#ifndef DELETE_WORKER_H
#define DELETE_WORKER_H

#include <QDialog>

namespace Ui {
    class delete_worker;
}

class delete_worker: public QDialog {
    Q_OBJECT

public:
    explicit delete_worker(QWidget* parent = nullptr);

    ~delete_worker();

    std::string &getDepartmentName();

    std::string &getWorkerName();

private
    slots: void on_pushButton_clicked();

private:
    Ui::delete_worker* ui;

    std::string departmentName;

    std::string workerName;
};

#endif // DELETE_WORKER_H
