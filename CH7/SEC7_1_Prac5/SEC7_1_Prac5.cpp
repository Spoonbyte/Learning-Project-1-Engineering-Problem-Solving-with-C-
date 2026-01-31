/*
File: SEC7_1_Prac5.cpp
Desc: To confirm what the output was after trying to solve in my head
Author: spoonais
Date: 12/03/24 @ 3:02pm
*/

/*-------- SELF FEEDBACK -----------*/
/*
If you dont initialize the arr[5] then you get crazy numbers that are printed out...


*/
/*-----------------------------------*/

#include<iostream>
#include<fstream>
#include<cmath>
using namespace std;

int main()
{
    //Decalare and Init objects:
    int arr[5] ={0}, i, k;

    for(i=0; i<5; ++i)
    {
        for(k=1; k<3; ++k)
        {
            arr[i] += k*i;
        }

        cout << " arr[" << i << "] is " << arr[i] << endl;
    }
 
    //Exit
    return 0;

}