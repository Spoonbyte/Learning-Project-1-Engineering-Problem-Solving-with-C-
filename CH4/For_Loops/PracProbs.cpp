/*
File: PracProbs.cpp
Desc: To convert the while loop for computing velocity made yesterday into a for loop
Author: spoonais
Date: 06/04/24 @4:41am
*/

#include<iostream>
#include<cmath>
using namespace std;

int main()
{   
    //Declare and Init objects 
    int count(0);

    //Create the loop
    for (int t = -1; t < 4; t++) //This should be equal to 5 x 3, so count = 15
    {
        for (int j =3; j>0; j--)
        {
            ++count;
        }
    
    }

    cout << count << endl;
}