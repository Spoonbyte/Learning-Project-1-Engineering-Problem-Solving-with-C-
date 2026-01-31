/*
File: CH8EOC_11.cpp
Desc: Try to solve problem #11
Author: spoonais
Date: 1/14/24 @ 12:00pm
Finished: @ 1:34pm
*/

/*-------- SELF FEEDBACK -----------

-----------------------------------*/
#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
using namespace std;

//Constants
const int NROW = 10, NCOL = 7;

/*------------ PROGRAMMER DEFINED FUNCTIONS -------------*/

double total_avg(double x[][NCOL], int row, int col)
{
    double sum(0);

    for(int i=0; i < row; ++i)
    {
        for(int j=0; j < col; ++j)
        {
            sum = sum + x[i][j];
        }
    }

    return sum/(row*col);
}

int gr8thanavg(double x[][NCOL], int row, int col)
{
    //Declare and init
    double mu = total_avg(x,row,col);
    int counter(0);

    //Compare each day to average
    for(int i=0; i < row; ++i)
    {
        for(int j=0; j < col; ++j)
        {
            if(x[i][j] > mu)
            {
                counter++;
            }
        }
    }

    return counter;
}

/*-------------------------------------------------------*/

int main()
{
    //Decalare and Init objects:
    ifstream fin;
    int row(0), col(0);
    double MW[NROW][NCOL] = {0};

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

    //Ensure actual data doesnt exceed array size...if it does truncate the data and 
    //alert the user that data will be truncated to prevent memory issues
    if(row > NROW || col > NCOL)
    {
        cout << "WARNING!!! Input file exceeds the size of the storage array. Input data will be truncated" << endl;
        cout << "Input Array = " << row << " x " << col << "." << endl;
        cout << "Storage Array = " << NROW << " x " << NCOL<< "." << endl;

        if(row > NROW)
        {   
            cout << "'Setting row = NROW" << endl;
            row = NROW;
        }
        if(col > NCOL)
        {   
            cout << "Setting col = NCOL" << endl;
            col = NCOL;
        }
    }

    //Read in the array
    for(int i=0; i < row; ++i)
    {
        for(int j=0; j < col; ++j)
        {
            fin >> MW[i][j];
        }
    }
    
    // //TRBLSHT
    // //Print array to console to ensure was written
    // for(int i=0; i < row; ++i)
    // {
    //     for(int j=0; j < col; ++j)
    //     {
    //         cout << MW[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    //Print the average MW for the data set
    cout << "The average output over " << row * col << " days = " << total_avg(MW,row,col) << " MW " << endl;
    cout << "The number of days greater than the average = " << gr8thanavg(MW,row,col) << endl;
    
    //System pause
    system("Pause");

    //Exit
    return 0;

}