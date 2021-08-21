//
// Created by timas on 10.08.2021.
//

#include <vector>
#include <iostream>

#include "company_structure.hpp"

namespace cstruct {

    Worker::Worker(std::string &name_, std::string &position_, int salary_)
            : name(name_), position(position_), salary(salary_) {}

    std::string& Worker::getName() {
        return name;
    }

    std::string& Worker::getPosition() {
        return position;
    }

    int Worker::getSalary() {
        return salary;
    }

    void Worker::setNewName(std::string &newName) {
        name = newName;
    }

    void Worker::setNewPosition(std::string &newPosition) {
        position = newPosition;
    }

    void Worker::setNewSalary(int newSalary) {
        salary = newSalary;
    }


    Department::Department(std::string& name_): name(name_) {
        avrgSalary = 0;
        workersNumber = 0;
    }

    void Department::addWorker(Worker &&worker_) {
        workers.emplace_back(std::move(worker_));
        workersNumber++;

        recalculateAvrgSalary();
    }

    void Department::recalculateAvrgSalary() {
        auto avrgSalaryCalculation = [&]() {
            if (workersNumber == 0) {
                return 0;
            }
            int avrgSalary_ = 0;
            for (auto &worker : workers) {
                avrgSalary_ += worker.salary;
            }

            return avrgSalary_ / workersNumber;
        };

        avrgSalary = avrgSalaryCalculation();
    }

    const std::string& Department::getName() {
        return name;
    }

    std::vector <Worker> &Department::getDepartment() {
        return workers;
    }

    void Department::showWorkers(std::vector<std::string> &workers_) {
        for (auto& worker : workers) {
            workers_.emplace_back(worker.name);
        }
    }

    bool Department::isEmpty() {
        if (workers.size() == 0) {
            return true;
        } else {
            return false;
        }
    }

    bool Department::isMember(std::string &workerName) {
        for (const auto &worker : workers) {
            if (worker.name == workerName) {
                return true;
            }
        }

        return false;
    }

    void Department::deleteWorker(std::string& workerName) {
        for (size_t i = 0; i < workers.size(); ++i) {
            if (workers[i].getName() == workerName) {
                workers.erase(workers.begin() + i);
                workersNumber--;
                break;
            }
        }
    }

    int Department::getWorkersNumber() {
        return workersNumber;
    }

    int Department::getAvrgSalary() {
        return avrgSalary;
    }

    void Department::setNewName(std::string &newName) {
        name = newName;
    }


    Company::Company() = default;

    std::vector<Department> &Company::getCompany() {
        return company;
    }

    void Company::addDepartment(std::string& name) {
        Department newDepartment(name);
        company.emplace_back(newDepartment);
    }

    void Company::deleteDepartment(std::string& name) {
        for (size_t i = 0; i < getCompany().size(); ++i) {
            if (company[i].name == name) {
                company.erase(company.begin() + i);
                break;
            }
        }
    }

    const std::vector<std::string>& Company::showCompany(std::vector<std::string>& companyTree) {
        for (const auto& department : getCompany()) {
            companyTree.push_back(department.name);
        }

        return companyTree;
    }

    bool Company::isMember(std::string &name) {
        for (size_t i = 0; i < getCompany().size(); ++i) {
            if (company[i].name == name) {
                return true;
            }
        }
        return false;
    }

    Department& Company::getDepartment(const std::string &name) {
        for (size_t i = 0; i < getCompany().size(); ++i) {
            if (company[i].name == name) {
                return company[i];
            }
        }
    }
}
