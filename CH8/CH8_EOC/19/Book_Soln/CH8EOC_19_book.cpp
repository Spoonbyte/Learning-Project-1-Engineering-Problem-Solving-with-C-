/*
File: CH8EOC_19_book.cpp
Desc: Create the books solution for problem 19.
Author: spoonais
Date: 1/19/24 @ 11:37pm
Finished: @ 
*/

/*-------- SELF FEEDBACK -----------


-----------------------------------*/
#include<iostream>
#include<fstream>
#include<vector>
#include<iomanip>
#include<string>
using namespace std;

/*------------ PROGRAMMER DEFINED FUNCTIONS -------------*/

/*
Function objective: 
Pre-Cond: 
Post-Cond: 
*/

/*-------------------------------------------------------*/

const int NO_OF_ROWS = 6;
const int NO_OF_COLS = 8;

int main()
{
    //Decalare and Init objects:
    int r,c;
    bool done(false);
    double top, right, bottom, left, tolerance, check_val, update_temp;
    double maxUpdate = 0;
    
    vector<double> table(NO_OF_ROWS,NO_OF_COLS);

    //Get user input for hot plate side temps
    cout << "Please provide the temps for each size of the hotplate" << endl;
    cin >> top >> right >> bottom >> left;

    //tolerance
    cout << "Enter tolerance value, greater than zero" << endl;
    cin >> tolerance;

    //Store abs value of tolerance
    tolerance = fabs(tolerance);
    
   
    for(r=1; r < NO_OF_ROWS; r++)
    {
        for(c=1; c < NO_OF_COLS; c++)
        {
            table[r][c];
        }

    }

    //Right and Left
    for(int i=1; i < temp.size()-1; ++i)
    {
        //Right
        temp[i][7] = right;
        //Left
        temp[i][0] = left;
    }


    // //TRBLSHT
    // //Print array to console to ensure was written
    // for(int i=0; i < temp.size(); ++i)
    // {
    //     for(int j=0; j < temp[i].size(); ++j)
    //     {
    //         cout << temp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
  
    // //Use a do while loop to keep calculating the temps based on the user tolerance value
    // double tolerance(0);

    // //Ask user for tolerance value
    // cout << "Provide the max temp value that you want" << endl;
    // cin >> tolerance;

    //
    int iters;
    cin >> iters;
    //See how hot temps get 
    for(int h=0; h < iters; ++h)
    {
        //Solve the zero elements using adjacent points
        for(int i=1; i < temp.size()-1; ++i)
        {

            for(int j=1; j < temp[i].size()-1; ++j)
            {
                temp[i][j] = (temp[i+1][j] + temp[i-1][j] + temp[i][j+1] + temp[i][j-1])/4;
            }
        }

    }

    
    //TRBLSHT
    //Print array to console to ensure was written
    for(int i=0; i < temp.size(); ++i)
    {
        for(int j=0; j < temp[i].size(); ++j)
        {
            cout << temp[i][j] << " ";
        }
        cout << endl;
    }

    //System pause
    system("Pause");

    //Exit
    return 0;

}