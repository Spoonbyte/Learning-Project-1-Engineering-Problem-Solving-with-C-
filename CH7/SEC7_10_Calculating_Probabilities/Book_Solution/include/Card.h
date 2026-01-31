/*
File: Card.h
Desc: Describes the card class (suit, value)
Author: spoonais
Date: 12/20/24 @ 10:20pm
Finished:
------------------------------------------------------------------
We use the following compiler directives to avoid including
the Card.h file multiple times

It is a good idea to always use these directives in the custom header file.

*/

#ifndef CARD_H
#define CARD_H
#include<iostream>
using namespace std;


class Card 
{
    public:
    //Constructors
    Card();                             //Default
    Card(char aSuit, int aRank);        //Parameterized

    //Accessors
    int getRank() const;
    char getSuit() const;

    //Formatted Display Method
    //Example if char is S then suit is 11
    //Output will be: Jack of Spades 

    void displayCard(ostream& outStream) const;

    private:
    char suit;
    int rank;

};


















#endif

