/*
File: SEC6_3_P5.cpp  
Desc: To understand the practice #5 problem
Author: spoonais
Date: 10/08/24 @2:55pm
*/

#include<iostream>
using namespace std;

/*---------------- PROGRAMMER DEFINED FUNCTIONS ---------------------*/

void fun_ch6(int first, int& second)
{
    first++;
    second += 2;
    return;
}

/*-------------------------------------------------------------------*/

int main()
{
    //Decalare and Init objects:
    int n1(0), n2(0);

    //Call function
    fun_ch6(n1,n2);

    //output
    cout << n1 << n2 << endl;

    //Pause program
    cout << "Press enter to exit...";
    cin.ignore();
    cin.get();

    //Exit
    return 0;

}

/* Predict the Ouptut

Since the first formal parameter is an int, so the function argument "n1" passes its value of 0 to "first".
From what I understand, since its pass by value "n1" will not actually increment.

But since the second format parameter is an int& then "second" will be an alias to n2 and so it will increment 
n2 by 2 and print out 2.

So the output will be 0,2...

After compiling this was correct. 

But I'm still unsure why passing by value from n1 to first does not increment n1?

*/