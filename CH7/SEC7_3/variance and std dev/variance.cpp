/*
File: variance.cpp
Desc: To calculate the variance
Author: spoonais
Date: 12/09/24 @ 
*/

/*----------- SELF FEEDBACK -------------

Takeaways:

*/

#include<iostream>
#include<cmath>
#include<fstream>
using namespace std;

//Prototypes (Do I really need these?)
double average(double x[], int elements);


/*--------------------- PROGRAMMER DEFINED FUNCTION --------------------------*/

double average(double x[], int elements)
{
    double sum(0);

    //Sum array
    for(int i=0; i<elements; ++i)
    {
        sum = sum + x[i];
    }

    //Divide sum by # of elements
    return {sum/elements};
}

double variance(double x[], int elements)
{   
    double sum(0), mu(0);
    mu = average(x,elements);                   //This is from the book to make the code more readable

    //Sum all of the variances
    for (int j=0; j<elements; ++j)
    {
       sum = sum + ((x[j] - mu) * (x[j] - mu));

    }

    return {sum/(elements-1)};

}


/*----------------------------------------------------------------------------*/

//Array size
const int N = 20;

int main()
{
    //Decalare and Init objects:
    int npts;
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
    cout << "The variance = " << variance(arr, npts) << endl;

    //Pause system
    system("pause");

    //Exit
    return 0;


}