/*
File: transpose.cpp
Desc: Try to and work with matrices, specifically transposing a 4 x 3 to a 3 x 4
Author: spoonais
Date: 1/8/24 @ 11:30am
Finished @ 12:10pm
*/

/*-------- SELF FEEDBACK -----------

The way I did the transpose is different than the book since I did not have to declare symbolic constants


-----------------------------------*/
#include<iostream>
#include<fstream>
#include<vector>
using namespace std;

/*------------ PROGRAMMER DEFINED FUNCTIONS -------------*/

/*
Funtion: get2D_vec()
Objective: Read input file with 2D vector format
-------------
Pre-Cond:
input filestream defined | vector object has been initialized
Post-Cond:
vector object has values stored from input file
*/
void get2D_vec(ifstream& in, vector<vector<int>> &arr)      //Pass by reference (we are accessing the ACTUAL memeory location of "matrix" vector not just copying values from it)
{
    for(int i=0; i < arr.size(); ++i)
    {
        for(int j=0; j < arr[i].size(); ++j)
        {
            in >> arr[i][j];
        }
    }
}

/*
Funtion: transpose()
Objective: Take a 2D vector and transpose it
-------------
Pre-Cond:
The inital vector object (v) has been initialized
The transposed vector object (v_T) has been initialized
Post-Cond:
v has been copied to v_T as a transposed object
*/

void transpose(vector<vector<int>> &v, vector<vector<int>> &v_T)
{
    for(int i=0; i < v_T.size(); ++i)
    {
        for(int j=0; j < v_T[i].size(); ++j)
        {
            v_T[i][j] = v[j][i];
        }
    }
}
/*-------------------------------------------------------*/

int main()
{
    //Decalare and Init objects:
    int row_N, col_N;
    ifstream fin;

    //Associate the filestream with input file
    fin.open("input.txt");
    if(fin.fail())
    {
        cerr << "Error! Input file failed to open" << endl;
        exit(1);
    }

    //Get the size of matrix from 1st line of input file
    fin >> row_N >> col_N;

    //Create the "blank" 2D vector to store the matrix into
    vector<int> row(col_N,0); //init a row with zeros
    vector < vector<int>> m(row_N,row); //init each row (element) with a row of zeros

    //Create the "blank" 2D vector to store the transposed matrix into
    vector<int> row_T(row_N,0);
    vector < vector<int>> m_T(col_N,row_T);

    //Read input file and store into 2D vector
    get2D_vec(fin,m);

    // //Check that the vector stored the input file correctly
    // for(int i=0; i < m.size(); ++i)
    // {
    //     for(int j=0; j < m[i].size(); ++j)
    //     {
    //         cout << m[i][j] << '\t';
    //     }
    //     cout << endl;
    // }

    //Calculate the transposed matrix
    transpose(m,m_T);

    //Print the transposed matrix 
    for(int i=0; i < m_T.size(); ++i)
    {
        for(int j=0; j < m_T[i].size(); ++j)
        {
            cout << m_T[i][j] << '\t';
        }
        cout << endl;
    }

    //Pause
    system("Pause");
    
    //Exit
    return 0;

}