/*
File: Sounding_Rocket.cpp   
Desc: To analyze the data from "rocket1.dat"
Author: spoonais
Date: 09/12/24 @12:30pm
*/

#include<iostream>
#include<fstream>
#include<iomanip>
#include<cmath>
using namespace std;

int main()
{
    //Decalare and Init objects:
    ifstream fin;
    double time(0), altitude(0), store_alt(0), velocity(0), store_vel(0), acceleration(0);                      //storage for data being read in from file
    int lines;
    char tab;
    int state = 0, store_state = 0;
    int counter(0);


    //Associate the filestream with file
    fin.open("rocket1.txt");

    //Check to ensure the file opens
    if(fin.fail())
    {
        cerr << "The input file failed to open" << endl;
        exit(1);
    }

    //Read in the first data point from the file
    //Will indicate how many lines of data to read
    fin >> lines;

    //get the first data set
    fin >> time;
    fin >> altitude;
    fin >> velocity;
    fin >> acceleration;

    //PROBLEM #20:
    //init the compare value
    // store_alt = altitude;

    //PROBLEM #21:
    //init the compare value
    store_vel = velocity;
    
    //Create a for loop to read through file
    for(int i = 0; i < 23 ; ++i)
    {   
    //get the next data set
    fin >> time;
    fin >> altitude;
    fin >> velocity;
    fin >> acceleration;
    
    // cout << fixed << setprecision(2) << endl; //sets 2 decimal points for each value.
    // cout << "----" << i << "------" << endl;
    // cout << store_vel << endl;
    // cout << velocity << endl;
    // cout << "----------" << endl;

    /*PROBLEM #20:
    //if the next altitude value is less than the prior, then the 
    //Also need this for problem 21 to ignore the state change due to descent(not stage separation)
    if (altitude > store_alt)
    {
        //store_alt = altitude;
        
    } else 
        {
            //cout << time << endl;
        }

    */

    //PROBLEM #21:
    //Is there a way to create a "state watcher" that when the state changes from 1 to 0 then it increments a counter?    
    if ((velocity - store_vel) > 0)
    {
        state = 1;
    
    } else if ((velocity - store_vel) < 0)
        {
            state = 0;
        } else 
            { 
                cout << "state unknown" << endl;
            }
       
    //create the prior velocity
    store_vel = velocity;

    cout << "----" << i << "------" << endl;
    cout << "New state: "   << state << endl;
    cout << "Prior state: " << store_state << endl;

    //State Watcher
    if (abs(state - store_state) == 1)
    {
        ++counter;

    }

    //Store state
    store_state = state;

    };

    //
    cout << "The number of stages is " << counter << endl;

    //Close the filestreams
    fin.close();

    //Exit
    return 0;

}