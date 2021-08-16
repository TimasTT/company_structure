//
// Created by timas on 16.08.2021.
//

#include <QListWidget>

#include "commands_tasks.hpp"

STask::STask(QListWidget* widget_, int task_id_)
        : widget(widget_), task_id(task_id_) {
    setText("Undo");
}

void STask::undo() {
    widget->addItem("ffff");
}

void STask::redo() {
    widget->addItem("lllll");
}
