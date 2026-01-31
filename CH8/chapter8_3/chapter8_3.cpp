/*
File: chapter8_3.cpp
Desc: Modify chapter8_1.cpp
Author: spoonais
Date: 1/4/24 @ 7am
FINISHED @ 8am
*/

/*-------- SELF FEEDBACK -----------

-----------------------------------*/
#include<iostream>
#include<fstream>
#include<string>
using namespace std;

//Const 
//Define a large 2d array space
const int NROW_MAX = 50;
const int NCOL_MAX = 50;

/*------------ PROGRAMMER DEFINED FUNCTIONS -------------*/

void get_2D_array(ifstream& input, double x[][NCOL_MAX], int act_row, int act_col)
{
    
    //Use nested for loop to populate the array from input file
    for(int i=0; i < act_row; ++i)
    {
        for(int j=0; j < act_col; ++j)
        {
            input >> x[i][j];
        }
    }
}

//This function just serves to compute the average for each trial
double trial_avg(double x[][NCOL_MAX], int act_row, int column)          
{
    double sum(0);

    for(int i=0; i < act_row; ++i )
    {
        sum += x[i][column];
    }

    return sum/act_row;

}


/*-------------------------------------------------------*/

int main()
{
    //Decalare and Init objects:
    ifstream fin;
    string filename;
    int row_N(0),col_N(0);
    double temp[NROW_MAX][NCOL_MAX] = {0};
    double avg_temp(0);                         //Stores each trial average run

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
    //Pass to the function 
    fin >> row_N >> col_N;

    //Get the array from input file
    get_2D_array(fin,temp,row_N,col_N);

    // //TRBLSHT
    // //Print entire array to console to check
    // for(int i=0; i < row_N; ++i)
    // {
    //     for(int k=0; k < col_N; ++k)
    //     {   
    //         cout << temp[i][k] << "\t";
    //     }
    //     cout << endl;
    // }

    //Close input filestream
    fin.close();

    //Print the report for each trial (column) 
    for (int i=0; i < col_N; ++i)
    {
        //Call the average function to compute each trial average
        avg_temp = trial_avg(temp,row_N,i);

        cout <<"TRIAL #" << i << " average temp = " << avg_temp << endl;
        cout << "-------------------------" << endl;

        //Compare each trial average to each trial value
        //Print the ones that were below average
        for(int k=0; k < row_N; ++k)
        {
            if(temp[k][i] < avg_temp)
            {
                cout << "Engine : " << k+1 << " was below average " << endl;
            }
                else
                {
                    cout << "Engine : " << k+1 << " equal to or above average" << endl;
                }
        }
        
        cout << "-------------------------" << endl;

    }

    //System pause
    system("Pause");

    //Exit
    return 0;

}