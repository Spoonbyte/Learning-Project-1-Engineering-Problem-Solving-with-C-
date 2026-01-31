/*
File: CH9EOC_27_book.cpp
Desc: To modify chapter9_13 based on #27.
Author: spoonais
Date: 02/25/25 @ 5:08pm
Started back @ 11:30pm
Finished: @ 12:24am
*/

/*
Self feedback:

Learned that I was having an issue because I was making the type for word_Count list strings 
instead of ints which is why the logic was not working for counting the words.



*/

#include<iostream>
#include<string>    
#include<fstream>
#include<cctype>
#include<list>
#include<algorithm>
using namespace std;

//Function Protoypes
void get_word(ifstream& in_stream, string& w);

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

/*
Name: word_count()
Objective: 
Pre-Cond:
Post-Cond:
*/

void count(list<string> word_list, list<int> &word_Count)
{
    //Declare and init local objs:
    string word_in;
    int num(0);
    list<string>::iterator iter_list = word_list.begin();

    //Clear content
    word_in = "";

    //While
    while(iter_list != word_list.end())
    {
        //Checks the repeated word is avaliable or not 
        if(*iter_list == word_in)
        {
            //calculates the count
            num = word_Count.back() + 1;
            word_Count.pop_back();
            word_Count.push_back(num);
        }
            else
            {
                //insert the value in the list
                word_Count.push_back(1);
                //Assign the next word to variable
                word_in = *iter_list;
            }

        //Increase the count
        iter_list++;

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
    list<int> word_Count;

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

    // //Check sorted list of words
    // for(auto iter1 = wordlist.begin(); iter1 != wordlist.end(); ++iter1)
    // {
    //     cout << *iter1 << endl;
    // }
    // cout << "----------------" << endl;
    
    //Count unique words
    count(wordlist,word_Count);

    //Remove the repeats from wordlist
    auto it = unique(wordlist.begin(),wordlist.end());
    wordlist.erase(it,wordlist.end());

    //print out the counts to console
    auto iter_list = wordlist.begin();
    auto iter_count = word_Count.begin();
    while(iter_list != wordlist.end())
    {
        cout << *iter_list << " : " << *iter_count << endl;
        iter_list++;
        iter_count++;
    }
    

    //Close 
    in_stream.close();

    return 0;

}