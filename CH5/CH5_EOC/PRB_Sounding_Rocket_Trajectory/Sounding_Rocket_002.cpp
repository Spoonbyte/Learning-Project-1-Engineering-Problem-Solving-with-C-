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
    double time(0), prior_time(0), next_time(0), altitude(0), store_alt(0), velocity(0), prior_vel(0), next_vel(0), acceleration(0);                      //storage for data being read in from file
    int lines;
    int counter(1); //init to 1 for prob #22
    const double upper_acc = (9.8 - (9.8*0.65)) * -1;
    const double lower_acc = (9.8 + (9.8*0.65)) * -1;

    //TRBLSHT PROBLEM #23:
    cout << "lower limit = " << lower_acc << endl;
    cout << "upper limit = " << upper_acc << endl;

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

    // //PROBLEM #21:
    // //Get the prior velocity
    // fin >> time >> altitude >> prior_vel >> acceleration;  
    // //To get the current velocity
    // fin >> time >> altitude >> velocity >> acceleration;
    // //To get the next velocity
    // fin >> time >> altitude >> next_vel >> acceleration;

    // //PROBLEM #22:
    // //Get the prior velocity
    // fin >> prior_time >> altitude >> prior_vel >> acceleration;  
    // //To get the current velocity
    // fin >> time >> altitude >> velocity >> acceleration;
    // //To get the next velocity
    // fin >> next_time >> altitude >> next_vel >> acceleration;

    //PROBLEM #23:
    fin >> time >> altitude >> velocity >> acceleration;

    //Create a for loop to read through file
    for(int i = 0; i < lines ; ++i) //for PROBLEM #23 i used "i < lines" instead of "i < 23"
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

        /* PROBLEM #21:
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

        */

        /* PROBLEM #22:
        //Init the counter with 1 (we are assuming the rocket requires at least 1 stage to get off the ground)
        //Then to find the firing of other stages, if there is a local MINIMUM velocity (a value less than the prior and next) 
        //then that's when the next stage fires

        if (velocity < prior_vel && velocity < next_vel)
        {
            counter++; //Count the stage
            cout << "Stage: " << counter << " fires at time " << time << " seconds " << endl; //Determine the time the stage fires
        }
        */

        // //PROBLEM #21:
        // //Store the current vel as prior vel
        // prior_vel = velocity;
        // //Store the next vel as the current 
        // velocity = next_vel;

        // //PROBLEM #22:
        // //This allows to "shift" the current time value to match with the current velocity
        // //Store current time as prior time
        // prior_time = time;
        // //Store next time as current time
        // time = next_time;

        //PROBLEM #23:
        if (acceleration >= lower_acc && acceleration <= upper_acc)
        {
            cout << time << endl;
        }
        
        // //PROBLEM #22:
        // //Get new velocity and set as the next
        // fin >> next_time >> altitude >> next_vel >> acceleration;

        //PROBLEM #23:
        fin >> time >> altitude >> velocity >> acceleration;

    };

    // //PROBLEM #21:
    // cout << "The number of stages is " << counter << endl;

    //Close the filestreams
    fin.close();

    //Exit
    return 0;

}