/*
File: Chapter5_8_2M.cpp
Desc: Use for the Modify! questions.
Author: spoonais
Date: 08/12/24 @5:00pm
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
    int counter(0), n(4), loop(0), unit;
    double low(0), high(0);
    double m(0), b(0), x(0), x_sum(0), y(0), y_sum(0), x2_sum(0), xy_sum(0), alt_user(0), OMR(0);
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

    //(Modify.4) Allow the user to select to make the linear model for km or miles
    char km_mile;
    cout << "Do you want the linear model in kilometers (km) or miles (mi)?. Enter (K) for kilometers or (M) for miles." << endl;
    cin >> km_mile;

    switch (km_mile)
    {
        case 'K':

            while(counter <= 4)
            {   

                if(counter == 1) //Stores the lowest altitude value
                {
                    low = x;
                }

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

                ++counter;

            }

            high = x; //Stores the highest altitude value

            //Trblsht: 
            cout << low << "\n" << high << endl;

            //Finished getting data from input file. Close 
            fin.close();

            //Compute m
            m = ((x_sum*y_sum) - (n*xy_sum))/(pow(x_sum,2) - (n*x2_sum));
            // Trblsht: 
            // cout << m << endl;
            //Compute b
            b = ((x_sum*xy_sum) - (x2_sum*y_sum))/(pow(x_sum,2) - (n*x2_sum));
            // Trblsht: 
            // cout << b << endl;

            //(Modify.2) Check the user altidude is within the range with a do-while loop
            do 
            {
                if (loop > 0)
                {
                    cout << "The altitude value entered was not within the range. Please try again" << endl; //I though this program was not limited by the range since its extrapolation??? Is it not to the point to be able to predict outside values?
                }

                //(Modify.1) Prompt user for the altitude
                cout << "This program is used to compute the Ozone Mixing Ratio at a provided altitude. \nPlease provide an altitude." << endl;
                cin >> alt_user;
                cout << "Input units : (1) for Miles (2) for Kilometers" << endl;
                cin >> unit;

                //(Modify.3) Allow user to enter the altitude in miles
                if(unit == 1)
                {
                    alt_user = alt_user/0.621; //convert the user miles to kilometers

                } else {}

                ++loop;

            } while ((alt_user < low) || (high < alt_user));

            //(Modify.1) Create the equation to solve for the ozone mix ration (OMR)
            OMR = m*alt_user + b;
            cout << "The approximate Ozone Mix Ratio at an altitude of " << alt_user << " (km) is " << OMR << " (ppmv) " << endl;

            break;

        case 'M':

            double x_mi;
            while(counter <= 4)
            {   

                x_mi = x*0.621; //Since the data file is in km, then this converts it to mi.

                if(counter == 1) //Stores the lowest altitude value
                {
                    low = x_mi;
                }

                //Get the sum of x values
                x_sum = x_sum + x_mi;

                //Get the sum of y values
                y_sum = y_sum + y;

                //Get the sum of x^2 values
                x2_sum = x2_sum + pow(x_mi,2);

                //Get the sum of x*y values 
                xy_sum = xy_sum + (x_mi*y);

                //Get next pair
                fin >> x >> y;

                ++counter;

            }

            high = x_mi; //Stores the highest altitude value
            
             //Trblsht: 
            cout << low << "\n" << high << endl;

            //Finished getting data from input file. Close 
            fin.close();

            //Compute m
            m = ((x_sum*y_sum) - (n*xy_sum))/(pow(x_sum,2) - (n*x2_sum));
            // Trblsht: 
            // cout << m << endl;
            //Compute b
            b = ((x_sum*xy_sum) - (x2_sum*y_sum))/(pow(x_sum,2) - (n*x2_sum));
            // Trblsht: 
            // cout << b << endl;

            //(Modify.2) Check the user altidude is within the range with a do-while loop
            do 
            {
                if (loop > 0)
                {
                    cout << "The altitude value entered was not within the range. Please try again" << endl; //I though this program was not limited by the range since its extrapolation??? Is it not to the point to be able to predict outside values?
                }

                //(Modify.1) Prompt user for the altitude
                cout << "This program is used to compute the Ozone Mixing Ratio at a provided altitude. \nPlease provide an altitude." << endl;
                cin >> alt_user;
                cout << "Input units : (1) for Kilometers (2) for Miles" << endl;
                cin >> unit;

                //(Modify.3) Allow user to enter the altitude in km
                if(unit == 1)
                {
                    alt_user = alt_user*0.621; //convert the user km to miles.

                } else {}

                ++loop;

            } while ((alt_user < low) || (high < alt_user));

            //(Modify.1) Create the equation to solve for the ozone mix ration (OMR)
            OMR = m*alt_user + b;
            cout << "The approximate Ozone Mix Ratio at an altitude of " << alt_user << " (mi) is " << OMR << " (ppmv) " << endl;

            break;


    }


   

    //Trblsht: Ensure values are correct
    // cout << x_sum  << "\n"
    //      << y_sum  << "\n"
    //      << x2_sum << "\n"
    //      << xy_sum << endl;


    //Exit program
    return 0;

}