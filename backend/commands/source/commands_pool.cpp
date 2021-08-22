//
// Created by timas on 12.08.2021.
//

#include <QListWidget>

#include "commands_pool.hpp"
#include "commands_tasks.hpp"

STaskPool::STaskPool(QObject* parent)
        : QObject(parent) {
    last_id = 0;
    redo_ = stack.createRedoAction(this, "Redo");
    undo_ = stack.createUndoAction(this, "Undo");

    company = std::make_shared<cstruct::Company>();
}

void STaskPool::setWidget(QListWidget* widget_) {
    widget = widget_;
}

QAction* STaskPool::getUndoCommand() {
    return undo_;
}

QAction* STaskPool::getRedoCommand() {
    return redo_;
}

void STaskPool::addDepartment(std::string &departmentName) {
    AddDepartment* task = new AddDepartment(widget, last_id++, departmentName, company);
    stack.push(task);
}

void STaskPool::deleteDepartment(std::string &departmentName) {
    if (!company->isMember(departmentName)) {
        return;
    }

    DeleteDepartment* task = new DeleteDepartment(widget, last_id++, departmentName, company);
    stack.push(task);
}

void STaskPool::addWorker(std::string &departmentName, std::string &workerName, std::string &workerPosition, int workerSalary) {
    if (!company->isMember(departmentName)) {
        return;
    }

    AddWorker* task = new AddWorker(widget, last_id++, departmentName, workerName, workerPosition, workerSalary, company);
    stack.push(task);
}

void STaskPool::deleteWorker(std::string &departmentName, std::string &workerName) {
    if (!company->isMember(departmentName)) {
        return;
    }
    if (!company->getDepartment(departmentName).isMember(workerName)) {
        return;
    }

    DeleteWorker* task = new DeleteWorker(widget, last_id++, departmentName, workerName, company);
    stack.push(task);
}

void STaskPool::changeDepartmentName(std::string &departmentLastName, std::string &departmentNewName) {
    if (!company->isMember(departmentLastName)) {
        return;
    }

    ChangeDepartmentName* task = new ChangeDepartmentName(widget, last_id++, departmentLastName, departmentNewName, company);
    stack.push(task);
}

void STaskPool::changeWorkerAll(std::string &departmentName, std::string &workerLastName, std::string &workerNewName,
                                std::string &workerNewPosition, int workerNewSalary) {
    if (!company->isMember(departmentName)) {
        return;
    }
    if (!company->getDepartment(departmentName).isMember(workerLastName)) {
        return;
    }

    ChangeWorkerAll* task = new ChangeWorkerAll(widget, last_id++, departmentName, workerLastName, workerNewName, workerNewPosition,
                                                workerNewSalary, company);
    stack.push(task);
}

void STaskPool::changeWorkerName(std::string &departmentName, std::string &workerLastName, std::string &workerNewName) {
    if (!company->isMember(departmentName)) {
        return;
    }
    if (!company->getDepartment(departmentName).isMember(workerLastName)) {
        return;
    }

    ChangeWorkerName* task = new ChangeWorkerName(widget, last_id++, departmentName, workerLastName, workerNewName, company);
    stack.push(task);
}

void STaskPool::changeWorkerPosition(std::string &departmentName, std::string &workerName, std::string &workerNewPosition) {
    if (!company->isMember(departmentName)) {
        return;
    }
    if (!company->getDepartment(departmentName).isMember(workerName)) {
        return;
    }

    ChangeWorkerPosition* task = new ChangeWorkerPosition(widget, last_id++, departmentName, workerName, workerNewPosition, company);
    stack.push(task);
}

void STaskPool::changeWorkerSalary(std::string &departmentName, std::string &workerName, int workerNewSalary) {
    if (!company->isMember(departmentName)) {
        return;
    }
    if (!company->getDepartment(departmentName).isMember(workerName)) {
        return;
    }

    ChangeWorkerSalary* task = new ChangeWorkerSalary(widget, last_id++, departmentName, workerName, workerNewSalary, company);
    stack.push(task);
}
