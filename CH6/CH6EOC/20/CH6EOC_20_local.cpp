/*
File: CH6EOC_20_local.cpp
Desc: To test the programs from #18-21
Author: spoonais
Date Started: 11/26/24 @12:50pm
Finished 11/26/24 @ 1:20pm

-----------------------------------------------------------------------------------------
SELF-FEEDBACK:

Not sure how to trigger a error when reading a floating point (double) into the int variable...
since it will read a part of the double into the int...for example if "input" comes across 
a value of 1.2, it will read the 1 but ignore the "0.2"

I guess I'd have to keep reading into the file in order to trigger the file.fail()...once I did that 
now it works with the ","....

I'd have to figure out how to not count the part of the double value that it would read in before it fails...
so for example if the file had:
12
1.2

It would read 12, increment counter, read 1, increment counter, read "," and then fail...but the counter would 
read one more that it should have....maybe have a if(char == '.') { --counter }?
not fully sure how to solve but I'm not going to spend more time on this.

GOOD ENOUGH!

-----------------------------------------------------------------------------------------


*/

#include<iostream>
#include<fstream>
#include<cmath>
using namespace std;

//#Problem 20:
/*----------- PROGRAMMER DEFINED FUNCTION ------------*/

int countInts(ifstream& file)
{   
    int input, counter(0);

    file >> input;

    while(!file.fail())
    {
        counter++;
        file >> input;
    }

    return {counter};

}

/*-----------------------------------------------------*/

int main()
{
    //Decalare and Init objects:
    ifstream fin;
    int counts(0);

    //Associate and open the file
    fin.open("integers.txt");

    //Check to ensure file opens.
    if(fin.fail())
    {
        cout << "Input file failed to open...Exiting" << endl;
        exit(1);
    }

    //Count the ints from the file
    counts = countInts(fin);
    cout << "The number of integers read successfully =  " << counts << endl;

    //exit
    return 0;

}