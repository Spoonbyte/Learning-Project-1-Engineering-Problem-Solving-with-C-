/*
File: Prg5_2.cpp
Desc: 

Author: spoonais
Date: 07/24/24 @11:15am
*/

#include<iostream>
#include<fstream>
using namespace std;

int main()
{
    //1. Decalare and Init objects:
    int val_in(0), lines(0);
    double time(0), time_atmax(0), time_atmin(0), wind(0), wind_max(0), wind_min(0), sum(0), avg(0);

    //2. Create file stream objects
    ifstream fin;
    ofstream fout;

    //3. Associate file stream objects with the input and output files required
    fin.open("Sensor1_dat.txt");
    fout.open("Summary_Report.txt");

    //Make sure no input file error
    if (fin. fail())
    {
        cerr << "Input file Sensor1_dat.txt FAILED to open" << endl;
        exit(1);
    }

    //4. Read 1st line to get the # of lines to read in the file
    fin >> lines;

    //5. Read in the next line to get the first values for time and wind.
    fin >> time >> wind;  //How does "fin" know to go to the next line in the input file?
    
    //6. Do stuff with data
    for (int i=1; i<=lines; ++i)
    {   
        //Finds the average wind speed
        sum = sum + wind;

        //Finds the max wind value
        if (i==1) //Store first value to use a comparison
        {
            wind_max = wind;
        } 
            else
            {
                if (wind > wind_max)
                {
                    wind_max = wind;
                    time_atmax = time;
                }
            } 

        //Finds the min wind value
        if (i==1) //Store first value to use a comparison
        {
            wind_min = wind;
        } 
            else
            {
                if (wind < wind_min)
                {
                    wind_min = wind;
                    time_atmin = time;
                }
            } 

        //Get the next data pair
        fin >> time >> wind;

    }
   
    //8. Compute the average wind speed
    avg = sum / lines;

    //9. Output to user
    fout << "---------------------------------------- Summary Report --------------------------------------------" << endl;
    fout << "The number of data points =  " << lines << endl; 
    fout << "The average wind speed was " << avg << " km/hr " << endl;
    fout << "The maximum wind speed was " << wind_max << " km/hr occuring at " << time_atmax << " hours " << endl;
    fout << "The minimum wind speed was " << wind_min << " km/hr occuring at " << time_atmin << " hours " << endl;
    fout << "----------------------------------------------------------------------------------------------------" << endl;

    //7. Close all files streams:
    fin.close();
    fout.close();

    //10. Pause program
    system("pause");

    //11. Exit program
    return 0;

}