//
// Created by timas on 16.08.2021.
//

#ifndef COMPANY_STRUCTURE_COMMANDS_TASKS_HPP
#define COMPANY_STRUCTURE_COMMANDS_TASKS_HPP

#include <QUndoCommand>

class QListWidget;

class STask: public QUndoCommand {
private:
    QListWidget* widget;

    int task_id;

public:
    STask(QListWidget*, int);

    void undo();

    void redo();
};


#endif //COMPANY_STRUCTURE_COMMANDS_TASKS_HPP
