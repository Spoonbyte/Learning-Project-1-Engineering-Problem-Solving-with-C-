/*
File: chapter8_5.cpp
Desc: To see why I was having an error with declaring the 2D vector.
Author: spoonais
Date: 1/5/24 @ 9:30am
FINISHED @ 
*/

/*-------- SELF FEEDBACK -----------

It seems that my data type is not matching, and that was causing the error?

-----------------------------------*/
#include<iostream>
#include<fstream>
#include<vector>
using namespace std;

/*------------ PROGRAMMER DEFINED FUNCTIONS -------------*/

/*-------------------------------------------------------*/

int main()
{
    //Decalare and Init objects:
    int row_N, col_N;
    ifstream fin;

    //Read in file
    fin.open("engine.txt");
    if(fin.fail())
    {
        cerr << "Error! engine.txt failed" << endl;
        exit(1);
    }

    //Get the size of 2D array from first line of data file
    fin >> row_N >> col_N;

    //Init single row
    //Example: if col_N = 3
    //                row[0]   row[1]   row[2]  ... 
    //Sets the row = {0        0        0       ... }
    vector<double> row(col_N,0);

    //Init the 2D vector with size from data file

    //Example: if row_N = 4
    //                    arr[0]      arr[1]   arr[2]     arr[3]      ...
    //Sets the array = { {0, 0, 0}  {0, 0, 0}  {0, 0, 0}  {0, 0, 0}   ...}
    //                   k0,k1,k2   k0,k1,k2   k0,k1,k2   k0,k1,k2      
    //Each element in a 2D array is an array itself!
    
    vector<vector<double>> arr(row_N,row);         
    //In arr(row_N,row) row_N sets the number of elements, and row initializes each element

    //read in the data file
    for(int i=0; i < arr.size(); ++i )
    {
        for(int k=0; k < arr[k].size(); ++k)
        {
            fin >> arr[i][k];
        }
    }

    //TRBLSHT
    //Print entire array to console to check
    for(int i=0; i < arr.size(); ++i)           //First for loop cycles through ROWS
    {
        for(int k=0; k < arr[i].size(); ++k)    //Second for loop cycles through COLUMNS
        {   
            cout << arr[i][k] << "\t";
        }
        cout << endl;
    }

    //pause
    system("Pause");

    //Exit
    return 0;

}