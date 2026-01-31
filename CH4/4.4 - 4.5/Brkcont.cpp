/*
File: Brkcont.cpp
Desc: To test the function of break and continue in a loop
Author: spoonais
Date: 06/10/24 @12:00pm
*/

#include<iostream>
#include<cmath>
using namespace std;

int main()
{
    //Decalare and Init objects:
    double sum(0), x;

    // //Loop 1 My Example
    // for ( short k=1; k<=20; ++k)
    // {
    //     cin >> x;
    //     sum += x;
    //     if (sum > 10)
    //     {
    //         break;
    //     }

    //     cout << sum << endl;
    // }

    // cout << "Sum = " << sum << endl;

    //Loop that adds ONLY numbers that are less than 10...if a value is greater than ten then the loop quits
    // for ( short k=1; k<=20; ++k)
    // {
    //     cin >> x;
        
    //     if (x > 10)
    //     {
    //         break;
    //     }

    //     sum += x;

    //     // cout << sum << endl;
    // }

    // cout << "Sum = " << sum << endl;


    //Loop differs from the one above because instead of breaking out of the loop once the number is greater than 10, it IGNORES the value greater than 10 and keeps the sum of values <= 10
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