/*
File: CH6EOC_31-33_book.cpp
Desc: To create a flight sim with microbursts.
Author: spoonais
Date: 12/02/24 @10:50pm

*/

/*
SELF-FEEDBACK:
---------------------


Try the book solution to see how it compares



*/

#include<iostream>
#include<fstream>
#include<cmath>
using namespace std;

const int COUNTER = 10;
const int BEGIN_TIME = 0;
const int END_TIME = 3600;
const string FILENAME = "wind_speed.txt";
const int STORM_WIND = 10;
const double Probability_of_storm = 0.005;
const int STORM = 1;
const int NO_STORM = 0;
const int MAXIMUM_DURATION = 300;

/*--------- PROGRAMMER DEFINED FUNCTION ---------------*/

double rand_float(double min, double max)
{   

    //Compute 
    return ((double)rand()/RAND_MAX) * (max-min) + min; //need to use cast operator to convert rand() from int to double
    
}

/*-----------------------------------------------------*/

int main()
{
    //Decalare and Init objects:
    double average_wind=0.0, minimum_gust=0.0,maximum_gust=0.0, speed_of_wind = 0.0;
    int timer=BEGIN_TIME, Duration_of_storm=0,Flag_of_storm=NO_STORM;
    ofstream output_data;

    //Open output file
    output_data.open(FILENAME.c_str());

    //Check that output file opens
    if(output_data.fail())
    {
        cout << "The output file wind.txt failed to open " << endl;
        exit(1);
    }

    //Get gust range from user
    cout << "Please provide the range of gusts... " << endl;
    cout << "Upper limit: " << endl;
    cin >> maximum_gust;
    cout << "Lower limit: " << endl;
    cin >> minimum_gust;

    //Header for output file
    output_data << "TIME" << "\t" << "WIND (mph)" << endl;

    //Logic
    for(timer=BEGIN_TIME; timer<=END_TIME; timer+=COUNTER)
    {
        //Checkif the storm flag is set as true
        if(Flag_of_storm==STORM)
        {
            if(Duration_of_storm < MAXIMUM_DURATION)
            {
                Duration_of_storm += COUNTER;
            }
                else
                {
                    //Reinit the storm flag
                    Flag_of_storm = NO_STORM;

                }
        }
            else
            {
                if(rand_float(0,1)<=Probability_of_storm)
                {
                    //Assign the value of the storm to storm
                    Flag_of_storm = STORM;

                    //Assign the value of 0 to storm duration
                    Duration_of_storm = 0;
                }
            }
        speed_of_wind = rand_float(average_wind+minimum_gust,average_wind+maximum_gust);

        if(Flag_of_storm == STORM)
        {
            //Add up the wind speed with storm wind 
            speed_of_wind += STORM_WIND;

            /* Write the timer and wind speed into the output file.*/
            output_data << timer << ' ' << speed_of_wind << endl;
        }
    }

    
    // Close the file
    output_data.close();

    // Pause the output screen
    system("pause");

    //Exit
    return 0;

}