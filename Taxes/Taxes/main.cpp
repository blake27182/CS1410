//
//  main.cpp
//  Taxes
//
//  Created by Blake Williams on 1/10/19.
//  Copyright © 2019 Blake Williams. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

int main() {
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);
    double Income;
    char filingAs, adCalc='y';
    double tax=0, subtract=0, add=0, rate = 0;
    string filingAsName;
    
    do{
        while(true){
            cout << "Please enter in your taxable income.\n(This must be a positive value): ";
            cin >> Income;
            if (cin.fail()||Income<0){
                cin.clear();
                cin.ignore(1000,'\n');
            }else{
                break;
            }
        }
        
        while(true){
            cout << "\nPlease enter m if married and filing joint return, \nor s if filing a single return: ";
            cin >> filingAs;
            if (cin.fail()||(filingAs!='M'&&filingAs!='m'&&filingAs!='S'&&filingAs!='s')){
                cin.clear();
                cin.ignore(1000,'\n');
            }else{
                break;
            }
        }
        
        switch (filingAs){
            case 's':
            case 'S':
                filingAsName = "single";
                if(Income<=863){
                    subtract = 0;
                    add = 0;
                    rate = .023;
                }else if(Income<=2588){
                    subtract = 863;
                    add = 25;
                    rate = .033;
                }else if(Income<=4313){
                    subtract = 2588;
                    add = 85;
                    rate = .052;
                }else{
                    subtract = 4313;
                    add = 181;
                    rate = .075;
                }
                break;
            case 'M':
            case 'm':
                filingAsName = "joint";
                if(Income<=1726){
                    subtract = 0;
                    add = .023;
                    rate = 0;
                }else if(Income<=5176){
                    subtract = 1726;
                    add = 40;
                    rate = .033;
                }else if(Income<=8626){
                    subtract = 5176;
                    add = 175;
                    rate = .052;
                }else{
                    subtract = 8626;
                    add = 390;
                    rate = .075;
                }
                break;
        }
        
        tax = (Income - subtract) * rate + add;

        
    //    cout << setprecision(2) << fixed;
        
        while(true){
            cout << "\nYour taxable income is $" << Income << "\n" << "and you are filing a " << filingAsName << " return.\nYour income tax will be $" << tax << "\n\n" << "Would you like to do another calculation (y or n)?";
            cin >> adCalc;
            if(cin.fail()||(adCalc!='y'&&adCalc!='Y'&&adCalc!='N'&&adCalc!='n')){
                cin.clear();
                cin.ignore(1000,'\n');
            }else{
                break;
            }
        }
    }while(adCalc=='y'||adCalc=='Y');
}
