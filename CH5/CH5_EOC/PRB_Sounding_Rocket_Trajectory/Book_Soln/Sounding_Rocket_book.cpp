/*
File: Sounding_Rocket_book
Desc: This is the books solution to the problem.
Author: spoonais
Date: 09/22/24 @11:18am
*/

#include<iostream>
#include<fstream>
using namespace std;

//Declare const variables
const int RAISE = 1;
const int REDUCE = -1;
const string INPUTFILE = "rocket1.txt";

int main()
{
    //Decalare and Init objects:
    int direction = RAISE, no_of_stages = 1;
    double time, val_alt, val_acc, val_vel = 0, prev_vel = 0;

    //Input steam file
    ifstream in_rocket;
    in_rocket.open(INPUTFILE.c_str());

    //Get the first set of data
    in_rocket >> time >> val_alt >> val_vel >> val_acc;

    //Assign velocity to "pre_vel" variable
    prev_vel = val_vel;

    //Set the header format
    cout << "Number of Stages in Rocket" << endl;
    cout << "---------------------------------" << endl;

    //Use the for loop to process all the input data from the file

    for (int i = 0; i < 23; ++i )
    {

        //Check for a change in direction
        if ((prev_vel > val_vel) && (direction == RAISE))
        {
            //Assign constant value to direction
            direction = REDUCE;

        } 
            else /* Check if velocity is increasing than previous value then new stage is fired. */
            {
                if ((prev_vel < val_vel) && (direction == REDUCE))
                {
                    //Increment the stage
                    no_of_stages++;

                    //Assign const value to direction
                    direction = RAISE;
                }

            }

        //Assign velocity value to “pervious_velocity” variable.
        prev_vel = val_vel;

        //Get the next set of data 
        in_rocket >> time >> val_alt >> val_vel >> val_acc;

    }

    cout << "Number of stages : " << no_of_stages << endl;

    //Pause the system
    system("pause");

    //Exit
    return 0;

}