//
// Created by timas on 10.08.2021.
//

#include <vector>

#include "company_structure.hpp"

namespace cstruct {

    Worker::Worker(std::string &name_, std::string &position_, int salary_)
            : name(name_), position(position_), salary(salary_) {}


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
        auto avrgSalaryCalculation = [&](const std::vector <Worker> &workers_) {
            int avrgSalary_ = 0;
            for (const auto &worker : workers_) {
                avrgSalary_ += worker.salary;
            }

            return avrgSalary_ / workers_.size();
        };

        avrgSalary = avrgSalaryCalculation(workers);
    }

    const std::string& Department::getName() {
        return name;
    }

    const std::vector <Worker> &Department::getDepartment() {
        return workers;
    }


    Company::Company() = default;

    const std::vector<Department> &Company::getCompany() {
        return company;
    }

    void Company::addDepartment(Department &&department_) {
        company.emplace_back(std::move(department_));
    }

    void Company::deleteDepartment(std::string& name) {
        for (size_t i = 0; i < getCompany().size(); ++i) {
            if (getCompany()[i].name == name) {
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
}
