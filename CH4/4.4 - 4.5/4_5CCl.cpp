/*
File: 4_5CCL.cpp
Desc: To use a counter controlled loop
Author: spoonais
Date: 06/10/24 @2:15pm
*/

#include<iostream>
#include<cmath>
using namespace std;

int main()
{
    //Decalare and Init objects:
    short counter;
    double avg, score, sum;

    //Set the counter value
    cout << "Please provide the number of exams you would like to average" << endl;
    cin >> counter;

    //Create the average routine
    for (int i = 1; i <= counter; ++i)
    {
        cout << "Provide the exam score below: " << i << " out of " << counter << endl;
        cin >> score;

        //compute the sum of the scores
        sum += score;

    }

    //Compute the average 
    avg = (sum / counter);
    cout << "The average for the set of exams is: " << avg << endl;
    


}

    