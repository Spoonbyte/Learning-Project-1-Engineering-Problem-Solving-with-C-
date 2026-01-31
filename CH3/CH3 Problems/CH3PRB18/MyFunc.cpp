/*
File:
Desc: To create a user function within int main()
Author: spoonais
Date: 05/24/24 @4:41am
*/

#include<iostream>
#include<cmath>
using namespace std;

//Define the user function to add 1 to user value
int myfunc(int x)
{
    return x + 4;
}

int main()
{
    //Print output
    cout << myfunc(2);

}