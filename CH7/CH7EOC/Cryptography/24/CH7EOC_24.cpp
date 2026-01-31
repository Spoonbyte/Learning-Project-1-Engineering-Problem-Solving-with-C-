/*
File: CH7EOC_24.cpp
Desc: Cryptography problem #24
Author: spoonais
Date: 12/31/24 @ 10am
Finihsed: @ 11:15am
*/

/*-------- SELF FEEDBACK -----------
-----------------------------------------------------*/

#include<iostream>
#include <string>
#include<cmath>
using namespace std;

/*------------ PROGRAMMER DEFINED FUNCTIONS -------------*/


/*-------------------------------------------------------*/

int main()
{
    //Decalare and Init objects:
    string input[] = {"henry eats lemons like oliver"};
  
    for(int i=0; i < input->size(); ++i)
    {   
        //Display the very first char
        if(i == 0)
        {
            cout << input->c_str()[i];
        }

        //Display the first char of each word
        if(i > 0)
        {
            if(input->c_str()[i] == ' ')
            {
                cout << input->c_str()[i+1];    //Prints the char after the space...assumes the character after the space is start of new word.
            }
        }
    }

    //Exit
    return 0;

}