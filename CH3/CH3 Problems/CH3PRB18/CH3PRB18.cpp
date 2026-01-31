/*
File:
Desc:
Author: spoonais
Date: 05/23/24 @3:34am
*/

#include<iostream>
#include<cmath>
using namespace std;

int main()
{
    //Decalare and Init objects:
    bool A(0), B(0), C(0);

    //Create the header 
    cout << "A\tB\tC\t   A&&B || B&&C\t   Tautology?" << endl;
    cout << "===================================================" << endl;
    if ((A&&B && B&&C) == 1)
    {
        cout << A << "\t" << B << "\t" << C << "\t\t" << (A&&B || B&&C) << "\t\t" << "YES" << endl;
    } else {
        cout << A << "\t" << B << "\t" << C << "\t\t" << (A&&B || B&&C) << "\t\t" << "NO" << endl;
    }
   
    //Toggle C
    C = !C;
    if ((A&&B && B&&C) == 1)
    {
        cout << A << "\t" << B << "\t" << C << "\t\t" << (A&&B || B&&C) << "\t\t" << "YES" << endl;
    } else {
        cout << A << "\t" << B << "\t" << C << "\t\t" << (A&&B || B&&C) << "\t\t" << "NO" << endl;
    }

    //Toggle C and B
    B = !B;
    C = !C;
    if ((A&&B && B&&C) == 1)
    {
        cout << A << "\t" << B << "\t" << C << "\t\t" << (A&&B || B&&C) << "\t\t" << "YES" << endl;
    } else {
        cout << A << "\t" << B << "\t" << C << "\t\t" << (A&&B || B&&C) << "\t\t" << "NO" << endl;
    }

    //Toggle C
    C = !C;
    if ((A&&B && B&&C) == 1)
    {
        cout << A << "\t" << B << "\t" << C << "\t\t" << (A&&B || B&&C) << "\t\t" << "YES" << endl;
    } else {
        cout << A << "\t" << B << "\t" << C << "\t\t" << (A&&B || B&&C) << "\t\t" << "NO" << endl;
    }

    //Toggle A, B, C
    A = !A;
    B = !B;
    C = !C;
    if ((A&&B && B&&C) == 1)
    {
        cout << A << "\t" << B << "\t" << C << "\t\t" << (A&&B || B&&C) << "\t\t" << "YES" << endl;
    } else {
        cout << A << "\t" << B << "\t" << C << "\t\t" << (A&&B || B&&C) << "\t\t" << "NO" << endl;
    }

    //Toggle C
    C = !C;
    if ((A&&B && B&&C) == 1)
    {
        cout << A << "\t" << B << "\t" << C << "\t\t" << (A&&B || B&&C) << "\t\t" << "YES" << endl;
    } else {
        cout << A << "\t" << B << "\t" << C << "\t\t" << (A&&B || B&&C) << "\t\t" << "NO" << endl;
    }

    //Toggle C and B
    B = !B;
    C = !C;
    if ((A&&B && B&&C) == 1)
    {
        cout << A << "\t" << B << "\t" << C << "\t\t" << (A&&B || B&&C) << "\t\t" << "YES" << endl;
    } else {
        cout << A << "\t" << B << "\t" << C << "\t\t" << (A&&B || B&&C) << "\t\t" << "NO" << endl;
    }

    //Toggle C
    C = !C;
    if ((A&&B && B&&C) == 1)
    {
        cout << A << "\t" << B << "\t" << C << "\t\t" << (A&&B || B&&C) << "\t\t" << "YES" << endl;
    } else {
        cout << A << "\t" << B << "\t" << C << "\t\t" << (A&&B || B&&C) << "\t\t" << "NO" << endl;
    }
}