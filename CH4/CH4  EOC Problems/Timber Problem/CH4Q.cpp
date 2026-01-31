/*
File:CH4Q.cpp
Desc: General workspace for CH4 end of chapter problems
Author: spoonais
Date: 07/2/24 @2:3pm
*/

#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;

int main()
{
    // //Decalare and Init objects:
    // double deg(0), rad(0);
    // const double PI = acos(-1);

    // //Create table header and columns
    // cout << "======================" << endl;
    // cout << "Convert Rad to Deg" << endl;
    // cout << "======================" << endl;
    // cout << "Rad" << "\t" << "Deg" << endl;
    // cout << "----------------------" << endl;

    // //Structure the output 
    // cout.setf(ios::fixed);
    // cout.precision(3);

    // //loop
    // for (int i(0); i<=20; i++)
    // {
    //     deg = rad * 180/PI;
    //     cout << rad << "\t" << deg << endl;
    //     rad = rad + (PI/10);
    // }

    // //Exit program
    // return 0;

    //--------------------------------------------------------------------------//


    // //Convert from ft/s to mph

    // //Decalare and Init objects:
    // double ft_s(0), mph(0);
    // const double mi(5280); // 1 mi = 5280ft

    // //Create table header and columns
    // cout << "======================" << endl;
    // cout << "Convert ft/s to mph" << endl;
    // cout << "======================" << endl;
    // cout << "ft/s" << "\t" << "mph" << endl;
    // cout << "----------------------" << endl;

    // //Structure the output 
    // cout.setf(ios::fixed);
    // cout.precision(3);

    // //loop
    // for (int i(0); i<=20; i++)
    // {
    //     mph = (ft_s/mi)*3600;
    //     cout << ft_s << "\t" << mph << endl;
    //     ft_s += 5;
    // }

    // //Exit program
    // return 0;


    //--------------------------------------------------------------------------------------------------------//

    //Problem 26//

    // //Declare and init objects
    // double TF(0), TC(0);
    // int i(0);

    // //Create table header and columns
    // cout << "======================" << endl;
    // cout << "Convert Fahrenheit to Celsius" << endl;
    // cout << "======================" << endl;
    // cout << "deg F" << "\t\t" << "deg C" << endl;
    // cout << "----------------------" << endl;

    // //Format output
    // cout.setf(ios::fixed);
    // cout.precision(3);   

    // //Convert TF to TC
    // while (i <= 20)
    // {
    //     TC = ((5)*(TF - 32))/9;   //Note cannot write as "TC = (TF-32) * (5/9)"... I guess the computer cant multiply by (5/9)??
    //     cout << TF << "\t\t" << TC << endl;

    //     //Increment values to use in next loop:
    //     TF += 5;
    //     ++i;
    
    // }

    // //Exit program
    // return 0;


    //--------------------------------------------------------------------------------------------------------//

    // //Problem 27//

    // //Declare and init objects
    // double TF(0), TK(0);
    // int i(0), inc(0);

    // //Create table header and columns
    // cout << "======================" << endl;
    // cout << "Convert Fahrenheit to Kelvin" << endl;
    // cout << "======================" << endl;
    // cout << "deg F" << "\t\t" << "K" << endl;
    // cout << "----------------------" << endl;

    // //Format output
    // cout.setf(ios::fixed);
    // cout.precision(3);

    // //User defines the increments
    // cin >> inc;
   
    // //Convert TF to TC
    // do
    // {   
    //     //Calculate the F to K conversion as long as 
    //     TK = ((TF + 459.67) * 5)/9;   
    //     cout << TF << "\t\t" << TK << endl;

    //     //Increment values to use in next loop:
    //     TF += inc;
    //     ++i;
        
    // } while (i <= (200/inc));
    
   
    // //Exit program
    // return 0;


    
    //--------------------------------------------------------------------------------------------------------//

    //Problem 28//

    //Declare and init objects
    double TC(0), TR(0);
    int inc(0), start(0);

    //Format output
    cout.setf(ios::fixed);
    cout.precision(3);

    //User defines the increments
    cout << "Please provide the start value" << endl;
    cin >> start;
    cout << "Please provide the increment value" << endl;
    cin >> inc;

    //Create table header and columns
    cout << "======================" << endl;
    cout << "Convert Celsius to Rankin" << endl;
    cout << "======================" << endl;
    cout << "deg C" << "\t\t" << "deg R" << endl;
    cout << "----------------------" << endl;

    //Convert TC to TR
    for (int i = start; i<=25; ++i)
    {
        //Convert C to R
        TR = ((TC*9)/5) + 491.67;
        cout << TC << "\t\t" << TR << endl;

        //Increment TC
        TC += inc; 
    }
    
   
    //Exit program
    return 0;



}