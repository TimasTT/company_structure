//
// Created by timas on 10.08.2021.
//

#ifndef COMPANY_STRUCTURE_COMPANY_STRUCTURE_HPP
#define COMPANY_STRUCTURE_COMPANY_STRUCTURE_HPP

#include <string>
#include <vector>

#pragma once
#include "commands.hpp"

namespace cstruct {
    class Company;
    class Department;

    struct Worker {
    private:
        friend Department;

        std::string name;

        std::string position;

        int salary;

    private:
        Worker(std::string &, std::string &, int);
    };

    class Department {
    private:
        friend Company;

        std::vector <Worker> workers;

        int workersNumber;

        int avrgSalary;

        std::string name;

    private:
        Department(std::string &);

        void addWorker(Worker &&);

        void recalculateAvrgSalary();

        const std::vector <Worker> &getDepartment();
    };

    class Company {
    private:
        std::vector<Department> company;

    private:
        Company();

        void addDepartment(Department &&);

        const std::vector<Department>& getCompany();
    };

}

#endif //COMPANY_STRUCTURE_COMPANY_STRUCTURE_HPP
