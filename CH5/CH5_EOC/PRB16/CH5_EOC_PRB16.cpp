/*
File: CH5_EOC_PRB16.cpp
Desc: This is try problem 16
Author: spoonais
Date: 09/03/24 @10:00am
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
    string filename;
    char char_in;

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

    //Get first character of input file (DID NOT WORK PLACED BEFORE THE LOOP)
    

    //Data Filter: Remove '$' and ',' and '()' characters
    //TO DO: Find a way to replace the ( ) with a negative sign [COMPLETED]
    while(fin >> char_in)
    { 

        //Sort through the characters 
        if (char_in == '$'|| char_in == ','|| char_in == '(' || char_in == ')')
        {
            if (char_in == '(')
                {
                    fout << '-';
                }
                
            continue;

        } 
            else 
            {  
                fout << char_in;
            }

    }

    //Close file streams:
    fin.close();
    fout.close();

    //Exit
    return 0;


}