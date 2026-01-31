/*
File: CH7EOC_19.cpp
Desc: Noise signal problems
Author: spoonais
Date: 12/28/24 @ 10am
*/

/*-------- SELF FEEDBACK -----------

-----------------------------------------------------*/

#include<iostream>
#include<cmath>
#include<random>
using namespace std;

/*------------ PROGRAMMER DEFINED FUNCTIONS -------------*/

void rand_float_array(int a, int b, int n, double x[])
{

    for(int i =0; i < n; ++i)
    {
        x[i] = ((double)rand()/RAND_MAX) + (rand()%(b-a) + a);      //My version
        // return ((double)rand()/RAND_MAX*(b-a) + a);              //Books version also written as... ((rand()/RAND_MAX) * 6) + 4 
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

double variance(double x[], int n)
{   
    double sum(0), mu(0);
    
    //Call mean
    mu = mean(x,n);

    for(int k=0; k < n; ++k)
    {
        sum += (x[k] - mu) * (x[k] - mu);
    }

    return sum/(n-1);

}

/*-------------------------------------------------------*/

int main()
{
    //Decalare and Init objects:
    int upper, lower, iter(0);
    double sum(0);
    double rand_arr[1000] = {0};

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

    //Compute the mean using the array
    //Computed value should converge on 7
    cout << "The mean = " << mean(rand_arr,iter) << endl;

    //Compute the variance using the array
    //Computed value should converge on 3
    cout << "The variance = " << variance(rand_arr,iter) << endl;
    
    //Exit
    return 0;

}