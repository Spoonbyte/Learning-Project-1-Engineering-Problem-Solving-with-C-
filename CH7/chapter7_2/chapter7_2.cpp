/*
File: chapter7_2.cpp
Desc: To try to assign values to 2 arrays read from an input file
Author: spoonais
Date: 12/03/24 @ 2:30pm
*/

/*-------- SELF FEEDBACK -----------*/
/*



*/
/*-----------------------------------*/

#include<iostream>
#include<fstream>
#include<cmath>
using namespace std;

int main()
{
    //Decalare and Init objects:
    ifstream fin;
    double time[10], motion[10];
    int counter(-1);

    //Open the input file
    fin.open("sensor3.txt");

    //Check to ensure it opened
    if(fin.fail())
    {
        cout << "Input file failed to open...exiting program " << endl;
        exit(1);
    }

    //Read in first set of values
    // fin >> time[0] >> motion[0];
    
    //Read in the file
    while(!fin.eof())
    {
        counter++;
        fin >> time[counter] >> motion[counter];
        cout << time[counter] << "\t" << motion[counter] << endl;   //Book solution to combine the write and read into the same loop 
    }

    //My solution
    // //Print to console to verify with sensor3.txt
    // //Header 
    // cout << "TIME" << "\t" << "MOTION" << endl;
    // for(int i=0; i<counter; ++i)
    // {
    //     cout << time[i] << "\t" << motion[i] << endl;
    // }

    fin.close();
 
    //Exit
    return 0;

}