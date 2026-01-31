/*
File:WhileEOF.cpp
Desc: To test how to make a while loop work with a eof()
Author: spoonais
Date: 07/23/24 @11:51pm
*/

#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int main()
{
    //Decalare and Init objects:
    int counter(0), vin(0);
    string filename;

    //Define stream objects
    ifstream fin;
    ofstream fout;

    //Let user pick the input file
    cout << "Please provide the input data file" << endl;
    cin >> filename;

    //Associate the files with the stream objects
    fin.open(filename.c_str());

    //Check the input file for open success
    if(fin. fail())
    {
        cout << "Input file " << filename << "FAILED" << endl;
        exit(1);
    }

    //Get first data values
    fin >> vin;

    //Create the while loop to check the data for negative values.
    while(!fin.eof())
    {
        //Keep track of line
        counter++;

        //Check to see if the data is negative (invalid)
        if(vin < 0)
        {
            cerr << "The negative value " << vin << " on line " << counter << " is invalid " << endl;
        }

        //get the next data point
        fin >> vin;

    }

    //Close the file
    fin.close();

    //Pause the program
    system("pause");

    //Exit
    return 0;

}