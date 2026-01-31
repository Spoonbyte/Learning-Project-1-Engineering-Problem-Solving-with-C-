/*
File: 
Desc: Quick program to calculate simple sin(x) 
Author: spoonais
Date: 06/20/24 @6pm
*/

#include<iostream>
#include<cmath>
#include<cfloat>
using namespace std;

int main()
{
    //Decalare and Init objects:
    double sinx, loop, x(0), res(0);
    double a1[1000], a2[1000];
    
    //input for loops (resolution)
    cout << "Provide # of loops" << endl;
    cin >> loop;
    cout << "Provide resolution" << endl;
    cin >> res;


    

    //
    for (int k(0); k <= loop; ++k)
    {
        sinx = sin(x);
        a1[k] = x;
        a2[k] = sinx;

        //increment x
        x += res;

    }


    for (int i(0); i<=loop; ++i)
    {
        cout << a1[i] << endl;
    }

    cout << "------------------------------------------" << endl;

    for (int j(0); j<=loop; ++j)
    {
        cout << a2[j] << endl;
    }

    


}