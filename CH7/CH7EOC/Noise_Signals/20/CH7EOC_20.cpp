/*
File: CH7EOC_20.cpp
Desc: Noise signal problems
Author: spoonais
Date: 12/28/24 @ 12:41pm
*/

/*-------- SELF FEEDBACK -----------

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

double mean(double x[], int n)
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
    mu = mean(y,n);

    for(int k=0; k < n; ++k)
    {
        sum += (y[k] - mu) * (y[k] - mu);
    }

    return sum/(n-1);

}

/*-------------------------------------------------------*/

int main()
{
    //Decalare and Init objects:
    double upper, lower;
    int iter(0);
    double sum(0), var(0);
    double rand_arr[5000] = {0};
    

    //get the upper and lower from user
    cout << "To generate a random number between a and b, provide a and b" << endl;
    cout << "Provide b (upper)" << endl;
    cin >> upper;
    cout << "Provide a (lower)" << endl;
    cin >> lower;
    cout << "Provide iterations" << endl;
    cin >> iter;

    //Create an array of floating point values
    rand_float_array(lower,upper,iter,rand_arr);

    //Calculate the mean
    cout << "Mean = " << mean(rand_arr,iter) << endl;

    //Calculate the variance
    cout << "Variance = " << variance(rand_arr,iter) << endl;

    
    //Exit
    return 0;

}