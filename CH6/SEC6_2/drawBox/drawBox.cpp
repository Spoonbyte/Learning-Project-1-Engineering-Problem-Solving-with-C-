/*
File: drawBox.cpp
Desc: This is a modification of the drawBlock.cpp code. Its making a box instead.
Author: spoonais
Date: 09/29/24 @9:15am
*/

#include<iostream>
#include<cmath>
using namespace std;

void drawBlock (ostream& out, int size)  //ostream& out is just a place holder for a standard output stream object like cout or ofstream object
{
    int width, height;
    for (height=0; height < size; height++)
    {
        if (height == 0 || height == size - 1)
        {
            for (width=0; width < size; width++)
            {
                out << "*";
            } 

        } 
        else 
        {
            out << "*";
            for (width=1; width <= size - 2; width++) //This worked since the first and last positions always are "*" so that means there are size - 2 empty spaces
            {
                out << " ";
            }
            out << "*";

        }

        out << endl;
    }
}

int main()
{
    //Decalare and Init objects:
    int size;

    //User size
    cout << "Please provide the size" << endl;
    cin >> size;
    
    //Use the function:
    drawBlock(cout, size);

    //Exit
    return 0;

}