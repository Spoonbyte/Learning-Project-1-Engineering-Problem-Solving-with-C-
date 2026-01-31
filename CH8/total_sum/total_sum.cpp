/*
File: total_sum.cpp
Desc: Try to compute the total sum of a 2D array and then the partial sum
Author: spoonais
Date: 1/4/24 @ 6:43am

*/

/*-------- SELF FEEDBACK -----------

-----------------------------------*/
#include<iostream>
#include<fstream>
#include<string>
using namespace std;

//Constants
const int NROW = 4, NCOL = 4;

/*------------ PROGRAMMER DEFINED FUNCTIONS -------------*/

double total_sum(double x[][NCOL])
{
    double total(0);

    for(int i=0; i < NROW; ++i)
    {
        for(int j=0; j < NCOL; ++j)
        {
            total += x[i][j];
        }
    }

    return total;
}

double partial_sum(double x[][NCOL], int a, int b)
{
    double partial(0);

    for(int i=0; i < a; ++i)
    {
        for(int j=0; j < b; ++j)
        {
            partial += x[i][j];
        }
    }

    return partial;
}

/*-------------------------------------------------------*/

int main()
{
    //Decalare and Init objects:
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

    //Calcuate the total sum
    cout << "Total Sum = " << total_sum(x) << endl;

    //Decalare and init
    int part_Row(0), part_Col(0);

    //Get user input on where to compute partial array
    cout << "Please provide the rows" << endl;
    cin >> part_Row;
    cout << "Please provide the columns" << endl;
    cin >> part_Col;

    //Calculate the partial sum
    cout << "Partial Sum = " << partial_sum(x,part_Row,part_Col) << endl;

    //System pause
    system("Pause");

    //Exit
    return 0;

}