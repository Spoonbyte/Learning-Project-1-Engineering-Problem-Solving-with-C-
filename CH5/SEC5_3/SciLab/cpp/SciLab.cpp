/*
File: SciLab.cpp
Desc: This program generates a data file of values from a damped sine function
Date: 07/28/24
Author: spoonais
*/

#include<iostream>
#include<fstream>
#include<cmath>
using namespace std;

int main()
{
    //Declare and init objects
    const double PI = 3.141593;
    double t(0), f_t(0);
    ofstream dsine;

    //Generate the data file
    dsine.open("dsine.dat");
    for(int k=1; k<=100; k++)
    {
        t = 0.1*k;
        f_t = exp(-t)*sin(2*PI*t);
        dsine << t << "\t" << f_t <<  endl;
    }

    //Close data file and exit the program
    dsine.close();
    return 0;

}