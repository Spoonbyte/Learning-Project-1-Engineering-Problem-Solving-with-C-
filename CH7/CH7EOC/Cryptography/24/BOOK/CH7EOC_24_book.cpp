/*
File: CH7EOC_24_book.cpp
Desc: Cryptography problem #24, books solution
Author: spoonais
Date: 12/31/24 @ 11:25am
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
    string input = "henry eats lemons like oliver";
    char c;
    bool input_wrd = false;

    //get first character
    c = input.c_str()[0];

    for(int i=0; i < input.size(); ++i)
    {
        if(!input_wrd)                      //This is how they print the first char...since there are no '\n' to trigger a print
        {
            cout << c;
            input_wrd = true;
        }

        switch(c)
        {
            case '\n':
                cout << c;
            case '\t':
                input_wrd = false;
            case ' ':
                input_wrd = false;
            default:
                break;
        }

        //get next character
        c = input.c_str()[i];
    }

    cout << endl;

    //Pause the system
    system("pause");

    //Exit
    return 0;

}