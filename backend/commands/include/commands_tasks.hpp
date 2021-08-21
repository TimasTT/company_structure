//
// Created by timas on 16.08.2021.
//

#ifndef COMPANY_STRUCTURE_COMMANDS_TASKS_HPP
#define COMPANY_STRUCTURE_COMMANDS_TASKS_HPP

#include <QUndoCommand>

#include "company_structure.hpp"

class QListWidget;

class ShowCompany {
public:
    ShowCompany(const std::shared_ptr<cstruct::Company>&, QListWidget*);
};


class AddDepartment: public QUndoCommand {
private:
    QListWidget* widget;

    int task_id;

    std::string departmentName;

    std::shared_ptr<cstruct::Company> company;

public:
    AddDepartment(QListWidget*, int, std::string &, std::shared_ptr<cstruct::Company>&);

    void undo();

    void redo();
};


class DeleteDepartment: public QUndoCommand {
private:
    QListWidget* widget;

    int task_id;

    std::string departmentName;

    std::shared_ptr<cstruct::Company> company;

public:
    DeleteDepartment(QListWidget*, int, std::string &, std::shared_ptr<cstruct::Company>&);

    void undo();

    void redo();
};


class AddWorker: public QUndoCommand {
private:
    QListWidget* widget;

    int task_id;

    std::string departmentName;

    std::string workerName;

    std::string workerPosition;

    int workerSalary;

    std::shared_ptr<cstruct::Company> company;

public:
    AddWorker(QListWidget*, int, std::string &, std::string &, std::string &, int, std::shared_ptr<cstruct::Company>&);

    void undo();

    void redo();
};


class DeleteWorker: public QUndoCommand {
private:
    QListWidget* widget;

    int task_id;

    std::string departmentName;

    std::string workerName;

    std::string workerPosition;

    int workerSalary;

    std::shared_ptr<cstruct::Company> company;

public:
    DeleteWorker(QListWidget*, int, std::string &, std::string &, std::shared_ptr<cstruct::Company>&);

    void undo();

    void redo();
};


class ChangeDepartmentName: public QUndoCommand {
private:
    QListWidget* widget;

    int task_id;

    std::string departmentLastName;

    std::string departmentNewName;

    std::shared_ptr<cstruct::Company> company;

public:
    ChangeDepartmentName(QListWidget*, int, std::string &, std::string &, std::shared_ptr<cstruct::Company>&);

    void undo();

    void redo();
};


class ChangeWorker: public QUndoCommand {
private:
    QListWidget* widget;

    int task_id;

    std::string departmentName;

    std::string workerLastName;

    std::string workerNewName;

    std::string workerLastPosition;

    std::string workerNewPosition;

    int workerLastSalary;

    int workerNewSalary;

    std::shared_ptr<cstruct::Company> company;

public:
    ChangeWorker(QListWidget*, int, std::string &, std::string &, std::string&, std::string &, int, std::shared_ptr<cstruct::Company>&);

    void undo();

    void redo();
};

#endif //COMPANY_STRUCTURE_COMMANDS_TASKS_HPP
