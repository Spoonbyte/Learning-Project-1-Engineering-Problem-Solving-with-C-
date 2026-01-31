/*
File: chapter9_5.cpp
Desc: This program converts a string to all upper case, book version
Author: spoonais
Date: 01/22/25 @12:09pm
*/

#include<iostream>      //Required for cout
#include<cctype>        //Required for toupper
using namespace std;

/*---------- PROGRAMMER DEFINED FUNCTION -----------*/

/*
Function objective:
Pre-Cond:
Post Cond:
*/

void stringtoupper(char *ptr_string)
{
    while(*ptr_string != '\0')                  //deref to get the char at the mem. address
    {
        *ptr_string = toupper(*ptr_string);
        ptr_string++;                           //Go to next mem. address
    }

    return;
}


/*--------------------------------------------------*/

int main()
{
    //Declare and init
    char strg1[] = "abbcfgwbibbw";
    char *ptr_strg1(strg1);

    //Output string before call to function
    cout << ptr_strg1 << endl;

    //Print address of each char
    while(*ptr_strg1)
    {
        cout << static_cast<void*>(ptr_strg1) << endl;
        ptr_strg1++;
    }

    //reset pointer to beginning
    ptr_strg1 = ptr_strg1 - 12;

    //Call function
    stringtoupper(ptr_strg1);

    //Output string after call to function
    cout << ptr_strg1 << endl;

    //Exit
    return 0;
}