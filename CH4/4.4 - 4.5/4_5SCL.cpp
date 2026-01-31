/*
File: 4_5SCL.cpp
Desc: To use a sentinel controlled loop
Author: spoonais
Date: 06/10/24 @2:30pm
*/

#include<iostream>
#include<cmath>
using namespace std;

int main()
{

    
    /*
    ** VERSION 1
    ** NOTE: Keeps allowing the -1 to "pass through"
    */

    //Decalare and Init objects:
    double avg, score, sum;
    int counter(0);

    // //Create the average routine
    // while (score >= 0)
    // {
    //     cout << "Provide the exam scores below: " << endl;
    //     cout << counter << endl;
    //     cin >> score;

    //     //compute the sum of the scores
    //     sum += score;

    //     //increment counter to keep track of iterations
    //     counter++;

    // }

    // //Compute the average 
    // cout << counter << endl;
    // avg = (sum / counter);
    // cout << "The average for the set of exams is: " << avg << endl;



    /*
    ** VERSION 1.5
    ** NOTE: Modify to prevent -1 from passing through
    */

    //Create the average routine
    cout << "Provide the exam scores below: " << endl;
    cin >> score;                                       // This is the trick, adding a cin BEFORE the loop allows you to reduce the count iteration in the loop by one, so when you type -1 the counter is 2 and not 3. Essentially the goal was to have the -1 evaluate in the condition before the counter goes to 3
    while (score >= 0)
    {
        //compute the sum of the scores
        sum += score;

        cout << counter << endl;
        cin >> score;

        //increment counter to keep track of iterations
        counter++;

    }

    //Compute the average 
    // cout << counter << endl;
    avg = (sum / counter);
    cout << "The average for the set of exams is: " << avg << endl;




    /*
    ** VERSION 2
    ** NOTE: Keeps allowing the -1 to "pass through"
    */
    //A slightly different routine (THIS ONE WORKED!!!)

    // //User input
    // cout << "Provide the exam scores below: " << endl;

    // while (cin >> score)
    // {
    //     //compute the sum of the scores
    //     if (score < 0)
    //     {
    //         break;

    //     }

    //     sum += score;

    //     //increment counter to keep track of iterations
    //     counter++;

    // }

    // //Compute the average 
    // cout << counter << endl;
    // avg = (sum / counter);
    // cout << "The average for the set of exams is: " << avg << endl;







    

    /*
    ** VERSION 3
    ** NOTE: Keeps allowing the -1 to "pass through"
    */
    //Another slightly different way of defining the sentinel:

    //User input
    // cout << "Provide the exam scores below: " << endl;

    // while (score != -1)
    // {
    //     cin >> score;
    //     sum += score;

    //     //increment counter to keep track of iterations
    //     counter++;

    // }

    // //Compute the average 
    // cout << counter << endl;
    // avg = (sum / counter);
    // cout << "The average for the set of exams is: " << avg << endl;












    /*
    ** VERSION 4 : Trying the books example
    ** NOTE: This works so maybe it was the way I structured the code
    */

    // //Create the average routine
    // cout << "Provide the exam scores below: " << endl;
    // cin >> score;
    // while (score >= 0)
    // {
        
    //     //compute the sum of the scores
    //     sum += score;

    //     //increment counter to keep track of iterations
    //     counter++;

    //     cin >> score;

    // }

    // //Compute the average 
    // cout << counter << endl;
    // avg = (sum / counter);
    // cout << "The average for the set of exams is: " << avg << endl;























}

    