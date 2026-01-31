/*
File: Practice_8.4.1.cpp
Desc: Try to and work with matrices, specifically computing the determinant of 3 X 3 matrix
Author: spoonais
Date: 1/7/24 @ 11:30am
Finished @ 12:33 pm
*/

/*-------- SELF FEEDBACK -----------

When I was starting this file, I told myself that I will JUST COPY the code from the past problems 
for the file reading function, initilizing the 2D vector and writing the pre/post function conditions
...BUT then I thought let me see if I can do all those things from memeory

I feel like I need to do this in the early stages of learning 
as it forces me to do ACTIVE RECALL and remember how these functions work.

I was able to do all of it from memory!

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
/*-------------------------------------------------------*/

int main()
{
    //Decalare and Init objects:
    int row_N, col_N;
    double det(0);

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

    //Calculate the determinant using the books method
    det = (m[0][0]*m[1][1]*m[2][2]) + (m[0][1]*m[1][2]*m[2][0]) + (m[0][2]*m[1][0]*m[2][1]) - (m[2][0]*m[1][1]*m[0][2]) - (m[2][1]*m[1][2]*m[0][0]) - (m[2][2]*m[1][0]*m[0][1]);

    //FUTURE: Is there a way to calculate this determinant using nested loops?

    //cout
    cout << "The determinant = " << det << endl;

    //Pause
    system("Pause");
    
    //Exit
    return 0;

}