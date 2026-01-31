/*
File: comparetest.cpp
Desc: To be able to compare the numbers in an array and return the largest value
Author: spoonais
Date: 06/07/24 @3:51pm
*/

#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;

int main()
{
    //Declare and Init objects
    double store(0);  //CHECK DATA TYPES!!!, my output was showing 16 instead of 16.7 because I had short instead of double for the store variable

    //set precision
    cout.setf(ios::showpoint);
    cout.precision(4);

    //Create an array
    double array[10] = {4, 7, 9, 16.7, 2.4, 3, 16, 10, 1, 15};

    //print array 
    cout << "----------ARRAY-------------" << endl;
    for (int j=0; j<8; j++)
    {
        cout << "A" << j << " = " <<  array[j] << endl;
    }
    cout << "----------------------------" << endl;

    //Create the compare logic
    for (int i=0; i<10; i++)
    {   
        if (array[i] > store)
        {
            store = array[i];
        } 
            else
                {
                    
                }
        // cout << array[i] << "compare to " << array[i+1] << endl;
        // cout << store << endl;
    
    } 

    cout << "The largest value is: " << store << endl;
    
}