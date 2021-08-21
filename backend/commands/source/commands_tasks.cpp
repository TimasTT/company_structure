//
// Created by timas on 16.08.2021.
//

#include <QListWidget>
#include <iostream>

#include "commands_tasks.hpp"
#include "company_structure.hpp"

AddDepartment::AddDepartment(QListWidget* widget_, int task_id_, std::string& department_name_, std::shared_ptr<cstruct::Company>& company_)
    : widget(widget_), task_id(task_id_), department_name(department_name_), company(company_) {}

void AddDepartment::redo(){
    company->addDepartment(department_name);

    show();
}

void AddDepartment::undo() {
    company->deleteDepartment(department_name);

    show();
}

void AddDepartment::show() {
    widget->clear();
    std::vector<std::string> companyTree;
    company->showCompany(companyTree);

    for (const auto& i : companyTree) {
        widget->addItem(QString::fromStdString(i));
    }
}


DeleteDepartment::DeleteDepartment(QListWidget* widget_, int task_id_, std::string& department_name_, std::shared_ptr<cstruct::Company>& company_)
    : widget(widget_), task_id(task_id_), department_name(department_name_), company(company_) {}

void DeleteDepartment::redo(){
    company->deleteDepartment(department_name);

    show();
}

void DeleteDepartment::undo() {
    company->addDepartment(department_name);

    show();
}

void DeleteDepartment::show() {
    widget->clear();
    std::vector<std::string> companyTree;
    company->showCompany(companyTree);

    for (const auto& i : companyTree) {
        widget->addItem(QString::fromStdString(i));
    }
}
