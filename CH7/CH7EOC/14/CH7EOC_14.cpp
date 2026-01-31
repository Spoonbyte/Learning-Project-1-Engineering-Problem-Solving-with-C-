/*
File: CH7EOC_14.cpp
Desc: To try to solve the 
Author: spoonais
Date: 12/27/24 @ 10:50am
*/

/*-------- SELF FEEDBACK -----------

Use the formula of 
(FPA, lift coeff.)
(a, f(a))   //lower bound
(b, f(b))   //Unknown
(c, f(c))   //upper bound

Solve for f(b):

slope = [f(c)-f(a)] / [c-a]

f(b) = f(a) + [f(c)-f(a) / (c-a)*(b-a)] 

Actually decided to use real data from wind turbine tests

-----------------------------------------------------*/

#include<iostream>
#include<fstream>
#include<string>
#include<cmath>
using namespace std;

/*------------ PROGRAMMER DEFINED FUNCTIONS -------------*/

int verify_order(double x[], int num_pts)
{
    int state(0);

    for(int i = 0; i < num_pts-1; ++i)      //Needed to subtract 1 from "num_pts" since on the last iteration, the array went out of bounds x[16] and this value was a negative number...so it triggered the else case
    {
        if(x[i] <= x[i+1])
        {
            state = 1;
        }
            else
            {
                state = 0;
                break;                  //If a condition of zero is ever met then at least one data point is out of order and needs to be reordered
            } 
    }
    return state;
}

void reorder(double x[], double y[], int num_pts)
{
    for(int i = 0; i < num_pts-1; ++i)      
    {
        int m = i;
        double store_AOA(0), store_CL(0);

        for(int j = i+1; j < num_pts; ++j)
        {
            if(x[j] <= x[m])
            {
                m = j;
            }

        }

        //Do some swapping, keep CL "linked" with AOA
        store_AOA = x[i];
        store_CL = y[i];
        x[i] = x[m];
        y[i] = y[m];
        x[m] = store_AOA;
        y[m] = store_CL;
    }

}

/*-------------------------------------------------------*/

int main()
{
    //Decalare and Init objects:
    ifstream fin;
    string filename;
    double npts(0);                                         //# of data points
    double f_a, f_b, f_c, a, b, c;                          //b is the flight path angle and f_b is the desired lift coeff
    double sample, time, AOA[50], CL[50], Cdp, Cm;
    char com;                                               //Use to store commas from the input file stream
    int result(0);

    //Get input file name from user
    cout << "Provide the name of the input file" << endl;
    cin >> filename;

    //Open and associate file stream
    fin.open(filename.c_str());
    if(fin.fail())
    {
        cerr << "The input file " << filename << " failed to open" << endl;
        exit(1);
    }

    //read in # of data points from first line of file
    fin >> npts;

    //Read in values from input file and store into arrays
    for(int a = 0; a < npts; ++a)
    {
        fin >> sample >> com >> time >> com >> AOA[a] >> com >> CL[a] >> com >> Cdp >> com >> Cm; 
    }

    // //TRBLSHT: Make sure array stored the input file
    // for(int b = 0; b < npts; ++b)
    // {
    //     cout << AOA[b] << " , " << CL[b] << endl; 
    // }

    //Call the ordered function to ensure that the AOA datapoints are in ascending order
    result = verify_order(AOA, npts);

    //If the function is not ordered (0), then call the "reorder function"
    if(result == 0)
    {
        reorder(AOA,CL,npts);
    }
        else
        {
            cout << "The AOA data is ordered" << endl;
        }

    //Print the reordered array
    for(int b = 0; b < npts; ++b)
    {
        cout << AOA[b] << " , " << CL[b] << endl; 
    }

    // //ask user for flight path angle
    // cout << "Please provide the flight path angle (Angle of Attack)" << endl;
    // cin >> b;

    // //EXTRA: Check that the FPA is within the bounds of the data

    // //If b is within bounds, then interpolate the lift coefficient (Cl)
    // //Find the upper and lower bound b is in between
    // for(int i=0; i<npts; ++i)
    // {
    //     if (b > AOA[i] && b < AOA[i+1])           //Chooses the 2 points that b is between and uses them to determine the slope
    //     {
    //         a = AOA[i];
    //         f_a = CL[i];
    //         c = AOA[i+1];
    //         f_c = CL[i+1];
    //     }
    // }

    // // //TRBLSHT:
    // // cout << f_a << " , " << f_c << endl;

    // //calculate the lift coeff
    // f_b = f_a + ((f_c-f_a)*(b-a) / (c-a));
    
    // //print the lift coeff
    // cout << "CL = " << f_b << endl;
  
    //Exit
    return 0;

}