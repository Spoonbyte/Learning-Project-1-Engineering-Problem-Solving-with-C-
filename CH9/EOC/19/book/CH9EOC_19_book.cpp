/*
File: CH9EOC_19_book_Copy.cpp
Desc: To solve the EOC problems
Author: spoonais
Date: 02/21/25 @ 2:20pm
Finished: @ 2:36pm
*/

#include<iostream>
#include<cstring>
using namespace std;

const int NUM_CHAR = 127;

/*--------- PROGRAMMER DEFINED FUNCTIONS -------------*/

/*
Name: repeat()
Objective: 
Pre-Cond: 
Post-Cond: 
*/

int repeat(char *ptr)
{
    //Declare and init local objects
    int i_val, length_val, repeaters_val = 0, allchars_val[NUM_CHAR];
    
    //Set each element in array as zero
    for(i_val = 0; i_val < NUM_CHAR; i_val++)
        allchars_val[i_val] = 0;
    
    //Find the # of repeated characters in the given string
    length_val = strlen(ptr);

    /*
    How the statement below works with an example:
    For example, if array[3] is initially 5, then array[3]++ 
    will first use the value 5, and then increment array[3] to 6. 
    */
    for(i_val = 0; i_val < length_val; i_val++)
    {
        allchars_val [ptr[i_val]]++;
        cout << allchars_val [ptr[i_val]] << endl;
    }
        
    // //Print the allchar[]
    // for(i_val = 0; i_val < NUM_CHAR; i_val++)
    // {
    //     cout << allchars_val[i_val];

    //     if(i_val%12 == 0)
    //         cout << endl;
    // }
    // cout << endl;
    // cout << "-------------" << endl;
    
    //Find the count of repeated character
    for (i_val = (int)'!'; i_val < (int)'~'; ++i_val)       //The for loop parameters were missing from the book so I had to figure this out.
        if (allchars_val[i_val] > 1)
            repeaters_val ++;

    //Rturn the count of repeated characters
    return repeaters_val;    

}

/*----------------------------------------------------*/

int main()
{
    //Declare and init objects
    char cstring[100];

    //Get the string from user 
    cout << "Please provide the word to analyze" << endl;
    cin >> cstring;

    //Create pointer to cstring
    char *ptr = cstring;    

    //Call the function
    cout << repeat(ptr) << endl;

    //Exit
    return 0;
}