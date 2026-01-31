/*
File: Card.cpp
Desc: This was my attempt to solve the 7.10 problem, how to simulate the probability of events occuring using 
a shuffled deck of cards.
Author: spoonais
Date: 12/19/24 @ 
Finished: 12/20/24 @ 2:10pm
*/

/*----------- SELF FEEDBACK -------------

Takeaways:
I have no idea how this code works
--------------------------
//Call the shuffle 
std::random_device rd;
std::mt19937 g(rd());

std::shuffle(x.begin(), x.end(), g);
--------------------------------------

*/
#include<iostream>
#include<random>
#include<algorithm>
#include<vector>

/*-------------- PROGRAMMER DEFINED FUNCTION --------------------*/
//Felt the need to make this a function, makes it easier to debug in the code to see exaclty where the function was called.
//Void function because its MODIFYING an argument, not returning any value...
//Pass by reference allows the original vector "v" to be modified by the function
void shuffle_deck(std::vector<int>& x)          
{
    //Call the shuffle 
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(x.begin(), x.end(), g);
   
    // //TRBLSHT: print SHUFFLED deck
    // for(int p=0; p<=51; ++p)
    // {
    //     std::cout << v[p] << std::endl;
    // }
    return;
}

/*---------------------------------------------------------------*/

int main()
{
    //Declare and init objects
    std::vector<int> v;
    double SIM(0);
    int pick1(0), pick2(0);                 //Where to store the 2 picks
    double event_occured(0);                     //This is the counter for the number of times the event occurs

    //Assign values to the array
    //52 unique "cards"
    for(int i=1; i<=52; ++i)
    {
        v.push_back(i);
    }

    // //TRBLSHT: See that array took values
    // for(int p=0; p<=51; ++p)
    // {
    //     std::cout << v[p] << std::endl;
    // }

    // //Check that shuffle_deck() works as intended:
    // shuffle_deck(v);
    // for(int i=0; i<=51; ++i)
    // {
    //     std::cout << v[i] << std::endl;
    // }

    //Get user input for simulations to run
    std::cout << "Please provide the number of simualtions to run " << std::endl;
    std::cin >> SIM;

    //Create logic that determines the event space
    //Shuffle card deck, then pick 2 cards, reshuffle ...etc
    //Count the number of times that you choose 2 cards and they are red and value < 10.
    //Essentially #s 1-16 will be red cards that are less than 10 in value
    for (int k=0; k<=SIM; ++k)
    {   
        //Call the shuffle function
        shuffle_deck(v);

        //Draw 2 cards from top of deck
        pick1 = v[0];
        pick2 = v[1];

        // std::cout << pick1 << "," << pick2 << std::endl;

        if((1 <= pick1 && pick1 <=16) && (1 <= pick2 && pick2 <=16))
        {
            event_occured++;
        }
    }

    
    //Calculate the probability of event occuring
    std::cout << "p(E) = " << event_occured/SIM << std::endl;

    //Exit
    return 0;


    // //TEST CODE: This helped with getting started with my code
    // std::vector<int> numbers = {1, 2, 3, 4, 5};
    // std::random_device rd;
    // std::mt19937 g(rd());
    // std::shuffle(numbers.begin(), numbers.end(), g);
    // for (int num : numbers) {
    //     std::cout << num << " ";
    // }
    // std::cout << std::endl;
    // return 0;

}