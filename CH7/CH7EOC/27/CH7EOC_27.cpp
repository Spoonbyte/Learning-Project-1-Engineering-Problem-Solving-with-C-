/*
File: CH7EOC_27.cpp
Desc: Cryptography problem #27
Author: spoonais
Date: 12/31/24 @ 12:00pm
Restared 1/1/25 @ 3:30pm 
Finished: 1/1/25 @5:04pm
*/

/*-------- SELF FEEDBACK -----------

#1
In order to make sure the code to encode was working properly, it was easier to just hardcode the key instead 
of having to enter a key every single time.

#2
When I had the message[] array not presized with a number in the brackets there was some odd behavior. 
If I was reading from the input file and added more than 32 characters it stopped encoding.

Example:input.txt
-----------------------------
well hello the my name is Sanjay            //This would encode 
well hello ther my name is Sanjay           //This would NOT encode
-----------------------------

Once I input a capacity of 33 it was able to read in the file and encode all the characters...not sure why?

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
    ofstream fout;
    string alpha = "abcdefghijklmnopqrstuvwxyz";
    char message[100] = {'\0'};
    // char key[] = {'1','2','3','4','5','6','7','8','9','~','!','@','#','$','%','^','&','*','(',')','=','+','{',']','<','?'};
    char key[] = {'q','w','e','r','t','y','u','i','o','p','a','s','d','f','g','h','j','k','l','z','x','c','v','b','n','m'};
    int counter(0);

    // cout << key[25] << endl;

    // //User assigns characters to the key
    // //TO DO: Add code that prevents the user from entering the same symbol for different letters
    // cout << "Create the key" << endl;
    // for(int i=0; i < N; ++i)
    // {
    //     cout << "Provide the replacement for " << alpha.c_str()[i]  << " in the data file" << endl;
    //     cin >> key[i];
    // }

    //Associate the file stream with input file. Exit if it fails to find the input file
    fin.open("input.txt");
    if(fin.fail())
    {
        cerr << "The input file failed to open" << endl;
        exit(1);
    }
    
    //Open output file stream
    fout.open("Encoded.txt");

    //Get the first character and store into message array
    //If I dont have this statement here, the counter will be 18 instead of 17.
    fin.get(message[counter]);

    //Read the message from the input file and store into an char array
    while(!fin.eof())
    {
        counter++;
        fin.get(message[counter]);  //get is better than >> since it captures the spaces, >> ignores them
    }

    //close the filestream
    fin.close();

    //TRBLSHT
    //Check that message was read into array properly
    cout << "Original message: ";
    for(int c=0; c < counter; ++c)
    {
        cout  << message[c];
    }
    cout << endl;

    //Use the generated key to go through the data file and replace all the letters with characters
    for(int i=0; i < counter; ++i)
    {
        char store = message[i];    //For some reason I couldnt do "switch(message[i])"...it wouldnt match to the case
        //Replace each message letter with key character
        switch(store)
        {
            case 'a':
                message[i] = key[0];
                break;
            case 'b':
                message[i] = key[1];
                break;
            case 'c':
                message[i] = key[2];
                break;
            case 'd':
                message[i] = key[3];
                break; 
            case 'e':
                message[i] = key[4];
                break;
            case 'f':
                message[i] = key[5];
                break;
            case 'g':
                message[i] = key[6];
                break;
            case 'h':
                message[i] = key[7];
                break;  
            case 'i':
                message[i] = key[8];
                break;
            case 'j':
                message[i] = key[9];
                break;
            case 'k':
                message[i] = key[10];
                break;
            case 'l':
                message[i] = key[11];
                break; 
            case 'm':
                message[i] = key[12];
                break;
            case 'n':
                message[i] = key[13];
                break;
            case 'o':
                message[i] = key[14];
                break;
            case 'p':
                message[i] = key[15];
                break;
            case 'q':
                message[i] = key[16];
                break;
            case 'r':
                message[i] = key[17];
                break;
            case 's':
                message[i] = key[18];
                break; 
            case 't':
                message[i] = key[19];
                break;
            case 'u':
                message[i] = key[20];
                break;
            case 'v':
                message[i] = key[21];
                break;
            case 'w':
                message[i] = key[22];
                break;
            case 'x':
                message[i] = key[23];
                break; 
            case 'y':
                message[i] = key[24];
                break;
            case 'z':
                message[i] = key[25];
                break;
            case ' ':
            case '.':
            case ',':
            case '?':
            case '!':
            case ':':
            case ';':
                message[i] = ' ';
            
        }

    }

    //Check that message was encoded properly
    cout << "Encoded message: See output file 'Encoded.txt' ";
    for(int c=0; c < counter; ++c)
    {
        fout << message[c];
    }

    //close
    fout.close();

    //Exit
    return 0;

}