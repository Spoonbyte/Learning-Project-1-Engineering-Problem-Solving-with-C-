/*
File: CH9EOC_23.cpp
Desc: To solve the EOC problems
Author: spoonais
Date: 02/23/25
Start: 2/23/25 @ 10:30AM
Finished: 
*/

/*
Self feedback:

*/

#include<iostream>
#include<string>
using namespace std;

const int ASCII_MAX = 127;

/*--------- PROGRAMMER DEFINED FUNCTIONS -------------*/

/*
Name: repeat()
Objective: To return the number of repeated characters in a string
Pre-Cond: 
Post-Cond: 
*/

int repeat(string x)
{
    //Declare and init local objs:
    int count(0);
    string::iterator iter;

    //Define ascii table
    int ascii[ASCII_MAX] = {0};

    //Count the instances of each character in the string
    for(iter = x.begin(); iter != x.end(); ++iter)
        ascii[*iter]++;

    //For characters where count is greater than 1 then its a repeated char
    for(int i=0; i < ASCII_MAX; i++)
        if(ascii[i] > 1)
                count++;

    return count;
}

/*----------------------------------------------------*/

int main()
{
    //Declare and init objects
    string string;

    //Get string from user
    cout << "Provide word " << endl;
    getline(cin,string);

    //Call the function
    cout << "Repeated letters: " << repeat(string) << endl;

    //Exit
    return 0;
}