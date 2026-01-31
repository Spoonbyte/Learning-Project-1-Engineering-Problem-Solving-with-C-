/*
File: CH8EOC_15.cpp
Desc: Try to solve problem #15
Author: spoonais
Date: 1/16/24 @ 1:30pm
Finished: @ 1:50pm
*/

/*-------- SELF FEEDBACK -----------
This is useful to a plant operator because it can tell them how much power on average a particular day
generates, and once you measure that then you can ask questions like why is Sunday the lowest demand
or why is Thursday the highest?

You could then also plot this data along with outside temp data to see if there is a relationship there.
-----------------------------------*/
#include<iostream>
#include<fstream>
#include<vector>
#include<iomanip>
#include<string>
using namespace std;

/*------------ PROGRAMMER DEFINED FUNCTIONS -------------*/

double week_avg(vector<vector<double>> &x, int c)
{
    double sum(0);

    for(int i=0; i < x.size(); ++i) 
    {
        sum = sum + x[i][c];        //Traverse downn a column(week)
    }

    return sum/(x.size());
}

/*-------------------------------------------------------*/

int main()
{
    //Decalare and Init objects:
    ifstream fin;
    int row(0), col(0);

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
    
    //Create the row vector (will be an ELEMENT of the overall MW vector)
    vector<double> ROW(col,0);              //init each element with zero
    //Create the 2D vector
    vector<vector<double>> MW(row,ROW);     //init each element with row vector

    //Read in the array
    for(int i=0; i < MW.size(); ++i)
    {
        for(int j=0; j < MW[i].size(); ++j)
        {
            fin >> MW[i][j];
        }
    }

    // //TRBLSHT
    // //Print array to console to ensure was written
    // for(int i=0; i < MW.size(); ++i)
    // {
    //     for(int j=0; j < MW[i].size(); ++j)
    //     {
    //         cout << MW[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    //Print the average MW for each week
    for(int i=0; i < col; ++i)
    {   
        string day;
        switch(i)
        {
            case 0:
                day = "Sunday";
                break;
            case 1:
                day = "Monday";
                break;
            case 2:
                day = "Tuesday";
                break;
            case 3:
                day = "Wednesday";
                break;
            case 4:
                day = "Thursday";
                break;
            case 5:
                day = "Friday";
                break;
            case 6:
                day = "Saturday";
                break;
        }
        //Print the average for each week
        cout << day << " average output over " << row << " weeks = " << week_avg(MW,i) << " MW " << endl;
    }
    
    
    //System pause
    system("Pause");

    //Exit
    return 0;

}