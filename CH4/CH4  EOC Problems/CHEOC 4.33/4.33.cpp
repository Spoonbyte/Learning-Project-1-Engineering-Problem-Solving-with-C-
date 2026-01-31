/*
File: 4.33.cpp
Desc: This is to redo CH4_5 using a do/while loop.
Author: spoonais
Date: 07/12/24 @2:46pm
*/

#include<iostream>
#include<cmath>
using namespace std;

int main()
{
    //Decalare and Init objects:
    const double c(299792458.0);
    int SatID(0), i(1), Store_ID(0);
    double ms_tran(0), sec_tran(0), P(0), store_P(0);

    do 
    {
        //Get the user input
        cout << "Please provide the Satellite ID" << endl;
        cin >> SatID;
        cout << "Please provide the transit time for Satellite" << endl;
        cin >> ms_tran;

        //Conversion of millisec to seconds
        sec_tran = ms_tran/1000;

        //Calculate the pseudorange in m
        P = sec_tran * c;

        //Print pseudorange
        cout << "Pseudorange for Satellite " << SatID << " is " << P << " meters " << endl;
        cout << "----------------------------------------------------------------" << endl;

        //Use switch case to determine the closest satellite:
        switch(i)
        {
            case 1:
                store_P = P;
                Store_ID = SatID;
                break;
            case 2 ... 4:
                if (P < store_P)
                {
                    store_P = P;
                    Store_ID = SatID;
                }
                break;
        }

        //Increment sentinal
        i++;

    } while ( i<=4 );
    
    cout << "The closest satellite: " << Store_ID << " at " << store_P << " meters " << endl;
    

}