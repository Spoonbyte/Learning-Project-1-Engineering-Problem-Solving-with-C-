/*
File: Sounding_Rocket_001.cpp   
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
    double time(0), altitude(0), store_alt(0), velocity(0), prior_vel(0), next_vel(0), acceleration(0);                      //storage for data being read in from file
    int lines;
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

    // //PROBLEM #20:
    // //get the first data set
    // fin >> time;
    // fin >> altitude;
    // fin >> velocity;
    // fin >> acceleration;
    //init the compare value
    // store_alt = altitude;

    //PROBLEM #21:
    //Get the prior velocity
    fin >> time >> altitude >> prior_vel >> acceleration;  
    //To get the current velocity
    fin >> time >> altitude >> velocity >> acceleration;
    //To get the next velocity
    fin >> time >> altitude >> next_vel >> acceleration;


    //Create a for loop to read through file
    for(int i = 0; i < 23 ; ++i)
    {
        // //PROBLEM #20:
        // //get the next data set
        // fin >> time;
        // fin >> altitude;
        // fin >> velocity;
        // fin >> acceleration;
        
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

        //Update 09/21/24: I need to find out an algorithm where the computer stores a current velocity value then compares it to the 
        //previous value and to the next value...if both are less than the the current value then it is a local maximum and counts 
        //as a stage

        // //TRBLSHT for PROBLEM #21:
        // cout << "-----------------" << endl;
        // cout << prior_vel << endl;
        // cout << velocity << endl;
        // cout << next_vel << endl;
        // cout << counter << endl;
        // cout << "-----------------" << endl;

        if (velocity > prior_vel && velocity > next_vel)
        {
            ++counter; //If the current velocity is greater than the prior and next velocity then its a stage 
        }

        //Store the current vel as prior vel
        prior_vel = velocity;
        //Store the next vel as the current 
        velocity = next_vel;
        //Get new velocity and set as the next
        fin >> time >> altitude >> next_vel >> acceleration;
    };

    //
    cout << "The number of stages is " << counter << endl;

    //Close the filestreams
    fin.close();

    //Exit
    return 0;

}