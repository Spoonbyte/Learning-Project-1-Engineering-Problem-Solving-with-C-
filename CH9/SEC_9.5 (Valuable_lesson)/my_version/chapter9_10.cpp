/*
File: chapter9_10.cpp
Desc: To solve the Seismic Event detection problem. Use dynamic memory allocation. My version
Author: spoonais
Date: 01/27/25 @ 1:25pm
Finished: @ 2:52pm (but had a 50 min work call from 1:58pm - 2:36pm)
*/

/*--------- 
Self Feedback:

1/28/25
Comparing my code to the books version, I can see my code is specifc for this problem that uses a short window of 2 and 
long window of 5...there is no generalizing to other window sizes


----------*/

#include<iostream>
#include<fstream>
#include<cmath>
using namespace std;

int main()
{
    //Decalre and init
    int npts(0);
    double interval(0), pwr_short(0), pwr_long(0), ratio(0), threshold(0);
    int *power;
    ifstream fin;

    //Get threshold from user 
    cout << "Please provide the threshold value that signals a seismic event" << endl;
    cin >> threshold;

    //Associate filestream with input file and open
    fin.open("seismic.txt");
    if(fin.fail())
    {
        cerr << "ERROR! Input file failed to open. Exiting program..." << endl;
        exit(1);
    }

    //Read in first lines of input file
    fin >> npts >> interval;

    //Use npts to dynamically size the array
    //Use power pointer to create the power array of integers of length npts
    power = new int[npts];

    //Populate array with input file data
    for(int i=0; i < npts; ++i)
    {
        fin >> power[i];
    }

    // //TRBLSHT: Print array to check it is populated
    // for(int i=0; i < npts; ++i)
    // {
    //     cout << power[i] << " ";
    // }
    // cout << endl;

    //Determine locations of possible seimic events 
    //Output to user should be the time interval
    for(int i=4; i < npts; ++i)
    {
        //Short term power
        pwr_short = (pow(power[i],2) + pow(power[i-1],2))/2;
        
        //Long term power (5 point window)
        double sum(0);
        for(int j=i; j>=0; --j)
        {
            sum = sum + pow(power[j],2);
        }
        pwr_long = sum/5;

        //Ratio
        ratio = pwr_short/pwr_long;

        //Compare ratio to threshold.
        if(ratio > threshold)
        {
            cout << "Event at " << (i*interval) << " seconds " << endl;
        }

    } 

    //Return array memory to computer and close filestream
    delete [] power;
    fin.close();

    //Exit
    return 0;
}