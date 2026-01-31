/*
File: CH5_5M1.cpp
Desc: This is the same weather balloon program but add the negative trailer values
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

    //Add the negative values for time, altitude and velocity
    fout << "-1" << "\t" << "-1" << "\t" << "-1" << endl; 

    //Close the file
    fout.close();

    //Pause Program
    system("pause");

    //Exit program
    return 0;


}