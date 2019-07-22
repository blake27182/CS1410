//
//  main.cpp
//  High-low guess
//
//  Created by Blake Williams on 9/13/18.
//  Copyright © 2018 Blake Williams. All rights reserved.
//

#include <iostream>
// following several lines for unit testing purposes
#include "RecursionCounter.h"
int RecursionCounter::currentDepth = 0;
int RecursionCounter::maxDepth = 0;
using namespace std;

// Enter your 4 functions here

void sorthelp(int a[], int start, int n){
    RecursionCounter rc;
    for(int i=start;i<n;i++){
        if (a[i] < a[start]){
            int temp = a[start];
            a[start] = a[i];
            a[i] = temp;
        }
    }
    if(start != n){
        sorthelp(a,++start,n);
    }
}

void mysort(int num[], int nelems){
    sorthelp(num, 0, nelems);
}

void GuessNumber(int lowVal, int highVal) {
    int midVal = ((highVal-lowVal)/2)+lowVal;
    char answer;
    if (highVal - lowVal == 2){
        cout << "Your number is " << midVal << endl;
    }else if (highVal - lowVal > 2){
    cout << "Is it " << midVal << " (l,y,h)?" << endl;
    cin >> answer;
        switch (answer){
            case 'h':
                GuessNumber(lowVal, midVal);
                break;
            case 'l':
                GuessNumber(midVal, highVal);
                break;
            case 'y':
                cout << "Your number is " << midVal << endl;
                break;
        }
    }else{
        cout << "You cheated!" << endl;
    }
}

void hilo(int n){
    GuessNumber(0, n);
}





int main() {
    // Guess a number between 1 and 100
    // Your hilo() will call a slightly modified GuessNumber
    cout << "Think of a number between 1 and 100 I will try and guess it with your help." << endl;
    hilo(100);
    
    // Sort an array
    // Your mysort() will call a recursive helper function.
    int a[] = {5,4,2,3,1};
    const int n = 5;
    mysort(a,n);
    cout << "Sorted result:\n";
    for (int n: a)
        cout << n << endl;
    cout << endl;
}
