/*
File:Func_proto.cpp
Desc:To test why the function prototypes are useful in a program.
Author: spoonais
Date: 10/03/24 @7:10am
*/

#include<iostream>
#include<cmath>
using namespace std;

//Without a function prototype
double sincx(double x)
{
    double value(0);
    value = sin(x)/x;
    return value;
}

int main()
{
    double x(0);

    //Get user value
    cout << "Please provide value to compute sinc(x)" << endl;
    cin >> x;

    //Calculate
    cout << sincx(x) << endl;

    // Wait for user input before closing
    // Dont use system("pause"), considered bad practice since it only works on Windows
    cout << "Press Enter to exit...";
    cin.ignore(); // Clear the input buffer
    cin.get();    // Wait for user input

    //Exit 
    return 0;

}