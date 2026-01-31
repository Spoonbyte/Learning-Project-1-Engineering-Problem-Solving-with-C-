/*
File: CH6EOC_22_Book.cpp
Desc: To test the program from #22...this is the books solution.
Author: spoonais
Date: 11/29/24 @ 12:00pm
*/

#include<iostream>
#include<cmath>
#include<fstream>
using namespace std;

const int VAL_OF_HEADS = 1;
const int VAL_OF_TAILS = 0;

//#Problem 22:
/*----------- PROGRAMMER DEFINED FUNCTION ------------*/

int coinflip(int min, int max)
{
    //Return the random value between the range of a and b
    /* Breakdown of code below
    return = (rand()%2) + 0
    So the remainder is either 1 or zero, like a coin flip.
    
    */
    return (rand()%(max-min+1))+min;
    
}

/*-----------------------------------------------------*/

int main()
{
    //Decalare and Init objects:
    int num_of_tosses(0), num_of_heads(0), user_request(0);

    //Ask user for # of flips
    cout << "Please provide the number of times to flip the coin" << endl;
    cin >> user_request;

    while (user_request <= 0)
    {
        cout << "Number of tosses must be greater than zero." << endl;
        // Get the number of tosses from user
        cout << "Enter the number of tosses using the fair coin: " << endl;
        cin>> user_request;
    }

    while(num_of_tosses < user_request)
    {
        //increment tosses
        num_of_tosses++;

        int result = coinflip(VAL_OF_TAILS,VAL_OF_HEADS);
        cout << result << endl;

        //Check if the function returns a positive
        if(result == VAL_OF_HEADS)
        {   
            num_of_heads++;
        }

    }

    //Print the number of head count
    cout << "Count of heads " << num_of_heads << endl;

    //Subtract the num_of_heads from the tosses and print the count of tails
    cout << "Count of tails " << num_of_tosses - num_of_heads << endl;

    //Percentages:
    cout << "The Percentage of head count" << (100*num_of_heads)/num_of_tosses << endl;
    cout << "The Percentage of tail count: " << 100.0 * (num_of_tosses-num_of_heads)/num_of_tosses << endl;

    //exit
    return 0;

}