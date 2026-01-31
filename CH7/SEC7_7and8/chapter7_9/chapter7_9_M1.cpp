/*
File: chapter7_9_M1.cpp
Desc: To work with arrays and the string class
Author: spoonais
Date: 12/16/24 @ 2:32pm
Finished: 2:55 pm
*/

/*----------- SELF FEEDBACK -------------

Takeaways:
I realized that I did not completely understand the books solution to the sorting algorithm.
When I tried to implement it to sort characters I realized I was lacking an understanding of what 
m = i and m = k was really doing...

Essentially the m = i was an initializing, similar to doing "store = x[0]"
Then when you do m = k, that was storing the minimum value in the entire array.

*/
#include<iostream>
#include<string>
#include<cmath>
#include<fstream>
using namespace std;

/*-------------- PROGRAMMER DEFINED FUNCTION --------------------*/

//Sort the characters in alphabetical order:
void string_sort(char x[], int n)
{
    for(int i=0; i<n; i++)
    {   
        //Declare and init
        char store('\0');

        int m = i;

        //Finds the "smallest" char
        for(int k=i+1; k<n; ++k)
        {
            if(x[k] < x[m])
            {
                m = k;
            }

        }
        //After 2nd for loop, replace the smallest char with the first position
        store = x[i];
        x[i] = x[m];
        x[m] = store;

        // //Exit after 1 loop to see that B and A swap
        // break;
    }

    for(int j=0; j<n; ++j)
    {
        cout << x[j] << endl;
    }

}

/*---------------------------------------------------------------*/

//Array size
int const N = 50;

int main()
{
    //Declare and init objects

    // //Test script to see how the overload operators for string class works
    // //----------------------------------------------------------------------
    // string a = "A", b = "B";
    // if(b > a)
    // {
    //     cout << "TRUE" << endl;
    // }
    //     else
    //     cout << "FALSE" << endl;
    // //---------------------------------------------------------------------

    //Modify 1:
    //Read in a array of strings
    ifstream fin;
    int npts(0);    //counts the number of data points
    char arr1[N] = {'\0'};

    //Associate the filestream with input file
    fin.open("input.txt");
    //Check
    if(fin.fail())
    {
        cerr << "Input file failed to open" << endl;
        exit(1);
    }   

    //Get # of data points
    fin >> npts;

    //Check that npts doesnt exceed the array size:
    if(npts > N)
    {
        cerr << "The datapoints exceeds the max array size" << endl;
        cerr << "WARNING: Not all data from input file will be used" << endl;
        npts = N;
    }

    //Loop through input file and write to array:
    for(int i=0; i<npts; i++)
    {   
        fin >> arr1[i];
    }
    // //Check that array is stored
    // for(int i=0; i<npts; ++i)
    // {
    //     cout << arr1[i] << endl;
    // }

    //Close input file
    fin.close();

    //Call the sorting function:
    string_sort(arr1,npts);

    //Pause system
    system("pause");

    //Exit
    return 0;

}