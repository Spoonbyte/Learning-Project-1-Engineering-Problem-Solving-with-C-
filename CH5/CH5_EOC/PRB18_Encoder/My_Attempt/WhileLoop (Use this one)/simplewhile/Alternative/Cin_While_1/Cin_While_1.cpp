/*
File: Cin_While.cpp
Desc: To test why the while loop is not ending.
Author: spoonais
Date: 09/09/24 @11:35am
*/

#include<iostream>
#include<fstream>
#include<cmath>
using namespace std;

int main()
{
    //Decalare and Init objects:
    int num(0);
    char letter,ch;

    cout << "Please provide the letter to convert" << endl;
    cin >> letter;
    
    while(!cin.eof()) 
    {
        switch(letter)
        {
            case 'a':
                cout << "1" << endl;
                break;
        }

        cin >> letter; //Seems like for cin.eof() you need to manually enter (ctrl+z) to trigger the eof. With fin.eof() you just need to attempt to read another line.

    }

    //Exit
    return 0;


}