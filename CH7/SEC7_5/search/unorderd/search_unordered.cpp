/*
File: search_unordered.cpp
Desc: To develop the search algorithm
Author: spoonais
Date: 12/12/24 @ 12:57pm
Finished 12/12/24 @ 2pm
*/

/*----------- SELF FEEDBACK -------------

Takeaways:
When initally trying to compile I kept getting the error  "[warning: control reaches end of non-void function [-Wreturn-type]"
but the actual issue was that i was trying to do a return within a loop...the error from the compiler was not helpful at all
If the error was cannot return multiple times within funtion that would have been more helpful

My original code snippet that didnt complie:
---------------------------------------------------------
for(int i=0; i<n; ++i)
    {
        //compare each element to the intended value
        if(x[i] == value)
            return i;
        else 
            return -1;

    }
---------------------------------------------------------

Comparing the txtbooks' method of using a while loop vs my for loop; it might make sense to use a while loop when doing 
any kind of search algorithm because it can be stopped just by the conditions...whereas the for loop needs to be stopped 
using the break function...although I'd argue my version is easier to understand quickly

*/
#include<iostream>
#include<cmath>
#include<fstream>
using namespace std;

/*-------------- PROGRAMMER DEFINED FUNCTION --------------------*/

//My first attempt
int search(const int x[], int n, int value)
{
    //Declare and init
    int indx(0);
    for(int i=0; i<n; ++i)
    {
        //compare each element to the intended value
        if(x[i] == value)
        {
            indx = i;
            break;
        }
        else
            indx = -1;
    }

    return indx;

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