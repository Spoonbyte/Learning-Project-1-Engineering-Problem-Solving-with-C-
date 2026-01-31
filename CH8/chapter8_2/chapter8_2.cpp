/*
File: chapter8_2.cpp
Desc: Try to compute averages of each column of data...practivce "navigating" through 2D arrays
Author: spoonais
Date: 1/3/24 @ 12:34am

*/

/*-------- SELF FEEDBACK -----------

-----------------------------------*/
#include<iostream>
#include<fstream>
#include<string>
using namespace std;

/*------------ PROGRAMMER DEFINED FUNCTIONS -------------

-------------------------------------------------------*/

int main()
{
    //Decalare and Init objects:
    ifstream fin;
    string filename;
    const int NROW = 10;                       
    const int NCOL = 7;
    double x[NROW][NCOL];
    
    //Use nested for loop to populate the array
    for(int i=0; i < NROW; ++i)
    {
        for(int j=0; j < NCOL; ++j)
        {
            x[i][j] = j + i;
        }
    }

    //Print entire array to console for visulization
    for(int i=0; i < NROW; ++i)
    {
        for(int k=0; k < NCOL; ++k)
        {   
            cout << x[i][k] << "\t";
        }

        cout << endl;
    }

    //Declare and init 
    double sum(0);

    //Calcuate the average per column
    for(int i=0; i < NCOL; ++i)
    {
        for(int j=0; j < NROW; ++j)
        {
            sum = sum + x[j][i];    //Swapped j with i so I could move "down" a column instead of across a row
        }

        cout << "Average for column: " << i << " = " << sum/NROW << endl;

        //reset sum
        sum = 0; 
    }

    //System pause
    system("Pause");

    //Exit
    return 0;

}