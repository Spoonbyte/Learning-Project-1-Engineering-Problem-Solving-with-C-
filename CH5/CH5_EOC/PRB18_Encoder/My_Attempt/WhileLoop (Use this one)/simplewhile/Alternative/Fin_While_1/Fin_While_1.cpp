/*
File: Fin_While.cpp
Desc: To test why the while loop is not ending.
Author: spoonais
Date: 09/09/24 @1:30pm
*/

#include<iostream>
#include<fstream>
#include<cmath>
using namespace std;

int main()
{
    //Decalare and Init objects:
    ifstream fin;
    int num(0);
    char letter,ch;

    //Associate the filestream with file
    fin.open("letter.txt");

    cout << "Please provide the letter to convert" << endl;
    fin >> letter;
    
    while(!fin.eof()) 
    {
        switch(letter)
        {
            case 'a':
                cout << "1" << endl;
                break;
            case 'b':
                cout << "2" << endl;
                break;
        }

        //Attempt to read PAST the eof()
        //If this is not included then it becomes infinite loop since fin.eof() never triggers.
        fin >> letter;

    }

    //Close filestream
    fin.close();

    //Exit
    return 0;


}