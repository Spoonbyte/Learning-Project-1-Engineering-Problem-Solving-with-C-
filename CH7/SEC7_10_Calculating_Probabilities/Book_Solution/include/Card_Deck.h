/*
File: Card_Deck.h
Desc: Describes the card deck class, which shuffles the deck
Author: spoonais
Date: 12/22/24 @ 10:22am
Finished:
------------------------------------------------------------------
We use the following compiler directives to avoid including the Card_Deck.h file multiple times.
It is a good idea to always use these directives in the custom header file.
*/
#ifndef CARDDECK_H
#define CARDDECK_H

#include<vector>
#include "C:\Users\sanja\Documents\Local_Cpp_Workspace\CH7\SEC7_10_Calculating_Probabilities\Book_Solution\include\Card.h"
using namespace std;

class CardDeck
{
    public:
        CardDeck();
        void shuffleDeck();
        Card draw();
    private:
    vector<Card> theDeck;
    vector<Card> deltCards;
};

#endif
