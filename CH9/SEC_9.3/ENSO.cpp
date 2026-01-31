/*
File: ENSO.cpp
Desc: To solve section 9.3 my way, not using pointers
Author: spoonais
Date: 01/26/25 @11:47am
Finished: @ 12:43pm
*/

/*--------- 
Self Feedback 




----------*/

#include<iostream>
#include<fstream>
using namespace std;

const int MAX_SIZE = 25;     //Max size of 1D arrays

/*--------- PROGRAMMER DEFINED FUNCTIONS ----------*/



/*-------------------------------------------------*/

int main()
{
    //Decalre and init
    int year[MAX_SIZE], qtr[MAX_SIZE], size(0), dummy(0);
    double index[MAX_SIZE], dummy2(0);
    ifstream fin;

    //Associate and open filestream
    fin.open("enso.txt");
    if(fin.fail())
    {
        cerr << "ERROR! Input file 'enso.txt' failed to open. Exiting program..." << endl;
        exit(1);
    }

    fin >> dummy >> dummy >> dummy2;

    //Assuming the first line of input file DOESNT contain the # of datapoints
    //Count using dummy variables 
    while(!fin.eof())
    {
        size++;
        fin >> dummy >> dummy >> dummy2;
    }

    //Check the size of the dataset
    cout << size << endl;

    //Ensure that the size of dataset doesnt exceed size of 1D arrays
    if(size > MAX_SIZE)
    {
        cout << "The size of the dataset exceeds the MAX_SIZE of arrays" << endl;
        cout << "Keeping arrays at MAX_SIZE. Data will be truncated!" << endl;
    }

    //Reset filestream and then read in data to write to arrays
    fin.close();
    fin.open("enso.txt");
    if(fin.fail())
    {
        cerr << "ERROR! Input file 'enso.txt' failed to open. Exiting program..." << endl;
        exit(1);
    }

    //Read input data to arrays
    for(int i=0; i < size; ++i)
    {
        fin >> year[i] >> qtr[i] >> index[i];
    }

    // //TRBLSHT
    // //Check that arrays were populated
    // for(int i=0; i < size; ++i)
    // {
    //     cout << year[i] << "\t" << qtr[i] << "\t" << index[i] << endl;
    // }

    //Find the largest index value
    double store = index[0];
    int store_yr(0), store_qtr(0);
    for(int i=1; i < size; ++i)
    {
        if(index[i] > store)
        {
            store = index[i];
            store_yr = year[i];
            store_qtr = qtr[i];
        }
    }

    //Print findings
    cout << "Maximum El Nino condition in data file: " << endl;
    cout << "Year: " << store_yr << " , " << "Quarter: " << store_qtr << endl; 

    //Exit
    return 0;
}