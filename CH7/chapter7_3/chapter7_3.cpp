/*
File: chapter7_3.cpp
Desc: To read a bunch of floating point numbers, find the average and then print numbers above the average
Author: spoonais
Date: 12/03/24 @ 3:12pm
Finished 12/03/24 @ 3:54pm
*/

/*-------- SELF FEEDBACK -----------*/
/*

I was able to guess the books technique for how to solve this not using an array (The Modify! for this problem)...
I said that you would have to open read from the file twice...once to compute the avg 
and then a second time to compare the values to the avg...this is exactly what the book recommended which felt good!

Also had the thought that you could wait to read how many data points are in the file and then you could set the array size to that?
Might be a bad idea in case the data set is massive....

*/
/*-----------------------------------*/

#include<iostream>
#include<fstream>
#include<cmath>
using namespace std;

//Array size
const int N = 10;

int main()
{
    //Decalare and Init objects:
    int datapoints(0), counter(0);
    ifstream fin;
    double arr[N]={0}, sum(0), avg(0);

    //open the filestream
    fin.open("numbers.txt");

    //Check that inputfile opens
    if(fin.fail())
    {
        cerr << "The input file failed to open...exiting program" << endl;
        exit(1);
    }

    //read in number of values
    fin >> datapoints;

    //Alert user the dataset is bigger than the array
    if(datapoints > N)
    {
        cerr << "The number of data points (" << datapoints << ") exceeds the array size (" << N << ")" << endl;
        cerr << "WARNING: Only the data points up the array size will be included!!!" << endl;
        datapoints = N;
    }

    //Write values to store into the array and compute the sum 
    for(int i=0; i<datapoints; ++i)
    {
        fin >> arr[i];
        //Calculate the sum
        sum = sum + arr[i];
         
    }

    //Done with the input file
    fin.close();

    //Calculate the average
    avg = sum/datapoints;
    cout << "avg = " << avg << endl;

    //Compare the arr[] values to find those greater than the average
    for(int k=0; k<datapoints; ++k)
    {
        if(arr[k] > avg)
        {   
            counter++;
            // cout << "Above Average = " << arr[k] << endl;
        }

    }

    cout << "The number of values above average = " << counter << endl;

    //Exit
    return 0;

}