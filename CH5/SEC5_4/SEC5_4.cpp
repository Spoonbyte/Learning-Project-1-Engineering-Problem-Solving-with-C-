/*
File:SEC5_4.cpp
Desc: To take a simple HTML file and pull only the text data from it.
Author: spoonais
Date: 08/01/24 @4:21pm
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


    //Go through the file
    while (!fin.eof())
    {   
        
        //Get the first character from the file
        fin.get(character);

        //Toggle the text states
        if(character == '<')
        {
            text_state = false;
        } 
            else 
            {
                if(character == '>')
                {
                    text_state = true;
                    continue; //Prevents the ">" from being written to the output file.
                }

            }

        // cout << text_state << endl;

        //Write only the values that are text_state TRUE
        if(text_state == true)
        {
            fout << character;
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