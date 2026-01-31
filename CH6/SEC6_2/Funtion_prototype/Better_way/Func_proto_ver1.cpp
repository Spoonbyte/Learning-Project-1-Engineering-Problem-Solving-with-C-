/*
File:Func_proto_ver1.cpp
Desc:To test why the function prototypes are useful in a program. This is an improved version than the first attemp. Makes more logical sense.
Author: spoonais
Date: 10/03/24 @12:19pm
*/

#include<iostream>
#include<cmath>
using namespace std;

//unction prototype
//Makes more sense, the "x" is a local placeholder for ANY variable used in the main function.
//In this case the variable "value" is used and its value is passed to variable "x".
//So really sin(x)/x becomes sin(value)/value
double sincx(double x)
{
    return sin(x)/x; 
}

int main()
{
    double value(0);

    //Get user value
    cout << "Please provide value to compute sinc(x)" << endl;
    cin >> value;

    //Calculate
    cout << sincx(value) << endl;

    // Wait for user input before closing
    // Dont use system("pause"), considered bad practice since it only works on Windows
    cout << "Press Enter to exit...";
    cin.ignore(); // Clear the input buffer
    cin.get();    // Wait for user input

    //Exit 
    return 0;

}