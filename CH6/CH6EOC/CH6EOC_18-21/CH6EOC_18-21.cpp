/*
File: CH6EOC_18-21.cpp
Desc: To test the program from #18-21
Author: spoonais
Date: 11/24/24 @10:58am
*/

#include<iostream>
#include<cmath>
using namespace std;

//#Problem 18:
/*----------- PROGRAMMER DEFINED FUNCTION ------------*/
 void primeGen(int n)  //assuming the first n primes starting from zero
 {
    int counter(0), prime_counter(0);

    for (int i=2; i<=1000; ++i)
    {
        for (int k=1; k <= i; ++k)
        {
            if (i%k == 0)
            {
                ++counter;

                if(counter == 2) //only care about the numbers that have 2 factors
                {
                    ++prime_counter;
                }
            } 

        }

        if (prime_counter == 6)
        {
            return;
        }

    }


 }

/*-----------------------------------------------------*/

int main()
{
    //Decalare and Init objects:
    int n;
    bool result = false;
    int counter;

    cout << "Please provide number to see if its prime" << endl;
    cin >> n;

    /*---------------------------------------------------------*/
    // for (int i=1; i <= n; ++i)
    // {
    //     if (n%i == 0)
    //     {
    //         ++counter;
    //     } 
    // }

    // if(counter == 2)
    // {
    //     cout << "The number is a prime" << endl;
    // } 
    //     else 
    //     {
    //         cout << "The number is composite " << endl;
    //     }
    /*---------------------------------------------------------*/
    

    //exit
    return 0;

}