/*
File:SEC5_4_Book.cpp
Desc: To take a simple HTML file and pull only the text data from it. Book solution
Author: spoonais
Date: 08/05/24 @2:02pm
*/

#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int main()
{
    //Decalare and Init objects:
    char character; 
    bool text_state(true);
    // string filename;
    ifstream fin;
    ofstream fout;

    //Associate the filestream objects
    fin.open("SmallHTML.html");
    fout.open("HTMLStrip.txt");

    //Ensure that the HTML file opens
    if(fin. fail())
    {
        cerr << "The input file SmallHTML.html failed to open" << endl;
        exit(1);
    }

    //Get the first character from the file
    fin.get(character);

    //Go through the file
    while (!fin.eof())
    {   
        //Check state
        if(text_state)
        {
            if (character == '<')
            {
                text_state = false;
            } 
                else 
                {
                    fout << character;
                }
        } 
            else 
            {
                if(character == '>')
                {
                    text_state = true;
                }

            }

        //Get the next character from the file
        fin.get(character);

    }

    //Close the files
    fin.close();
    fout.close();

    //System Pause
    system("pause");

    //Exit Program
    return 0;


}