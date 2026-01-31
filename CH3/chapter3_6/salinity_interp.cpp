/*
File: salinity_interp.cpp
Desc: To create a linear interpolator, given a time give a corresponding salinity find the freezing temp
Author: spoonais        
Date: 05/10/24
*/

#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
    //Declare and Init variables (these are global variables so they are stored in the STATIC SEGMENT)
    double a, b, c, f_a(0), f_b(0), f_c(0), tC;

    //Create arrays to store the time and temperature
    double salinity[] = {0,10,20,24.7,30,35};
    double temp[] = {32,31.1,30.1,29.6,29.1,28.6};

    //User provides the time value they would like to interpolate and get temp 
    cout << "Select the salinity value for which you want the related freezing temp \n";
    cin >> b;

    //Take the b value and find the values in the salinity array it is between
    for( int i=0; i<12; i++)
    {
        if (b < salinity[i]) 
        {
            c = salinity[i];
            a = salinity[i-1];
            f_c = temp[i];
            f_a = temp[i-1];
            break; //without this "break" the loop will continue to run 
        }
    }

    //Define the linear interpolation equation
    f_b = f_a + ((b-a)/(c-a))*(f_c - f_a);

    //Convert deg F to deg C and display both
    tC = (f_b - 32)*(0.56); //initially I used (5/9) instead of 0.56 but it kept giving zero as the answer?

    //Output value
    cout << setprecision(8) << "The freezing temperature at a salinity of " << b << " ppt is " << f_b << " deg F or " << tC << "deg C" << endl;

return (0);

}