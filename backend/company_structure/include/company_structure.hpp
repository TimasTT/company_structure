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

        std::string& getName();

        std::string& getPosition();

        int getSalary();

        void setNewName(std::string &);

        void setNewPosition(std::string &);

        void setNewSalary(int);
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

        void deleteWorker(std::string &);

        void recalculateAvrgSalary();

        const std::string& getName();

        bool isEmpty();

        bool isMember(std::string &);

        std::vector <Worker> &getDepartment();

        int getWorkersNumber();

        int getAvrgSalary();

        void showWorkers(std::vector<std::string> &);

        void setNewName(std::string &);
    };


    class Company {
    private:
        std::vector<Department> company;

    public:
        Company();

        void addDepartment(std::string& name);

        void deleteDepartment(std::string &name);

        bool isMember(std::string &name);

        std::vector<Department>& getCompany();

        const std::vector<std::string>& showCompany(std::vector<std::string>&);

        Department& getDepartment(const std::string&);
    };

}

#endif //COMPANY_STRUCTURE_COMPANY_STRUCTURE_HPP
