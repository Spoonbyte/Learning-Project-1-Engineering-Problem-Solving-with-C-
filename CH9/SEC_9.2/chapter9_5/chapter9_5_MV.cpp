/*
File: chapter9_5_MV.cpp
Desc: This program converts a string to all upper case, my attempt without pointers 
Author: spoonais
Date: 01/22/25 @12:09pm
Finished @ 12:25pm
*/

/*
Self Feedback:

I originally had the while loop like this:
-------------------
while(strg1[iter] != '\0')
{
    ....
}
-------------------------
but then I read that the while loop will exit anyways when encountering a null character...
so I just made it as while(strg1[iter])

*/

#include<iostream>      //Required for cout
#include<cctype>        //Required for toupper
using namespace std;

int main()
{
    //Declare and init
    char strg1[] = "abbcfgwbibbw";
    int iter(0);

    //My simple version without pointers
    //For loop 
    while(strg1[iter])                          //Go until the NULL char
    {
        strg1[iter] = toupper(strg1[iter]);     //Capitalize the current char
        iter++;                                 //Move to next char
    }
    //Print the new string
    cout << strg1 << endl;

    //Exit
    return 0;
}