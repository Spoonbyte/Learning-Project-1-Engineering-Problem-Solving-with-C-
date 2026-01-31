/*
File: CtoF.cpp
Desc: To use a programmer defined function to take a file with temps in c and convert all to f.
Author: spoonais
Date: 09/26/24 @10:00am
    Finished @11am ~ 1 hour to write and work out issues with printing the decimals
*/

#include<iostream>
#include<cmath>
#include<fstream>
#include<iomanip>
using namespace std;

//Declare and init GLOBAL objects
double cels(0);

double CeltoFahr() //I had this as "int" instead of "double", so even though "temp_conver" was returning a double the function was "int" so it rounded my numbers.
{
    double temp_conver(0);
    temp_conver = ((9*cels)/5) + 32;
    //TRBLSHT// cout << temp_conver << endl;
    return temp_conver;
}

/*---------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

int main()
{
    //Decalare and Init objects:
    ifstream fin;
    ofstream fout;
    double fahr(0);

    //Associate the file streams with files
    fin.open("temp_cel.txt");
    fout.open("temp_fahr.txt");
    
    //Check that file open, if not exit
    //input
    if(fin.fail())
    {
        cerr << "The input file failed to open" << endl;
        exit(1);
    }
    //output
    if(fout.fail())
    {
        cerr << "The output file failed to open" << endl;
        exit(1);
    }

    //While loop to convert all the cel values to fahr:
    while(!fin.eof()) 
    {
        
        fin >> cels;

        //Call the function and store into fahr.
        fahr = CeltoFahr();

        //TRBLSHT// cout << fahr << endl;

        //Print to output file.
        fout <<fahr <<endl;

    
    }

    //Close file streams
    fin.close();
    fout.close();

    //Exit
    system("pause");
    return 0;
}