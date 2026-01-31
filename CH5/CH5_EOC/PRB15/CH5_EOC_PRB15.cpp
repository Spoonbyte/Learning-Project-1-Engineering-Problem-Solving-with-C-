/*
File: CH5_EOC_PRB15.cpp
Desc: This is try problem 15
Author: spoonais
Date: 08/30/24 @10:00am
*/

#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int main()
{
    //Decalare and Init objects:
    ifstream fin;
    ofstream fout;
    int int_val;
    double dble_val;
    char char_val;
    string filename;

    //Get the input file name
    cout << "Please provide the input file name" << endl;
    cin >> filename;


    //Associate the file streams with files
    fin.open(filename.c_str());
    fout.open("Output.txt");

    //Simple check that input file opened successfully
    if (fin.fail())
    {
        cout << "Could not open input file. Teminate program" << endl;
        exit(1);
    }

    //Read file and output to new file
    while(!fin.eof())
    {
        //Get next set of values
        fin >> int_val >> char_val >> dble_val;

        //Print out the values to the output file
        fout << int_val << " " << dble_val << endl;
 
    }

    //Close the file streams
    fin.close();
    fout.close();

    //Exit
    return 0;


}