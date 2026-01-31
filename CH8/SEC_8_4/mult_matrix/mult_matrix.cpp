/*
File: mult_matrix.cpp
Desc: Try to and work with matrices, specifically multipying 2 matricies
Author: spoonais
Date: 1/8/24 @ 3:50pm
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
Funtion: mult_matrix()
Objective: multiply 2 matrices
-------------
Pre-Cond:
vector objects have been initialized AND are same size
Post-Cond:
vector object v3 has the multiplied matrix result
*/
void mult_matrix(vector<vector<int>> &v1, vector<vector<int>> &v2, vector<vector<int>> &v3)
{   
    //Declare and init
    int sum(0);

    for(int h=0; h < v1.size(); ++h)
    {
        for(int i=0; i < v1[h].size(); ++i)
        {   
            
            for(int j=0; j < v2.size(); ++j)
            {
                sum = sum + (v1[h][j] * v2[j][i]);
            }

            v3[h][i] = sum;
            sum = 0;
        }
    }

    //Void return
    return;
    
}

/*-------------------------------------------------------*/

int main()
{
    //Decalare and Init objects:
    int row_N1, row_N2, col_N1, col_N2;
    ifstream fin1, fin2;

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

    //Check that the row size of matrix  1 == column size of matrix 2
    if(col_N1 == row_N2)
    {
        cout << "The matrices can be multiplied" << endl;
    }
        else
        {
            cout << "ERROR! The matrices CANNOT be multiplied" << endl;
            exit(1);
        }

    //Create the "blank" 2D vector to store the matrix 1 into
    vector<int> row1(col_N1,0); //init a row with zeros
    vector < vector<int>> m1(row_N1,row1); //init each row (element) with a row of zeros

    //Create the "blank" 2D vector to store the matrix 2 into
    vector<int> row2(col_N2,0); //init a row with zeros
    vector < vector<int>> m2(row_N2,row2); //init each row (element) with a row of zeros

    //Create the "blank" 2D vector to store the result matrix into
    //Set to the size of matrix 1
    vector<int> row3(col_N1,0); //init a row with zeros
    vector < vector<int>> mR(row_N1,row3); //init each row (element) with a row of zeros

    //Read input file and store into 2D vector
    get2D_vec(fin1,m1);
    get2D_vec(fin2,m2);

    //Check that the vector stored the input file correctly
    cout << "Matrix 1" << endl;
    for(int i=0; i < m1.size(); ++i)
    {
        for(int j=0; j < m1[i].size(); ++j)
        {
            cout << m1[i][j] << '\t';
        }
        cout << endl;
    }

    //Check that the vector stored the input file correctly
    cout << "Matrix 2" << endl;
    for(int i=0; i < m2.size(); ++i)
    {
        for(int j=0; j < m2[i].size(); ++j)
        {
            cout << m2[i][j] << '\t';
        }
        cout << endl;
    }

    //Check that the vector stored the input file correctly
    cout << "Matrix result" << endl;
    for(int i=0; i < mR.size(); ++i)
    {
        for(int j=0; j < mR[i].size(); ++j)
        {
            cout << mR[i][j] << '\t';
        }
        cout << endl;
    }

    //Multiply
    mult_matrix(m1,m2,mR);
   
    //Print resultant matrix
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