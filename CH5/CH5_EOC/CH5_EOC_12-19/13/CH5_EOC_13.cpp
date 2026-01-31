/*
File: CH5_EOC_13.cpp
Desc: To solve CH5 EOC problems 13.
Author: spoonais
Date: 08/27/24 @3:27pm
*/

#include<iostream>
#include<string>
#include<fstream>
using namespace std;

int main()
{
     //Problem 13 Data Filters:
     //Declare and init objects:
     ifstream fin;
     ofstream fout;
     int counter(0), attempts(0), x(0);
     string filename;

     //Associate the file stream with a file
     fin.open(filename.c_str());
   
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

     

     }

     

     



}