/*
File: CH5_5M2.cpp
Desc: This is the same weather balloon program but adds the line count at the beginning of the file
Author: spoonais
Date: 07/31/24 @11:15am
*/

#include<iostream>
#include<cmath>
#include<fstream>
using namespace std;


int main()
{
    //Decalare and Init objects:
    double altitude(0), velocity(0);
    int counter(0);
    string filename;
    ofstream fout;

    //Prompt user for name of output file
    cout << "Enter the user name for the output file" << endl;
    cin >> filename;

    //Associate the file stream objects with the specific files
    fout.open(filename.c_str());

    //Print the report heading
    fout << "Time Altitude Velocity\n";

    //Print the number of lines of data (acts as a placeholder until seekp() comes back)
    //How can I do this after all the data has been printed...I want to use the counter to track the number of lines printed and 
    //then update display this counter on the FIRST LINE of the text file. I want the # of loops and the "counter" to be independent...
    //so the #of loops is executed and then the counter gets this number
    fout << "The number of lines of data = " << counter << endl;

    //Create the loop 
    for (int i=0; i<=50; i++)
    {
        altitude = -0.12*pow(i, 4) + 12*pow(i, 3) - 380*i*i + 4100*i + 220;
        velocity = -0.48*pow(i, 3) + 36*i*i - 760*i + 4100;

        fout << i << "\t" << altitude << "\t" << velocity << endl;

        counter++;

    }

    //Find the second line of the file and overwrite with updated counter
    fout.seekp(23);
    fout << "The number of lines of data = " << counter << endl;

    //Close the file
    fout.close();

    //Pause Program
    system("pause");

    //Exit program
    return 0;


}