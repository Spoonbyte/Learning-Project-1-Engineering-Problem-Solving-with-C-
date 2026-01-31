/*
File: CH7EOC_28.cpp
Desc: Cryptography problem #28 using my own method
Author: spoonais
Date: 1/2/24 @ 12:00pm
Finished @1:22pm

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


int main()
{
    //Decalare and Init objects:
    ifstream fin;
    ofstream fout;
    string filename;
    string alpha = "qwertyuiopasdfghjklzxcvbnm ";
    string decode = "abcdefghijklmnopqrstuvwxyz ";
    char message[] = {'\0'}, store;
    int counter(0),i;

    //Get encoded file
    cout << "Please provide the encoded file" << endl;
    cin >> filename;

    //Open the input filestream and associate with input file (encoded)
    fin.open(filename.c_str());
    if(fin.fail())
    {
        cerr << "Error!" << filename << " could not open" << endl;
        exit(1);
    }

    //Open the output filestream and associate with the output file (decoded)
    fout.open("decoded.txt");

    //Get the first character from stream
    fin.get(message[counter]);                   //message[0]

    //Output to decoded file
    while(!fin.eof())
    {

        while(message[counter] != alpha[i])
        {
            ++i;
        }

        // //TRBLSHT
        // cout << i << endl;

        //output
        fout << decode[i];

        //Get next char
        fin.get(message[counter]);

        //Reset i
        i = 0;

    }
    

    //Exit
    return 0;

}