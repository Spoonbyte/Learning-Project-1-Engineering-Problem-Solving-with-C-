/*
File: Chapter5_8_2.cpp
Desc: To determine a model for a set of data points that can be used to predict the ozone mixing ratios.
      Try to rework the problem using only one loop.
Author: spoonais
Date: 08/11/24 @3:14pm
*/

#include<iostream>
#include<fstream>
#include<string>
#include<cmath>
using namespace std;

int main()
{
    //Decalare and Init objects:
    ifstream fin;
    int counter(0), n(4);
    double m(0), b(0), x(0), x_sum(0), y(0), y_sum(0), x2_sum(0), xy_sum(0), alt_user(0);
    string filename;

    //Prompt user for filename
    cout << "Please provide the name of data file " << endl;
    cin >> filename;  

    //Associate the file streams with files
    fin.open(filename.c_str());

    //Check to make sure input file opened successfully (COMPREHENSIVE ERROR CHECK):
    //If it fails this will give the user 5 attempts
    while(fin.fail())
    {
        ++counter;

        //Print status 
        cerr << "The fin stream status = " << fin.rdstate() << endl;
        cerr << "badbit = "  << fin.bad()  << "\n"
             << "failbit = " << fin.fail() << "\n"
             << "eofbit = "  << fin.eof()  << "\n"
             << "goodbit = " << fin.good()  << endl;
        cerr << "***********************************" << endl;
        
        //Reset the failiure
        fin.clear();

        //Print clear status 
        cerr << "The fin stream status = " << fin.rdstate() << endl;
        cerr << "badbit = "  << fin.bad()  << "\n"
             << "failbit = " << fin.fail() << "\n"
             << "eofbit = "  << fin.eof()  << "\n"
             << "goodbit = " << fin.good()  << endl; 

        //After 5 attempts close program.
        if(counter >= 5)
        {
            cout << "File name was incorrect or file failed. Closing program." << endl;
            exit(1);
        }

        //Prompt user again for filename
        cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
        cout << "File failed to open! Please provide the name of data file " << endl;
        cout << "You have " << 5 - counter << " attempts left " << endl;
        cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
        cin >> filename;
        fin.open(filename.c_str()); //If you dont add this again it wont allow the attempts if statement to work properly. Not sure why though?

    }

    //Develop the logic for the linear model
    //Need to find m and b first 
    //Get the first x and y:
    fin >> x >> y;
    counter = 1; //reset counter to reuse

    while(counter <= 4)
    {   
        ++counter;

        //Get the sum of x values
        x_sum = x_sum + x;

        //Get the sum of y values
        y_sum = y_sum + y;

        //Get the sum of x^2 values
        x2_sum = x2_sum + pow(x,2);

        //Get the sum of x*y values 
        xy_sum = xy_sum + (x*y);

        //Get next pair
        fin >> x >> y;

    }

    //Trblsht: Ensure values are correct
    // cout << x_sum  << "\n"
    //      << y_sum  << "\n"
    //      << x2_sum << "\n"
    //      << xy_sum << endl;

    //Finished getting data from input file. Close 
    fin.close();

    //Compute m
    m = ((x_sum*y_sum) - (n*xy_sum))/(pow(x_sum,2) - (n*x2_sum));
    // Trblsht: cout << m << endl;
    //Compute b
    b = ((x_sum*xy_sum) - (x2_sum*y_sum))/(pow(x_sum,2) - (n*x2_sum));
    // Trblsht: cout << b << endl;

    //Prompt user for the altitude
    cout << "This program is used to compute the Ozone Mixing Ratio at a provided altitude. \nPlease provide an altitude." << endl;
    cin >> alt_user;
    //Create the equation to solve for the ozone mix ration (OMR)
    double OMR = m*alt_user + b;

    cout << "The approximate Ozone Mix Ratio at an altitude of " << alt_user << " (km) is " << OMR << " (ppmv) " << endl;
    
    //Exit program
    return 0;

}