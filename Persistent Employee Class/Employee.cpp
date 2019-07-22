//
//  Employee.cpp
//  Employee Class
//
//  Created by Blake Williams on 2/4/19.
//  Copyright © 2019 Blake Williams. All rights reserved.
//
#include <iostream>
#include <iomanip>
#include <fstream>
#include <stdexcept>
using namespace std;

#include "Employee.hpp"

Employee::Employee(int empNum, string name, string address, string phone, double hourlyWage, double hoursWorked){
    this->empNum = empNum;
    this->name = name;
    this->address = address;
    this->phone = phone;
    this->hourlyWage = hourlyWage;
    this->hoursWorked = hoursWorked;
}

Employee::Employee(){
    empNum = 37;
    name = "";
    address = "";
    phone = "";
    hourlyWage = 0;
    hoursWorked = 0;
}

void Employee::printCheck() const{
    cout << fixed << setprecision(2);
    cout << "\n....................UVU Computer Science Dept.................................\n\n\nPay to the order of " << getName() << "....................................$" << calcPay();
    cout << "\n\n\nUnited Community Credit Union\n..............................................................................\n\n";
    cout << "Hours worked: " << getHoursWorked() << endl;
    cout << "Hourly wage: " << getHourlyWage() << endl;
    cout << "\n\n\n";
}
double Employee::calcPay() const{
    double pay;
    if(getHoursWorked()>40)
        pay = 40*getHourlyWage() + (getHoursWorked()-40)*1.5*getHourlyWage();
    else
        pay = getHourlyWage()*getHoursWorked();
    pay = pay-(pay*.275);
    return pay;
}

Employee Employee::read(ifstream& inFS){
    int en;
    string na,ad,ph;
    double ly,wk;
    try {
        inFS >> en;
        inFS.get();
        getline(inFS,na);
        getline(inFS,ad);
        getline(inFS,ph);
        inFS >> ly >> wk;
        inFS.get();
    } catch (runtime_error& excpt) {
        cout << excpt.what() << endl;
        cout << "cannot read in file" << endl;
    }
    Employee temp (en,na,ad,ph,ly,wk);
    return temp;
}
void Employee::write(ofstream& outFS){
    outFS << empNum << endl;
    outFS << name << endl;
    outFS << address << endl;
    outFS << phone << endl;
    outFS << hourlyWage << endl;
    outFS << hoursWorked << endl;
}


int Employee::getEmployeeNumber() const{
    return empNum;
}
const std::string& Employee::getName() const{
    return name;
}
const std::string& Employee::getAddr() const{
    return address;
}
const std::string& Employee::getPhone() const{
    return phone;
}
double Employee::getHourlyWage() const{
    return hourlyWage;
}
double Employee::getHoursWorked() const{
    return hoursWorked;
}


void Employee::setName(const std::string& name){
    this->name = name;
}
void Employee::setAddr(const std::string& address){
    this->address = address;
}
void Employee::setPhone(const std::string& phone){
    this->phone = phone;
}
void Employee::setHourlyWage(double wage){
    hourlyWage = wage;
}
void Employee::setHoursWorked(double hours){
    hoursWorked = hours;
}
