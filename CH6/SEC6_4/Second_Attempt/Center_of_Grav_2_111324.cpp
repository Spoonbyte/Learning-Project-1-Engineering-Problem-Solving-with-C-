/*
File: Center_of_Grav_2.cpp

Desc: This is to solve the probelm in sec 6_4 using a function for getting the crew and cargo info. 
The book says that this is good to use a function since there is error checking:
Max crew is 2 people 
Max cargo weight is 5000lbs

Author: spoonais 
Date: 10/28/24 @12:15pm
*/

#include<iostream>
using namespace std;

void Crew_and_Cargo(int& a, int& b)
{


    //Create a error checking feature if the crew# > 2 
    do
    {
        if(a > 2)
        {cout << "Crew member exceeds 2 person max" << endl;}
        cout << "Please enter the number of crew members for the flight" << endl;
        cin >> a;

    } while (a > 2);

    //Create a error checking feature if the cargo weight > 5000LBS 
    do
    {
        if(b > 5000)
        {cout << "Cargo weight exceeds 5000lbs max" << endl;}
        cout << "Please enter the cargo weight" << endl;
        cin >> b;

    } while (b > 5000);
    
}


int main()
{
    //empty aircraft and fuel
    const double empty_craft_W = 9021;
    const double empty_craft_M = 2751405;
    const double fuel_W = 540*6.7;
    const double fuel_M = 1169167.3;
    
    //Decalare and Init objects:
    double crew_W(0), crew_dist(0), cargo_dist(0), total_W(0) ;
    int crew_number(0), cargo_weight(0);

    Crew_and_Cargo(crew_number,cargo_weight);

    //TRBLSHT:
    // cout << "crew number = " << crew_number << endl;
    // cout << "cargo weight = " << cargo_weight << endl;

    //User input for the unknowns
    cout << "Please provide the weight and distance (from nose) of crew memebers" << endl;
    cin >> crew_W;
    cin >> crew_dist;
    cout << "Please provide the distance (from nose) of the cargo" << endl;
    cin >> cargo_dist;

    //Calculate the moments
    double crew_M = (crew_W * crew_number) * crew_dist;
    double cargo_M = cargo_weight * cargo_dist;

    //Calculate the total_W
    total_W = empty_craft_W + fuel_W + (crew_W * crew_number) + cargo_weight;

    //Calculate the COG 
    double cog = (empty_craft_M + fuel_M + crew_M + cargo_M) / total_W;

    //Print the COG
    cout << "The COG of this aircraft is = " << cog << " inches" << endl;

    //Exit
    return 0;

}