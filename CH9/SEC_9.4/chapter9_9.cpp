/*
File: chapter9_9.cpp
Desc: To understand how the new and delete operators work in dynamically allocating memory.
Author: spoonais
Date: 01/27/25 @11:54am
Finished: @ 
*/

/*--------- 
Self Feedback:

Is this how the std::vector works, does it use the new and delete oeprators to be able to 
dynamically size the array?

Read the article on Quora:
"In C++, does std::vector<T> call new and delete?"
This has a wide range of answers some saying yes and some saying no.

Another good article on Stackoverflow:
"Why using the new operator instead of std::vector?"
This goes into why you should use std::vector vs new and delete
but MAYBE in some cases new and delete are better?

----------*/

#include<iostream>
using namespace std;

int main()
{
    //Decalre and init
    int *ptr, npts(10);
    double *darr_ptr;
    double array[10] = {0};

    //Dynamically allocate one integer object
    ptr = new int(-1);

    //Dynamically allocate array of type double
    darr_ptr = new double[npts];

    //My edit: Get the address of the new dynamic array
    cout << "array = " << array << endl;
    cout << "darr_ptr = " << darr_ptr << endl;

    //Assign what is pointed to by ptr to all elements of dynamic array
    for(int i=0; i < npts; i++)
    {
        *(darr_ptr + i) = *ptr;
        // darr_ptr[i] = *ptr;                 //OR can write this way
    }

    //Print all values in dynamic array
    for(int i=0; i < npts; i++)
    {
        cout << *(darr_ptr + i) << " ";
        // cout << darr_ptr[i] << endl;        //OR can write this way          

    }

    cout << endl;

    //Return memory to free-store
    delete ptr;
    delete [] darr_ptr; 

    //My edit: Get the address of the new dynamic array
    cout << "array = " << array << endl;
    cout << "darr_ptr = " << darr_ptr << endl;

    //Check values of dynamic array after the delete operator is used
    for(int i=0; i < npts; i++)
    {
        cout << *(darr_ptr + i) << " ";
        // cout << darr_ptr[i] << endl;        //OR can write this way          

    }

    //Exit
    return 0;
}