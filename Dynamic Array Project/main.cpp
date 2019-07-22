//
//  main.cpp
//  Dynamic Array Project
//
//  Created by Blake Williams on 3/26/19.
//  Copyright © 2019 Blake Williams. All rights reserved.
//

//#include <iostream>
//#include "dynarray.h"
//using namespace std;
//
//int main()
//{
//    // Create a default vector (cap = 2)
//    DynArray sam;
//    cout << "capacity = " << sam.capacity() << endl;
//
//    // push some data into sam
//    cout << "\nPushing three values into sam";
//    sam.push_back(21);
//    sam.push_back(31);
//    sam.push_back(41);
//
//    cout << "\nThe values in sam are: ";
//
//    // test for out of bounds condition here
//    for (int i = 0; i < sam.size() + 1; i++)
//    {
//        try
//        {
//            cout << sam.at(i) << " ";
//        }
//        catch(runtime_error& x)
//        {
//            cout << x.what() << endl;
//        }
//    }
//    cout << "\n--------------\n";
//
//    // clear sam and display its size and capacity
//    sam.clear();
//    cout << "\nsam has been cleared.";
//    cout << "\nSam's size is now " << sam.size();
//    cout << "\nSam's capacity is now " << sam.capacity() << endl;
//    cout << "---------------\n";
//
//    // Push 12 values into the vector - it should grow
//    cout << "\nPush 12 values into sam.";
//    for (int i = 0; i < 12; i++)
//        sam.push_back(i);
//
//    DynArray phillip = sam;
//
//    cout << "\nSam's size is now " << phillip.size();
//    cout << "\nSam's capacity is now " << phillip.capacity() << endl;
//    cout << "---------------\n";
//
//    cout << "\nTest to see if contents are correct...";
//    // display the values in the vector
//    cout << phillip.front() << phillip.back() << endl;
//    for (int i = 0; i < phillip.size( ); i++)
//    {
//        cout << phillip.at(i) << " ";
//    }
//    cout << "\n--------------\n";
//
//    cout << "\nTest pop_back...";
//    // display the values in the vector
//    sam.pop_back();
//    for (int i = 0; i < sam.size( ); i++)
//    {
//        cout << sam.at(i) << " ";
//    }
//    cout << endl;
//}

#include <iostream>
#include "dynarray.h"
using namespace std;

int main( )
{
    const char START = 'A';
    const int MAX = 12;

    // create a vector of chars
    DynArray<char> vectD;

    // push some values into the vector
    for (int i = 0; i < MAX; i++)
    {
        vectD.push_back(START + i);
    }

    // remove the last element
    vectD.pop_back();

    // add another value
    vectD.push_back('Z');

    // test memory management
    DynArray<char> vectD2 = vectD;
    // display the contents
    cout << "\n[";
    for (int i = 0; i < vectD2.size() - 1; i++)
    {
        cout << vectD2.at(i) << ", ";
    }

    cout << "..., " << vectD2.back() << "]\n";

    DynArray<char> vectD3;
    vectD3 = vectD2;
    cout << "\n[";
    for (int i = 0; i < vectD3.size() - 1; i++)
    {
        cout << vectD3.at(i) << ", ";
    }
    cout << "..., " << vectD3.back() << "]\n";

    vectD3.front() = '{';
    vectD3.back() = '}';
    cout << vectD3.front();
    for (int i = 1; i < vectD3.size() - 2; i++)
    {
        cout << vectD3.at(i) << ", ";
    }
    cout << vectD3.at(vectD3.size()-2) << vectD3.back() << endl;
}
