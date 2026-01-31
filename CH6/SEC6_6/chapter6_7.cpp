/*
File: chapter6_7.cpp
Desc: To determine the reliability of a series and parallel system and compare them.
Author: spoonais
Date: 11/18/24 @12:13pm
Finished the program 1:05pm

NOTES: 
The code itself was straighforward since I just converted the book explanation of what the code was suppose to do.
Figuring out why the "rel" was not printing out was where most time was spent.
 
*/

#include<iostream>
#include<cmath>
using namespace std;

/*-------------------------PROGRAMMER DEFINED FUNCTION-----------------------------*/

double rand_float()
{   

    //Compute 
    return ((double)rand()/RAND_MAX); //need to use cast operator to convert rand() from int to double
    
}

/*---------------------------------------------------------------------------------*/

int main()
{
    //Decalare and Init objects:
    double ICR(0), component1(0), component2(0), component3(0);
    double trials(0), counter_pass_S(0), counter_fail_S(0), counter_pass_P(0), counter_fail_P(0);
    double rel_series(0), rel_parallel(0);

    //Set format flags
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(5);
    
    //User to enter the individual component reliability, "ICR", and the # of trials, "trials"
    cout << "Please enter the individual component reliability" << endl;
    cin >> ICR;
    cout << "Please enter the number of trials to run" << endl;
    cin >> trials;

    //Call the rand_float function
    //Call it 3 times (one for each component) and after 3 times that is ONE TRIAL.

    for(int i=1; i<=trials; ++i)
    {   
        //EACH TRIAL
        // cout << "------- TRIAL " << i << " --------" << endl;
        component1 = rand_float();
        // cout << "comp1 = " << component1 << endl;
        component2 = rand_float();
        // cout << "comp2 = " << component2 << endl;
        component3 = rand_float();
        // cout << "comp3 = " << component3 << endl;
    
        //Logic to detrmine if pass or fail

        //SERIES
        if (component1 <= ICR && component2 <= ICR && component3 <= ICR)
        {
            ++counter_pass_S;
        }
            else
            {
                ++counter_fail_S;
            }

        //PARALLEL
        if (component1 <= ICR || component2 <= ICR || component3 <= ICR)
        {
            ++counter_pass_P;
        }
            else
            {
                ++counter_fail_P;
            }

    }


    //After all trials are run, compute the overall reliability of the system
    rel_series = counter_pass_S/trials;
    rel_parallel = counter_pass_P/trials;

    //Print
    cout << "The reliability of the series sytem is = " << rel_series << endl;
    cout << "The reliability of the parallel sytem is = " << rel_parallel << endl;

    //exit
    return 0;

}