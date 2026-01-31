/*
File: chapter7_5.cpp
Desc: To create a program that reads a data file containing storms and their max winds. 
Author: spoonais
Date: 12/06/24 @ 1:16pm
Finished: 4:00pm
*/

/*-------- SELF FEEDBACK -----------*/
/*

I choose not to do the Modify! problems for this since they all seemed focused on the formatting of the data 
instead of anything new in terms of arrays that I need to learn.


*/
/*-----------------------------------*/

#include<iostream>
#include<fstream>
#include<cmath>
using namespace std;

/*---------------- PROGRAMMER DEFINED FUNCTION ----------------------*/

void hurricane(int x[], int y[], int datapoints )
{   
    int store_max = 0;               //Init 

    for(int k=0; k<datapoints; ++k)     //Determine the highest wind speed in the dataset
    {
        if(y[k] > store_max)
        {
            store_max = y[k];
        }
    }

    if(store_max <= 74)
    {
        cout << "No hurricanes in the file " << endl;
    }

    for(int i=0; i<datapoints; ++i)
    {
        //Determine the category of all the storms
        int cat(0);
 
        switch (y[i])                   //Not sure how I would deal with floating point since the switch() only takes int and enum datatypes
        {
            case 74 ... 94:
                cat = 1;
                break;
            case 95 ... 110:
                cat = 2;
                break;
            case 111 ... 129:
                cat = 3;
                break;
            case 130 ... 156:
                cat = 4;
                break;
            case 157 ... 250:
                cat = 5;
                break;
    
        }

        if(y[i] > 74)
        {
            if(y[i] == store_max)
            {
                cout << "**StormID:" << x[i] << " Max Winds: " << y[i] << " Category: " << cat << endl;
            } 
            else
                {
                    cout << "  StormID:" << x[i] << " Max Winds: " << y[i] << " Category: " << cat << endl;
                }
        } 


    }

}

/*-------------------------------------------------------------------*/

//Max Array size
const int N = 20;
//Input file path
const string FILENAME = "storms.txt";

int main()
{
    //Decalare and Init objects:
    ifstream fin;
    int npts(0);    //counter for actual number of values in the data file...prevents hurricane() from reading the ENTIRE array
    int stormID[N] = {0};
    int windspeed[N] = {0};

    //Associate filestream with file
    fin.open(FILENAME);

    //Check that file opens
    if(fin.fail())
    {
        cerr << "The input file failed to open...exiting program" << endl;
        exit(1);
    } else 
        {
            cerr << "File Opened!" << endl;
        }


    //Read in the file, store to arrays
    while(!fin.eof())
    {
        fin >> stormID[npts] >> windspeed[npts];
        ++npts;
    }

    //TRBLSHT: Ensure the array stores the file data
    // for(int i=0; i<npts; ++i)
    // {
    //     cout << stormID[i] << "\t" << windspeed[i] << endl;
    // }
    
    //Call the function hurricane
    hurricane(stormID,windspeed,npts);

    //Pause
    system("pause");

    //Exit
    return 0;

}