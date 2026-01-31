/*
File: Tsunami_Warn_M3.cpp
Desc: To develop a significant wave height calculator but without sorting the array
Author: spoonais
Date: 12/xx/24 @ 
Finished: 12/xx/24 @ 
*/

/*----------- SELF FEEDBACK -------------

Takeaways:

*/
#include<iostream>
#include<cmath>
#include<fstream>
using namespace std;

/*-------------- PROGRAMMER DEFINED FUNCTION --------------------*/

//Average Function
double mean(double x[], int n)
{   
    //Declare and init
    double sum(0);

    for(int i=0; i<n; ++i)
    {
        sum = sum + x[i];
    }

    return sum/n;
}

//My first attempt
//Function takes the 
double WVHT(double x[], int n)
{
    //Declare and init objects
    int m(0);
    double hold(0);
    double arr[6] = {0};


    //Sort the array in ascending order
    for(int k=0; k<n-1; ++k)
    {
        //Find position of smallest value in array
        //beginning at k
        m = k;

        for (int j=k+1; j<=n-1; ++j)
        {
            if(x[j] < x[m])
            {
                m = j;
            }
        }

        //Exchange samllest value with value at k
        hold = x[m];
        x[m] = x[k];
        x[k] = hold;
    }

    // //TRBLSHT:
    // //Check to see if sorted
    // for(int m=0; m<n; m++)
    // {
    //     cout << x[m] << endl;
    // }

    //Find the highest 1/3 of WH's
    int offset = n - floor(n/3);
    // cout << offset << endl;

    for(int k=0; k<floor(n/3); ++k)
    {
        arr[k] = x[offset + k];
    }

    // //Check that array was created
    // for(int a=0; a<floor(n/3); ++a)
    // {
    //     cout << arr[a] << endl;
    // }
   
    // //Average the 1/3 highest values
    return mean(arr,floor(n/3));

}

/*---------------------------------------------------------------*/

//Array size
const int N = 50;

int main()
{
    //Decalare and Init objects:
    int npts;
    ifstream fin;
    int year[N] = {0};
    int month[N] = {0};
    int day[N] = {0};
    int hour[N] = {0};
    int min[N] = {0};
    double WH[N] = {0};
    
    //open the filestream
    fin.open("JulySample.txt");

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
  
    //Write values to store into the array(s)
    for(int i=0; i<npts; ++i)
    {
        fin >> year[i] >> month[i] >> day[i] >> hour[i] >> min[i] >> WH[i];   
    }

    //Done with the input file
    fin.close();

    //Print data start and end times
    cout << "START TIME: "  << year[0] << month[0] << day[0] << hour[0] << min[0] << endl;
    cout << "END TIME: "    << year[npts-1] << month[npts-1] << day[npts-1] << hour[npts-1] << min[npts-1] << endl;

    //Call WVHT function
    cout << "WVHT = " << WVHT(WH,npts) << endl;

    //Pause system
    system("pause");

    //Exit
    return 0;

}