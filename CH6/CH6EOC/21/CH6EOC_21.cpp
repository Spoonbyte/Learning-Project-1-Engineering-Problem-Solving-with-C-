/*
File: CH6EOC_21.cpp
Desc: To test the programs from #18-21
Author: spoonais
Date Started: 11/26/24 @ 2PM, FINISHED 2:30PM

-----------------------------------------------------------------------------------------
SELF-FEEDBACK:

This function could be used in troubleshooting a file stream...

GOOD ENOUGH!

-----------------------------------------------------------------------------------------


*/

#include<iostream>
#include<fstream>
#include<cmath>
using namespace std;

//#Problem 20:
/*----------- PROGRAMMER DEFINED FUNCTION ------------*/

void filestream_status(ifstream& file)
{
    int input, counter(0);

    file >> input;

    while(!file.eof())
    {
        counter++;

        //Get status
        cout << "----------" << counter << "------------" << endl;
        cout << "input.bad = "  << file.bad()  << endl;
        cout << "input.good = " << file.good() << endl;
        cout << "input.fail = " << file.fail() << endl;
        cout << "input.eof = "  << file.eof()  << endl;

        //get next 
        file >> input;

    }

}

/*-----------------------------------------------------*/

int main()
{
    //Decalare and Init objects:
    ifstream fin;
    
    //Associate file stream with file
    fin.open("integers.txt");

    //Call function
    filestream_status(fin);

    //Close
    fin.close();

    //exit
    return 0;

}