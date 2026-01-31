/*
File: Card.cpp
Desc: Card class implementation
Author: spoonais
Date: 12/20/24 @ 10:47pm
Finished: 
*/

/*----------- SELF FEEDBACK -------------

Takeaways:


*/
#include<iostream>
#include<random>
#include<algorithm>
#include<vector>
#include "C:\Users\sanja\Documents\Local_Cpp_Workspace\CH7\SEC7_10_Calculating_Probabilities\Book_Solution\include\Card.h"

//Constructors
Card::Card():rank(2), suit('S')
{

}
Card::Card(char ch, int i): rank(i)
{
    suit = toupper(ch);
}

//Accessor methods
char Card::getSuit() const
{
    return suit;
}

int Card::getRank() const
{
    return rank;
}

//Formatted display method
void Card::displayCard(ostream& out) const
{
    string suitString;
    //Establish suit string
    //Constructors and mutators guarantee uppercase suit 
    switch(suit)
    {
        case 'S':
            suitString = "Spades";
            break;
        case 'D':
            suitString = "Diamonds";
            break;
        case 'C':
            suitString = "Clubs";
            break;
        case 'H':
            suitString = "Hearts";
            break;
        default:
            suitString = "Invalid Suit";
            break;
    }

    if(rank >= 2 && rank < 11)
    {
        out << rank << " of " << suitString;
    }
    else
    {
        switch(rank)
        {
            case 11:
                out << "JACK of " << suitString;
                break;
            case 12:
                out << "QUEEN of " << suitString;
                break;
            case 13:
                out << "KING of " << suitString;
                break;
            case 14:
                out << "ACE of " << suitString;
                break;
            
        }
    }

    //End display
    return;
}