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

void STaskPool::addTask() {
    STask* task = new STask(widget, 0);
    stack.push(task);
}

