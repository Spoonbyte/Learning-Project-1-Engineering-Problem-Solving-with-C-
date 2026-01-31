/*
File: add_sub_matrix.cpp
Desc: Try to and work with matrices, specifically adding OR subtracting 2 matrices based on user input
Author: spoonais
Date: 1/8/24 @ 12:15pm
Finished @ 
*/

/*-------- SELF FEEDBACK -----------

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
Funtion: add_matrix()
Objective: subtract 2 vectors
-------------
Pre-Cond:
vector objects have been initialized AND are same size
Post-Cond:

*/

void add_matrix(vector<vector<int>> &v1, vector<vector<int>> &v2, vector<vector<int>> &v3)
{
    for(int i=0; i < v3.size(); ++i)
    {
        for(int j=0; j < v3[i].size(); ++j)
        {
            v3[i][j] = v1[i][j] + v2[i][j];
        }
    }
}

/*
Funtion: sub_matrix()
Objective: Subtract 2 vectors
-------------
Pre-Cond:
vector objects have been initialized AND are same size
Post-Cond:

*/

void sub_matrix(vector<vector<int>> &v1, vector<vector<int>> &v2, vector<vector<int>> &v3)
{
    for(int i=0; i < v3.size(); ++i)
    {
        for(int j=0; j < v3[i].size(); ++j)
        {
            v3[i][j] = v1[i][j] - v2[i][j];
        }
    }
}
/*-------------------------------------------------------*/

int main()
{
    //Decalare and Init objects:
    int row_N1, row_N2, col_N1, col_N2;
    ifstream fin1, fin2;
    char choose;

    //Associate the filestream with input file
    //Matrix 1
    fin1.open("input.txt");
    if(fin1.fail())
    {
        cerr << "Error! Input file failed to open" << endl;
        exit(1);
    }

    //Matrix 2
    fin2.open("input1.txt");
    if(fin2.fail())
    {
        cerr << "Error! Input file failed to open" << endl;
        exit(1);
    }

    //Get the size of matrix from 1st line of input file
    fin1 >> row_N1 >> col_N1;
    fin2 >> row_N2 >> col_N2;

    //Check that the 2 vectors are the same size
    if(row_N1 == row_N2 && col_N1 == col_N2)
    {
        cout << "The matrices are the same size" << endl;
    }
        else
        {
            cout << "The matrices are NOT the same size" << endl;
            exit(1);
        }

    //Create the "blank" 2D vector to store the matrix 1 into
    vector<int> row1(col_N1,0); //init a row with zeros
    vector < vector<int>> m1(row_N1,row1); //init each row (element) with a row of zeros

    //Create the "blank" 2D vector to store the matrix 2 into
    vector<int> row2(col_N2,0); //init a row with zeros
    vector < vector<int>> m2(row_N2,row2); //init each row (element) with a row of zeros

    //Create the "blank" 2D vector to store the result matrix into
    vector<int> row3(col_N2,0); //init a row with zeros
    vector < vector<int>> mR(row_N2,row3); //init each row (element) with a row of zeros

    //Read input file and store into 2D vector
    get2D_vec(fin1,m1);
    get2D_vec(fin2,m2);

    // //Check that the vector stored the input file correctly
    // cout << "Matrix 1" << endl;
    // for(int i=0; i < m1.size(); ++i)
    // {
    //     for(int j=0; j < m1[i].size(); ++j)
    //     {
    //         cout << m1[i][j] << '\t';
    //     }
    //     cout << endl;
    // }

    // //Check that the vector stored the input file correctly
    // cout << "Matrix 2" << endl;
    // for(int i=0; i < m2.size(); ++i)
    // {
    //     for(int j=0; j < m2[i].size(); ++j)
    //     {
    //         cout << m2[i][j] << '\t';
    //     }
    //     cout << endl;
    // }

    // //Check that the vector stored the input file correctly
    // cout << "Matrix result" << endl;
    // for(int i=0; i < mR.size(); ++i)
    // {
    //     for(int j=0; j < mR[i].size(); ++j)
    //     {
    //         cout << mR[i][j] << '\t';
    //     }
    //     cout << endl;
    // }

    //Calculate addition or subtraction based on user input
    cout << "Choose + if you want to add the matrices or - if you want to subtract" << endl;
    cin >> choose;
    switch(choose)
    {
        case '+':
            cout << "+" << endl;
            add_matrix(m1,m2,mR);
            break;
        case '-':
            cout << "-" << endl;
            sub_matrix(m1,m2,mR);
            break;
    }

    cout << "Matrix result" << endl;
    for(int i=0; i < mR.size(); ++i)
    {
        for(int j=0; j < mR[i].size(); ++j)
        {
            cout << mR[i][j] << '\t';
        }
        cout << endl;
    }
   

    //Pause
    system("Pause");
    
    //Exit
    return 0;

}