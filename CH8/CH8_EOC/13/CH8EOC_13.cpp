/*
File: CH8EOC_13.cpp
Desc: Try to solve problem #13
Author: spoonais
Date: 1/15/24 @ 2pm
Finished: @ 2:53pm
*/

/*-------- SELF FEEDBACK -----------



-----------------------------------*/
#include<iostream>
#include<fstream>
#include<iomanip>
using namespace std;

//Constants
const int NROW = 10, NCOL = 7;

/*------------ PROGRAMMER DEFINED FUNCTIONS -------------*/

double colavg(double x[][NCOL], int c)
{
    double sum(0);

    for(int i=0; i < NROW; ++i)
    {
        sum = sum + x[i][c-1];
    }

    return sum/NROW;
}

/*-------------------------------------------------------*/

int main()
{
    //Decalare and Init objects:
    ifstream fin;
    int row(0), col(0);
    int user_col(0);
    int valid_tries(0);
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

    //Error checking to ensure user doesnt try to use a column # that exceeds column size of array
    //Gives the user 5 attempts before exiting the program
    do
    { 
        if(valid_tries == 5)
        {
            cout << "The number of attempts has been exceeded...exiting program" << endl;
            exit(1);
        }

        if(valid_tries >= 1)
        {
            cout << "The column # entered is not valid. Please re-enter column #" << endl;
            cout << "WARNING! "<< 5 - valid_tries << " attempts left " << endl;
            cin >> user_col;
            valid_tries++;
            
        }
            else
            {
                //User to provide the column to compute the average 
                cout << "Please provide the column you want the average of" << endl;
                cout << "Range = " << 0 << " - " << col << endl;
                cin >> user_col;
                valid_tries++;
            }

    } while(user_col > col || user_col < 0);

    //Print the lowest value for the data set and what day and week it occurs
    cout << "The average of column: " << user_col << " = " << colavg(MW,user_col) << endl;
    
    //System pause
    system("Pause");

    //Exit
    return 0;

}