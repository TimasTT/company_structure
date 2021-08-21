//
// Created by timas on 12.08.2021.
//

#ifndef COMPANY_STRUCTURE_COMMANDS_HPP
#define COMPANY_STRUCTURE_COMMANDS_HPP

#include <QObject>
#include <QUndoStack>
#include <QAction>

#include "company_structure.hpp"

class STask;
class QListWidget;

class STaskPool: public QObject {

private:
    QUndoStack stack;

    QListWidget* widget;

    int last_id;

    QAction* undo_;
    QAction* redo_;

    std::shared_ptr<cstruct::Company> company;

public:
    explicit STaskPool(QObject* parent = nullptr);

    void setWidget(QListWidget*);

    QAction* getUndoCommand();

    QAction* getRedoCommand();

    signals:

public
    slots:
    void addTask();

    void addDepartment(std::string &);

    void deleteDepartment(std::string &);
};


#endif //COMPANY_STRUCTURE_COMMANDS_HPP
