/*
File: GPS.cpp   
Desc: To calcualte the pseudorange for 4 unique gps satellites
Author: spoonais
Date: 06/05/24 @5:10pm
*/

#include<iostream>
#include<cmath>
using namespace std;

int main()
{
    //Decalare speed of light (in m/s)
    const double c(299792458.0);

    //Declare and init objects
    int satID, i;
    double sec_tran, ms_tran, P;
    double comp[4];
    double store;

    for (satID = 1, i=0; satID <=4; satID++, i++)
    {
        cout << "Please provide the tranist time for satellite: " << satID << endl;
        cin >> ms_tran; //For testing do 500, 600, 700, 800 ms for each sat starting at sat 1

        //Conversion of millisec to seconds
        sec_tran = ms_tran/1000;

        //Calculate the pseudorange in m
        P = sec_tran * c;

        //Print pseudorange
        cout << "Pseudorange for Satellite " << satID << " is " << P << " meters " << endl;
        cout << "----------------------------------------------------------------" << endl;

        //Store each iteration of p calculated into the array
        comp[i] = P;


    }

    //Create the compare logic
    for (int i=0; i<4; i++)
    {   
        if (comp[i] > store)
        {
            store = comp[i];
        } 
            else
                {
                    
                }
    
    } 

    cout << "The largest value is: " << store << endl;


    // //Print out comp[i]:
    // for (int i=0; i<4; i++)
    //     {
    //         cout << comp[i] << endl;
    //     }



}