/*
File: CH9EOC_19_proof.cpp
Desc: basic program to count the # of unique letters in a word
Author: spoonais
Date: 02/22/25 @ 1:16pm
Finished: @ 
*/

#include<iostream>
#include<cstring>
using namespace std;

const int NUM_CHAR = 127;

/*--------- PROGRAMMER DEFINED FUNCTIONS -------------*/

/*
Name:
Objective: 
Pre-Cond: 
Post-Cond: 
*/


/*----------------------------------------------------*/

const int ELEMENT_MAX = 127;

int main()
{
    //Declare and init objects
    int arr[ELEMENT_MAX];
    char cstrg1[] = "qwwwwwwwwwwwwwwweeeeeeeeeeeeeqqqqqasddrkkqwduuif";    //Random incomming string
    char *str = cstrg1;
    int count(0);

    //Initialize the array
    for(int i=0; i < ELEMENT_MAX; ++i)
    {
        arr[i] = 0;
    }

    // //Check that it inits properly
    // for(int i=0; i < ELEMENT_MAX; ++i)
    // {
    //     cout << arr[i] << " ";
    //     if(i%10 == 0)
    //     {
    //         cout << endl;
    //     }
    // }
    
    //Length of string
    int length = strlen(str);

    //Find the unique characters
    for(int i=0; i < length; ++i)
    {
        arr[str[i]]++;      //Increment each 
    }

    // //Check that counts properly
    // for(int i=0; i < ELEMENT_MAX; ++i)
    // {
    //     cout << arr[i] << " ";
    //     if(i%10 == 0)
    //     {
    //         cout << endl;
    //     }
    // }

    //Count the unique characters
    for(int i=0; i < ELEMENT_MAX; ++i)
    {
        if(arr[i] >= 1)
        {
            count++;
        }
    }

    cout << "Unique characters = " << count << endl;

    //Exit
    return 0;
}