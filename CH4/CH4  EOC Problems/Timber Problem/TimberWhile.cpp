/*
File:TIMBER.cpp
Desc: To solve CH4 EOC "Timber Regrowth" questions
Author: spoonais
Date: 07/5/24 @1:45pm
*/

#include<iostream>
#include<cmath>
using namespace std;

int main()
{
    //Decalare and Init objects:
    double rate(0), acres(0), total_acres(0), cut(0), store(0), acres_uncut(0);
    int i(1);

    //Get user input to define the reforestation rate:
    cout << "Please provide the estimated reforestation rate" << endl;
    cin >> rate;
    cout << "Please provide the total acres" << endl;
    cin >> total_acres;
    cout << "Please provide the total acres left uncut" << endl;
    cin >> acres_uncut;


    //Compute the acres cut
    //Subtracts the total acres from the uncut (2500) to determine how much needs to grow back
    cut = total_acres - acres_uncut;

    //Header for table
    cout << "---------------------------" << endl;
    cout << "Year" << "\t\t" << "Acres" << endl;
    cout << "---------------------------" << endl;

    //Calculate the first year
    acres = acres_uncut + (acres_uncut * rate);
    cout << i << "\t\t" << acres << endl;

    //Create loop for calculating the years needed to regrow the acres that were cut
    while (acres <= cut)
    {
        ++i;
        acres = acres + (acres * rate);
        cout << i << "\t\t" << acres << endl;

            if (acres <= cut)
            {
                //Store the value of the year that this occurs
                store = i;
            }
              
    }

    cout << "The number of years to regrow "  << cut << " acres is approximately " << store << " years" << endl;

    //Exit program
    return(0);

}