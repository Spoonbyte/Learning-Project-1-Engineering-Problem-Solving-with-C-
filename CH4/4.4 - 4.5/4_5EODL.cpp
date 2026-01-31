/*
File: 4_5EODL.cpp
Desc: To use a "end of data" loop
Author: spoonais
Date: 06/11/24 @12:22pm
*/

#include<iostream>
#include<cmath>
using namespace std;

int main()
{
    //Decalare and Init objects:
    short counter;
    double avg, score, sum;

    //Create the average routine
    cout << "Please provide the set of exam grades" << endl;
    cin >> score; //Need this to enter the While loop since there needs to be data in the CIN to enter the while loop 

    while (!cin.eof())
    {   
        sum += score; //Once in, the data gets added to the score
        
        cin >> score; //Asks for the next data...to trigger EOD use Crtl+C
        ++counter; //Increments by 1 NOTE: When you put the ++counter after the cin >> score, I thought after you input Crt+C it will increment before exiting the while loop
    }

    //Calculate the exam score average
    avg = (sum / counter);
    cout << "The average score of the exams are: " << avg << endl;
    
    

    


}

    