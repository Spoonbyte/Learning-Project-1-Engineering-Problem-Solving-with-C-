/*
File: CH6EOC_31-33.cpp
Desc: To create a flight sim with microbursts.
Author: spoonais
Date: 12/01/24 @7:50pm
Finished prob 31... 12/10/24 @ 8:30pm
*/

/*
SELF-FEEDBACK:
---------------------
I think it would be harder to generate a file with random gusts that when averaged out was EQUAL to 1O mph...but Im not sure how to do this.




*/

#include<iostream>
#include<fstream>
#include<cmath>
using namespace std;

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
    double wind_avg(10), upper_gust(0), lower_gust(0), gust(0), total(0), storm(0);
    ofstream fout;

    //Open output file
    fout.open("wind.txt");

    //Check that output file opens
    if(fout.fail())
    {
        cout << "The output file wind.txt failed to open " << endl;
        exit(1);
    }

    //Get gust range from user
    cout << "Please provide the range of gusts... " << endl;
    cout << "Upper limit: " << endl;
    cin >> upper_gust;
    cout << "Lower limit: " << endl;
    cin >> lower_gust;

    //Header for output file
    fout << "TIME" << "\t" << "WIND (mph)" << endl;

    //Create the logic for the wind output file
    for(int t=0; t<=3600; t=t+10)
    {
        //Generate random number between the gust range 
        gust = rand_float(lower_gust, upper_gust);
        
        //Potential Storm:
        storm = rand_float(1,0)*100;

        if (storm > 99.5)   //Storm occurs
        {
            wind_avg = 20;

            for(int i=0; i=300; i=i+10)
            {   
                t=t+10;     //keeps track of "t"
                total = wind_avg + gust;
                fout << t << "\t" << total << endl;
            }
        }
            else    //No storm occurs
            {   
                if(wind_avg == 20)  //Corrects if the storm was triggered before this loop
                {
                    wind_avg = 10;
                }

                //Add the gust to the average
                total = wind_avg + gust;

                //Write to the file
                
                fout << t << "\t" << total << endl;
            }
        
        

    }

    //Close file
    fout.close();

    //Exit
    return 0;

}