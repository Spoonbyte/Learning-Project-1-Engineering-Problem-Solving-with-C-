/*
File: Practice_1.cpp
Desc: Try to access the different elements of 2D arrays
Author: spoonais
Date: 1/2/24 @ 5pm

*/

/*-------- SELF FEEDBACK -----------

-----------------------------------*/
#include<iostream>
using namespace std;

/*------------ PROGRAMMER DEFINED FUNCTIONS -------------*/


/*-------------------------------------------------------*/


int main()
{
    //Decalare and Init objects:
    double array1[2][5] = {{3.0,5.0},{2.1,7.4}};
    int g[3][3]={{0,0,0},{1,1,1},{2,2,2}};

    // //Access elements 
    // cout << array1[1][1] << endl;

    // //Print entire array
    // for(int i=0; i < 2; ++i)
    // {
    //     for(int k=0; k < 5; ++k)
    //     {   
    //         cout << array1[i][k] << "\t";

    //         if(k == 4)
    //         {
    //             cout << endl;
    //         }
    //     }
    // }

    //Practice!
    int sum = 0;
    for (int i=0; i<3; ++i)
    {
        sum += g[i][1];
        cout << sum << endl;
    }

    //Exit
    return 0;

}