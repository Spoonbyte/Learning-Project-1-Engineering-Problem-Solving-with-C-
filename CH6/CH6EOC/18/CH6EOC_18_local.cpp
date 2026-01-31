/*
File: CH6EOC_18-21.cpp
Desc: To test the program from #18-21
Author: spoonais
Date Started: 11/24/24 @10:58am
Continued 11/25/24 @ 2:30pm....Finished 11/25/24 @ 3:47pm, 

-----------------------------------------------------------------------------------------
SELF-FEEDBACK:
I was able to figure out the basic logic to test for primality on 11/24 so most of my time 
on 11/25 was figuring out where the "if(counter == 2 )", "counter = 0", and "if(prime_counter == n)" should be placed within 
the for loops to ensure that the program did not keep testing all of the numbers up to 10,0000.

Used a lot of "cout" of the various counters and i and k values to see where the problems were happening.

The one that took the longest to figure out was that I had the "if(counter == 2 )" statement within
the second for loop, so even a composite number would trigger it. I had to make sure that the second 
for loop FINISHED counting all the cases for each number BEFORE moving on to test with "if(counter == 2 )"....

The second issue was that I was not resetting the counter variable before each new number to be tested.
The counter just kept increasing and never triggered the "if(counter == 2 )" statement.

The last issue was making sure "if(prime_counter == n)" was placed at the end of the first for loop.
I had it outside so the first for loop had nothing to stop it from running until i == 10,000.

*/

#include<iostream>
#include<cmath>
using namespace std;

//#Problem 18:
/*----------- PROGRAMMER DEFINED FUNCTION ------------*/
 void primeGen(int n)  //assuming the first n primes starting from zero
 {
    int counter(0), prime_counter(0);

    for (int i=2; i<=100000; ++i)
    {
        for (int k=1; k <= i; ++k)
        {
            if (i%k == 0){++counter;} 
        }

        if (counter == 2) //only care about the numbers that have 2 factors
        {
            ++prime_counter;    //keeps track of how many primes
            cout << "prime number:" << prime_counter << " = " << i << endl; 
        }

        counter = 0;        //Reset the counter for the next number to test for primality

        //This needs to be in the for loop or else the loop will try to test all 1000 #s for primality!
        if (prime_counter == n)     //When the first n primes are printed, then close function
        {
            return;
        }

    }

 }

/*-----------------------------------------------------*/

int main()
{
    //Decalare and Init objects:
    int primes;
    bool result = false;
    int counter;

    cout << "Input the number of primes you want, starting from zero " << endl;
    cin >> primes;

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
    
    //Call primeGen function
    primeGen(primes);

    //Pause
    system("pause");

    //exit
    return 0;

}