/*
File: ENSO_book.cpp
Desc: To solve section 9.3 books solution (using pointers)
Author: spoonais
Date: 01/26/25 @12:53pm
Finished: @ 1:15pm
Started Modify 2: @ 2:35pm
Finished Modify 2: @ 3:20pm
*/

/*--------- 
Self Feedback 




----------*/

#include<iostream>
#include<fstream>
#include<cmath>
using namespace std;

const int MAX_SIZE = 25;     //Max size of 1D arrays

int main()
{
    //Decalre and init
    int year[MAX_SIZE], qtr[MAX_SIZE], k(0), minK(0);
    double index[MAX_SIZE];
    ifstream fin;

    //Associate and open filestream
    fin.open("enso.txt");
    if(fin.fail())
    {
        cerr << "ERROR! Input file 'enso.txt' failed to open. Exiting program..." << endl;
        exit(1);
    }

    fin >> *year >> *qtr >> *index;
    // cout << year[0] << "\t" << qtr[0] << "\t" << index[0] << endl;

    // //Read input data to arrays
    // //While reading into array also checking to find the largest value
    // while(fin)
    // {
    //     //Find the largest index value
    //     if(*(index + k) > *(index + maxK))
    //     {
    //         maxK = k;
    //     }
    //     //increment k
    //     k++;
    //     //Get next set of values by incrementing the addresses of array
    //     fin >> *(year + k) >> *(qtr + k) >> *(index + k);
    // }

    //Modify! 2: Find the most normal condition
    while(fin)
    {
        //Find the smallest index value
        if(fabs(*(index + k)) < fabs(*(index + minK)))
        {
            minK = k;
        }

        //increment k
        k++;

        //Get next set of values by incrementing the addresses of array
        fin >> *(year + k) >> *(qtr + k) >> *(index + k);
    }

    // cout << minK << endl;

    //Print findings
    cout << "Closest nominal conditions in data file: " << endl;

    //Go back through the arrays and search for multiple occurances of the same nominal index
    for(int i=0; i < 11; i++)
    {
        if(fabs(index[i]) == fabs(*(index + minK)))
        {
            cout << "Year: " << year[i] << " , " << "Quarter: " << qtr[i] << endl; 
        }
    }

    //Exit
    return 0;
}