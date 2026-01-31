/*
File: CH7EOC_27_Book.cpp
Desc: Cryptography problem #27, books solution
Author: spoonais
Date: 1/2/25 @ 10am
Finished copying @ 11am
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

const int NO_OF_LETTERS = 26;

int main()
{
    //Decalare and Init objects:
    int key[NO_OF_LETTERS], k(0), I;
    char char_in;
    string input_name, output_name;

    //Declare the input file object and output file object
    ifstream input;
    ofstream output;

    //Get key from user and validate it
    cout << "Enter the 26 alphabets: " << endl;

    //Validate the entered key using the while loop.
    while(k < NO_OF_LETTERS)
    {
        //Get the input
        cin >> char_in;

        //Use theh switch case to check the entered key contains space, backspace tab or newline
        switch (char_in)
        {
            //Ignore while space characters (lines 47 - 55)
            case ' ':
            break;
            case '\b':
            break;
            case '\t':
            break;
            case '\n':
            break;
            default:
            //Check if input key is a symbol or not
            if((char_in < '!' ) || (char_in > '~'))
            {
                cout << "OUT OF RANGE" << endl;
            }
                else
                {
                    //Assign the character to the key
                    key[k] = (int)char_in;

                    //Display the corresponding ASCII value for // key
                    cout << "key[" << k << "] = " << key[k] << endl;

                    //Increment value
                    k++;
                }
            break;
        }
    }
    
    //Continue the loop until the key for all 26 characters is entered by user
    for(k = 1; k < NO_OF_LETTERS; k++)
    {
        //Check the given key is unique or not
        //If there are duplicates exit program...
        //MODIFY: OR can make user reenter the key element that was duplicated
        for(I=0; I < k; I++)
        {
            if(key[k] == key[I])
            {
                //Display the error message
                cout  <<"Key[" << k << "] value already exists" << endl;
            
                //Pause the output screen
                system("Pause");

                //Return void
                return 0;
            }
        }
    }

    //Read the file names from the user
    cout << "Enter input file name " << endl;
    cin >> input_name;
    cout << "Enter output file name " << endl;
    cin >> output_name;

    //Open the file
    input.open(input_name.c_str());
    if(input.fail())
    {
        cerr << "Error! " << input_name << "could not open" << endl;
        exit(1);
    }

    //Open the file for writing
    output.open(output_name.c_str());

    //read the first character
    input.get(char_in);

    //Loop continuously reads the char until eof
    while(!input.eof())
    {
        if((char_in >= 'a') && (char_in <= 'z'))
        {
            //Encrypt the input file
            output << (char)key[char_in - 'a'];

        }
            else
            {
                switch(char_in)
                {
                    case '\n':
                    break;
                    case ' ':
                    break;
                    case '\t':
                    output << char_in;
                    break;
                    //If input filie contains special char, encrypt to space
                    case '.':
                    case ',':
                    case '?':
                    case '!':
                    case ':':
                    case ';':
                    output << ' ';
                    break;
                    default:
                    output << char_in;
                    break;
                }
            }
        
        //Get next char from the file:
        input.get(char_in);

    }

    //Pause the output screen
    system("Pause");

    //Exit
    return 0;

}