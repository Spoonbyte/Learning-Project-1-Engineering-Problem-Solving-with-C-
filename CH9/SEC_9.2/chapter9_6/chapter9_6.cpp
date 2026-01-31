/*
File: chapter9_6.cpp
Desc: This program converts a string to all upper case, using pass by reference
Author: spoonais
Date: 01/22/25 @12:54pm
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

void stringtoupper(char *&ptr_string)   //Pass by ref
{
    while(*ptr_string)                  //deref to get the char at the mem. address
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

    //Call function
    stringtoupper(ptr_strg1);

    //Output string after call to function
    cout << ptr_strg1 << endl;

    //Output string after call to function
    cout << strg1 << endl;

    //Exit
    return 0;
}