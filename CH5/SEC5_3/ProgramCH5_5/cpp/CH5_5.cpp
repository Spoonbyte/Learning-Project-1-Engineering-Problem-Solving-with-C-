/*
File: CH5_5.cpp
Desc: This is the same weather balloon program but prints the data to a output file.
Author: spoonais
Date: 05/22/24 @10:51am
*/

#include<iostream>
#include<cmath>
#include<fstream>
using namespace std;

int main()
{
    //Decalare and Init objects:
    double altitude(0), velocity(0);
    string filename;
    ofstream fout;

    //Prompt user for name of output file
    cout << "Enter the user name for the output file" << endl;
    cin >> filename;

    //Associate the file stream objects with the specific files
    fout.open(filename.c_str());

    //Print the report heading
    fout << "Time Altitude Velocity\n";

    //Create the loop 
    for (int i=0; i<=10; i++)
    {
        altitude = -0.12*pow(i, 4) + 12*pow(i, 3) - 380*i*i + 4100*i + 220;
        velocity = -0.48*pow(i, 3) + 36*i*i - 760*i + 4100;

        fout << i << "\t" << altitude << "\t" << velocity << endl;
    }

    //Close the file
    fout.close();

    //Pause Program
    system("pause");

    //Exit program
    return 0;


}