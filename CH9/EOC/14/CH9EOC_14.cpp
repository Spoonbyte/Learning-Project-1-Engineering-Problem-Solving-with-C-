/*
File: CH9EOC_14.cpp
Desc: To solve the EOC problems
Author: spoonais
Date: 02/13/25 @ 1:40pm
Finished: @ 2:40pm
*/

#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

/*--------- PROGRAMMER DEFINED FUNCTIONS -------------*/

/*
Name: assign_n()
Objective
Pre-Cond:
Post-Cond:
*/
void assign_n(double v, int n, vector<double> &vector)
{
    //Method 1.
    // vector.resize(n,v);

    //Method 2.
    //Fill vector with v
    for(int i=0; i < n; i++)
    {
        vector[i] = v;
    }
}

/*----------------------------------------------------*/

int main()
{
    // //Method 1:
    // //Decalare and Init objects:
    // int n(0);
    // double v(0);
    // vector<double> x;

    // //Define the size of the vector
    // cout << "Provide the size of the vector" << endl;
    // cin >> n;
    // cout << "Provide the fill value" << endl;
    // cin >> v;

    // //Call the function
    // assign_n(v,n,x);

    // //Print out vector x
    // for(int i=0; i < n; i++)
    // {
    //     cout << x[i] << endl;
    // }

    /*--------------------------------------------------------------------------------------------*/

    // //Method 2: Initialize the vector after getting the user size. Books solution.
    // //Decalare and Init objects:
    // int n(0);
    // double v(0);
    
    // //Define the size of the vector
    // cout << "Provide the size of the vector" << endl;
    // cin >> n;
    // cout << "Provide the fill value" << endl;
    // cin >> v;

    // //After getting the size of vector (n) from user declare vector
    // vector<double> x(n);

    // //Call the function
    // assign_n(v,n,x);

    // //Print out vector x
    // for(int i=0; i < n; i++)
    // {
    //     cout << x[i] << endl;
    // }

    /*--------------------------------------------------------------------------------------------*/

    //Method 3: Not using a function and just init the vector directly.
    //Decalare and Init objects:
    int n(0);
    double v(0);
    
    //Define the size of the vector
    cout << "Provide the size of the vector" << endl;
    cin >> n;
    cout << "Provide the fill value" << endl;
    cin >> v;

    //Directly init the vector
    vector<double> x(n,v);

    //Print out vector x
    for(int i=0; i < n; i++)
    {
        cout << x[i] << endl;
    }

    //Exit
    return 0;

}