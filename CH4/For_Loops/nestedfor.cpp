/*
File: While-For.cpp
Desc: Messing with nested for loop 
Author: spoonais
Date: 06/05/24 @4:14am
*/

#include<iostream>
#include<cmath>
using namespace std;

int main()
{
    //Decalare and Init objects:
    int count;

    //Create the nested for loop
    for (int k = 1; k <= 3; ++k ) //can think about it like multiplication...nested addition so in this case it is 3 x 3 x 3 and count = 27
    {
        for (int j = 0; j <= 2; ++j)
        {
            for (int l = 0; l <= 2; ++l)
            {
                ++count;

            }
                
        }
        
    }

    cout << count << endl;

}