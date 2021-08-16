//
// Created by timas on 16.08.2021.
//

#ifndef COMPANY_STRUCTURE_COMMANDS_TASKS_HPP
#define COMPANY_STRUCTURE_COMMANDS_TASKS_HPP

#include <QUndoCommand>

#include "company_structure.hpp"

class QListWidget;

class AddDepartment: public QUndoCommand {
private:
    QListWidget* widget;

    int task_id;

    std::string department_name;

    std::shared_ptr<cstruct::Company> company;

public:
    AddDepartment(QListWidget*, int, std::string &, std::shared_ptr<cstruct::Company>&);

    void undo();

    void redo();
};

#endif //COMPANY_STRUCTURE_COMMANDS_TASKS_HPP
