/*
File: rand_float.cpp
Desc: To create a function that generates a random float BETWEEN 2 values
Author: spoonais
Date: 11/16/24 @9:14am
*/

#include<iostream>
#include<cstdlib>
#include<fstream>
using namespace std;

/*--------------------------PROGRAMMER DEFINED FUNC ---------------------------------*/

double rand_float(double a, double b)
{   

    //Compute 
    return ((double)rand()/RAND_MAX*(b-a) + a); //need to use cast operator to convert rand() from int to double

    //Not sure why we have to add back a at the end?
    
}

/*-----------------------------------------------------------------------------------*/

int main()
{
    //Decalare and Init objects:
    double low(0), high(0), result(0);

    //User
    cout << "Please provide 2 numbers and I will generate a random number between them" << endl;
    cout << "Lower = ";
    cin >> low;
    cout << "Upper = ";
    cin >> high;

    //Print 10 random ints
    for(int i=1; i<=10; ++i)
    {
        //Call function
        result = rand_float(low, high);
    
        //print
        cout << "The random number " << i << " is = " << result << endl;

    }

    cout << RAND_MAX << endl;
    
    
    return 0;
}