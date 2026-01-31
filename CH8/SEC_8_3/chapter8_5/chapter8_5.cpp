/*
File: chapter8_5.cpp
Desc: Modify chapter8_3.cpp using vector class instead
Author: spoonais
Date: 1/5/24 @ 9:30am
FINISHED @ 
*/

/*-------- SELF FEEDBACK -----------

-----------------------------------*/
#include<iostream>
#include<fstream>
#include<vector>
using namespace std;

/*------------ PROGRAMMER DEFINED FUNCTIONS -------------*/


/* 
Function: get_2D_vec
Use: To read from the input file and store into an array
--------------------
Preconditions: 
The ifstream has been defined
The ifstream source has data

Post-conditions:
The vector x (or "temp" in main program) is filled
*/

void get_2D_vec(ifstream& input, vector<vector<double> >&x)
{
    //Declare and init local objects
    int rows = x.size();
    int column = x[0].size();

    //Use nested for loops to populate array
    for(int i=0; i < rows; ++i)
    {
        for(int j=0; j < column; ++j)
        {
            input >> x[i][j];
        }
    }
}

/* 
Function: trial_avg_vec
Use: To compute the average of each column
--------------------
Preconditions: 
The array "x" has been filled
The row and column data has been filled

Post-conditions:
The average of each column (trial) is computed and returned to user
*/

double trial_avg_vec(vector<vector<double> >&x,int column)          
{
    double sum(0);
    for(int i=0; i < x.size(); ++i )
    {
        sum += x[i][column];
    }

    return sum/x.size();
}

/*-------------------------------------------------------*/

int main()
{
    //Decalare and Init objects:
    ifstream fin;
    int row_N ,col_N;
    double avg_temp(0);                         //Stores each trial average run

    //Associate filestream with input file
    fin.open("engine.txt");
    if(fin.fail())
    {
        cerr << "Error! engine.txt failed to open " << endl;
        exit(1);
    }

    //Read first lines from data file
    //Pass to the function 
    fin >> row_N >> col_N;

    //initialize the row (length based on # of columns) with zeros
    vector<double> row(col_N,0);            //This part was not mentioned in the C++ book

    //Then use the the row and copy for each row_N
    vector< vector<double> > temps(row_N,row);

    //Get the array from input file
    get_2D_vec(fin,temps);

    // //TRBLSHT
    // //Print entire array to console to check
    // for(int i=0; i < temps.size(); ++i)
    // {
    //     for(int k=0; k < temps[i].size(); ++k)
    //     {   
    //         cout << temps[i][k] << "\t";
    //     }
    //     cout << endl;
    // }

    //Close input filestream
    fin.close();

    //Print the report for each trial (column) 
    for (int i=0; i < col_N; ++i)
    {
        //Call the average function to compute each trial average
        avg_temp = trial_avg_vec(temps,i);

        cout <<"TRIAL #" << i << " average temp = " << avg_temp << endl;
        cout << "-------------------------" << endl;

        // //Compare each trial average to each trial value
        // //Print the ones that were below average
        // for(int k=0; k < row_N; ++k)
        // {
        //     if(temps[k][i] < avg_temp)
        //     {
        //         cout << "Engine : " << k+1 << " was below average " << endl;
        //     }
        //         else
        //         {
        //             cout << "Engine : " << k+1 << " equal to or above average" << endl;
        //         }
        // }
        // cout << "-------------------------" << endl;

    }

    //System pause
    system("Pause");

    //Exit
    return 0;

}