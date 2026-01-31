/*
File: GPSvarSat#.cpp   
Desc: To calcualte the pseudorange for 4 unique gps satellites but the number of satellites varies based on user input...will I still be able to use the switch case?
Author: spoonais
Date: 06/13/24 @5:10pm
*/

#include<iostream>
#include<cmath>
using namespace std;

int main()
{
    //Decalare speed of light (in m/s)
    const double c(299792458.0);

    //Declare and init objects
    int satID, i, satnum;
    double sec_tran, ms_tran, P;
    double storeP, storeID;

    //Provide the number of satellites
    cout << "Please provide the number of satellites" << endl;
    cin >> satnum;

    for (i = 1; i <= satnum; i++)
    {
        
        cout << "Please provide the Satellite ID number" << endl;
        cin >> satID;
        cout << "Please provide the tranist time for satellite: " << satID << endl;
        cin >> ms_tran; //For testing do 500, 600, 700, 800 ms for each sat starting at sat 1

        //Conversion of millisec to seconds
        sec_tran = ms_tran/1000;

        //Calculate the pseudorange in m
        P = sec_tran * c;

        //Print pseudorange
        cout << "Pseudorange for Satellite " << satID << " is " << P << " meters " << endl;
        cout << "----------------------------------------------------------------" << endl;

        //Use swtich case to determine the closest satellite
        switch (i)
        {
            case 1:         //This case 1 serves to store the first calculated P and use it to compare all other values too (You cant initialize storeP with zero and if I initialize it on each iteration with P it will update each time and compare itself to iteself so I needed to find a way to store the first P and then once that is done, compare all the future Ps)...if its the smallest then it will stay the smallest throughout
                storeP = P;
                storeID = satID;
                break;
            case 2 ... satnum:
                if (P < storeP)
                {
                    storeP = P;         //This updates the new lowest pseudorange
                    storeID = satID;  //This updates the SatID that goes with the new lowest pseudorange
                } else {}
                break;

        }

        //Monitor 
        cout << storeP << endl;

    }

    cout << "The closest is satellite: "  << storeID  << " at " << storeP << " meters " << endl;


}