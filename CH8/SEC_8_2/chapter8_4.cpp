/*
File: chapter8_4.cpp
Desc: This program will be used to find the peaks in the elevation dataset.
Author: spoonais
Date: 1/5/24 @ 11am
FINISHED @ 11:47am
*/
/*-------- SELF FEEDBACK -----------

-----------------------------------*/
#include<iostream>
#include<fstream>
#include<string>
using namespace std;

//Const 
//Define a large 2d array space
const int NROW_MAX = 50;
const int NCOL_MAX = 50;
const int ELEV_MAX = 10000;

/*------------ PROGRAMMER DEFINED FUNCTIONS -------------*/

void get_2D_array(ifstream& input, double x[][NCOL_MAX], int act_row, int act_col)
{
    
    //Use nested for loop to populate the array from input file
    for(int i=0; i < act_row; ++i)
    {
        for(int j=0; j < act_col; ++j)
        {
            input >> x[i][j];
        }
    }
}

// //This function just serves to compute the average for each trial
// double find_peak(int x[][NROW_MAX])         
// {
    
// }
/*-------------------------------------------------------*/

int main()
{
    //Decalare and Init objects:
    ifstream fin;
    string filename;
    int row_N(0),col_N(0);
    double elev[NROW_MAX][NCOL_MAX] = {0};

    //Get input filename from user
    cout  << "Please provide the input file name" << endl;
    cin >> filename;

    //Associate filestream with input file
    fin.open(filename.c_str());
    if(fin.fail())
    {
        cerr << "Error!" << filename << " failed to open " << endl;
        exit(1);
    }

    //Read first lines from data file
    //Pass to the function 
    fin >> row_N >> col_N;

    //Get the array from input file
    get_2D_array(fin,elev,row_N,col_N);

    // //TRBLSHT
    // //Print entire array to console to check
    // for(int i=0; i < row_N; ++i)
    // {
    //     for(int k=0; k < col_N; ++k)
    //     {   
    //         cout << temp[i][k] << "\t";
    //     }
    //     cout << endl;
    // }
   
    //Close input filestream
    fin.close();

    //Create code to find the peak elevations
    for(int i=0; i < row_N; ++i)
    {   
        for(int j=0; j < col_N; ++j)
        {
            //Create conditional to determine that there a 4 valid data points around each elev point
            int north = elev[i-1][j];
            int south = elev[i+1][j];
            int west = elev[i][j-1];
            int east = elev[i][j+1];
            if(
                ((north > 0) && (north <= ELEV_MAX)) &&
                ((south > 0) && (south <= ELEV_MAX)) &&
                ((west > 0) && (west <= ELEV_MAX)) &&
                ((east > 0) && (east <= ELEV_MAX)))
                {
                    if((elev[i][j] > north) && (elev[i][j] > south) && (elev[i][j] > west) && (elev[i][j] > east))
                    {
                        cout << "Peak = " << elev[i][j] << endl;
                    }
                }

        }
    }

    //System pause
    system("Pause");

    //Exit
    return 0;

}