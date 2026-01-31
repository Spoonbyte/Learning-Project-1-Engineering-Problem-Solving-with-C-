/*
File: CH4EOC4.32.cpp
Desc: This is the answer from Chegg
Author: spoonais
Date: 07/11/24 @12:05pm
*/

#include<iostream>
using namespace std;

int main()
{
    //Decalare and Init objects:
    bool A(false), B(false), C(false), D(false);
    bool condition_taut(true);
    bool condition = (A&&B || B&&C || C&&D);

    //Create the header
    cout << "------------------------------" << endl;
    cout << "A \t B \t C \t D \t\t A&&B || B&&C" << endl;
    cout << "------------------------------" << endl;

    //Create the logic to fill out the table
    for (int i=1; i<=2; ++i)
    {
        for (int j=1; j<=2; ++j)
        {
            for (int k=1; k<=2; ++k)
            {
                for (int l=1; l<=2; ++l)
                {
                    condition = (A&&B || B&&C || C&&D);
                    cout << A << "\t" << B << "\t" << C << "\t" << D << "\t\t" << condition << endl;
                    if(!condition) condition_taut = false;
                    D = !D;
                }
                C =!C;
            }
            B=!B;
        }
        A = !A;
    }

    //Pause output screen
    system("pause");

    //Exit 
    return(0);
}
