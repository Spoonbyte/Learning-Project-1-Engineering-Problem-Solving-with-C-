/*
File: chapter9_7.cpp
Desc: This program counts how many times a specific character occurs
Author: spoonais
Date: 01/24/25 @3:32pm
*/

#include<iostream>      //Required for cout
#include<cctype>        //Required for toupper
using namespace std;

/*---------- PROGRAMMER DEFINED FUNCTION -----------*/

/*
Function objective: To change all lowercase characters to uppercase
Pre-Cond: 
Post Cond:
*/

void stringtoupper(char *ptr_string)   //Pass by value
{
    while(*ptr_string)                  //deref to get the char at the mem. address
    {
        *ptr_string = toupper(*ptr_string);
        ptr_string++;                           //Go to next mem. address
    }

    return;
}


/*
Function objective: To count the occurences of a specified character
Pre-Cond: 
Post Cond:
*/

int countchar(const char* ptr_strng, char ch)
{
    //Counter
    int counter(0);

    //Search
    while(*ptr_strng)
    {
        if(*ptr_strng == ch)
        {
            counter++;
        }

        //Move pointer to next char
        ptr_strng++;
    }

    return counter;
}

/*--------------------------------------------------*/

int main()
{
    //Declare and init
    char strg1[] = "abbcfgwbibbw";
    char *ptr_strg1(strg1), ch = 'B';

    //Output string before call to function
    cout << ptr_strg1 << endl;

    //Change string to uppercase
    stringtoupper(ptr_strg1);

    //Output string after call to function
    cout << ptr_strg1 << endl;
    cout << strg1 << endl;

    //Call the count function
    cout << "The character " << ch << " appears a total of " << countchar(ptr_strg1,ch) << " times" << endl;

    //Exit
    return 0;
}