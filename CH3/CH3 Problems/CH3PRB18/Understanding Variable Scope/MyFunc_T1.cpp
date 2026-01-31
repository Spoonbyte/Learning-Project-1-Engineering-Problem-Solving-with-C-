/*
File: MyFunc_T1
Desc: To create a user (programmer defined) function within int main() and also test to see if I declare the variable globally how I can use it in mutiple functions.
Author: spoonais
Date: 05/29/24 @5pm
*/

#include<iostream>
#include<cmath>
using namespace std;

//Declare and Init objects
int x;

//Define the user function to add 2 to user value
int myfunc1()
{
    return x = x + 2;
}

//Define the user function to choose 
int myfunc2()
{
    int y;
    if (x < 5)
    {
        y = 1;
    } 
        else 
        {
            y = -1;
        }

    return y;
}

int main()
{

    //Get value of x from user
    cout << "Provide value for x" << endl;
    cin >> x;

    //Call functions
    myfunc1();
    cout << x << endl;
    myfunc2();
    cout << x << endl;

    //Print output
    cout << "The output of myfunc2 is " << myfunc2() << endl;

}