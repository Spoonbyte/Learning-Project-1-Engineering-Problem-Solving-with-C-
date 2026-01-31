/*
File: CH9EOC_25.cpp
Desc: To solve the EOC problems
Author: spoonais
Date: 02/23/25
Start: 2/23/25 @ 11:40AM
Finished: 
*/

/*
Self feedback:

*/

#include<iostream>
#include<string>
using namespace std;

/*--------- PROGRAMMER DEFINED FUNCTIONS -------------*/

/*
Name: pattern()
Objective: To return the number times the substring occurs in the main string
Pre-Cond: 
Post-Cond: 
*/

int pattern(string x, string y)
{   
    //Declare and init
    int pos = 0;
    int count(0);

    //Go through the main string
    while ((pos = x.find(y, pos + y.length())) != string::npos)
    {
        if(pos != -1)
        {
            count++;
        }
    }
    
    return count;
}

/*----------------------------------------------------*/

int main()
{
    //Declare and init objects
    string string, substring;

    //Get string from user
    cout << "Provide main string" << endl;
    getline(cin,string);
    cout << "Provide sub string" << endl;
    getline(cin,substring);

    //Call the function
    cout << "Found " << pattern(string,substring) <<" instances " << endl;

    //Exit
    return 0;
}