/*
File: sincx.cpp
Desc: To plot the sinc(x) function over a user defined range.
Author: spoonais
Date: 10/01/24 @1:15pm, finished first attempt by 1:38pm 
*/

#include<iostream>
#include<cmath>
#include<fstream>
using namespace std;

//GLOBAL VARIABLES:
double x(0);

/*------------ PROGRAMMER DEFINED FUNCTIONS ----------------*/

double sincx()
{   
    double output(0);
    output = (sin(x)/x);
    return output;
}

/*---------------------------------------------------------*/

int main()
{
    //Decalare and Init objects:
    double a(0), b(0), increment(0), plot(0);
    ofstream fout, fout2;

    //Associate the filestream with file
    fout.open("Output_x.txt");
    fout2.open("Output_sincx.txt");


    //Get the range from user
    cout << "Please provide the lower range value to plot the function sinc(x)" << endl;
    cin >> a;
    cout << "Please provide the upper range value to plot the function sinc(x)" << endl;
    cin >> b;

    //Calculate the increment for the range 
    increment = (b - a)/20;

    //Initialize x with a 
    //This will start the function plot with a then add the increment to x with the loop:
    x = a;

    //Header for cout
    fout << "x" << endl;
    fout2 << "sinc(x)" << endl;
    //Use loop to plot the function:
    while(x <= b) //wait until x increments to b
    {
        //call function
        plot = sincx();

        //Output the plot of (x, sincx)
        fout << x << endl;
        fout2 << plot << endl;

        //Increment x 
        x = x + increment;
    }

    //Close
    fout.close();
    fout2.close();

    //Exit program:
    return 0;

}