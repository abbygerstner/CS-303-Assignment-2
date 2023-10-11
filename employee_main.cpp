#include <iostream>
#include <string>
#include "employee.h"

// Employee class
Employee::Employee(std::string name) : name(name) {}

std::string Employee::getName() {
    return name;
}

// Professional class
Professional::Professional(std::string name, double monthlySalary, int vacationDays) : Employee(name), monthlySalary(monthlySalary), vacationDays(vacationDays) {}

double Professional::calculateWeeklySalary() {
    return monthlySalary / 4.0; // Assuming 4 weeks in a month
}

double Professional::calculateHealthCareContributions() {
    return 100.0; // Example value for health care contributions
}

int Professional::calculateVacationDays() {
    return vacationDays;
}

// Nonprofessional class
Nonprofessional::Nonprofessional(std::string name, double hourlyRate, int hoursWorked) : Employee(name), hourlyRate(hourlyRate), hoursWorked(hoursWorked) {
    vacationHoursEarned = hoursWorked / 10; // Example rule: 1 vacation hour for every 10 hours worked
}

double Nonprofessional::calculateWeeklySalary() {
    return hourlyRate * hoursWorked;
}

double Nonprofessional::calculateHealthCareContributions() {
    return 50.0; // Example value for health care contributions
}

int Nonprofessional::calculateVacationDays() {
    return vacationHoursEarned / 8; // Assuming 8 hours make a day
}


int main() {
    Professional professionalEmployee("Ringo Starr", 5000.0, 10);
    Nonprofessional nonprofessionalEmployee("Rihanna", 20.0, 40);

    std::cout << "Professional Employee:\n";
    std::cout << "Name: " << professionalEmployee.getName() << std::endl;
    std::cout << "Weekly Salary: $" << professionalEmployee.calculateWeeklySalary() << std::endl;
    std::cout << "Health Care Contributions: $" << professionalEmployee.calculateHealthCareContributions() << std::endl;
    std::cout << "Vacation Days: " << professionalEmployee.calculateVacationDays() << std::endl;

    std::cout << "\nNonprofessional Employee:\n";
    std::cout << "Name: " << nonprofessionalEmployee.getName() << std::endl;
    std::cout << "Weekly Salary: $" << nonprofessionalEmployee.calculateWeeklySalary() << std::endl;
    std::cout << "Health Care Contributions: $" << nonprofessionalEmployee.calculateHealthCareContributions() << std::endl;
    std::cout << "Vacation Days: " << nonprofessionalEmployee.calculateVacationDays() << std::endl;

    return 0;
}
