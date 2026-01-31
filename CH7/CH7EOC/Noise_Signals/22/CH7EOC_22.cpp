/*
File: CH7EOC_22.cpp
Desc: Noise signal problem #22
Author: spoonais
Date: 12/29/24 @ 9:40am
*/

/*-------- SELF FEEDBACK -----------

So to solve this problem, I just used the computer to solve the equations in terms of a then b. Then I fed those 
values into the original "rand_float_array" function to generate an array of values bounded by the user mean and variance. 

Then to check, I put the generated array into the avg() and variance() functions to check and ensure they matched the 
user inputted mean and variance.

Seems like this is a valuable script to be able to create a set of random numbers but have the random numbers still be "contained" by the mean and variance.

-----------------------------------------------------*/

#include<iostream>
#include<cmath>
#include<random>
using namespace std;

/*------------ PROGRAMMER DEFINED FUNCTIONS -------------*/

void rand_float_array(double a, double b, int n, double x[])
{
    for(int i =0; i < n; ++i)
    {
        x[i] = ((double)rand()/RAND_MAX*(b-a) + a);                  //Books version also written as... ((rand()/RAND_MAX) * 6) + 4            
    } 
}

double avg(double x[], int n)
{
    double sum(0);

    for(int h=0; h < n; ++h)
    {
        sum = sum + x[h];
    }

    return sum/n;
}

double variance(double y[], int n)
{   
    double sum(0), mu(0);
    
    //Call mean
    mu = avg(y,n);

    for(int k=0; k < n; ++k)
    {
        sum += (y[k] - mu) * (y[k] - mu);
    }

    return sum/(n-1);

}

void rand_mv(double mean, double variance, int n, double z[])   //Need to pass the iter and rand_arr[] to the rand_float_array() so I need n, and z in the rand_mv() arguments
{
    double a(0), b(0);       //Declare and init

    //Solve for a and b based on given mean and var
    //Used the equations provided by the book
    a = ((2 * mean) - (sqrt(variance*12))) / 2;
    b = (2*mean) - a;

    //Call the rand_float_array function
    rand_float_array(a,b,n,z);

}

/*-------------------------------------------------------*/

int main()
{
    //Decalare and Init objects:
    double mean(0), var(0);
    int iter(0);
    double rand_arr[5000] = {0};
    
    //get the mean and var from user
    cout << "To generate a random number sequence with a specified mean and variance" << endl;
    cout << "Provide mean" << endl;
    cin >> mean;
    cout << "Provide variance" << endl;
    cin >> var;
    cout << "Provide iterations" << endl;
    cin >> iter;

    //Create an array of floating point values with specified mean and var
    rand_mv(mean, var, iter, rand_arr);

    // //Create a 5 second timer                //DID NOT WORK
    // for (int i=0; i<5; ++i)
    // {
    //     for(int k=0; k<1000; ++k)
    //     {
    //         if(k==999)
    //         {
    //             cout << "Seconds = " << i << endl;
    //         }
    //     }
    // }

    // //Print out array to visualize how the mean and variance affect the spread of numbers generated
    // for(int i=0; i < iter; ++i)
    // {
    //     cout << rand_arr[i] << endl;
    // }

    //CHECK THAT THE ARRAY GENERATED MATCHED THE USER INPUT OF MEAN AND VAR//
    //Calculate the mean
    cout << "Mean = " << avg(rand_arr,iter) << endl;

    //Calculate the variance
    cout << "Variance = " << variance(rand_arr,iter) << endl;

    //Exit
    return 0;

}