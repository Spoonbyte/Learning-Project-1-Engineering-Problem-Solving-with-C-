/*
File: While-For.cpp
Desc: To convert the while loop for computing velocity made yesterday into a for loop
Author: spoonais
Date: 06/04/24 @4:41am
*/

#include<iostream>
#include<cmath>
using namespace std;

int main()
{   
    //Define and init objects
    double deg, rad;
    const double PI = acos(-1);
   
    //Create the loop
    for (int i = counter; i > 0; --i )  // not sure what this "counter" variable is?
    {
        cin >> deg;
        rad = deg * (PI/180);
        cout << deg << " " << rad << endl;

    }

}