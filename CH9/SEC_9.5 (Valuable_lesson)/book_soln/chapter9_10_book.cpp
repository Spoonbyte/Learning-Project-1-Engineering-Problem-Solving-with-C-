/*
File: chapter9_10_book.cpp
Desc: To solve the Seismic Event detection problem. Use dynamic memory allocation. Books version
Author: spoonais
Date: 01/28/25 @ 3:00pm
Finished copying @3:15pm

*/

/*--------- 
Self Feedback:


----------*/

#include<iostream>
#include<fstream>
#include<cmath>
using namespace std;

/*--------- PROGRAMMER DEFINED FUNCTIONS ----------*/

double power_w(double arr[], int length, int n)
{
    //Declare adn init objects
    double xsquare(0);

    //Compute sum of values squared in the array x
    for(int k=0; k < n; ++k)
    {
        xsquare += pow(arr[length-k],2);
    }

    return xsquare/n;

}

/*-------------------------------------------------*/

//Set threshold
const double THRESHOLD = 1.5;

int main()
{
    //Decalre and init objects
    int npts, short_window(2), long_window(5);
    double time_incr, *sensor, short_pwr, long_pwr, ratio;
    ifstream fin;

    //Associate and open input file
    fin.open("seismic.txt");
    if(fin.fail())
    {
        cerr << "ERROR! Input file failed to open" << endl;
        exit(1);
    }

    //Read data header and allocate memory
    fin >> npts >> time_incr;
    sensor = new double[npts];

    //Program continues if no exception is thrown
    cout << "Memeory allocated." << endl;

    //Read data into array
    for(int k=0; k < npts; ++k)
        fin >> sensor[k];
    
    //Read window sizes (NOTE: I just set them for ease of running program)

    //Compute power ratios and search for events
    //Note using the "long_window-1" allows the program to know where to start in the array
    for(int k=long_window-1; k < npts; ++k)
    {
        short_pwr = power_w(sensor, k, short_window);
        long_pwr = power_w(sensor, k, long_window);
        ratio = short_pwr/long_pwr;
        if(ratio > THRESHOLD)
        {
            cout << "Possible event at " << time_incr*k 
                                        << " seconds \n";
        }
    }

    //Return memory to free-store, close file and exit program
    delete [] sensor; 
    fin.close();
    return 0;
}