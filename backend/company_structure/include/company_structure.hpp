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

    class Worker {
    private:
        friend Department;

        std::string name;

        std::string position;

        int salary;

    public:
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

        const std::string& getName();

        const std::vector <Worker> &getDepartment();
    };

    class Company {
    private:
        std::vector<Department> company;

    public:
        Company();

        void addDepartment(Department &&);

        void deleteDepartment(std::string& name);

        const std::vector<Department>& getCompany();

        const std::vector<std::string>& showCompany(std::vector<std::string>&);
    };

}

#endif //COMPANY_STRUCTURE_COMPANY_STRUCTURE_HPP
