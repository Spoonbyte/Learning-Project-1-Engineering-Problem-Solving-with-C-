/*
File: CH7EOC_23.cpp
Desc: Cryptography problem #23
Author: spoonais
Date: 12/30/24 @ 9am
*/

/*-------- SELF FEEDBACK -----------
-----------------------------------------------------*/

#include<iostream>
#include<cmath>
using namespace std;

/*------------ PROGRAMMER DEFINED FUNCTIONS -------------*/

/*-------------------------------------------------------*/

int main()
{
    //Decalare and Init objects:
    char x[10] = {'&', '*','#','&','&','@','!','*','#','#'};
    int counter(0);
    int state = 0;

    for(int i=0; i < 10; i++)
    {
        //Skip over already counted character
        //---------------------------------------------
        for(int k=i-1; k >= 0; --k)         //This for loop acts like our memory,preventing a character from being recounted
        {
            if(x[i] == x[k])
            {
                state = 1;
                break;
            }
                else
                state = 0;
            // cout << "State = " << state << endl;
        }

        if(state == 1)
        {
            continue;   //Skips this iteration
        }
        //-------------------------------------------------------

        //Count occurances of characters
        for(int j=i; j < 10; ++j )
        {
            if(x[j] == x[i])
            {
                ++counter;
            }
        }

        cout << "Character " << x[i] << " occurs " << counter << " times " << endl;
        counter = 0;     //Reset counter for next character count
    }
   

    //Exit
    return 0;

}