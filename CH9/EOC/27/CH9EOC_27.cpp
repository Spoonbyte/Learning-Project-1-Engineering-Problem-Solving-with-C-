/*
File: CH9EOC_27.cpp
Desc: To modify chapter9_13 based on #27.
Author: spoonais
Date: 02/24/25 @ 2:05pm
Finished: @
*/

/*
Self feedback:


*/

#include<iostream>
#include<string>    
#include<fstream>
#include<cctype>
#include<list>
#include<algorithm>
using namespace std;

//Function Protoypes
void get_word(istream& in_stream, string& w);

/*---------- PROGRAMMER DEFINED FUNCTIONS -------------*/

/*
Name: get_word()
Objective: Get a word from input file and add it to the variable word.
Pre-Cond:
Post-Cond:
*/
void get_word(ifstream& in_stream, string& w)
{
    char ch;
    w = "";     //Clear word to make way for new word

    in_stream.get(ch);
    
    //If its a non-letter this will remove from stream
    while(!isalpha(ch) && !in_stream.eof())
    {
        in_stream.get(ch);
    }

    //Store letters
    //If it is a letter then it will append each char into the word until 
    //then next non-letter is reached
    while(isalpha(ch) && !in_stream.eof())
    {
        ch = tolower(ch);
        w += ch;
        in_stream.get(ch);
    }
    
}

/*------------------------------------------------------*/

int main()
{
    //Decalare and Init objects:
    ifstream in_stream;
    string infile;
    string word;                        //String to hold current word

    //Prompt for filename and open files
    cout << "Enter the input filename" << endl;
    cin >> infile; 

    in_stream.open(infile.c_str());
    if(in_stream.fail())
    {
        cerr << "ERROR! Failed to open file " << infile << endl;
    } 
        else
        {
            cout << "File opened success!" << endl;
        }  

    
    list<string> wordlist;

    //Start the file read in process
    get_word(in_stream,word);       //Get first word
    //(*1*)
    auto iter = wordlist.begin();

    //While non-empty word was returned
    //(*1*)
    while(word.size())
    {
        wordlist.insert(iter, word);  //Add word to word list
        iter++;
        get_word(in_stream,word);    //Get next word

    }
    
    //Sort words by alphabetical order
    wordlist.sort();

    //Check sorted list of words
    for(auto iter1 = wordlist.begin(); iter1 != wordlist.end(); ++iter1)
    {
        cout << *iter1 << endl;
    }

    cout << "----------------" << endl;
    
    //Count unique words
    int count(0);
    for(auto iter1 = wordlist.begin(); iter1 != wordlist.end(); ++iter1)
    {
        for(auto iter2 = iter1; iter2 != wordlist.end(); iter2++)
        {
            // cout << *iter1 << " = " << *iter2 << endl;
            if(*iter1 == *iter2)
            {
                count++;
            }
            else
                {
                    cout << *iter1 << " occurs " << count << " times " << endl;

                    for(int i=1; i < count; i++)
                    {
                        iter1++;     //Increment iterator past the repeats
                    }

                    break; //stop comparing
                }
        }

        count = 0;
    }

    //Close 
    in_stream.close();

    return 0;

}