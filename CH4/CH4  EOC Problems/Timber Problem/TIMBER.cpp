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
    double rate(0), years(0), acres(0), total_acres(0), cut(0), store(0);
    int i;

    //Get user input to define the reforestation rate:
    cout << "Please provide the estimated reforestation rate" << endl;
    cin >> rate;
    cout << "Please provide the years to calcuate for" << endl;
    cin >> years;
    cout << "Please provide the total acres cut" << endl;
    cin >> total_acres;

    //Compute the acres cut
    //Subtracts the total acres from the uncut (2500) to determine how much needs to grow back
    cut = total_acres - 2500;

    //Header for table
    cout << "---------------------------" << endl;
    cout << "Year" << "\t\t" << "Acres" << endl;
    cout << "---------------------------" << endl;

    //Create loop for calculating the acres per year for XX years
    for (i=1; i<=years; ++i)
    {
        if (i == 1)
        {
            acres = 2500 + (2500 * rate);
            cout << i << "\t\t" << acres << endl;
        }
        if (i > 1)
        {
            acres = acres + (acres * rate);
            cout << i << "\t\t" << acres << endl;

            if (acres <= cut)
            {
                //Store the value of the year that this occurs
                store = i;
            }
        }
            

    }

    cout << "The number of years to regrow "  << cut << " acres is approximately " << store << " years" << endl;

    //Exit program
    return(0);

}