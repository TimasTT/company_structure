//
// Created by timas on 16.08.2021.
//

#include <QListWidget>
#include <iostream>

#include "commands_tasks.hpp"
#include "company_structure.hpp"

ShowCompany::ShowCompany(const std::shared_ptr<cstruct::Company>& company_, QListWidget* widget_){
    widget_->clear();
    std::vector<std::string> companyTree;
    company_->showCompany(companyTree);

    for (const auto& i : companyTree) {
        widget_->addItem(QString::fromStdString(i));

        if (company_->getDepartment(i).isEmpty()) {
            widget_->addItem("No workers in this department");
        } else {
            widget_->addItem("Workers number: " + QString::number(company_->getDepartment(i).getWorkersNumber()));
            widget_->addItem("AverageSalary: " + QString::number(company_->getDepartment(i).getAvrgSalary()));
            widget_->addItem("Workers:");
            int workersCnt = 1;
            for (auto& worker : company_->getDepartment(i).getDepartment()) {
                widget_->addItem(QString::number(workersCnt++) + ". Name: " + QString::fromStdString(worker.getName()));
                widget_->addItem("Position: " + QString::fromStdString(worker.getPosition()));
                widget_->addItem("Salary: " + QString::number(worker.getSalary()));
            }
        }

        widget_->addItem("");
    }
}


AddDepartment::AddDepartment(QListWidget* widget_, int task_id_, std::string& departmentName_, std::shared_ptr<cstruct::Company>& company_)
    : widget(widget_), task_id(task_id_), departmentName(departmentName_), company(company_) {}

void AddDepartment::redo(){
    company->addDepartment(departmentName);

    ShowCompany show(company, widget);
}

void AddDepartment::undo() {
    company->deleteDepartment(departmentName);

    ShowCompany show(company, widget);
}


DeleteDepartment::DeleteDepartment(QListWidget* widget_, int task_id_, std::string& departmentName_, std::shared_ptr<cstruct::Company>& company_)
    : widget(widget_), task_id(task_id_), departmentName(departmentName_), company(company_) {}

void DeleteDepartment::redo(){
    company->deleteDepartment(departmentName);

    ShowCompany show(company, widget);
}

void DeleteDepartment::undo() {
    company->addDepartment(departmentName);

    ShowCompany show(company, widget);
}


AddWorker::AddWorker(QListWidget* widget_, int task_id_, std::string &departmentName_, std::string &workerName_,
                     std::string &workerPosition_, int workerSalary_, std::shared_ptr<cstruct::Company>& company_)
    : widget(widget_), task_id(task_id_), departmentName(departmentName_), workerName(workerName_), workerPosition(workerPosition_),
      workerSalary(workerSalary_), company(company_) {}

void AddWorker::redo() {
    for (auto& department : company->getCompany()) {
        if (department.getName() == departmentName) {
            cstruct::Worker worker(workerName, workerPosition, workerSalary);
            department.addWorker(std::move(worker));
            department.recalculateAvrgSalary();
        }
    }

    ShowCompany show(company, widget);
}

void AddWorker::undo() {
    for (auto& department : company->getCompany()) {
        if (department.getName() == departmentName) {
            department.deleteWorker(workerName);
            department.recalculateAvrgSalary();
        }
    }

    ShowCompany show(company, widget);
}


DeleteWorker::DeleteWorker(QListWidget* widget_, int task_id_, std::string &departmentName_, std::string &workerName_,
                     std::shared_ptr<cstruct::Company>& company_)
    : widget(widget_), task_id(task_id_), departmentName(departmentName_), workerName(workerName_), company(company_) {}

void DeleteWorker::redo() {
    for (auto& department : company->getCompany()) {
        if (department.getName() == departmentName) {
            for (auto &worker : department.getDepartment()) {
                if (worker.getName() == workerName) {
                    workerPosition = worker.getPosition();
                    workerSalary = worker.getSalary();
                    department.deleteWorker(workerName);
                    department.recalculateAvrgSalary();
                }
            }
        }
    }

    ShowCompany show(company, widget);
}

void DeleteWorker::undo() {
    for (auto& department : company->getCompany()) {
        if (department.getName() == departmentName) {
            cstruct::Worker worker(workerName, workerPosition, workerSalary);
            department.addWorker(std::move(worker));
            department.recalculateAvrgSalary();
        }
    }

    ShowCompany show(company, widget);
}


ChangeDepartmentName::ChangeDepartmentName(QListWidget* widget_, int task_id_, std::string &departmentLastName_,
                                           std::string &departmentNewName_, std::shared_ptr<cstruct::Company> &company_)
    :widget(widget_), task_id(task_id_), departmentLastName(departmentLastName_), departmentNewName(departmentNewName_), company(company_) {}

void ChangeDepartmentName::redo() {
    for (auto& department : company->getCompany()) {
        if (department.getName() == departmentLastName) {
            department.setNewName(departmentNewName);
        }
    }

    ShowCompany show(company, widget);
}

void ChangeDepartmentName::undo() {
    for (auto& department : company->getCompany()) {
        if (department.getName() == departmentNewName) {
            department.setNewName(departmentLastName);
        }
    }

    ShowCompany show(company, widget);
}
