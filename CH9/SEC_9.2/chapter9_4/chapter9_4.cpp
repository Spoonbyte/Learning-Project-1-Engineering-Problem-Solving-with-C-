/*
File: chapter9_4.cpp
Desc: To count the number of times string 2 occurs in string 1
Author: spoonais
Date: 01/21/25 @11:50am
*/

#include<iostream>
#include<cstring>
using namespace std;

int main()
{
    //Declare and init
    int count(0);
    char strg1[] = "abbcfgwbibbw";
    char strg2[] = "bb";
    char *ptr1(strg1), *ptr2(strg2);

    cout << ptr1 << endl;               //Why doesnt this print the address like the regular array above?
    
    // //This works though to print the char at the memory location...which implies that "ptr" has the mem. address stored
    // cout << *ptr1 << endl; 
    // //Solution from chatgpt to get the mem. address
    // cout << static_cast<void*>(ptr1) << endl;


    // //Count how many times strg2 occurs in strg1
    // while(!(strg1[incr] == '\0'))
    // {
    //     //IF
    //     if(strstr(ptr1,ptr2))
    //     //Count throught the string characters
    //     ++incr;
    // }

    //Books way of solving
    while((ptr1=strstr(ptr1,ptr2)) != NULL)
    {
        count++;
        ptr1++;
    }

    //Print the number of occurences
    cout << "Count: " << count << endl;

    //Exit
    return 0;
}