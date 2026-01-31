/*
File: chapter5_7M1.cpp
Desc: This program illustrates the use of stream flags and stream functions for detecting and handling INPUT errors.
Author: spoonais
Date: 08/06/24 @2:00pm
*/

#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
using namespace std;

int main()
{
    //Decalare and Init objects:
    ifstream fin;
    ofstream fout;
    int var1(0), count(0); 
    bool state(false);
    string filename;
    char junk;

    //Request name of input file:
    cout << "Please provide the name of the input file " << endl;
    cin >> filename;

    //Open file and check for failure:
    fin.open(filename.c_str());
    while(fin.fail())
    {

        //Open failed, attempt to recover
        //rdstate() returns the iostate of a stream
        //Print the state (summary) of the fin stream.

        cout << "Could not open " << filename
             <<". The state of the fin stream is "
             << fin.rdstate() << endl;
        cerr << setw(10) << "badbit" << setw(10)
             << fin.bad() << endl;
        cerr << setw(10) << "failbit" << setw(10)
             << fin.fail() << endl;
        cerr << setw(10) << "eofbit" << setw(10)
             << fin.eof() << endl;
        cerr << setw(10) << "goodbit" << setw(10)
             << fin.good() << endl;
        cerr << "***********************************" << endl;

        //reset fin and re-attempt
        fin.clear();

        //Print the state (summary) of the fin stream after clearing.
        cout << "fin state reset to: "
             << fin.rdstate() << endl;
        cout << setw(10) << "badbit" << setw(10)
             << fin.bad() << endl;
        cout << setw(10) << "failbit" << setw(10)
             << fin.fail() << endl;
        cout << setw(10) << "eofbit" << setw(10)
             << fin.eof() << endl;
        cout << setw(10) << "goodbit" << setw(10)
             << fin.good() << endl;
        cout << "***********************************" << endl;

        if(state == true)
        {
            cerr << "Failed to open the input file. Closing program. " <<endl;
            exit(1);
        }

        cout << "Please try again! Provide the name of the input file " << endl;
        cout << "You have 1 attempt left" << endl;
        cin >> filename;
        fin.open(filename.c_str());

        //If fail again then set state to true
        state = true;
        
    }

    //File has been successfully opened:
    //Get state of fin.
    cout << "File " << filename 
         << " is open. State of fin is "
         << fin.rdstate() << endl;

    //Open file for output.
    fout.open("output.dat");

    //Print the table of values to output file.
    //Print heading
    fout << "Count\tvar1" << endl;
    fout << "----------------------" << endl;

    //Read and print data from the file:
    count = 0; //reuse count variable
    fin >> var1;
    while(!fin.eof()) 
    {   
        //Test state of fin.
        if(!fin) //if fin is bad
        {
            cerr << "Bad data encountered.\n";
            cerr << "The state of fin is: "
                 << fin.rdstate() << endl;
            cerr << setw(10) << "badbit" << setw(10)
                 << fin.bad() << endl;
            cerr << setw(10) << "failbit" << setw(10)
                 << fin.fail() << endl;
            cerr << setw(10) << "eofbit" << setw(10)
                 << fin.eof() << endl;
            cerr << setw(10) << "goodbit" << setw(10)
                 << fin.good() << endl;
            cerr << "***********************************" << endl;

            //Reset fin to good state
            fin.clear();

            //Remove bad character from input stream:
            fin.get(junk);
            cerr << "The bad character is: " << junk << endl;
            continue; //Force next iteration of while loop.
        }
        
        ++count;
        fout << setw(5) << count 
             << setw(10) << var1 << endl;
        fin >> var1;
        
    }

    //Print the state (summary) of the fin to std output.
        cout << "Outside of while, state of the fin stream is"
             << fin.rdstate() << endl;
        cout << setw(10) << "badbit" << setw(10)
             << fin.bad() << endl;
        cout << setw(10) << "failbit" << setw(10)
             << fin.fail() << endl;
        cout << setw(10) << "eofbit" << setw(10)
             << fin.eof() << endl;
        cout << setw(10) << "goodbit" << setw(10)
             << fin.good() << endl;
        cout << "***********************************" << endl;

    //Close files and close program
    fin.close();
    fout.close();
    return 0;
    
}