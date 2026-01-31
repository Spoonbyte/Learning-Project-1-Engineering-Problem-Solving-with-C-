/*
File: search_ordered.cpp
Desc: To develop the ordered search algorithm
Author: spoonais
Date: 12/12/24 @ 2:10 pm
Finished: 12/12/24 @ 2:35 pm 
*/

/*----------- SELF FEEDBACK -------------

Takeaways:
Originially had this code snip but when I put in a value of 38 it was not returning the position:
----------------------------------------
int indx(0);
    while(indx < n && x[indx]<=value)
    {
        ++indx;
    }
----------------------------------------
The issue was instead of "<=" it should just be "<" becuase when you put 38, it will continue to see the while condition as satisfied so 
it will increment the indx one more to 4 before exiting, so when the compare is done after 
it wont trigger to return the indx since 52 =/= 38
Instead it triggers the else condition
----------------------
if(x[4] == 38)
    {
        return indx;
    }
    else
        return (-1);
---------------------

*/
#include<iostream>
#include<cmath>
#include<fstream>
using namespace std;

/*-------------- PROGRAMMER DEFINED FUNCTION --------------------*/

//My first attempt
int search(const int x[], int n, int value)
{
    int indx(0);
    while(indx < n && x[indx]<value)
    {
        ++indx;
    }

    if(x[indx] == value)
    {
        return indx;
    }
    else
        return (-1);
   
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