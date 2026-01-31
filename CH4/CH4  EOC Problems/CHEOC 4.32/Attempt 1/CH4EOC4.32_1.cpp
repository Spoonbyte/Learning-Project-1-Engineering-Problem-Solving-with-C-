/*
File: CH4EOC_Loops.cpp
Desc: Recreate the Truth Table from CH3_1 using nested for loops
Author: spoonais
Date: 07/08/24 @12:30pm
*/

#include<iostream>
using namespace std;

int main()
{
    //Decalare and Init objects:
    bool A(0), B(0), C(0), AandB(0), BandC(0);

    //Create the header
    cout << "----------------------" << endl;
    cout << "A" << "\t" << "B" << "\t" << "C" << "\t" << "A&&B || B&&C" << endl;
    cout << "----------------------" << endl;

    //Create the logic to fill out the table
  
    for (int j=1; j<=3; ++j)
    {
        
        if (j<=2)
        {
            B = B;

            if (j == 1)
            {
            C = C;
            } 
            else 
            {
                C = !C;
            }

            cout << A << "\t" << B << "\t" << C << "\t" << (A&&B || B&&C) << endl;

        } else {

            B = !B;

            for (int k=1; k<=2; ++k)
            {
                C = !C;
                cout << A << "\t" << B << "\t" << C << "\t" << (A&&B || B&&C) << endl;
            }

        }
        
    }

    //Toggle A then create new loop for toggled A
    A = !A;
    B = !B;

    for (int a=1; a<=3; ++a)
    {   
        if (a<=2)
        {
            if (a == 1)
            {
            C = !C;
            } 
            else 
            {
                C = !C;
            }

            cout << A << "\t" << B << "\t" << C << "\t" << (A&&B || B&&C) << endl;

        } else {

            B = !B;

            for (int b=1; b<=2; ++b)
            {
                C = !C;
                cout << A << "\t" << B << "\t" << C << "\t" << (A&&B || B&&C) << endl;
            }

        }
        
    }
        
    
}
