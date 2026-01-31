/*
File: CH9EOC_17.cpp
Desc: To solve the EOC problems
Author: spoonais
Date: 02/14/25 @ 11:18am
Finished: @ 
*/

#include<iostream>
#include<vector>
#include<cstdlib>
using namespace std;

/*--------- PROGRAMMER DEFINED FUNCTIONS -------------*/

/*
(#15)
Name: assign_rand()
Objective: Given a range of numbers fill vector with random #s
Pre-Cond: Vector with init size, values for n, a, b
Post-Cond: Rand number is generated n times and placed into random[] (&vector)
*/

void assign_rand(vector<int> &vector, int n, int a, int b)
{
    //Declare and init local obj.
    double rN(0);

    for(int i=0; i < n; i++)
    {
        //Compute random number
        rN = (rand()%(b-a+1)) + a;

        //Write numbers to array
        vector[i] = rN;
    }
     
}

/*
Name: v_abs()
Objective: Replace all negative numbers with abs value
Pre-Cond: Vector filled with random numbers
Post-Cond: random[] is overwritten with all positive values
*/

void v_abs(vector<int> &vector)
{
    for(int i=0; i < vector.size(); i++)
    {
        if(vector[i] < 0)
        {
            vector[i] = abs(vector[i]);
        }
    }
}

/*----------------------------------------------------*/

int main()
{
    //Declare and init objects
    int a(0), b(0), n(0);

    //Get info from user
    cout << "Provide a " << endl;
    cin >> a;
    cout << "Provide b " << endl;
    cin >> b;
    cout << "Provide the size of the array" << endl;
    cin >> n;

    //Allocate size to vector and init with zeros
    vector<int> random(n,0);

    //Fill vector with random numbers
    assign_rand(random,n,a,b);

    //Print vector to check
    cout << "AFTER" << endl;
    for(int i=0; i < n; i++)
    {
        cout << random[i] << endl;
    }

    //Remove negative numbers
    v_abs(random);

    //Print vector to check
    cout << "NO NEGATIVE" << endl;
    for(int i=0; i < n; i++)
    {
        cout << random[i] << endl;
    }

    //Exit
    return 0;

}