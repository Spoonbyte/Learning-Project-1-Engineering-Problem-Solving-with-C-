/*
File:SEC5_4M2.cpp
Desc: Take SEC5_4 program and use switch statements
Author: spoonais
Date: 08/05/24 @3:05pm
*/

#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int main()
{
    //Decalare and Init objects:
    char character; 
    int text_state(1);
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

    // //Get the first character from the file
    // fin.get(character);

    //Go through the file
    while (fin.get(character))
    {   
        // //Get the first character from the file
        // fin.get(character);
        
        //Switch Statement
        switch (text_state)
        {
            case 1:
                if(character == '<')
                {
                    text_state = 0;
                }
                    else
                    {
                        fout << character;
                    }
                break;
            case 0:
                if(character == '>')
                {
                    text_state = 1;
                }
                break;

        }

        

    }

    //Close the files
    fin.close();
    fout.close();

    //System Pause
    system("pause");

    //Exit Program
    return 0;
}