/*
File: chapter_13_book.cpp
Desc: To implement the books solution of chapter9_13.
Author: spoonais
Date: 02/12/25 @9am.
Finished: 
*/

/*
Self feedback:

When first trying to run the compiled program it was not writing anything to the output file.
I think it was because I did not have the #include<string>. Oddly the compiler was not throwing and error.

Update: The issue was not what I said above, rather it was a comnination. 
*1* The way the book formatted the output to the output file was not working
AND 
*2* I forgot to direct the iterator to the start of the wordlist so it was just printing blanks to the 
output file

------------------------------------------------

My method was essentially creating a list of words using a 2D vector.

This method was much more easy to understand in a way because a lot of the functions are 
abstracted, such as using the find() function (checked if the word was alread 
in the list and prevented duplicates) and the sort() function (alphabetized)

Instead of a find() function in my code I choose to add ALL the words to the list THEN compare 
each word to one another to see which were the same. (The book version checked the list to see
if a word was already in it, if it was then it would skip over) This was tough because I had to use 
another vector as a "hash" which stored the # of letters in each word. Then if this was true 
I then tried to match each letter and if the # matches == # letters then it was a duplicate 
word and I had to remove the word from the list AND the corresponding hash.

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
void insert_word(string word, list<string> &wordlist);
void display_list(ostream& out_stream, list<string> wordlist);

/*---------- PROGRAMMER DEFINED FUNCTIONS -------------*/

/*
Name: insert_word()
Objective: Insert a word from input file to the wordlist
Pre-Cond:
Post-Cond:
*/
void insert_word(string word, list<string> &wordlist)
{
    list<string>::iterator iter;

    //Checking to see if the word is already in the wordlist
    //Uses the find() from the std::algorithm
    /* What std::find does
    std::find is a function template defined in the <algorithm> header. It takes three arguments:
    An iterator to the beginning of the range to search.
    An iterator to the end of the range to search.
    The value to search for.
    */

    /*
    I assume how find() works is that the iter starts at wordlist.begin() and then does this:

    if(*iter == word)    //Compares deref to word (Not sure how it does this comparison? Is it char by char?)
    {
        return;          //If a match, then it exits
    }
        else
        {
            iter++       //If no match then keep going
        }

    Essentially the iter stops at the point where there is a match so it 
    never reaches the end of the wordlist.

    */
    iter = find(wordlist.begin(), wordlist.end(), word);

    //This is how the duplicate words are removed
    if(iter == wordlist.end())  
    {
        //Word is not currently in list, insert the word
        wordlist.insert(iter, word);
    }
}

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
    list<string>::iterator iter;

    //Start the file read in process
    get_word(in_stream,word);       //Get first word

    //While non-empty word was returned
    while(word.size())
    {
        insert_word(word,wordlist);
        get_word(in_stream,word);    //Get next word
    }

    //Sort words by alphabetical order
    wordlist.sort();

    //Output to file
    /*1*/
    out_stream << "There were " << wordlist.size() << " distinct words." << endl;
    out_stream << "--------------------------------------------" << endl;
    out_stream << "Here is the ordered list of words" << endl;
    display_list(out_stream, wordlist);

    //Close 
    in_stream.close();
    out_stream.close();

    return 0;

}