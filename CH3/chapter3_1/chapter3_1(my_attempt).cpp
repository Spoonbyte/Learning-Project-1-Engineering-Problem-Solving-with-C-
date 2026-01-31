/*
File: chapter3_1.cpp
Desc: To create a truth table for A&&B || B&&C based on user inputs
Author:spoonais
Date: 04/29/24
*/

#include<iostream>
using namespace std;

int main()
{
    //Declare and Init objects
    int A,B,C;
    int AandB, BandC, AandB_BandC;

    //Get values for A, B, C:
    cout << "Provide a value for A, either 0 or 1" << endl;
    cin >> A;
    cout << "Provide a value for B, either 0 or 1" << endl;
    cin >> B;
    cout << "Provide a value for C, either 0 or 1" << endl;
    cin >> C;

    //Compute the A&&B logic
    if (A == 1 && B == 1)
    {
        AandB = 1;
    } else {
        AandB = 0;
    }

    //Compute the B&&C logic
    if (B == 1 && C == 1)
    {
        BandC = 1;
    } else {
        BandC = 0;
    }

    //Compute the OR logic
    if (AandB == 1 && BandC == 0 || AandB == 0 && BandC == 1 || AandB == 1 && BandC == 1) 
    {
        AandB_BandC = 1;

    } else {
        AandB_BandC = 0;
    }

    //Print the result:
    cout << "The result is: " << AandB_BandC << endl;
}