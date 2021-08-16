//
// Created by timas on 10.08.2021.
//

#ifndef COMPANY_STRUCTURE_COMPANY_STRUCTURE_HPP
#define COMPANY_STRUCTURE_COMPANY_STRUCTURE_HPP

#include <string>
#include <vector>

namespace cstruct {
    class Company;
    class Department;

    struct Worker {
        std::string name;

        std::string position;

        int salary;

        Worker(std::string &, std::string &, int);
    };

    class Department {
    private:
        friend Company;

        std::vector <Worker> workers;

        int workersNumber;

        int avrgSalary;

        std::string name;

    public:
        Department(std::string &);

        void addWorker(Worker &&);

        void recalculateAvrgSalary();

        const std::vector <Worker> &getDepartment();
    };

    class Company {
    private:
        std::vector<Department> company;

    public:
        Company();

        void addDepartment(Department &&);

        const std::vector<Department>& getCompany();
    };

}

#endif //COMPANY_STRUCTURE_COMPANY_STRUCTURE_HPP
