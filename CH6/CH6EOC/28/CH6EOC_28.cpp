/*
File: CH6EOC_28.cpp
Desc: To create a simulation of a Figure 6.17 system.
Author: spoonais
Date: 11/30/24 @9:20pm
*/

/*
SELF-FEEDBACK:

The books logic was more concise...





*/

#include<iostream>
#include<cmath>
using namespace std;

/*--------- PROGRAMMER DEFINED FUNCTION ---------------*/

double rand_float()
{   

    //Compute 
    return ((double)rand()/RAND_MAX); //need to use cast operator to convert rand() from int to double
    
}


/*-----------------------------------------------------*/

int main()
{
    //Decalare and Init objects:
    double ICR1(0), ICR2(0), ICR3(0), component1(0), component2(0), component3(0);
    double trials(0), counter_pass(0), counter_fail(0);

    //Set format flags
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(5);

    //User to enter the individual component reliability, "ICR", and the # of trials, "trials"
    cout << "Please enter each of the individual components reliability" << endl;
    cin >> ICR1 >> ICR2 >> ICR3;
    cout << "Please enter the number of trials to run" << endl;
    cin >> trials;

    //Use for loop for trials
    for(int i=1; i<=trials; i++)
    {

        //EACH TRIAL
        // cout << "------- TRIAL " << i << " --------" << endl;
        component1 = rand_float();
        // cout << "comp1 = " << component1 << endl;
        component2 = rand_float();
        // cout << "comp2 = " << component2 << endl;
        component3 = rand_float();
        // cout << "comp3 = " << component3 << endl;

        //My version of the logic 
        if(component1 > ICR1)
        {
            counter_fail++;
        }
            else    //This else is the pass case
            {
                if(component2<ICR2 || component3<ICR3)
                {
                    counter_pass++;
                }
                    else 
                    {
                        counter_fail++;

                    }
            }

        // //Books Solution for the logic
        // if (component1<=ICR1 && ((component2<=ICR2)||(component3<=ICR3)))
        // {
        //     counter_pass++;
        // }


    }

    //Print the system reliability
    cout << "Reliability = " << counter_pass/trials << endl;

    //Exit
    return 0;

}