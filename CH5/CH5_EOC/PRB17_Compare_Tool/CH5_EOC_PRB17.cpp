/*
File: CH5_EOC_PRB17.cpp
Desc: This is try problem 17. Make a file compare tool.
Author: spoonais
Date: 09/05/24 @2:03pm
*/

#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int main()
{
    //Decalare and Init objects:
    ifstream fin1, fin2;
    string filename1, filename2;
    char f1_val('\0'), f2_val('\0'); //Init to null character
    bool state;
    int counter(0);

    //Get the input file name
    cout << "Please provide the input file 1 name" << endl;
    cin >> filename1;
    cout << "Please provide the input file 2 name" << endl;
    cin >> filename2;

    //Associate the file streams with files
    fin1.open(filename1.c_str());
    fin2.open(filename2.c_str());

    //Simple check that input file(s) opened successfully
    if (fin1.fail())
    {
        cerr << "Could not open input file 1. Teminate program" << endl;
        exit(1);
    }

    if (fin2.fail())
    {
        cerr << "Could not open input file 2. Teminate program" << endl;
        exit(1);
    }

    /*
    Read each of the files into the program and compare 
    I will create 2 file streams and compare the stored values on each loop
    Need to create a state machine that once one value is encountered that 
    is not the same, then it says the 2 files are different
    */

    // fin1 >> f1_val;
    //TRBLSHT: check fin1 filestream
    // cout << "------------------" << endl;
    // cout << fin1.bad() << "\n"
    //     << fin1.good() << "\n"
    //     << fin1.eof() << "\n"
    //     << fin1.fail() << endl;
    // cout << "------------------" << endl;

    // fin2 >> f2_val;
    //TRBLSHT: check fin2 filestream
    // cout << "------------------" << endl;
    // cout << fin2.bad() << "\n"
    //     << fin2.good() << "\n"
    //     << fin2.eof() << "\n"
    //     << fin2.fail() << endl;
    // cout << "------------------" << endl;


    // cout << f1_val << "\n" << f2_val << endl; 

    ++counter;

    while (!fin1.eof() && !fin2.eof())
    {
            //Get next values
            fin1.get(f1_val); //When I tried to use "fin1 >> f#_val" it did not store the "\n" into f#_val. Not sure why this is?
            fin2.get(f2_val);

            // TRBLSHT
            //cout << f1_val << " and " << f2_val << endl;
            
            if(f1_val == '\n')
            {
                ++counter;
            }  

            if (!(f1_val == f2_val))
            {
                state = 1;
                cout << "Difference found on line : " << counter << endl;
            }
                else 
                { 
                    state = 0;
                }

            //TRBLSHT: print State
            // cout << state << endl;

    }

    //Print the state to the user
    if (state == 1) 
    {
        cout << "The files are different" << endl;
    }
        else if (state == 0) 
        {
            cout << "The files are the same" << endl;
        }
            else 
            { 
                cout << "Unknown state. Terminate program." << endl;
                exit(1);
            }

    //Close file streams:
    fin1.close();
    fin2.close();

    //Exit
    return 0;


}