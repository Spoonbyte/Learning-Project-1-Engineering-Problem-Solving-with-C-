/*
File: CH9EOC_14.cpp
Desc: To show that an array is default pass by value
Author: spoonais
Date: 02/13/25 @ 2:45pm
Finished: @ 2:59pm
*/

/*
Outcome:

I was incorrect, an array as a function argument is by default a pass by reference 
as I did not need to add the & sign to "int x[]" in order for "array[]" to print 
out the proper values.


*/

#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

/*--------- PROGRAMMER DEFINED FUNCTIONS -------------*/

/*
Name: assign()
Objective
Pre-Cond:
Post-Cond:
*/
void assign(int v, int x[], int size)
{
    for(int i=0; i < size; i++)
    {
        x[i] = v;
    }
    
}

/*----------------------------------------------------*/

const int MAX_SIZE = 10;

int main()
{

    //Decalare and Init objects:
    int array[MAX_SIZE];
    int value(0);

    //Get value from user
    cout << "Provide fill value for array" << endl;
    cin >> value;

    //Call fill function
    assign(value,array,MAX_SIZE);

    //Print out vector x
    for(int i=0; i < MAX_SIZE; i++)
    {
        cout << "array[" << i << "] = " << array[i] << endl;
    }

    //Exit
    return 0;

}