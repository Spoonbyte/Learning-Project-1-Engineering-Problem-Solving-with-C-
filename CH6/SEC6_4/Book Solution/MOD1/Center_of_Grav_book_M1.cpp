/*
File: Center_of_Grav_book_M1.cpp
Desc: This is the books solution to the problem and the Modify 1 problem.       
Author: spoonais
Date: 11/14/24 @6:22am
*/

#include<iostream>
using namespace std;

//Program assumptions
const double PERSON_WT(160.0);          //Average weight per person
const double FUEL_MOMENT(1169167.3);    //Fuel moment for full tank
const double EMPTY_WT(9021.0);          //Standard empty weight
const double EMPTY_MOMENT(2751405.0);    //Standard empty moment     
const double FUEL_WT(3618.0);           //Full fuel weight
const double CARGO_DIST(345.0);
const double CREW_DIST(120.0);
//My notes: It looks like they used uppercase to denote const values, I will use this convention.

//function prototypes
double CargoMoment(double); 
double CrewMoment(int);
void GetData(int&, double&);
//My Notes: Still unsure why this function protoype is done???

int main()
{
    //Decalare and Init objects
    int crew;                                   //# of crew on board
    double cargo;                               //weight of cargo lbs
    double total_weight, center_of_grav;        

    //Set format flags
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(1);

    GetData(crew, cargo);

    total_weight = EMPTY_WT + (crew * PERSON_WT) + cargo + FUEL_WT;

    center_of_grav = (CargoMoment(cargo) + CrewMoment(crew) + FUEL_MOMENT + EMPTY_MOMENT) / total_weight;

    cout << endl << "The total weight is " << total_weight
                 << "pounds. \n"
         << "The center of gravity is " << center_of_grav
         << " inches from the nose of the plane. \n";

    return 0;
}

/*--------------------------------------------------------------------------------------------------------*/

double CargoMoment(double weight)
{
    return(CARGO_DIST * weight);
}

/*--------------------------------------------------------------------------------------------------------*/

double CrewMoment(int crew)
{
    return(CREW_DIST * crew * PERSON_WT);
}

/*--------------------------------------------------------------------------------------------------------*/


void GetData(int& crew, double& cargo)
{

    char ch;
    
    cout << "Enter number of crew memebers (Max of 2) " << endl;
    cin >> crew;

    //Note: I think to understand this I need to go back to CH5 (I think it was these problems "CH5_EOC_12-19") and review how the data filters worked and how I can
    //trigger an error using the data types...since "crew" is suppose to be an int, any floating point values should 
    //not be accepted...BUT what is happening is that if I put "2.5" in for crew, crew == 2 and then cargo == 0.5 since it 
    //is a double type. Not sure how to prevent this "overflow" into the cargo variable.

    while(cin.get() == '.')
    {
        cout << "User tried to enter floating point value. Please enter a whole value" << endl;
        cin.clear();
        cin >> crew;
    }

    while(crew <= 0 || crew > 2)
    {
        cout << endl << crew
             << " is an invalid entry\n"
             << " re-enter number of crew, 0 < crew <= 2 ";

        cin >> crew;
    }

    cout << crew << " crew members, thank you. \n\n";


    cout << "Enter weight of cargo (Max of 5000 lbs) " << endl;
    cin >> cargo;

    cout << "cin.fail = " << cin.fail() << endl;

    while(cargo < 0 || cargo > 5000)
    {
        cout << endl << cargo
             << " is an invalid entry\n"
             << " re-enter cargo weight, 0 < cargo <= 5000\n ";

        cin >> cargo;
    }

    cout << cargo << " pounds of cargo loaded. Thank you. \n\n";

    return;
}