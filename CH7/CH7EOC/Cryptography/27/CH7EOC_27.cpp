/*
File: CH7EOC_27.cpp
Desc: Cryptography problem #27
Author: spoonais
Date: 12/31/24 @ 12:00pm
Finished: 1/1/25
*/

/*-------- SELF FEEDBACK -----------


-----------------------------------*/
#include<iostream>
#include<fstream>
#include <cstring>
#include<string>
using namespace std;

/*------------ PROGRAMMER DEFINED FUNCTIONS -------------*/


/*-------------------------------------------------------*/

const int N = 26;

int main()
{
    //Decalare and Init objects:
    ifstream fin;
    string alpha = "abcdefghijklmnopqrstuvwxyz";
    char key[N];
    char message[] = {'\0'};
    int counter(0);

    //User assigns characters to the key

    //TO DO: Add code that prevents the user from entering the same symbol for different letters
    for(int i=0; i < N; ++i)
    {
        cout << "Provide the replacement for " << alpha.c_str()[i]  << " in the data file" << endl;
        cin >> key[i];
    }

    // //Associate the file stream with input file. Exit if it fails to find the input file
    // fin.open("input.txt");
    // if(fin.fail())
    // {
    //     cerr << "The input file failed to open" << endl;
    //     exit(1);
    // }

    // //Get the first character and store into message array
    // //If I dont have this statement here, the counter will be 18 instead of 17.
    // fin.get(message[counter]);

    // //Read the message from the input file and store into an char array
    // while(!fin.eof())
    // {
    //     counter++;
    //     fin.get(message[counter]);  //get is better than >> since it captures the spaces, >> ignores them
    // }

    // //Check that message was read into array properly
    // for(int c=0; c < counter; ++c)
    // {
    //     cout  << message[c];
    // }

    // //Use the generated key to go through the data file and replace all the letters with characters
    // for(int i=0; i < counter; ++i)
    // {
    //     //Replace each message letter with key character
    //     switch(message[i])
    //     {
    //         case 'a' || 'A':
    //             key[0];
    //             break;
    //         case 'b' || 'B':
    //             key[1];
    //             break;
    //         case 'c' || 'C':
    //             key[2];
    //             break;
    //         case 'a' || 'A':
    //             key[0];
    //             break; 
    //         case 'a' || 'A':
    //             key[0];
    //             break;
    //         case 'b' || 'B':
    //             key[1];
    //             break;
    //         case 'a' || 'A':
    //             key[0];
    //             break;
    //         case 'a' || 'A':
    //             key[0];
    //             break;  
            
    //     }

    //     //Print the encoded message
    //     cout << message[i] << endl;
    // }

    //Exit
    return 0;

}