/*
File: InputFile_Generator.cpp
Desc: To create a program that generates a input file of random values...Instead of me having to type one by hand.
Author: spoonais
Date: 12/04/24 @12:10am
*/

#include<iostream>
#include<cstdlib>
#include<fstream>
using namespace std;

/*--------------------------PROGRAMMER DEFINED FUNC ---------------------------------*/

double rand_float(double a, double b)
{   

    //Compute 
    return ((double)rand()/RAND_MAX*(b-a) + a); //need to use cast operator to convert rand() from int to double

    //Not sure why we have to add back a at the end?
    
}

/*-----------------------------------------------------------------------------------*/

int main()
{
    //Decalare and Init objects:
    double low(0), high(0), result(0);
    ofstream fout;
    int datapoints(0);

    //Open 
    fout.open("Input.txt");

    //Check that file opens
    if(fout.fail())
    {
        cerr << "Output file failed to open " << endl;
        exit(1);
    }

    //User
    cout << "Please provide 2 numbers and I will generate random number between them" << endl;
    cout << "Lower = ";
    cin >> low;
    cout << "Upper = ";
    cin >> high;
    cout << "Provide the # of datpoints you want";
    cin >> datapoints;

    //Print 10 random ints
    for(int i=1; i <= datapoints; ++i)
    {
        //Call function
        result = rand_float(low, high);
    
        //print
        fout << result << endl;

    }

    //Close the file stream
    fout.close();

    //Pause
    system("pause");
    
    //Exit program
    return 0;
}