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

void STaskPool::addDepartment(std::string &department_name) {
    AddDepartment* task = new AddDepartment(widget, last_id++, department_name, company);
    stack.push(task);
}

void STaskPool::deleteDepartment(std::string &department_name) {
    if (!company->isMember(department_name)) {
        return;
    }

    DeleteDepartment* task = new DeleteDepartment(widget, last_id++, department_name, company);
    stack.push(task);
}
