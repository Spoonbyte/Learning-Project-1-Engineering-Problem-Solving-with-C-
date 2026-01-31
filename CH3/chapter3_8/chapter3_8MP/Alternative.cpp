/*
File: Alternative.cpp
Desc: This is an alternative to the switch statements, instead use the if else statements.
Author: spoonais
Date: 05/16/24
*/

#include<iostream>
#include<stdlib.h>
using namespace std;

int main()
{
    //Decalare and init objects
    char code;
    double dollars, euros, pesos, lbs;

    //Get user input
    cout << "Please provide the conversion code" << endl;
    cout << "E => euros\nP => pesos\nS => pounds sterling" << endl;
    cin >> code;
    cout << "Please provide the dollar amount to convert" << endl;
    cin >> dollars;

    //Create the logic:
    if (toupper(code) == 'E')
    {
        euros = dollars * 0.92;
        cout << euros << endl;
    }
        else 
        {
            if (toupper(code) == 'P')
            {
                pesos = dollars * 16.69;
                cout << pesos << endl;
            }
                else
                {
                    if (toupper(code) == 'S')
                    {
                        lbs = dollars * 0.79;
                        cout << lbs << endl;
                    }
                        else 
                        {
                            cout << "Conversion code not recognized" << endl;
                        }
                }

        }
}