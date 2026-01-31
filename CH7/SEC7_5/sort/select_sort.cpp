/*
File: select_sort.cpp
Desc: To develop the select sorting algorithm
Author: spoonais
Date: 12/11/24 @ 6:26am
Finished 12/11/24 @ 7:20am
*/

/*----------- SELF FEEDBACK -------------

Takeaways:


*/
#include<iostream>
#include<cmath>
#include<fstream>
using namespace std;

/*-------------- PROGRAMMER DEFINED FUNCTION --------------------*/

/*
//My first attempt
void select_sort (double x[], int n)
{
    int store(0), store_min_place(0), j_val(0);
    double min_val = x[0];

    for(int i=0; i<n; i++)
    {   

        //Min_finder logic
        for(int j=j_val; j<n; j++)
        {
            if(x[j] <= min_val)         //Needed the " = " to allow the "store_min_place" variable to be updated from the initial run...now the function works!
            {
                min_val = x[j];
                store_min_place = j;
            }

        }
        
        store = x[i];                   //store element to be swapped
        x[i] = min_val;                 //Move min value to front   
        x[store_min_place] = store;     //Move original element to back 
        // break;  

        min_val = x[i+1];                //Increment up the min value init to ignore the LOWEST value now
        j_val++;                            //To prevent the Min_Finder logic from using the lowest value again

    }

    // //TRBLSHT: Print min value
    // cout << min_val << endl;
    // cout << store_min_place << endl;

    //Check to see if sorted
    for(int m=0; m<n; m++)
    {
        cout << x[m] << endl;
    }

    return;

}

*/

//The books solution
void select_sort(double x[], int n)
{
    //Declare and init objects
    int m(0);
    double hold(0);

    for(int k=0; k<n-2; ++k)
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

    //Check to see if sorted
    for(int m=0; m<n; m++)
    {
        cout << x[m] << endl;
    }

    //Void return 
    return;

}

/*---------------------------------------------------------------*/

//Array size
const int N = 20;

int main()
{
    //Decalare and Init objects:
    int npts;
    ifstream fin;
    double arr[N]={0}, sum(0), avg(0);
    
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

  
    //Write values to store into the array and compute the sum 
    for(int i=0; i<npts; ++i)
    {
        fin >> arr[i];
         
    }

    //Done with the input file
    fin.close();

    //Call sort function
    select_sort(arr,npts);

    //Pause system
    system("pause");

    //Exit
    return 0;


}