/*
File: CH6EOC_11-14.cpp
Desc: To test the program from #11-14
Author: spoonais
Date: 11/21/24 @5:00pm
*/

#include<iostream>
#include<cmath>
using namespace std;

/*----------- PROGRAMMER DEFINED FUNCTION ------------*/

int fives(int n)
{
    //Declare objects
    int result;

    //comput result to return
    if ((n%5) == 0)
    {
        return 1;
    }
        else 
        {
            return 0;
        }
}

/*-----------------------------------------------------*/

int main()
{
    //Decalare and Init objects:
    // int value(0);

    //ask for user input
    // cout << "Please provide a number. If the number is divisible by 5 then output will be 1" << endl;
    // cin >> value;

    //call function 
    cout << fives(ceil(sqrt(62.5))) << endl;

    cout << ceil(sqrt(62.5)) << endl;

    //exit
    return 0;

}