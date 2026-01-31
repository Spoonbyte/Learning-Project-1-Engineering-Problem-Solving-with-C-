/*
File: Prg5_3.cpp
Desc: This program is like 5_2 but using a sentinal to control the loop
Author: spoonais
Date: 07/25/24 @11:30am
*/

#include<iostream>
#include<fstream>
using namespace std;

int main()
{
    //Decalare and Init objects:
    int counter(0);
    double time(0), time_max(0), time_min(0), wind(0), wind_max(0), wind_min(0), sum(0);

    //Create file stream objects
    ifstream Sensor2;
    ofstream Report;

    //Associate the file stream objects with specific files
    Sensor2.open("Sensor2_dat.txt");
    Report.open("Summary_Report.txt");

    //Check to make sure Input file opens
    if (Sensor2. fail())
    {
        cerr << "Input file Sensor2_dat.txt FAILED to open" << endl;
        exit(1);
    }

    //Grab the first pair of values and init wind_min and max
    Sensor2 >> time >> wind;
    wind_max = wind_min = wind;

    while (!(time == -99))
    {
        counter++;

        //compute the average wind speed
        sum = sum + wind;

        //Max wind speed
        if (wind > wind_max)
        {
            wind_max = wind;
            time_max = time;
        }

        //Min wind speed
        if (wind < wind_min)
        {
            wind_min = wind;
            time_min = time;
        }

        //Get next pair of values
        Sensor2 >> time >> wind;
    }

    //9. Output to user
    Report << "---------------------------------------- Summary Report --------------------------------------------" << endl;
    Report << "The number of data points =  " << counter << endl; 
    Report << "The average wind speed was " << sum/counter << " km/hr " << endl;
    Report << "The maximum wind speed was " << wind_max << " km/hr occuring at " << time_max << " hours " << endl;
    Report << "The minimum wind speed was " << wind_min << " km/hr occuring at " << time_min << " hours " << endl;
    Report << "----------------------------------------------------------------------------------------------------" << endl;

    //7. Close all files streams:
    Sensor2.close();
    Report.close();

    //10. Pause program
    system("pause");

    //11. Exit program
    return 0;


}