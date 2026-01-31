/*
File: increment_test.cpp
Desc: This program used to test how incremeting works with a for loop
Author: spoonais
Date: 12/17/24 @ 12:23pm
Finished: 
*/

/*----------- SELF FEEDBACK -------------

Takeaways:

*/
#include<iostream>
using namespace std;


/*-------------- PROGRAMMER DEFINED FUNCTION --------------------*/


/*---------------------------------------------------------------*/


int main()
{
    //Declare and init objects
    int A(0);

    for(int i=0; i<5; ++i)
    {
        A = A + i;
        cout << A << endl;
    }

    cout << "------------------" << endl;


    for(int i=0; i<5; ++i)
    {
        A = A + i;
        cout << A << endl;
    }


    //Exit
    return 0;

}