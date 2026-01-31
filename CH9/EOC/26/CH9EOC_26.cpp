/*
File: CH9EOC_26.cpp
Desc: To modify chapter9_13 based on #26.
Author: spoonais
Date: 02/24/25 @ 1:30pm
Finished: @2pm
*/

/*
Self feedback:

(*1*): 
I actually implemented some advice from John Ousterhout from his talk "A Philosophy of Software Design  Talks at Google"
He talks about how classes should be deep and I applied this to my functions. The function insert_word() was more LOC than just 
writing the statement to just get the word WITHOUT using a function. This helped clean up about 10-15 LOC.

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
void display_list(ostream& out_stream, list<string> wordlist);

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
Name: display_list()
Objective: Display the list of words to user.
Pre-Cond:
Post-Cond:
*/
void display_list(ostream& out_stream, list<string> wordlist)
{
    list<string>::iterator iter;

    /*2*/
    //Direct the iterator to the beginning of the list
    iter = wordlist.begin();

    while(iter != wordlist.end())
    {
        out_stream << *iter << endl;
        iter++;
    }
}

/*------------------------------------------------------*/

int main()
{
    //Decalare and Init objects:
    ifstream in_stream;
    ofstream out_stream;
    string infile, outfile;
    string word;                        //String to hold current word

    //Prompt for filename and open files
    cout << "Enter the input filename" << endl;
    cin >> infile; 
    cout << "Enter the ouput filename" << endl;
    cin >> outfile; 

    in_stream.open(infile.c_str());
    if(in_stream.fail())
    {
        cerr << "ERROR! Failed to open file " << infile << endl;
    } 
        else
        {
            cout << "File opened success!" << endl;
        }  

    out_stream.open(outfile.c_str());
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

    //Remove all duplicate words after sort
    //(*1*)
    auto iter1 = wordlist.begin();
    auto last = unique(wordlist.begin(), wordlist.end());
    wordlist.erase(last, wordlist.end());   //Erase the last word

    //Output to file
    /*1*/
    out_stream << "There were " << wordlist.size() << " distinct words." << endl;
    out_stream << "Here is the ordered list of words" << endl;
    out_stream << "--------------------------------------------" << endl;
    display_list(out_stream, wordlist);

    //Close 
    in_stream.close();
    out_stream.close();

    return 0;

}