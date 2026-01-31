/*
File: chapter9_13_v2.cpp
Desc: To solve the practice problem chapter9_13, my first attempt.
Author: spoonais
Date: 02/7/25 @ 11:30am
Finished: 02/11/25 @ 2:30pm
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

    //Write to console
    cout << "Before removal of repeat words" << endl;
    for(int i=0; i < word_list.size(); ++i)
    {
        for(int j=0; j < word_list[i].size(); ++j)
        {
            cout << word_list[i][j];
        }
        cout << endl;
    }

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
    }

    // //Check that count array stored length of each word
    // for(int i=0; i<18; i++)
    // {
    //     cout << count_A[i] << endl;
    // }
    
    //Remove repeat words
    //Check for word size first, then if same size check character matches and
    //if char matches equals word size then it's the SAME word
    for(int i=0; i < word_list.size(); ++i)
    {
        int match(0);
        // cout << "i = " << i << endl;
        
        for(int j=i+1; j < word_list.size(); ++j)
        {   
            if(count_A[i] == count_A[j])
            {   
                // cout << j << endl;
                for(int m=0; m < count_A[i]; ++m)
                {    
                    if(word_list[i][m] == word_list[j][m] || word_list[i][m] == toupper(word_list[j][m]))
                    {
                        match++;
                    }
                }

                //Need to remove each repeat word from both the "word array" and the "# of letters array"
                if(match == count_A[i])  //If each letter matches then its the same word
                {
                    // cout << "MATCH" << endl;
                    word_list.erase(word_list.begin() + j);
                    count_A.erase(count_A.begin() + j);
                }
            }

            match = 0; //Reset match before next word compare
        }

        // cout << "--------------" << endl;

    }

    cout << "------------------" << endl;

    // //Write to console
    // cout << "After removal of repeat words" << endl;
    // for(int i=0; i < word_list.size(); ++i)
    // {
    //     for(int j=0; j < word_list[i].size(); ++j)
    //     {
    //         cout << word_list[i][j];
    //     }
    //     cout << endl;
    // }

    // //Check that count array after deleting repeated words
    // for(int i=0; i < count_A.size(); i++)
    // {
    //     cout << count_A[i] << endl;
    // }

    //Now with new reduced word_list array, sort by alphabetical order
    for(int i=0; i < word_list.size(); ++i)
    {   
        for(int j=i+1; j < word_list.size() ; ++j)
        {
            if(word_list[j][0] < word_list[i][0])
            {
                word_list[i].swap(word_list[j]);
            }
            
        }   
    }

    for(int i=1; i < word_list.size(); ++i)     //Avoid A since I think the null character is less than all other characters
    {   
        for(int j=i+1; j < word_list.size() ; ++j)
        {
            if(word_list[j][1] < word_list[i][1] && word_list[j][0] == word_list[i][0])
            {
                word_list[i].swap(word_list[j]);
            }
            
        }   
    }

    cout << "After alphabetical order" << endl;
    for(int i=0; i < word_list.size(); ++i)
    {
        for(int j=0; j < word_list[i].size(); ++j)
        {
            cout << word_list[i][j];
        }
        cout << endl;
    }
    

    //EXIT 
    return 0;
}