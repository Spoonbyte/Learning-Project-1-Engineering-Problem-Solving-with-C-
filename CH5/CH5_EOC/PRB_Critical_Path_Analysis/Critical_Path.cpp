/*
File: Critical_Path.cpp
Desc: This is to solve Problems #35-37
Author: spoonais
Date: 09/18/24 @2:00PM 
    Finished prob #35 at 3:00PM ~ 1 hour to finish
    Started Problem #36 - 11:15am, 
    Finished problem #36 and 37 at 1:00 PM ~ 1:45min with lunch to finish both
*/

#include<iostream>
#include<cmath>
#include<fstream>
using namespace std;

int main()
{
    //Decalare and Init objects:
    ifstream fin;
    int event(0), task(0), days(0);
    int event1_max_days(0), event2_max_days(0), event3_max_days(0), event4_max_days(0), event5_max_days(0), total_days(0);
    int counter1(0), counter2(0), counter3(0), counter4(0), counter5(0);

    //Associate the filestream with a file
    fin.open("schedule.txt");

    //Check that the file has opened successfully:
    if (fin.fail())
    {
        cerr << "The input file schedule.txt failed to open" << endl;
        exit(1);
    }

    //PROBLEM #35:
    //This will calculate the critical path (longest time) for the project.
    //Does this by going though each event, determining the longest task and then finally 
    //adding those tasks up at the end.

    //Get the first data set
    //Make sure to comment out for Prob #37 
    // fin >> event >> task >> days;

    // //TRBLSHT: Ensure the data reads in correctly
    // cout << event << endl;
    // cout << task << endl;
    // cout << days << endl;

    //This is for the while loop 
    while(fin >> event >> task >> days)
    {   
        /* PROBLEM #35:
        //Use a switch statement to find the largest task time per event
        switch (event)
        {
            case 1: //Longest task for event 1
                if (days > event1_max_days)
                {event1_max_days = days;}
                break;
            case 2: //Longest task for event 2
                if (days > event2_max_days)
                {event2_max_days = days;}
                break;
            case 3: //Longest task for event 3
                if (days > event3_max_days)
                {event3_max_days = days;}
                break;
            case 4: //Longest task for event 4
                if (days > event4_max_days)
                {event4_max_days = days;}
                break;
            case 5: //Longest task for event 5
                if (days > event5_max_days)
                {event5_max_days = days;}
                break;
        }
        */

        /* PROBLEM #36:
       //This is to deternmine which task required more than 5 days
       switch (event)
        {
            case 1: //Longest task for event 1
                if (days > 5)
                {
                    cout << "Event: " << event << endl;
                    cout << "Task Number: " << task << endl;
                    cout << "Duration: " << days << endl;
                    cout << "-----------------" << endl;
                }
                break;
            case 2: //Longest task for event 2
                if (days > 5)
                {
                    cout << "Event: " << event << endl;
                    cout << "Task Number: " << task << endl;
                    cout << "Duration: " << days << endl;
                    cout << "-----------------" << endl;
                }
                break;
            case 3: //Longest task for event 3
                if (days > 5)
                {
                    cout << "Event: " << event << endl;
                    cout << "Task Number: " << task << endl;
                    cout << "Duration: " << days << endl;
                    cout << "-----------------" << endl;
                }
                break;
            case 4: //Longest task for event 4
                if (days > 5)
                {
                    cout << "Event: " << event << endl;
                    cout << "Task Number: " << task << endl;
                    cout << "Duration: " << days << endl;
                    cout << "-----------------" << endl;
                }
                break;
            case 5: //Longest task for event 5
                if (days > 5)
                {
                    cout << "Event: " << event << endl;
                    cout << "Task Number: " << task << endl;
                    cout << "Duration: " << days << endl;
                    cout << "-----------------" << endl;
                }
                break;
        }
        */

        /* PROBLEM #37:
        switch (event)
        {
            case 1: 
                ++counter1;
                break;
            case 2: 
                ++counter2;
                break;
            case 3: 
                ++counter3;
                break;
            case 4: 
                ++counter4;
                break;
            case 5: 
                ++counter5;
                break;
        }
        */

    }

    //Close the file
    fin.close();

    //PROBELM #37:
    //Print the # of tasks per event
    cout << "Event 1: " << "contains " << counter1 << " tasks " << endl;
    cout << "Event 2: " << "contains " << counter2 << " tasks " << endl;
    cout << "Event 3: " << "contains " << counter3 << " tasks " << endl;
    cout << "Event 4: " << "contains " << counter4 << " tasks " << endl;
    cout << "Event 5: " << "contains " << counter5 << " tasks " << endl;

    // //TRBLSHT:
    // cout << event1_max_days << endl;
    // cout << event2_max_days << endl;
    // cout << event3_max_days << endl;
    // cout << event4_max_days << endl;
    // cout << event5_max_days << endl;
    
    // //Problem #35:
    // //Add up all the max tasks to get the total number of days for project completion:
    // total_days = event1_max_days + event2_max_days + event3_max_days + event4_max_days + event5_max_days;
    // cout << "The total number of days for the project completion is: " << total_days << " days " << endl;

    //Exit program
    return 0;

}