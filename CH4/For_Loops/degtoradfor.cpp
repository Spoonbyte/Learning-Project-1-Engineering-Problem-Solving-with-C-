/*
File: While-For.cpp
Desc: Converting deg to rad, now using for loop
Author: spoonais
Date: 06/05/24 @4:31pm
*/

#include<iostream>
#include<cmath>
using namespace std;

int main()
{
    //Decalare and Init objects:
    const double PI = acos(-1);
    double rad;

    //Create header lines 
    cout << "Deg" << "\t" << "Rad" << endl;

    //Create the nested for loop
    for (int deg = 0; deg <= 360; deg += 10 ) 
    {
        rad = deg * (PI/180);
        cout << deg << "\t" << rad << endl;   
    }

}