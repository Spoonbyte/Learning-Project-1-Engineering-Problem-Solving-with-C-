/*
File: variance.cpp
Desc: To use the stat_lib custom library
Author: spoonais
Date: 12/10/24 @ 2:15pm
Finished: 12/10/24 @ 3pm
*/

/*----------- SELF FEEDBACK -------------

Takeaways:

*/

#include "stat_lib.h"
#include<iostream>
#include<cmath>
#include<fstream>
using namespace std;

//Array size
const int N = 50;

int main()
{
    //Decalare and Init objects:
    int npts;
    ifstream fin;
    double arr[N]={0}, sum(0), avg(0);
    string filename;

    //User file to process
    cout << "Provide file name " << endl;
    cin >> filename;

    //open the filestream
    fin.open(filename.c_str());

    //Check that inputfile opens
    if(fin.fail())
    {
        cerr << "The input file failed to open...exiting program" << endl;
        exit(1);
    }

    //read in number of values
    fin >> npts;

    //Alert user the dataset is bigger than the array
    if(npts > N)
    {
        cerr << "The number of data points (" << npts << ") exceeds the array size (" << N << ")" << endl;
        cerr << "WARNING: Only the data points up the array size will be included!!!" << endl;
        npts = N;
    }

  
    //Write values to store into the array and compute the sum 
    for(int i=0; i<npts; ++i)
    {
        fin >> arr[i];
         
    }

    //Done with the input file
    fin.close();

    //Call variance function
    cout << "The mean = " << mean(arr,npts) << endl;
    cout << "The median = " << median(arr,npts) << endl;
    cout << "The variance = " << variance(arr, npts) << endl;
    cout << "The standard deviation = " << std_dev(arr,npts) << endl;

    //Pause system
    system("pause");

    //Exit
    return 0;


}