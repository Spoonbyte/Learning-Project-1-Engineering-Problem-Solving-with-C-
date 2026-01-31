/*
File: search_binary.cpp
Desc: To develop the binary search algorithm
Author: spoonais
Date: 12/12/24 @ 
Finished: 
*/

/*----------- SELF FEEDBACK -------------

Takeaways:



*/
#include<iostream>
#include<cmath>
#include<fstream>
using namespace std;

/*-------------- PROGRAMMER DEFINED FUNCTION --------------------*/

//My first attempt
//**Assuming an even # ordered array, not sure how to deal with odd # ordered array**

int search(const int x[], int n, int value)
{
    int index(0);
    int n_store = n;    //Will always be the n value before the new n value
    n = n/2;            //Divide the array in half

    //The first half array
    for(int i=0; i<n; ++i)
    {
        //Check to see if max value in this half is less than the value:
        //If it is, then you can ignore this half
        //If not, then you split again
        if (x[n-1] < value)
        {
            break;          //Exit this for loop to enter the next array half
        }
            else            //Stay in this for loop until you find the value
            {
                n_store = n;
                n = n/2;
            }
    }

    //Second half of array
    for(int j=n; j<n_store; ++j)
    {
        //test for max value in array 
        if (x[n-1] > value)
        {
            break;
        }
            else
            {
                n_store = n;
                n = n/2;
            }

    }

}
/*---------------------------------------------------------------*/

//Array size
const int N = 20;

int main()
{
    //Decalare and Init objects:
    int npts, value(0);
    ifstream fin;
    int arr[N]={0}, sum(0), avg(0);
    
    //open the filestream
    fin.open("input.txt");

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

    //Get the value the user wants the position of
    cout << "Please provide the value you want to find the position of " << endl;
    cin >> value;
  
    //Write values to store into the array and compute the sum 
    for(int i=0; i<npts; ++i)
    {
        fin >> arr[i];
         
    }

    //Done with the input file
    fin.close();

    //Call search function
    cout << "x[" <<  search(arr,npts,value) << "]" << endl;

    //Pause system
    system("pause");

    //Exit
    return 0;


}