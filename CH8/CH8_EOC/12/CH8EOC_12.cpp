/*
File: CH8EOC_12.cpp
Desc: Try to solve problem #11
Author: spoonais
Date: 1/15/24 @ 11:00am
Finished: @ 12:00pm
*/

/*-------- SELF FEEDBACK -----------

This took a while to figure out because I was trying to print out the day and week values within the 
same for loop that was searching for the lowest value...

How I solved it was to use a second for loop to search through the array again and see where the lowest 
value occurs and print the day and week

-----------------------------------*/
#include<iostream>
#include<fstream>
#include<iomanip>
using namespace std;

//Constants
const int NROW = 10, NCOL = 7;

/*------------ PROGRAMMER DEFINED FUNCTIONS -------------*/


void leastvalue(double x[][NCOL], int row, int col)
{
    //Declare and init
    double store = x[0][0];

    //Finds the lowest value
    for(int i=0; i < row; ++i)
    {
        for(int j=0; j < col; ++j)
        {
            if(x[i][j] < store)
            {
                store = x[i][j];
            } 
        }
    }

    cout << "The lowest output power = " << store << " MW " << endl;

    //Go through array again and find all instances of lowest values and print the week and day
    for(int i=0; i < row; ++i)
    {
        for(int j=0; j < col; ++j)
        {
            if(x[i][j] == store)
            {
                cout << "It occured on day " << j+1 << " of week " << i+1 << endl;
            } 
        }
    }
    
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

    //Print the lowest value for the data set and what day and week it occurs
    leastvalue(MW,row,col);
    
    //System pause
    system("Pause");

    //Exit
    return 0;

}