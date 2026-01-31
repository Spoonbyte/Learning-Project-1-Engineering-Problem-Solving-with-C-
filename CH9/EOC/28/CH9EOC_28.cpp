/*
File: CH9EOC_28.cpp
Desc: To solve #28
Author: spoonais
Date: 02/26/25 @1:27pm
Finished: @ 1:48pm
*/

/*
Self feedback:


*/

const int MAX_ELEM = 20;

#include<iostream>
#include<string>    
#include<fstream>
#include<cctype>
#include<list>
#include<algorithm>
using namespace std;

//Prototype
void assignV(double *x, int n, double v);

/*---------- PROGRAMMER DEFINED FUNCTIONS -------------*/

/*
Name: assignV()
Objective: To assign the value V to the first n elements of array x
Pre-Cond:
Post-Cond:
*/

void assignV(double *x, int n, double v)
{
    //Print *x to confirm it holds the address of array[0];
    cout << "Address of x :" << (void*)x << endl;

    for(int i=0; i < n; i++)
    {
        *(x+i) = v;     //Looping through the array[] using a pass by reference pointer that is dereferenced
    }

}

/*------------------------------------------------------*/

int main()
{
    //Decalare and Init objects:
    int value(0), num_elem(0);
    double array[MAX_ELEM] = {0};

    //Get user info
    cout << "Provide the value you want to write to the array " << endl;
    cin >> value;   
    
    //Do while for number of elements
    do
    {
        cout << "Provide the number of elements you want to write too. Value must be less than :" << MAX_ELEM << endl;
        cin >> num_elem;

    } while (num_elem > MAX_ELEM);

    //Address start of array
    cout << "Address of array[0]: " << &array << endl;

    //Call the function
    assignV(array,num_elem,value);
    
    //Print out the array
    for(int i=0; i < MAX_ELEM; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;

    return 0;

}