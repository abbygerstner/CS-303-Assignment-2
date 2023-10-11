#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>

// Abstract base class for all employees
class Employee {
protected:
    std::string name;

public:
    Employee(std::string name);

    // Getter method for the employee's name
    std::string getName();

    virtual double calculateWeeklySalary() = 0;
    virtual double calculateHealthCareContributions() = 0;
    virtual int calculateVacationDays() = 0;
};

// Derived class for professional employees
class Professional : public Employee {
private:
    double monthlySalary;
    int vacationDays;

public:
    Professional(std::string name, double monthlySalary, int vacationDays);

    double calculateWeeklySalary() override;
    double calculateHealthCareContributions() override;
    int calculateVacationDays() override;
};

// Derived class for nonprofessional employees
class Nonprofessional : public Employee {
private:
    double hourlyRate;
    int hoursWorked;
    int vacationHoursEarned;

public:
    Nonprofessional(std::string name, double hourlyRate, int hoursWorked);

    double calculateWeeklySalary() override;
    double calculateHealthCareContributions() override;
    int calculateVacationDays() override;
};

#endif
