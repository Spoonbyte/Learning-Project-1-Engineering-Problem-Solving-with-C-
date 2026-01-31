/*
File: chapter3_1.cpp
Desc: To create a truth table for A&&B || B&&C based on user inputs
Author:spoonais
Date: 05/03/24
*/

#include<iostream>
using namespace std;

int main()
{
    //Decalre and Initialize objects
    bool A(false), B(false), C(false);
    
    //Print table header
    cout << "Table 3.2\n" << "A\t B\t C\t A&&!B\n" << endl;
    cout << "--------------------------------------------------" << endl;
    cout << A << "\t" << B << "\t" << C << "\t\t\t" << (A&&B || B&&C) << endl;

    //Toggle C
    C = !C;
    cout << A << "\t" << B << "\t" << C << "\t\t\t" << (A&&B || B&&C) << endl;

    //Toggle B & C
    B = !B;
    C = !C;
    cout << A << "\t" << B << "\t" << C << "\t\t\t" << (A&&B || B&&C) << endl;

    //Toggle C
    C = !C;
    cout << A << "\t" << B << "\t" << C << "\t\t\t" << (A&&B || B&&C) << endl;

    //Toggle A, B, C (1 0 0)
    A = !A;
    B = !B;
    C = !C;
    cout << A << "\t" << B << "\t" << C << "\t\t\t" << (A&&B || B&&C) << endl;

    //Toggle C (1 0 1)
    C = !C;
    cout << A << "\t" << B << "\t" << C << "\t\t\t" << (A&&B || B&&C) << endl;

    //Toggle C and B (1 1 0)
    B = !B;
    C = !C;
    cout << A << "\t" << B << "\t" << C << "\t\t\t" << (A&&B || B&&C) << endl;

    //Toggle  C
    C = !C;
    cout << A << "\t" << B << "\t" << C << "\t\t\t" << (A&&B || B&&C) << endl;


}