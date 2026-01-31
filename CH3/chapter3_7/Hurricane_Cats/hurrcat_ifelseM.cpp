/*
File: Hurrcat_ifelse.cpp
Desc: The original CH3.7 example to compare to
Author: spoonais            
Date: 05/14/24
*/

#include<iostream>
#include <stdio.h>
#include <chrono>
using namespace std;

int main()
{
    
    // Start measuring time
    auto begin = std::chrono::high_resolution_clock::now();
    
    ////////////////// Actual Program BEGIN //////////////////////////////////////////////////////

    //Declare and Init objects
    double wind;

    //User wind value provided
    cout << "Provide the wind velocity" << endl;
    cin >> wind;

    //Logic to determine category
    if (wind >= 74 && wind <= 95)
    {
        cout << "Category 1" << endl;
    } 
    else 
    {
        if (wind >= 96 && wind <= 110)
        {
            cout << "Category 2" << endl;
        }
        else
        {
            if (wind >= 111 && wind <= 129)
            {
                cout << "Category 3" << endl;
            }
            else 
            {
                if (wind >= 130 && wind <= 156)
                {
                    cout << "Category 4" << endl;
                }
                else
                {
                    if (wind >= 157)
                    {
                        cout << "Category 5" << endl;
                    }
                    else 
                    {
                        cout << "Tropical Storm or Depression" << endl;
                    }
                }

            }
        }
    }

     ////////////////// Actual Program END //////////////////////////////////////////////////////

    
    // Stop measuring time and calculate the elapsed time
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    
        
    printf("Time measured: %.3f seconds.\n", elapsed.count() * 1e-9);
    
   

   
}
