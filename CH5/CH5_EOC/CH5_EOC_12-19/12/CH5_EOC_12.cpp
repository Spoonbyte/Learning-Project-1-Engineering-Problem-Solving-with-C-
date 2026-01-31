/*
File: CH5_EOC_12.cpp
Desc: To solve CH5 EOC problems 12.
Author: spoonais
Date: 08/22/24 @3:31pm
*/

#include<iostream>
#include<string>
#include<fstream>
using namespace std;

int main()
{
     //Problem 12 Data Filters:
     //Declare and init objects:
     ifstream fin;
     ofstream fout;
     int counter(0), attempts(0), x(0);
     string filename;

     //Associate the file stream with a file
     fin.open(filename.c_str());
     fout.open("PRB12_out.txt");

     //Error checking to ensure input file opens
     //It will terminate the program after 5 attempts

     do 
     {
          ++attempts;

          //Get user for input file
          cout << "Please provide the input data file you would like to use" << endl;
          cin >> filename;

          //Check to make sure that the input file was opened
          if(attempts > 1)
          {
               cout << "The Input file : " << filename << " failed to open" << endl;

               //Get user for input file
               cout << "Try again! You have " << 5 - attempts << "left " << endl;
               cin >> filename;

               if(attempts > 5 ) {exit(1);}
               
          }

     } while (fin.fail());

     //Parse the file and filter the data
     fin >> x;
     while (!fin.eof())
     {

          ++counter; //Initialize to start from line 1

          //If a fin value fails, that means the value was not an int
          if(fin.fail())
          {
               store = x;
               store_line = counter;
          }

          //Once invalid are stored, reset fin
          fin.clear();

          //Get next value
          fin >> x;

     }

     

     



}