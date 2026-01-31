/*
File: CH5_EOC_14.cpp
Desc: To solve CH5 EOC problems 14.
Author: spoonais
Date: 08/27/24 @3:27pm
*/

#include<iostream>
#include<string>
#include<fstream>
using namespace std;

int main()
{
     //Problem 14 Data Filters:
     //Declare and init objects:
     ifstream fin;
     ofstream fout;
     int counter(0), attempts(0), x(0);
     string filename;

   
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

     //Associate the file stream with a file
     fin.open(filename.c_str());
     fout.open("PRB14_Out.txt");

     //get first input
     fin >> x;

     while(!fin.eof())
     {
          ++counter;

          fout << x;

          if (fin.fail())
          {    
               //If the fin reads a "," it will fail so 
               //Clear the error so the next int can be read in
               fin.clear();

          }

          //Get the next value from the file
          fin >> x;

     }

     //After file is done close
     fin.close();
     fout.close();

     //Return
     return 0;


}