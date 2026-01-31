/*
File: Center_of_Grav.cpp
Desc: This is to solve the probelm in sec 6_4 NOT using a function
Author: spoonais 
Date: 10/28/24 @12:15pm
*/

#include<iostream>
using namespace std;


int main()
{
    //empty aircraft and fuel
    const double empty_craft_W = 9021;
    const double empty_craft_M = 2751405;
    const double fuel_W = 540*6.7;
    const double fuel_M = 1169167.3;
    
    //Decalare and Init objects:
    double crew1_W(0), crew1_dist(0), crew2_W(0), crew2_dist(0), cargo_W(0), cargo_dist(0), total_W(0) ;

    //User input for the unknowns
    cout << "Please provide the weight and distance (from nose) of crew memeber 1" << endl;
    cin >> crew1_W;
    cin >> crew1_dist;
    cout << "Please provide the weight and distance (from nose) of crew memeber 2" << endl;
    cin >> crew2_W;
    cin >> crew2_dist;
    cout << "Please provide the weight and distance (from nose) of the cargo" << endl;
    cin >> cargo_W;
    cin >> cargo_dist;

    //Calculate the moments
    double crew1_M = crew1_W * crew1_dist;
    double crew2_M = crew2_W * crew2_dist;
    double cargo_M = cargo_W * cargo_dist;

    //Calculate the total_W
    total_W = empty_craft_W + fuel_W + crew1_W + crew2_W + cargo_W;

    //Calculate the COG 
    double cog = (empty_craft_M + fuel_M + crew1_M + crew2_M + cargo_M) / total_W;

    //Print the COG
    cout << "The COG of this aircraft is = " << cog << " inches" << endl;

    //Exit
    return 0;

}