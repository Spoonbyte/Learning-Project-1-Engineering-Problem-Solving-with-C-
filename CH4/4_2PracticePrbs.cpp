/*
File: 4_2PracticePrbs.cpp
Desc:
Author: spoonais
Date: 06/03/24 @11:39am
*/

#include<iostream>
#include<cmath>
using namespace std;

int main()
{
    //Problem 1
    // int count(1);
    // while (count < 5)
    // {
    //     count++;
    //     cout << count << endl;
    // }

    // cout << count << endl;

    //I expected it to stop at 4 but 4 is still makes the condition true so it needs to set the count to 5 before it triggers the while loop off.

    //Problem 2:
    // int count(1);
    // while (count < 5)
    // {
    //     -count;
    // }

    // cout << count << endl;

    //There was no output probably because the count goes to negative infinity...but I thought it would trigger a infinite loop?

    //PROBLEM 3
    // int count(10);
    // while (count >= 0)
    // {
    //     count -= 2;
    // }

    // cout << count << endl;

    //Again the count needs to be set to -2 before the while loop can complete

    //PROBLEM 4:
    int count(0);
    do
    {
        count += 10;

    } while (count >= 10);

    cout << count << endl;

    //The do-while runs the statement first then checks the condition, which is false after the first statement block completes
    //If I set it to to add 10 each time, then the loop runs but gives an output of -2147483646...NOT SURE WHY?
}