/*
File: lin_interpol.cpp
Desc: To create a linear interpolator, given a time give a corresponding temperature
Author: spoonais        
Date: 05/09/24
*/

#include<iostream>
using namespace std;

int main()
{
    //Declare and Init variables (these are global variables so they are stored in the STATIC SEGMENT)
    double a, b, c, f_a(0), f_b(0), f_c(0);

    //Create arrays to store the time and temperature
    double time[] = {0.0,0.5,1.0,1.5,2.0,2.5,3.0,3.5,4.0,4.5,5.0,5.5};
    double temp[] = {72.5,78.1,86.4,92.3,110.6,111.5,109.3,110.2,110.5,109.9,110.2};

    //User provides the temp value they would like to interpolate and get the time  
    cout << "Select what temp value \n";
    cin >> b;

    //Take the b value and find the values in the time array it is between
    for( int i=0; i<12; i++)
    {
        if (b < temp[i]) 
        {
            f_c = time[i];
            f_a = time[i-1];
            c = temp[i];
            a = temp[i-1];
            break; //without this "break" the loop will continue to run because TIME values 4.0 and 5.0 also satisfy the loop!
        }
    }

    //Define the linear interpolation equation
    f_b = f_a + ((b-a)/(c-a))*(f_c - f_a);

    //Output value
    cout << "The interpolated temperature is " << f_b << "seconds"<< endl;

return (0);

}