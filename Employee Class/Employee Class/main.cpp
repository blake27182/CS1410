//
//  main.cpp
//  Employee Class
//
//  Created by Blake Williams on 2/4/19.
//  Copyright © 2019 Blake Williams. All rights reserved.
//

#include <iostream>
#include "Employee.hpp"
using namespace std;

int main() {
    Employee person1(37,"Joe Brown","123 Main St.","123-6788",10,45);
    Employee person2(37,"Sam Jones","45 East State","661-9000",12.5,30);
    
    cout << "Employee Name: " << person1.getName() << endl;
    cout << "Employee Number: " << person1.getEmployeeNumber() << endl;
    cout << "Address: " << person1.getAddr() << endl;
    cout << "Phone: " << person1.getPhone() << endl;
    
    person1.printCheck();
    
    cout << "\n\n\nEmployee Name: " << person2.getName() << endl;
    cout << "Employee Number: " << person2.getEmployeeNumber() << endl;
    cout << "Address: " << person2.getAddr() << endl;
    cout << "Phone: " << person2.getPhone() << endl;
    
    person2.printCheck();
    return 0;
}
