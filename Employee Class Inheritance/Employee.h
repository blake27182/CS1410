//
//  Employee.hpp
//  Employee Class
//
//  Created by Blake Williams on 2/4/19.
//  Copyright © 2019 Blake Williams. All rights reserved.
//

#ifndef Employee_h
#define Employee_h

#include <iostream>
#include <string>

using namespace std;

class Employee{
private:
    int empNum;
    string name;
    string address;
    string phone;
    
protected:
    Employee() = default;
    virtual void readData(ifstream& inFS);      // override
    Employee(int empNum, string name, string address, string phone);

public:
    virtual ~Employee() = default; // default
    
    int getEmpNum() const;
    const string getName() const;
    const string getAddress() const;
    const string getPhone() const;
    
    void setName(const string name);
    void setAddress(const string address);
    void setPhone(const string phone);
    void setEmpNum(int empNum);
    
    virtual double calcPay() const = 0;
    virtual void printCheck() const = 0;
    virtual void write(ofstream& outFS) = 0;
};



class HourlyEmployee : public Employee{
private:
    double hourlyWage;
    double hoursWorked;
    
protected:
    HourlyEmployee() = default;      // protected
    void readData(ifstream& inFS);   // override protected

public:
    ~HourlyEmployee() = default;
    HourlyEmployee(int empNum, std::string name, std::string address, std::string phone, double hourlyWage, double hoursWorked);
    
    double getHourlyWage() const;
    double getHoursWorked() const;
    
    void setHourlyWage(double wage);
    void setHoursWorked(double hours);
    
    void write(ofstream& outFS);       // override
    void printCheck() const;    // override
    double calcPay() const;   // override
    static HourlyEmployee* read(ifstream& inFS);
};



class SalariedEmployee : public Employee{
private:
    double salary;
    
protected:
    SalariedEmployee() = default;
    void readData(ifstream& inFS);   // override protected
    
public:
    ~SalariedEmployee() = default;
    SalariedEmployee(int empNum, std::string name, std::string address, std::string phone, double salary);
    
    double getSalary() const;
    
    void setSalary(double sa);
    
    void write(ofstream& outFS);    // override
    double calcPay() const;         // override
    void printCheck() const;        // override
    static SalariedEmployee* read(ifstream& inFS);
};

#endif /* Employee_hpp */
