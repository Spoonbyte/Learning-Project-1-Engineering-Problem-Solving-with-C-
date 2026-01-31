/*
File: chapter7_4.cpp
Desc: To read an input file and call a function to find the largest number
Author: spoonais
Date: 12/04/24 @ 12:16pm
Finished 12/04/24 @ 1:45pm
*/

/*-------- SELF FEEDBACK -----------*/
/*


*/
/*-----------------------------------*/

#include<iostream>
#include<fstream>
#include<cmath>
using namespace std;

/*---------------- PROGRAMMER DEFINED FUNCTION ----------------------*/

double MaxValue(double x[], double datapoints )
{   
    double store_max = x[0];    //Get the first value from array

    for(int i=1; i<datapoints; ++i)
    {
        if(x[i] > store_max)
        {
            store_max = x[i];
        }

    }

    return store_max;

}

/*-------------------------------------------------------------------*/

//Max Array size
const int N = 100;
//Input file path
const string FILENAME = "C:/Users/sanja/Documents/Local C++ Workspace/CH7/chapter7_4/Input_File_Gen/Input.txt";

int main()
{
    //Decalare and Init objects:
    ifstream fin;
    int npts(0);    //counter for actual number of values in the data file...prevents MaxValue() from reading the ENTIRE array
    double check(0), max(0);
    double arr1[N] = {0};

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

    //Store the first array element 
    fin >> arr1[npts];      //Will store arr1[0]

    //Read in the total number of data points and compare to the max array size
    while(!fin.eof() && npts < N)       
    {
        npts++;    

        //My attempt to prevent the array from going past N
        //The advantage with my attempt is that it tells the user the datapoints have exceeded the array size 
        //So if they were expecting all of the dataset to be used, they'd know not all of it is being used...
        // if(npts > N)
        // {
        //     cout << "Number of data points (" << npts << ") exeeds max array size (" << N << ")." << endl;
        //     cout << "Only the first " << N << " data points will be included " << endl;
        //     break;
        // }

        fin >> arr1[npts];
    
    }
    //TRBLSHT//
    cout << npts << endl;

    //close the file stream since array is stored.
    fin.close();

    //Now that we have the array filled and the # of actual datapoints call the function to get the max value
    max = MaxValue(arr1, npts);

    //Print the result
    cout << "The max value is = " << max << endl;

    //Pause
    system("pause");

    //Exit
    return 0;

}