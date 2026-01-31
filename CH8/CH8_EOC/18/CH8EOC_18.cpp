/*
File: CH8EOC_18.cpp
Desc: Try to solve problem #18
Author: spoonais
Date: 1/16/24 @ 1:50pm
Finished: @ 2:20pm
*/

/*-------- SELF FEEDBACK -----------

Gave me the idea that I can collect data sets with my arduino and use a c++
mean and variance script to take the realtime data in an calculate on the fly

-----------------------------------*/
#include<iostream>
#include<fstream>
#include<vector>
#include<iomanip>
#include<string>
using namespace std;

/*------------ PROGRAMMER DEFINED FUNCTIONS -------------*/

/*
Function objective: To calculate the mean(average) of the entire dataset
Pre-Cond: 2D vector with dataset has been initialized in main()
Post-Cond: return value is sum divided by the array dimensions
*/
double mean(vector<vector<double>> &x)
{
    //Declare and init
    double sum(0);

    for(int i=0; i < x.size(); ++i)
    {
        for(int j=0; j < x[i].size(); ++j)
        {
            sum = sum + x[i][j];
        }
    }

    return sum/(x.size()*x[0].size());
}

/*
Function objective: To calculate the variance of the entire dataset
Pre-Cond: 2D vector with dataset has been initialized in main()
Post-Cond: return value is...
*/

double variance(vector<vector<double>> &x)
{
    //Subtract mu from each element and square the result then sum them all together 
    double mu = mean(x);
    double sum(0);

    //Calculate
    for(int i=0; i < x.size(); ++i)
    {
        for(int j=0; j < x[i].size(); ++j)
        {
            sum = sum + ((x[i][j] - mu)*(x[i][j] - mu));
        }
    }

    return sum / ((x.size()*x[0].size())-1);
}

/*-------------------------------------------------------*/

int main()
{
    //Decalare and Init objects:
    ifstream fin;
    int row(0), col(0);

    //Set the precision for cout
    cout << fixed << setprecision(4);   //4 decimal place
    
    //Associate the filestream with input file
    fin.open("power1.txt");
    if(fin.fail())
    {
        cerr << "ERROR! 'power1.txt' failed to open." << endl;
        exit(1);
    }

    //Get the size of the array from the first line of the file
    fin >> row >> col;
    
    //Create the row vector (will be an ELEMENT of the overall MW vector)
    vector<double> ROW(col,0);              //init each element with zero
    //Create the 2D vector
    vector<vector<double>> MW(row,ROW);     //init each element with row vector

    //Read in the array
    for(int i=0; i < MW.size(); ++i)
    {
        for(int j=0; j < MW[i].size(); ++j)
        {
            fin >> MW[i][j];
        }
    }

    // //TRBLSHT
    // //Print array to console to ensure was written
    // for(int i=0; i < MW.size(); ++i)
    // {
    //     for(int j=0; j < MW[i].size(); ++j)
    //     {
    //         cout << MW[i][j] << " ";
    //     }
    //     cout << endl;
    // }
  
    //Print the dataset mean and variance
    cout << "The powerplant output mean = " << mean(MW) << " MW " << endl;
    cout << "The powerplant output variance = " << variance(MW) << " MW " << endl;

    //System pause
    system("Pause");

    //Exit
    return 0;

}