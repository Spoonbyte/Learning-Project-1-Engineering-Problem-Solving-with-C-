/*
File: chapter7_8.cpp
Desc: To work with arrays of characters
Author: spoonais
Date: 12/16/24 @ 1:40pm
Finished: 2:00 pm
*/

/*----------- SELF FEEDBACK -------------

Takeaways:

*/
#include<iostream>
#include<cstring>
#include<cmath>
#include<fstream>
using namespace std;

/*-------------- PROGRAMMER DEFINED FUNCTION --------------------*/


/*---------------------------------------------------------------*/

int main()
{
    //Declare and init objects
    char string1[] = "Hello";
    char string2[] = "World";
    char string3[75]; 

    // //print char string length
    // cout << "string1 = " << strlen(string1) << endl;
    // cout << "string2 = " << strlen(string2) << endl; 

    //compare 
    cout << strcmp(string1,string2) << endl;

    //concatentate then copy
    strcat(string1,string2);
    strcpy(string3,string1);

    cout << "string3 = " << string3 << endl;

    //Pause system
    system("pause");

    //Exit
    return 0;

}