/*
File: 4.34.cpp
Desc: This is to redo CH4_5 using a while loop.
Author: spoonais
Date: 07/12/24 @3:30pm
*/

#include<iostream>
#include<cmath>
//removed the "using namespace std" and instead tried the indiviual std calls

int main()
{
    //Decalare and Init objects:
    const double c(299792458.0);
    int SatID(0), i(1), Store_ID(0);
    double ms_tran(0), sec_tran(0), P(0), store_P(0);

    while(i<=4)
    {
        //Get the user input
        std::cout << "Please provide the Satellite ID" << std::endl;
        std::cin >> SatID;
        std::cout << "Please provide the transit time for Satellite" << std::endl;
        std::cin >> ms_tran;

        //Conversion of millisec to seconds
        sec_tran = ms_tran/1000;

        //Calculate the pseudorange in m
        P = sec_tran * c;

        //Print pseudorange
        std::cout << "Pseudorange for Satellite " << SatID << " is " << P << " meters " << std::endl;
        std::cout << "----------------------------------------------------------------" << std::endl;

        //Store for initial compare
        if(i==1)
        {
            store_P = P;
            Store_ID = SatID;
        } 
            else if (P < store_P) 
            {
                store_P = P;
                Store_ID = SatID;
            }
        
        //Increment i:
        i++;
    }
    
    std::cout << "The closest satellite: " << Store_ID << " at " << store_P << " meters " << std::endl;

    //Pause program
    system("pause");

    //Exit program
    return(0);
    

}