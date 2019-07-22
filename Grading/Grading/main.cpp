//
//  main.cpp
//  Grading
//
//  Created by Blake Williams on 1/12/19.
//  Copyright © 2019 Blake Williams. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;

void InputCheck(int& value, string message, int low=0){
    cout << '\n' << message;
    cin >> value;
    while(cin.fail()||value>100||value<low){
        cin.clear();
        cin.ignore(1000,'\n');
        if(value>100||value<low)
            cout << "\nSorry, your input must be between 0 and 100. Please try again." << endl;
        else
            cout << "\nSorry, your input must be an integer. Please try again." << endl;
        cout << message;
        cin >> value;
    }
}

int FindMedianScore(vector<int>& scores){
    int temp;
    bool change = false;
    do{
        for (int i=0;i<scores.size()-1;i++){
            if(scores.at(i)>scores.at(i+1)){
                temp = scores.at(i);
                scores.at(i)=scores.at(i+1);
                scores.at(i+1)=temp;
                change = true;
            }
            else{
                change = false;
            }
        }
    }while(change);
    
    if(scores.size()%2==1)
        return scores.at(scores.size()/2);
    else
        return (scores.at((scores.size()/2)-1)+scores.at(scores.size()/2))/2;
}

string CalculateLetterGrade(int points){
    if(points<=180)
        return "fail";
    else if(points<=200)
        return "D-";
    else if(points<=220)
        return "D";
    else if(points<=240)
        return "D+";
    else if(points<=260)
        return "C-";
    else if(points<=280)
        return "C";
    else if(points<=300)
        return "C+";
    else if(points<=320)
        return "B-";
    else if(points<=340)
        return "B";
    else if(points<=360)
        return "B+";
    else if(points<=380)
        return "A-";
    else
        return "A";
}

int main() {
    int exam1, exam2, exam3, temp;
    vector<int> homeworks;
    
    cout << "Dr. DoLittle's Grading Program .....\n";
    
    InputCheck(exam1,"Please enter in the score for the first exam: ");
    
    InputCheck(exam2,"Please enter in the score for the second exam: ");
    
    InputCheck(exam3,"Please enter in the score for the final exam: ");
    
    InputCheck(temp,"Enter the score for a homework assignment: ",-1);
    while(temp!=-1){
        homeworks.push_back(temp);
        InputCheck(temp,"Enter the score for a homework assignment: ",-1);
    }
    
    cout << "\nThe median homework score was " << FindMedianScore(homeworks) << endl;
    cout << "The total points earned was " << FindMedianScore(homeworks)+exam1+exam2+exam3 << endl;
    cout << "The letter calculated letter grade is " << CalculateLetterGrade(FindMedianScore(homeworks)+exam1+exam2+exam3) << endl;
    
    return 0;
}
