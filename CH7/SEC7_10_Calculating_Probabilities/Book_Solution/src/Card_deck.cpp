/*
File: Card_deck.cpp
Desc: The implementation of the Card_Deck.h file
Author: spoonais
Date: 12/22/24 @ 10:30AM
Finished: 
*/

#include "C:\Users\sanja\Documents\Local_Cpp_Workspace\CH7\SEC7_10_Calculating_Probabilities\Book_Solution\include\Card_Deck.h"
#include<ctime>
#include<random>
#include<algorithm>
using namespace std;

CardDeck::CardDeck()
{
    //13 cards in each suit
    //52 new cards
    for (int i=2; i<15; ++i)
    {
        theDeck.push_back(Card('S',i));         //Add a spade to the deck
        theDeck.push_back(Card('H',i));         //Add a heart to the deck
        theDeck.push_back(Card('D',i));         //Add a diamond to the deck
        theDeck.push_back(Card('C',i));         //Add a clubs to the deck
    }

    srand(time(NULL));                          //Must seed RNG 1 time!
}

Card CardDeck::draw()
{
    //Draw and return one card
    if(theDeck.empty())
    {
        exit(1);
    }

    Card aCard = theDeck.back();               //Draw card
    theDeck.pop_back();                        //Remove card

    //Retain card for shuffle
    deltCards.push_back(aCard);
    return(aCard);
}

void CardDeck::shuffleDeck()
{
    //Replace drawn cards
    for(int i=0; i<deltCards.size(); ++i)
    {
        theDeck.push_back(deltCards[i]);
    }

    //Clear the vector
    deltCards.resize(0);

    //These are not included in the books original solution but are needed since random_shuffle has been replaced with shuffle
    std::random_device rd;
    std::mt19937 g(rd());
    
    //Use the top level function from algorithm
    shuffle(theDeck.begin(), theDeck.end(), g);
}