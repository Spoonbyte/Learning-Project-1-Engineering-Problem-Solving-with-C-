/*
File: rand.cpp
Desc: To solve the SESC6_5 problems using the rand() function.
Author: spoonais
Date: 11/15/24 @6:35am
*/

#include<iostream>
#include<cstdlib>
using namespace std;

/*---------------------------------------------------------------------------*/


/*---------------------------------------------------------------------------*/

int main()
{
    //Decalare and Init objects:
    int seed(0);

    //User seed value
    cout << "Please provide a seed value for initializing the random number sequence" << endl;
    cin >> seed;

    //Initialize seed
    srand(seed);

    //Print out 10 random numbers
    for(int i=1; i<=10; i++)
    {
        cout << "Random number " << i << " = " << rand() << endl;
    }

    return 0;

}