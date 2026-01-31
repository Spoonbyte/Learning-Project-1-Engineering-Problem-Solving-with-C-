/*
File: search_binary_v2.cpp
Desc: To develop the binary search algorithm
Author: spoonais
Date: 12/12/24 @ 4:14pm
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

//My second attempt
//**Assuming an even # ordered array, not sure how to deal with odd # ordered array**

int search(const int x[], int n, int value)
{
    int index(0);
    int half_1[4], half_2[4];

    int store = n/2;

    if(x[store-1] > value)
    {
        if(x[n-1] < value)
        {
            return -1;
        }
            else
            {
                for(int i=store; i<n; ++i)
                {
                    half_2[i] = x[i];

                }

            }

    }


    // if(x[index] == value)
    // {
    //     return index;
    // }
    // else
    //     return -1;
    

    

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

    search(arr,npts,value);

    // //Call search function
    // cout << "x[" <<  search(arr,npts,value) << "]" << endl;

    //Pause system
    system("pause");

    //Exit
    return 0;


}