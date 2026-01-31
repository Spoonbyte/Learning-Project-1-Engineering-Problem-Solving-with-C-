/*
File: CH8EOC_19.cpp
Desc: Try to solve problem #19
Author: spoonais
Date: 1/17/24 @ 1:44pm
50%: @ 2:44PM
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


int main()
{
    //Decalare and Init objects:
    int top(0), right(0), bottom(0), left(0);             //The temps of each side of the hot plate
    int row(6), col(8);

    //Set the precision for cout
    cout << fixed << setprecision(3);   //4 decimal place

    //Get user input for hot plate side temps
    cout << "Please provide the temps for each size of the hotplate" << endl;
    cout << "top" << endl;
    cin >> top;
    cout << "right" << endl;
    cin >> right;
    cout << "bottom" << endl;
    cin >> bottom;
    cout << "left" << endl;
    cin >> left;
    
    //Create the row vector (will be an ELEMENT of the overall MW vector)
    //Creates a 6 X 8 array
    vector<double> ROW(col,0);              //init each element with zero
    //Create the 2D vector
    vector<vector<double>> temp(row,ROW);     //init each element with row vector

    // //
    // int row_size = temp.size();

    //Assign the side temps to the relevant elements
    //Top and bottom
    //NOTE: Not sure how to make scalable to any size array? For now making specific for this problem
    for(int i=0; i < temp.size(); i += 5)
    {
        for(int j=0; j < temp[i].size(); ++j)
        {
            switch(i)
            {
                case 0:
                    temp[i][j] = top;
                    break;
                case 5:
                    temp[i][j] = bottom;
                    break;
            }
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