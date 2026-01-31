/*
File: chapter9_13_v3.cpp
Desc: To solve the practice problem chapter9_13.
Improvement on v2 but using the idea of a buffer to hold the next word.
Author: spoonais
Date: 02/13/25 @ 9:24am
Finished: 
*/

/*
Dev Notes:



*/



#include<iostream>
#include<fstream>
#include<vector>
using namespace std;

/*--------- PROGRAMMER DEFINED FUNCTIONS ----------*/

/*
Name: getwrd()
Objective
Pre-Cond
Post-Cond
*/

void getwrd(ifstream& in, vector<char> word_buff)
{
    //Declare and init
    char ch;
    int count(0); 
    word_buff = {'\0'};  //Reinit word upon each funtion call

    //Get first char
    in.get(ch);

    //Check if space or period
    while(!(ch == ' '))
    {
        word_buff[count] = ch;
        count++;
        in.get(ch);
    }

    // //Print word
    // for(int i=0; i < count; i++)
    // {
    //     cout << word_buff[i];
    // }
    // cout << endl;
}

void insertwrd(vector<char> buff, vector<char> word)
{
   //Not sure how to make a comparable function to check against the words in the list
}

/*-------------------------------------------------*/

const int MAX_SIZE = 15;            //Longest word is 12 char long

int main()
{
    //Decalre and init objects
    ifstream fin;
    vector<int> count_A(18,0);
    vector<char> buffer;

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

    while(!fin.eof())
    {
        //Get word
        getwrd(fin,buffer);

        // //Insert word
        // insertwrd(buffer,word);

    }


    for(int i=0; i < word.size(); ++i)
    {
        cout << word[i];
    }
    cout << endl;

  
    // //Read in data from file
    // for(int i=0; i < word_list.size(); ++i)
    // {
    //     for(int j=0; j < word_list[i].size(); ++j)
    //     {
    //         fin >> word_list[i][j];

    //         if(fin.peek() == ' ' || fin.peek() == '.' )
    //             break;
    //     }
    // }

    // //Write to console
    // cout << "Before removal of repeat words" << endl;
    // for(int i=0; i < word_list.size(); ++i)
    // {
    //     for(int j=0; j < word_list[i].size(); ++j)
    //     {
    //         cout << word_list[i][j];
    //     }
    //     cout << endl;
    // }

    // //Count actual # of letters in each word 
    // for(int h=0; h < word_list.size(); ++h)
    // {
    //     int count(0);
    //     for(int i=0; i < word_list[h].size(); ++i)
    //     {
    //         if(word_list[h][i] != '\0')
    //         {
    //             count++;
    //         }
    //     }
    //     //Store each count into count array 
    //     count_A[h] = count;
    // }

    // // //Check that count array stored length of each word
    // // for(int i=0; i<18; i++)
    // // {
    // //     cout << count_A[i] << endl;
    // // }
    
    // //Remove repeat words
    // //Check for word size first, then if same size check character matches and
    // //if char matches equals word size then it's the SAME word
    // for(int i=0; i < word_list.size(); ++i)
    // {
    //     int match(0);
    //     // cout << "i = " << i << endl;
        
    //     for(int j=i+1; j < word_list.size(); ++j)
    //     {   
    //         if(count_A[i] == count_A[j])
    //         {   
    //             // cout << j << endl;
    //             for(int m=0; m < count_A[i]; ++m)
    //             {    
    //                 if(word_list[i][m] == word_list[j][m] || word_list[i][m] == toupper(word_list[j][m]))
    //                 {
    //                     match++;
    //                 }
    //             }

    //             //Need to remove each repeat word from both the "word array" and the "# of letters array"
    //             if(match == count_A[i])  //If each letter matches then its the same word
    //             {
    //                 // cout << "MATCH" << endl;
    //                 word_list.erase(word_list.begin() + j);
    //                 count_A.erase(count_A.begin() + j);
    //             }
    //         }

    //         match = 0; //Reset match before next word compare
    //     }

    //     // cout << "--------------" << endl;

    // }

    // cout << "------------------" << endl;

    // // //Write to console
    // // cout << "After removal of repeat words" << endl;
    // // for(int i=0; i < word_list.size(); ++i)
    // // {
    // //     for(int j=0; j < word_list[i].size(); ++j)
    // //     {
    // //         cout << word_list[i][j];
    // //     }
    // //     cout << endl;
    // // }

    // // //Check that count array after deleting repeated words
    // // for(int i=0; i < count_A.size(); i++)
    // // {
    // //     cout << count_A[i] << endl;
    // // }

    // //Now with new reduced word_list array, sort by alphabetical order
    // for(int i=0; i < word_list.size(); ++i)
    // {   
    //     for(int j=i+1; j < word_list.size() ; ++j)
    //     {
    //         if(word_list[j][0] < word_list[i][0])
    //         {
    //             word_list[i].swap(word_list[j]);
    //         }
            
    //     }   
    // }

    // for(int i=1; i < word_list.size(); ++i)     //Avoid A since I think the null character is less than all other characters
    // {   
    //     for(int j=i+1; j < word_list.size() ; ++j)
    //     {
    //         if(word_list[j][1] < word_list[i][1] && word_list[j][0] == word_list[i][0])
    //         {
    //             word_list[i].swap(word_list[j]);
    //         }
            
    //     }   
    // }

    // cout << "After alphabetical order" << endl;
    // for(int i=0; i < word_list.size(); ++i)
    // {
    //     for(int j=0; j < word_list[i].size(); ++j)
    //     {
    //         cout << word_list[i][j];
    //     }
    //     cout << endl;
    // }
    

    //EXIT 
    return 0;
}