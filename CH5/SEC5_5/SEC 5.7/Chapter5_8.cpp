/*
File: Chapter5_8.cpp
Desc: To determine a model for a set of data points that can be used to predict the ozone mixing ratios.
Author: spoonais
Date: 08/08/24 @12:47pm
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
    double m(0), b(0), x_sum(0), y_sum(0), xy_sum(0), x2_sum(0), alt_user(0);
    string filename;

    //Prompt user for filename
    cout << "Please provide the name of data file " << endl;
    cin >> filename;  

    //Associate the file streams with files
    fin.open(filename.c_str());

    /*
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

        //Prompt user again for filename
        cout << "File failed to open! Please provide the name of data file " << endl;
        cout << "You have " << 5 - counter << " attempts left " << endl;
        cin >> filename; 

        //After 5 attempts close program.
        if(counter >= 5)
        {
            cout << "File name was incorrect or file failed. Closing program." << endl;
            exit(1);
        }

    }

    */


    //Develop the logic for the linear model
    
    //Need to find m and b first 
    //create a variable for each "sum" term

    // x_sum: Sum of all x values
    for (int i(1); i<=n; ++i)
    {   
        int x; //temporary holding varaible (locally scoped)
        fin >> x;
        x_sum = x_sum + x;
        fin >> x; //skip the "y" values
    }
    fin.seekg(0); //start from file beggining...or else the following computations will be off.

    // y_sum: Sum of all y values
    for (int i(1); i<=n; ++i)
    {   
        int y; //temporary holding varaible (locally scoped)
        fin >> y;
        fin >> y; //skip the "x" values
        y_sum = y_sum + y;  
    }
    fin.seekg(0);

    //xy_sum: Sum of all the x*y values
    for (int i(1); i<=n; ++i)
    {   
        int x, y; //temporary holding varaible (locally scoped)
        fin >> x;
        fin >> y; 
        int xy = x*y;
        xy_sum = xy_sum + xy;
    }
    fin.seekg(0);

    // x2_sum: Sum of all x^2 values
    for (int i(1); i<=n; ++i)
    {   
        int x; //temporary holding varaible (locally scoped)
        fin >> x;
        int x2 = x*x;
        x2_sum = x2_sum + x2;
        fin >> x; //skip the "y" values
    }
    fin.seekg(0);

    //Finished getting data from input file. Close 
    fin.close();


    //Compute m
    m = ((x_sum*y_sum) - (n*xy_sum))/(pow(x_sum,2) - (n*x2_sum));
    //Compute b
    b = ((x_sum*xy_sum) - (x2_sum*y_sum))/(pow(x_sum,2) - (n*x2_sum));
   
    //Prompt user for the altitude
    cout << "This program is used to compute the Ozone Mixing Ratio at a provided altitude. \nPlease provide an altitude." << endl;
    cin >> alt_user;
    //Create the equation to solve for the ozone mix ration (OMR)
    double OMR = m*alt_user + b;

    cout << "The approximate Ozone Mix Ratio at an altitude of " << alt_user << " (km) is " << OMR << " (ppmv) " << endl;

    
    //Exit program
    return 0;

    


    
      
    

}