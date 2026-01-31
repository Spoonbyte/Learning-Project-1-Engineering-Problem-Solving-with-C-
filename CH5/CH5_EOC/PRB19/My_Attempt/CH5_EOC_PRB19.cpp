/*
File: CH5_EOC_PRB19
Desc: The decoder...user enters a message and it creates an output file that has been decrypted.
Author: spoonais
Date: 09/11/24 @9:45am
*/

#include<iostream>
#include<fstream>
using namespace std;

int main()
{
    //Decalare and Init objects:
    ifstream fin;
    ofstream fout;
    char message('\0'), message_enc('\0'), ch;
    int counter(0);

    //Associate fout stream with a file
    fin.open("Encoded.txt");
    fout.open("Decoded.txt");

    //Get the first character from the input file.
    //fin >> message;
    fin.get(message);

    while(!fin.eof())
    {
        ++counter;

        switch (message)
        {
            case 'c':
                message_enc = 'a';
                fout << message_enc;
                break;
            case 'd':
                message_enc = 'b';
                fout << message_enc;
                break;
            case 'e':
                message_enc = 'c';
                fout << message_enc;
                break;
            case 'f':
                message_enc = 'd';
                fout << message_enc;
                break;
            case 'g':
                message_enc = 'e';
                fout << message_enc;
                break;
            case 'h':
                message_enc = 'f';
                fout << message_enc;
                break;
            case 'i':
                message_enc = 'g';
                fout << message_enc;
                break;
            case 'j':
                message_enc = 'h';
                fout << message_enc;
                break;
            case 'k':
                message_enc = 'i';
                fout << message_enc;
                break;
            case 'l':
                message_enc = 'j';
                fout << message_enc;
                break;
            case 'm':
                message_enc = 'k';
                fout << message_enc;
                break;
            case 'n':
                message_enc = 'l';
                fout << message_enc;
                break;
            case 'o':
                message_enc = 'm';
                fout << message_enc;
                break;
            case 'p':
                message_enc = 'n';
                fout << message_enc;
                break;
            case 'q':
                message_enc = 'o';
                fout << message_enc;
                break;
            case 'r':
                message_enc = 'p';
                fout << message_enc;
                break;
            case 's':
                message_enc = 'q';
                fout << message_enc;
                break;
            case 't':
                message_enc = 'r';
                fout << message_enc;
                break;
            case 'u':
                message_enc = 's';
                fout << message_enc;
                break;
            case 'v':
                message_enc = 't';
                fout << message_enc;
                break;
            case 'w':
                message_enc = 'u';
                fout << message_enc;
                break;
            case 'x':
                message_enc = 'v';
                fout << message_enc;
                break;
            case 'y':
                message_enc = 'w';
                fout << message_enc;
                break;
            case 'z':
                message_enc = 'x';
                fout << message_enc;
                break;
            case 'a':
                message_enc = 'y';
                fout << message_enc;
                break;
            case 'b':
                message_enc = 'z';
                fout << message_enc;
                break;
            case ' ':                   //This will keep any spaces from the input file.
                fout << ' ';
                break;
        }

        //get next character:
        //fin >> message;
        fin.get(message);

    }

    //close the fout stream 
    fin.close();
    fout.close();

    //Exit
    return 0;


}