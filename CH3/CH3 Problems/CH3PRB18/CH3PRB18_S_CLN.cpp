/*
File: CH3PRB18_S_CLN.cpp
Desc: This is the version of the Chapter 3 Prb 18 code with Switch statements instead of if-else but I go through and try to clean the code up.
Author: spoonais
Date: 05/29/24 @4:38pm
*/

#include<iostream>
#include<cmath>
using namespace std;

//Decalare and Init objects:
    bool A(0), B(0), C(0);
    char x;

//Define the tautological condition based on states of A,B,C:
    char taut()
    {
        int AandBandC = (A&&B && B&&C);
            if (AandBandC == 1) 
            {
                x = '1';
            } else {
                x = '0';
            }
        return x;

    }
    
//Switch case function
    char myfunc()
    { 
        char taut;
        switch (x) //How is x able to be used here? Is it becuase I declared the scope as global vs local? I can understand this by using the simple "MyFunc.cpp" program I made
        {
            case ('0'):
                taut = 'N';
                break;
            case ('1'):
                taut = 'Y';
                break;
        }
        return taut;
    }

int main()
{

    //Create the header 
    cout << "A\tB\tC\t   A&&B || B&&C\t   Tautology?" << endl;
    cout << "===================================================" << endl;
    taut();
    cout << A << "\t" << B << "\t" << C << "\t\t" << (A&&B || B&&C) << "\t\t" << myfunc() << endl;

    //Toggle C
    C = !C;
    taut(); //Call taut() each time to calculate the new conditions based on the toggle that occurs:
    cout << A << "\t" << B << "\t" << C << "\t\t" << (A&&B || B&&C) << "\t\t" << myfunc() << endl;

    //Toggle C and B
    B = !B;
    C = !C;
    taut();
    cout << A << "\t" << B << "\t" << C << "\t\t" << (A&&B || B&&C) << "\t\t" << myfunc() << endl;

    //Toggle C
    C = !C;
    taut();
    cout << A << "\t" << B << "\t" << C << "\t\t" << (A&&B || B&&C) << "\t\t" << myfunc() << endl;

    //Toggle A, B, C
    A = !A;
    B = !B;
    C = !C;
    taut();
    cout << A << "\t" << B << "\t" << C << "\t\t" << (A&&B || B&&C) << "\t\t" << myfunc() << endl;

    //Toggle C
    C = !C;
    taut();
    cout << A << "\t" << B << "\t" << C << "\t\t" << (A&&B || B&&C) << "\t\t" << myfunc() << endl;

    //Toggle C and B
    B = !B;
    C = !C;
    taut();
    cout << A << "\t" << B << "\t" << C << "\t\t" << (A&&B || B&&C) << "\t\t" << myfunc() << endl;

    //Toggle C
    C = !C;
    taut();
    cout << A << "\t" << B << "\t" << C << "\t\t" << (A&&B || B&&C) << "\t\t" << myfunc() << endl;

}