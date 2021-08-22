#ifndef ADD_WORKER_WINDOW_H
#define ADD_WORKER_WINDOW_H

#include <QDialog>

namespace Ui {
    class add_worker_window;
}

class add_worker_window: public QDialog {
    Q_OBJECT

public:
    explicit add_worker_window(QWidget* parent = nullptr);

    ~add_worker_window();

    std::string &getDepartmentName();

    std::string &getWorkerName();

    std::string &getWorkerPosition();

    int getWorkerSalary();

private
    slots: void on_pushButton_clicked();

private:
    Ui::add_worker_window* ui;

    std::string departmentName;

    std::string workerName;

    std::string workerPosition;

    int workerSalary;
};

#endif // ADD_WORKER_WINDOW_H
