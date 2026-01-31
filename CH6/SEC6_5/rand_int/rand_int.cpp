/*
File: rand_int.cpp
Desc: To create a function that generates a random integer BETWEEN 2 values
Author: spoonais
Date: 11/15/24 @7:04am
*/

#include<iostream>
#include<cstdlib>
#include<fstream>
using namespace std;

/*--------------------------PROGRAMMER DEFINED FUNC ---------------------------------*/

int rand_int(int& a, int& b)
{   
    ifstream fin;
    ofstream fout;

    if(fin.fail())
    {
        cout << "Input file failed to open" << endl;
    }
    
    int seed(0);
    fin.open("seed.txt");
    fin >> seed;
    fin.close();
    // cout << seed << endl;

    ++seed; 
    // cout << seed << endl;
    fout.open("seed.txt");
    fout << seed;
    fout.close();

    //This allows a new random number to be generated each time the program is ran.
    srand(seed);

    //Compute 
    return rand()% (b - a + 1) + a;
    
}

/*-----------------------------------------------------------------------------------*/

int main()
{
    //Decalare and Init objects:
    int low(0), high(0), result(0);

    //User
    cout << "Please provide 2 numbers and I will generate a random number between them" << endl;
    cout << "Lower = ";
    cin >> low;
    cout << "Upper = ";
    cin >> high;

    //Print 10 random ints
    for(int i=1; i<=10; ++i)
    {
        //Call function
        result = rand_int(low, high);
    
        //print
        cout << "The random number " << i << " is = " << result << endl;

    }
    
    
    return 0;
}