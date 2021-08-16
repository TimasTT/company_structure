//
// Created by timas on 16.08.2021.
//

#include <QListWidget>

#include "commands_tasks.hpp"
#include "company_structure.hpp"

STask::STask(QListWidget* widget_, int task_id_)
        : widget(widget_), task_id(task_id_) {
    //setText("Undo");
}

void STask::undo() {
    widget->addItem("ffff");
}

void STask::redo() {
    widget->addItem("lllll");
}


AddDepartment::AddDepartment(QListWidget* widget_, int task_id_, std::string& department_name_, std::shared_ptr<cstruct::Company>& company_)
    : widget(widget_), task_id(task_id_), department_name(department_name_), company(company_) {}

void AddDepartment::redo(){
    cstruct::Department newDepartment(department_name);
    company->addDepartment(std::move(newDepartment));

    std::vector<std::string> companyTree;
    company->showCompany(companyTree);

    for (const auto& i : companyTree) {
        widget->addItem(QString::fromStdString(i));
    }
}

void AddDepartment::undo() {
    company->deleteDepartment(department_name);

    std::vector<std::string> companyTree;
    company->showCompany(companyTree);

    for (const auto& i : companyTree) {
        widget->addItem(QString::fromStdString(i));
    }
}
