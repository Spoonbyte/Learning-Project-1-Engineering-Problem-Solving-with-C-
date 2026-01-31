/*
File: DataFilter.cpp
Desc: To act as a data filter for rainfall data
Author: spoonais
Date: 07/22/24 @11:16pm
*/

#include<iostream>
#include<cmath>
using namespace std;

int main()
{
    //Decalare and Init objects:
    double sum(0), x;

    
    for ( short k=1; k<=20; ++k)
    {
        cin >> x;
        
        if (x > 10)
        {
            continue;
        }
            
        sum += x;
    }
    
    cout << "Sum = " << sum << endl;


}

//A good application of this would be to create an array of random numbers and create a program that adds only the values <= 10...creating almost a filter 
// Can think of it like a filter...if given a dataset with a bunch of say rainfall data and you only want to keep the values that are say >= 5 in of rain
//Maybe grab a netcdf file with rainfall amounts and use this type of code to filter for only specific rainfall totals