/*
File: ch6-static
Desc: This is to show how the 'static' storage class works
Author: spoonais
Date: 10/25/24 @12pm
*/

#include<iostream>
#include<cmath>
using namespace std;

/*---------PROGRAMMER DEFINED FUNC --------------*/

void ch6_static()
{
    static int x(0);
    static int counter(0); //preserves the variable counter
    x++;
    counter++;
    cout << x << "," << counter << endl;
}

/*-----------------------------------------------*/

int main()
{
    //Call function
    ch6_static();
    ch6_static();
    ch6_static();

    //EXIT
    return 0;

}