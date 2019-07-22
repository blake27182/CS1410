//
//  main.cpp
//  Employee Class
//
//  Created by Blake Williams on 2/4/19.
//  Copyright © 2019 Blake Williams. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <vector>
#include "Employee.hpp"
using namespace std;

int main() {
    ifstream inFS;
    ofstream outFS;
    vector<Employee> people;
    int userInput = 1;
    string fileName;
    
    
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
        Employee person1(37,"Joe Brown","123 Main St.","123-6788",10,45);
        Employee person2(21,"Sam Jones","45 East State","661-9000",12.0,30);
        Employee person3(15,"Mary Smith","12 High Street","401-8900",15.00,40.00);
        
        // write default employees to emplist
        outFS.open(fileName);
        person1.write(outFS);
        person2.write(outFS);
        person3.write(outFS);
        outFS.close();
        
        // finished creation
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
        while(inFS.peek()!=EOF){
            people.push_back(Employee::read(inFS));
        }
        inFS.close();
        
        // printer
        for (int i=0;i<people.size();i++){
            people.at(i).printCheck();
        }
    }else{
        throw runtime_error("invalid idiot");
    }
    
    return 0;
}
//        cout << "Employee Name: " << people.at(i).getName() << endl;
//        cout << "Employee Number: " << people.at(i).getEmployeeNumber() << endl;
//        cout << "Address: " << people.at(i).getAddr() << endl;
//        cout << "Phone: " << people.at(i).getPhone() << endl;
//
