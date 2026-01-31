/*
File: CH6EOC_22.cpp
Desc: To test the program from #22
Author: spoonais
Date: 11/27/24 @ 6:20am
*/

#include<iostream>
#include<cmath>
#include<fstream>
using namespace std;

//#Problem 22:
/*----------- PROGRAMMER DEFINED FUNCTION ------------*/

bool coinflip()
{
    //use randmax divided by 2 to get the distribution
    double cutoff = RAND_MAX/2;
    bool heads = true, tails = false;

    if (rand()< cutoff)
    {
        return heads;
    } 
        else
        {
            return tails;
        }

}

/*-----------------------------------------------------*/

int main()
{
    //Decalare and Init objects:
    int flips(0); 
    double head_counter(0), tails_counter(0);

    //Ask user for # of flips
    cout << "Please provide the number of times to flip the coin" << endl;
    cin >> flips;

    //use a for loop to do the flips
    for(int i=0; i<=flips; ++i)
    {
        coinflip();

        if(coinflip() == true)
        {
            ++head_counter;
        }

        if(coinflip() == false)
        {
            ++tails_counter;
        }
    }

    //total
    cout << "Head probability = " << head_counter/flips << endl;
    cout << "Tails probability = " << tails_counter/flips << endl;

    //exit
    return 0;

}