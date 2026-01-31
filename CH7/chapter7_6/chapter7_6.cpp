/*
File: chapter7_6.cpp
Desc: Only worked on the "zero crossing function" 
Author: spoonais
Date: 12/10/24 @ 3:36pm
Finished 12/10/24 @ 4:55pm
*/

/*----------- SELF FEEDBACK -------------

Takeaways:

I developed my first attempt and I knew it was kind of cumbersome and when I noticed that the 
book seemed to solve it with way less lines of code, I figured it out before looking at the books solution.
There had to be a simpler way to determine if there was a zero crossing...and my intuition about it being a simple math rule was correct.

Reason for not doing entire problem:
Because all of the rest of the problem seemed pretty stright forward.
And I wanted to catch back up to my schedule...since I'd be a day behind if I kept working on the entire problem.
Also I dont have access to the "zero.dat" file with the sound data from the instructors CD...so I will call this "GOOD ENOUGH"

This would actually be an interesting problem to come back to. I could possible record my own sound and export it 
to a array file using FL studio or something. I assume this is how speech recognition software works by running stat analysis 
on the sound files and then comparing these stats to a reference stat file that is related to a specific word...

*/
#include<iostream>
#include<cmath>
#include<fstream>
using namespace std;

/*-------------- PROGRAMMER DEFINED FUNCTION --------------------*/

// //My first attempt
// int zero_cross(const double x[], int n)
// {   
//     int counter(0);
//     for(int i=0; i<n; ++i)
//     {
//         if((x[i]>=0 && x[i+1]>=0) ||(x[i]<=0 && x[i+1]<=0) )
//         {           
//         }
//             else
//             {             
//                 counter++;  
//             }
//     }
//     return counter;
// }

//Second attempt...and this version matched what the book had!!!
int zero_cross(const double x[], int n)
{   
    int counter(0);
    for(int i=0; i<n-2; i++)
    {
        if((x[i]*x[i+1]) < 0)   //Simple math rule: Postive * Negative is always a negative
        {
            counter++;
        }
        
    }

    return counter;
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

    //Call variance function
    cout << "The # of zero crossings = " << zero_cross(arr, npts) << endl;

    //Pause system
    system("pause");

    //Exit
    return 0;


}