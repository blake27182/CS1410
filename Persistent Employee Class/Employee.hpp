//
//  Employee.hpp
//  Employee Class
//
//  Created by Blake Williams on 2/4/19.
//  Copyright © 2019 Blake Williams. All rights reserved.
//

#ifndef Employee_hpp
#define Employee_hpp

#include <stdio.h>
#include <string>

class Employee{
public:
    Employee(int empNum, std::string name, std::string address, std::string phone, double hourlyWage, double hoursWorked);
    Employee();
    int getEmployeeNumber() const;
    const std::string& getName() const;
    const std::string& getAddr() const;
    const std::string& getPhone() const;
    double getHourlyWage() const;
    double getHoursWorked() const;

    void setName(const std::string& name);
    void setAddr(const std::string& address);
    void setPhone(const std::string& phone);
    void setHourlyWage(double wage);
    void setHoursWorked(double hours);
    
    double calcPay() const;
    void printCheck() const;
    static Employee read(std::ifstream& inFS);
    void write(std::ofstream& outFS);
    
private:
    int empNum;
    std::string name;
    std::string address;
    std::string phone;
    double hourlyWage;
    double hoursWorked;
};
#endif /* Employee_hpp */
