/*
File: CH4EOC4.32_2.cpp
Desc: Recreate the Truth Table from CH3_1 using nested for loops attempt 2. Attempt 1 
(90 LOC) was way longer and harder to understand than the original code written in "chapter3_1" (54 LOC)
Author: spoonais
Date: 07/11/24 @12:05pm
*/

#include<iostream>
using namespace std;

int main()
{
    //Decalare and Init objects:
    bool A(false), B(false), C(false);

    //Create the header
    cout << "----------------------" << endl;
    cout << "A" << "\t" << "B" << "\t" << "C" << "\t" << "A&&B || B&&C" << endl;
    cout << "----------------------" << endl;

    //Create the logic to fill out the table
    for (int i=1; i<=8; ++i)
    {
        if (i == 1) //Prints the first row in table 
        {
            cout << A << "\t" << B << "\t" << C << "\t\t" << (A&&B || B&&C) << endl;
        }
            else //Prints the remaining 7 rows in table
            {
                C = !C;
                if (i == 3 || i == 5 || i == 7 ) //This is the correct way...not (i == 3||5||7) or (i == 3,5,7)
                {
                    B = !B;
                }
                if(i == 5)
                {
                    A = !A;
                }

                cout << A << "\t" << B << "\t" << C << "\t\t" << (A&&B || B&&C) << endl;

            }
    }

    //Exit 
    return(0);
}
