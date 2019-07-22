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
#include "Employee.h"

using namespace std;


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Abstract Employee Base ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


Employee::Employee(int empNum, string name, string address, string phone){
    this->empNum = empNum;
    this->name = name;
    this->address = address;
    this->phone = phone;
}


int Employee::getEmpNum() const{
    return empNum;
}
const string Employee::getName() const{
    return name;
}
const string Employee::getAddress() const{
    return address;
}
const string Employee::getPhone() const{
    return phone;
}


void Employee::setName(const string name){
    this->name = name;
}
void Employee::setAddress(const string address){
    this->address = address;
}
void Employee::setPhone(const string phone){
    this->phone = phone;
}
void Employee::setEmpNum(int empN){
    this->empNum = empN;
}



void Employee::printCheck() const{
    cout << fixed << setprecision(2);
    cout << "\n....................UVU Computer Science Dept.................................\n\n\nPay to the order of " << getName() << "....................................$" << calcPay();
    cout << "\n\n\nUnited Community Credit Union\n..............................................................................\n\n";
}

void Employee::write(ofstream& outFS){
    outFS << empNum << endl;
    outFS << name << endl;
    outFS << address << endl;
    outFS << phone << endl;
}

double Employee::calcPay() const{
    return -1;
}

void Employee::readData(ifstream& inFS){
    int e;
    string na;
    string ad;
    string ph;
    
    inFS >> e;
    this->setEmpNum(e);
    inFS.get();
    getline(inFS,na);
    this->setName(na);
    getline(inFS,ad);
    this->setAddress(ad);
    getline(inFS,ph);
    this->setPhone(ph);
    if(inFS.fail()){
        inFS.clear();
        inFS.ignore(1000,'\n');
        throw runtime_error("invalid data");
    }
}






//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Hourly Employee ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~



HourlyEmployee::HourlyEmployee(int empNum, string name, string address, string phone, double hourlyWage, double hoursWorked){
    this->setEmpNum(empNum);
    this->setName(name);
    this->setAddress(address);
    this->setPhone(phone);
    this->setHourlyWage(hourlyWage);
    this->setHoursWorked(hoursWorked);
}


double HourlyEmployee::getHourlyWage() const{
    return hourlyWage;
}
double HourlyEmployee::getHoursWorked() const{
    return hoursWorked;
}


void HourlyEmployee::setHourlyWage(double wage){
    hourlyWage = wage;
}
void HourlyEmployee::setHoursWorked(double hours){
    hoursWorked = hours;
}


void HourlyEmployee::printCheck() const{
    Employee::printCheck();
    cout << "Hours worked: " << getHoursWorked() << endl;
    cout << "Hourly wage: " << getHourlyWage() << endl;
    cout << "\n\n\n";
}

double HourlyEmployee::calcPay() const{
    double pay;
    if(getHoursWorked()>40)
        pay = 40*getHourlyWage() + (getHoursWorked()-40)*1.5*getHourlyWage();
    else
        pay = getHourlyWage()*getHoursWorked();
    pay = pay-(pay*.275);
    return pay;
}

void HourlyEmployee::write(ofstream& outFS){
    Employee::write(outFS);
    outFS << hoursWorked << endl;
    outFS << hourlyWage << endl;
}

HourlyEmployee* HourlyEmployee::read(ifstream& inFS){
    try {
        HourlyEmployee* emp = new HourlyEmployee();
        emp->readData(inFS);
        return emp;
    } catch (runtime_error& excpt) {
        cout << excpt.what() << endl;
        return nullptr;
    }
}

void HourlyEmployee::readData(ifstream& inFS){
    Employee::readData(inFS);
    inFS >> this->hoursWorked >> this->hourlyWage;
    inFS.get();
}




//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Salaried Employee ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

SalariedEmployee::SalariedEmployee(int empNum, string name, string address, string phone, double salary){
    this->setEmpNum(empNum);
    this->setName(name);
    this->setAddress(address);
    this->setPhone(phone);
    this->setSalary(salary);
}


double SalariedEmployee::getSalary() const{
    return salary;
}


void SalariedEmployee::setSalary(double sa){
    salary = sa;
}


double SalariedEmployee::calcPay() const{
    return getSalary()-(getSalary()*.2)-(getSalary()*.075)-(getSalary()*.0524);
}

void SalariedEmployee::printCheck() const{
    Employee::printCheck();
    cout << "Salary: " << getSalary() << endl;
    cout << "\n\n\n";
}

void SalariedEmployee::write(ofstream& outFS){
    Employee::write(outFS);
    outFS << salary << endl;
}

SalariedEmployee* SalariedEmployee::read(ifstream& inFS){
    try {
        SalariedEmployee* emp = new SalariedEmployee();
        emp->readData(inFS);
        return emp;
    } catch (runtime_error& excpt) {
        cout << excpt.what() << endl;
        return nullptr;
    }
}

void SalariedEmployee::readData(ifstream &inFS){
    Employee::readData(inFS);
    inFS >> this->salary;
    inFS.get();
}
