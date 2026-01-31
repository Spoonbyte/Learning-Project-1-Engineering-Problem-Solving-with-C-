/*
File: CH5_EOC_RPB18.cpp
Desc: The encoder...user types a message and it creates an output file that has been encrypted.
Author: spoonais
Date: 09/08/24 @11:10am
*/

#include<iostream>
#include<fstream>
#include<cmath>
using namespace std;

int main()
{
    //Decalare and Init objects:
    ofstream fout;
    char message('\0'), message_enc('\0'), ch;
    int counter(0);

    //Associate fout stream with a file
    fout.open("Encoded.txt");

    do 
    {
        ++counter;

        if(counter == 1)
        {   
            //Message for user to type 
            cout << "Please provide the message you would like to encode" << endl;
        }

        cin >> message;

        // cout << message << endl;

        switch (message)
        {
            case 'a':
                message_enc = 'c';
                fout << message_enc;
                break;
            case 'b':
                message_enc = 'd';
                fout << message_enc;
                break;
            case 'c':
                message_enc = 'e';
                fout << message_enc;
                break;
            case 'd':
                message_enc = 'f';
                fout << message_enc;
                break;
            case 'e':
                message_enc = 'g';
                fout << message_enc;
                break;
            case 'f':
                message_enc = 'h';
                fout << message_enc;
                break;
            case 'g':
                message_enc = 'i';
                fout << message_enc;
                break;
            case 'h':
                message_enc = 'j';
                fout << message_enc;
                break;
            case 'i':
                message_enc = 'k';
                fout << message_enc;
                break;
            case 'j':
                message_enc = 'l';
                fout << message_enc;
                break;
            case 'k':
                message_enc = 'm';
                fout << message_enc;
                break;
            case 'l':
                message_enc = 'n';
                fout << message_enc;
                break;
            case 'm':
                message_enc = 'o';
                fout << message_enc;
                break;
            case 'n':
                message_enc = 'p';
                fout << message_enc;
                break;
            case 'o':
                message_enc = 'q';
                fout << message_enc;
                break;
            case 'p':
                message_enc = 'r';
                fout << message_enc;
                break;
            case 'q':
                message_enc = 's';
                fout << message_enc;
                break;
            case 'r':
                message_enc = 't';
                fout << message_enc;
                break;
            case 's':
                message_enc = 'u';
                fout << message_enc;
                break;
            case 't':
                message_enc = 'v';
                fout << message_enc;
                break;
            case 'u':
                message_enc = 'w';
                fout << message_enc;
                break;
            case 'v':
                message_enc = 'x';
                fout << message_enc;
                break;
            case 'w':
                message_enc = 'y';
                fout << message_enc;
                break;
            case 'x':
                message_enc = 'z';
                fout << message_enc;
                break;
            case 'y':
                message_enc = 'a';
                fout << message_enc;
                break;
            case 'z':
                message_enc = 'b';
                fout << message_enc;
                break;
        }

        //When this part is included then the only printed characters are "el" and the encoded file is "gn"
        //not sure why?
        // if (cin.get() == '\n') {break;} 


    } while (!cin.eof());

    //close the fout stream 
    fout.close();

    //Exit
    return 0;


}