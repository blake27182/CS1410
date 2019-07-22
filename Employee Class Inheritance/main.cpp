//
//  main.cpp
//  Employee Class Inheritance
//
//  Created by Blake Williams on 3/30/19.
//  Copyright © 2019 Blake Williams. All rights reserved.
//


#include <vector>
#include <fstream>
#include <stdexcept>
#include "Employee.h"

using namespace std;

int main() {
    int userInput;
    string fileName;
    ofstream outFS;
    ifstream inFS;
    vector<Employee*>staff;
    
    
    cout << "This program has two options:\n1 - Create a data file, or\n2 - Read data from a file and print paychecks.\nPlease enter (1) to create a file or (2) to print checks:";
    cin >> userInput;
    if((userInput!=1&&userInput!=2)||cin.fail()){
        cin.clear();
        cin.ignore(1000,'\n');
        throw runtime_error("invalid input");
    }
    if(userInput==1){
        cout << "\n\nPlease enter a file name: ";
        cin >> fileName;
        if(cin.fail()){
            cin.clear();
            cin.ignore(1000,'\n');
            throw runtime_error("invalid input");
        }
        
        // create 3 objects
        staff.push_back(new HourlyEmployee(1, "H. Potter", "Privet Drive", "201-9090", 12.00, 40.0));
        staff.push_back(new SalariedEmployee(2, "A. Dumbledore", "Hogwarts", "803-1230", 1200));
        staff.push_back(new HourlyEmployee(3, "R. Weasley", "The Burrow", "892-2000", 10.00, 40.0));
        staff.push_back(new SalariedEmployee(4, "R. Hagrid", "Hogwarts", "910-8765", 1000));
        
        // write employees to file
        outFS.open(fileName);
        for (unsigned int i=0;i<staff.size();i++){
            staff.at(i)->write(outFS);
        }
        outFS.close();
        
        // finished file creation
        cout << "\n\nData file created ... you can now run option 2.\n\n" << endl;
        
    }else if(userInput==2){
        cout << "\n\nPlease enter a file name: ";
        cin >> fileName;
        if(cin.fail()){
            cin.clear();
            cin.ignore(1000,'\n');
            throw runtime_error("invalid input");
        }
        
        // read file out to console
        try {
            inFS.open(fileName);
            if (!inFS.is_open())
                throw runtime_error("Couldn't open file for input");
        } catch (runtime_error& excpt){
            cout << excpt.what() << endl;
        }
        // load data into vector of objects
//        HourlyEmployee* hourly = nullptr;
//        SalariedEmployee* salaried = nullptr;
        staff.push_back(HourlyEmployee::read(inFS));
        staff.push_back(SalariedEmployee::read(inFS));
        staff.push_back(HourlyEmployee::read(inFS));
        staff.push_back(SalariedEmployee::read(inFS));
        inFS.close();
        
        // printer
        for (unsigned int i=0;i<staff.size();i++){
            staff.at(i)->printCheck();
        }
    }else{
        throw runtime_error("invalid user input");
    }
    
    return 0;
}
