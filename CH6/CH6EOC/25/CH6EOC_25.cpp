/*
File: CH6EOC_25.cpp
Desc: To create a simulation of a rolling dice.
Author: spoonais
Date: 11/30/24 @10:13am
*/

/*
SELF-FEEDBACK:

With this code below, after about 10,000 rolls the percentages for each face converged on 16.6-17%.



*/

#include<iostream>
#include<cmath>
using namespace std;

/*--------- PROGRAMMER DEFINED FUNCTION ---------------*/

int rolldice()
{
    int result;
    result = rand()%7;     //Returns a number from 0 - 6;
    
    while (result == 0)     //If a zero is generated, it keeps "rolling" until a non zero appears and returns that
    {
        result = rand()%7;
    }

    return result;

}

/*-----------------------------------------------------*/

int main()
{
    //Decalare and Init objects:
    double rolls(0), S1(0), S2(0), S3(0), S4(0), S5(0), S6(0);
    int result(0);

    //Roll dice
    cout << "Please provide the number of rolls " << endl;
    cin >> rolls;

    for (int i=1; i<=rolls; i++)
    {
        result = rolldice();

        cout << result << endl;

        //Use a switch case to count the occurence of each side
        switch (result)
        {
            case 1:
                S1++;
                break;
            case 2:
                S2++;
                break;
            case 3:
                S3++;
                break;
            case 4:
                S4++;
                break;
            case 5:
                S5++;
                break;
            case 6:
                S6++;
                break;
        }

    }

    //Distribution 
    cout << "S1 Percentage = " << S1/rolls * 100 << endl;
    cout << "S2 Percentage = " << S2/rolls * 100 << endl;
    cout << "S3 Percentage = " << S3/rolls * 100 << endl;
    cout << "S4 Percentage = " << S4/rolls * 100 << endl;
    cout << "S5 Percentage = " << S5/rolls * 100 << endl;
    cout << "S6 Percentage = " << S6/rolls * 100 << endl;

    //Exit
    return 0;

}