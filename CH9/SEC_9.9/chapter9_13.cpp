/*
File: chapter9_13.cpp
Desc: To solve the practice problem chapter9_13, my first attempt.
Author: spoonais
Date: 02/7/25 @ 11:30am
Finished @ 
*/

/*
Dev Notes:

I need to be able to do 2 things:
Count the number of unique words (exclude duplicates)
Arrange the words in alphabetical order

Is one dependednt on the other? 
Yes, count unique words 

How can I accomplish this...
Use a vector class of type char to store each word using the "space" char to denote each new word
Can use a 2D vector where each element is a vector word (assume I know the longest word and set as MAX_SIZE)



*/

/*--------- 
Self Feedback:


----------*/

#include<iostream>
#include<fstream>
#include<vector>
using namespace std;

/*--------- PROGRAMMER DEFINED FUNCTIONS ----------*/


/*-------------------------------------------------*/

const int MAX_SIZE = 15;            //Longest word is 12 char long

int main()
{
    //Decalre and init objects
    ifstream fin;
    vector<int> count_A(18,0);

    //Create 2D vector
    vector<char> word(MAX_SIZE, '\0');      //Init each word with maxsize and null
    vector<vector<char>> word_list(18, word);

    //Associate filestream with input file
    fin.open("input.txt");
    if(fin.fail())
    {
        cerr << "ERROR! Input file failed to open...Exiting program" << endl;
        exit(1);
    }

    // //Check that 2D array was init properly
    // for(int i=0; i < word_list.size(); ++i)
    // {
    //     for(int j=0; j < word.size(); ++j)
    //     {
    //         cout << word[j];
    //     }
    //     cout << endl;
    // }
  

    //Read in data from file
    for(int i=0; i < word_list.size(); ++i)
    {
        for(int j=0; j < word_list[i].size(); ++j)
        {
            fin >> word_list[i][j];

            if(fin.peek() == ' ' || fin.peek() == '.' )
                break;
        }
    }

    // //Write to console
    // for(int i=0; i < word_list.size(); ++i)
    // {
    //     for(int j=0; j < word_list[i].size(); ++j)
    //     {
    //         cout << word_list[i][j];
    //     }
    //     cout << endl;
    // }

    //Count actual # of letters in each word 
    for(int h=0; h < word_list.size(); ++h)
    {
        int count(0);

        for(int i=0; i < word_list[h].size(); ++i)
        {
            if(word_list[h][i] != '\0')
            {
                count++;
            }
        }

        //Store each count into count array 
        count_A[h] = count;

        // cout << "Word " << h << " has " << count << " letters " << endl;

    }

    // //Check that count array stored length of each word
    // for(int i=0; i<18; i++)
    // {
    //     cout << count_A[i] << endl;
    // }
    
    

    //Count unique words
    //Check for word size first, then if same check characters
    for(int i=0; i < word_list.size(); ++i)
    {
        int same(0);

        for(int j=i+1; j < word_list.size(); ++j)
        {
            if(count_A[i] == count_A[j])
            {

                // same++;

                for(int m=0; m < count_A[i]; ++m)
                {
                    cout << word_list[i][m] << endl;
                    // if(word_list[i][m] == word_list[j][m])
                    // {
                    //     cout << word_list[i][m] << endl;
                    // }
                }
            }

        }

        // cout << same << endl;

    }

    

    //EXIT 
    return 0;
}