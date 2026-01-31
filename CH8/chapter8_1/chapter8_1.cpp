/*
File: Practice_1.cpp
Desc: Try to read in data from a txt file into a 2D array
Author: spoonais
Date: 1/3/24 @ 11:52am

*/

/*-------- SELF FEEDBACK -----------

-----------------------------------*/
#include<iostream>
#include<fstream>
#include<string>
using namespace std;

/*------------ PROGRAMMER DEFINED FUNCTIONS -------------

Even though I was getting a VS code squiggle error for 

line 54: double temp[NROW][NCOL];

It was still compiling...not sure why its showing the error that "expression must have a constant value"?


-------------------------------------------------------*/

int main()
{
    //Decalare and Init objects:
    ifstream fin;
    string filename;
    int row_N(0),col_N(0);

    //Get input filename from user
    cout  << "Please provide the input file name" << endl;
    cin >> filename;

    //Associate filestream with input file
    fin.open(filename.c_str());
    if(fin.fail())
    {
        cerr << "Error!" << filename << " failed to open " << endl;
        exit(1);
    }

    //Read first lines from data file
    fin >> row_N >> col_N;

    //Use symbolic constants to size the array 
    //This allows us to read in the non-const values and change them to const to use in the array bounds
    const int NROW(row_N);                       
    const int NCOL(row_N);
    double temp[NROW][NCOL];
    
    //Use nested for loop to populate the array
    for(int i=0; i < NROW; ++i)
    {
        for(int j=0; j < NCOL; ++j)
        {
            fin >> temp[i][j];
        }
    }

    //Close input filestream
    fin.close();

    //Print entire array to console to check
    for(int i=0; i < NROW; ++i)
    {
        for(int k=0; k < NCOL; ++k)
        {   
            cout << temp[i][k] << "\t";
        }

        cout << endl;
    }

    //System pause
    system("Pause");

    //Exit
    return 0;

}