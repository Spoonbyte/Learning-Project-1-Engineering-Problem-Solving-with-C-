/*
File: CH6EOC_22.cpp
Desc: To test the program from #22...this version is more along the lines of what the book wants
Author: spoonais
Date: 11/27/24 @ 6:20am
Updated on 11/29/24 @ 1pm
*/

/*
SELF FEEDBACK:

11/29/24: I realized after working on the books solution that their "return (rand()%(max-min+1))+min;" was the same as my "rand()%2" since their 
min = 0 and max =1.

Also I wondered if those were the same, why was I not getting the same percentages as the books solution. And another issue was my percentages 
were adding past 100%!

I realized the original code was calling the function coinflip() too many times

  for(int i=1; i<=flips; ++i)
    {
        coinflip();
        cout << "result = " << result << endl;

        if(coinflip() == true)
        {
            ++head_counter;
            cout << head_counter << endl;
        }

        if(coinflip() == false)
        {
            tails_counter++;  
        }
    }

So when testing the code I put 10 flips in, coinflip() would produce 4 heads BUT the head_counter would count 5!
I realized this was probably due to the coinflip() being used in the 2 if statements which is actually calling the function again which 
was probably causing the discrepancy.

The updated code is below which now matches the books percentages and also doesnt add past 100%.
I just called coinflip() once, stored it in the "result" variable and used that for the if statements.

I think with this fix, my solution here is more concise than the books solution. The only thing my code didnt do was ask the user again if they put a incorrect flip number.

*/

#include<iostream>
#include<cmath>
#include<fstream>
using namespace std;

//#Problem 22:
/*----------- PROGRAMMER DEFINED FUNCTION ------------*/

bool coinflip()
{
    bool heads = true, tails = false;

    if (rand()%2 == 1)
    {
        return heads;
    } 
        else
        {
            return tails;

        }
    
}

/*-----------------------------------------------------*/

int main()
{
    //Decalare and Init objects:
    int flips(0); 
    double head_counter(0), tails_counter(0);

    //Ask user for # of flips
    cout << "Please provide the number of times to flip the coin" << endl;
    cin >> flips;

    //use a for loop to do the flips
    for(int i=1; i<=flips; ++i)
    {
        int result = coinflip();
        cout << "result = " << result << endl;

        if(result == true)
        {
            ++head_counter;
            //TRBSLSHT
            // cout << head_counter << endl;
        }

        if(result == false)
        {
            tails_counter++;  
        }
    }

    //total
    cout << "Head probability = " << head_counter/flips << endl;
    cout << "Tails probability = " << tails_counter/flips << endl;

    //exit
    return 0;

}