/*
File: SEC7_1_Mod2.cpp
Desc: To confirm the mod2 output
Author: spoonais
Date: 12/04/24 @ 11:20am
*/

/*-------- SELF FEEDBACK -----------*/
/*

*/
/*-----------------------------------*/

#include<iostream>
#include<fstream>
#include<cmath>
using namespace std;

int main()
{
    //Decalare and Init objects:
    char greeting[] = "HelloWorld";
    char greeting1[] = {'H','e','l','l','o'};
    int numbers[] = {1,2,3,4,5};

    //Print to console
    cout << greeting << endl;

    //So it does store all of the characters into a array AND you can print out the entire array by just calling 
    //the variable name...instead of doing what I did below..
    cout << greeting[0] << endl;
    cout << greeting[1] << endl;
    cout << greeting[2] << endl;
    cout << greeting[3] << endl;
    cout << greeting[4] << endl;
    cout << greeting[5] << endl;
    cout << greeting[6] << endl;
    cout << greeting[7] << endl;
    cout << greeting[8] << endl;
    cout << greeting[9] << endl;

    // cout << greeting1[0];
    // cout << greeting1[1];
    // cout << greeting1[2];
    // cout << greeting1[3];
    // cout << greeting1[4] << endl;

    cout << numbers << endl;

    //Exit
    return 0;

}