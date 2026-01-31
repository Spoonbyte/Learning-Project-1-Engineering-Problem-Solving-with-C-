/*
File: Project4.7_000
Desc: To create a divide and conquer program that guesses a # between 1 and 20
Author: spoonais
Date: 06/27/24 @2:00pm

Notes: Thinking about it from a logical viewpoint, the most basic way to guess is to start from 0 and count 
up to 20, but if your number is 20 then it will take 21 iterations to get there. If you use my version of 
divide and conquer then you get there in about 7 iterations
*/

#include<iostream>
#include<cmath>
using namespace std;

int main()
{
    //Decalare and Init objects:
    //LL is Lower Limit, UL is Upper Limit
    double R_UL(20), R_LL(0), R1_LL(0), R1_UL(0), R2_LL(0), R2_UL(0), mid1(0), mid2((0));
    int AB, guess1, guess2, guess3, guess4;

    //Ask the user
    cout << "Pick a number between" << R_LL << " and " << R_UL << "and I will guess it" << endl;

    //Get the first 2 sets of ranges
    mid1 = (R_UL - R_LL)/2;
    R1_UL = mid1;
    R2_LL = mid1;
    R2_UL = R_UL;

    //
    for (int count(0); count <= 21; ++count ) //if my code works how I want, should get there in less than 21 iterations
    {
        //Check
        cout << "Is the number between" << R1_LL << "-" << R1_UL << " OR " << R2_LL << "-" << R2_UL << endl;
        cout << "Enter (1) for 1st Range or (2) for 2nd Range" << endl;
        cin >> AB;
        
        if (AB == 1)
        {   
            //Calcualte new range
            R2_UL = R1_UL; //Store orig UL 
            R1_LL = R1_LL; //Stays the same
            mid1 = (R1_UL - R1_LL)/2;
            R1_UL = mid1;
            R2_LL = mid1;

        }

        if (AB == 2)
        {   
            R1_LL = R2_LL;
            R2_UL = R2_UL; //Stays the same
            mid2 = (R2_UL - R2_LL)/2;
            R1_UL = R1_LL + mid2;
            R2_LL = R2_UL - mid2;
        }

        if ((R1_UL - R1_LL) <= 1.99 || (R2_UL - R2_LL) <= 1.99)
        {
           guess1 = ceil(R1_LL );
           guess2 = ceil(R2_LL);
           guess3 = floor(R1_UL);
           guess4 = floor(R2_UL);
           break;
        }

        
       
    }

    cout << guess1 << " or " << guess3 << endl;
    cout << guess2 << " or " << guess4 << endl;

    //Exit program
    return 0;

}