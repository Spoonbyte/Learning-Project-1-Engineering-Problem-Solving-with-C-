/*
File: median.cpp
Desc: To calculate the median of a given array.
Author: spoonais
Date: 12/07/24 @12:51pm
*/

/*----------- SELF FEEDBACK -------------

Takeaways:

- Not sure why I had to typcast the floor(elements/2) with the int datatype?



*/

#include<iostream>
#include<cmath>
#include<fstream>
using namespace std;

/*--------------------- PROGRAMMER DEFINED FUNCTION --------------------------*/

double median(double x[], int elements)
{
    //Determine if the array have an even or odd # of elements
    double mid1(0), mid2(0);

    if(elements%2 == 0)                             //This means that the file has even # of elements            
    {
        //Find the 2 middle numbers
        mid1 = x[elements/2];
        mid2 = x[(elements/2)-1];

        //Find the median
        return {(mid1+mid2)/2};

    }
        else
        {
            //Find the middle number
            return x[(int)floor(elements/2)];       //for some reason it kept giving an error that the result of floor(elements/2) was not an int....so I typcasted(I think thats the term?) and it worked.
            
        }

}

/*----------------------------------------------------------------------------*/

//Array size
const int N = 20;

int main()
{
    //Decalare and Init objects:
    ifstream fin;
    string filename;                //Made it variable since I have 2 files I want to open
    int npts(0);                    //Keeps track of the # of datapoints
    double arr1[N] = {0};              //Array to store values from file

    //Get the file name
    cout << "Please provide the name of the file to open" << endl;
    cin >> filename;

    //Associate the filestream with the file
    fin.open(filename.c_str());

    //Check that the file opened
    if(fin.fail())
    {
        cerr << "Input file: " << filename << " failed to open " << endl;
        exit(1);
    }

    //Read the first data point
    // fin >> arr1[npts];

    //Read the file into the array
    while(fin >> arr1[npts])
    {npts++;}

    cout << "Number of elements = " << npts << endl;

    // //To check the array stored all the values
    // for(int i=0; i<npts; i++)
    // {
    //     cout << arr1[i] << endl;
    // }

    //Call the funtion to find the median 
    cout << "The median of the numbers = " << median(arr1,npts) << endl;


    system("pause");

    //Exit
    return 0;


}