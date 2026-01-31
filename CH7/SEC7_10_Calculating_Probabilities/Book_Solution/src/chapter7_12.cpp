/*
File: chapter7_12.cpp
Desc: This is the books way of solving the problem
Author: spoonais
Date: 12/22/24 @ 10:57am
Finished: 
*/

/*----------- SELF FEEDBACK -------------


--------------------------------------

*/

//Custom Header files
#include "C:\Users\sanja\Documents\Local_Cpp_Workspace\CH7\SEC7_10_Calculating_Probabilities\Book_Solution\include\Card.h"
#include "C:\Users\sanja\Documents\Local_Cpp_Workspace\CH7\SEC7_10_Calculating_Probabilities\Book_Solution\include\Card_Deck.h"
//Standard header files
#include<iostream>
#include<random>
#include<algorithm>
#include<vector>
using namespace std;

/*-------------- PROGRAMMER DEFINED FUNCTION --------------------*/

/*---------------------------------------------------------------*/

int main()
{
    //Declare and init objects
    int n(0);                           //The number of simulations
    CardDeck theDeck;
    Card card1, card2;
    double event_counter(0);
    bool rank;


    //Get user input
    cout << "Please provide the number of simulations to run" << endl;
    cin >> n;

    for(int i=0; i<n; ++i)
    {
        theDeck.shuffleDeck();          //Shuffle the deck
        card1 = theDeck.draw();
        card2 = theDeck.draw();

        //Check if event occured
        if( card1.getRank() < 10 && card2.getRank() < 10)
        {
            rank = true;
        }
            else
            {
                rank = false;
            }
        
        if(rank && ((card1.getSuit() == 'H' || card1.getSuit() == 'D') && (card2.getSuit() == 'H' || card2.getSuit() == 'D')))
        {
            event_counter++;
            cout << "Event " << event_counter << endl;
            card1.displayCard(cout);
            cout << " ";
            card2.displayCard(cout);
            cout << endl;
        }


    }

    //cout
    cout << "Simulated results: " << event_counter << "/" << n  << " = " << event_counter/n << endl;

    //Exit
    return 0;

}