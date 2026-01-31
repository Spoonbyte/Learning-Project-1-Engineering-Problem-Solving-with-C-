/*
File: CH9EOC_15.cpp
Desc: To solve the EOC problems
Author: spoonais
Date: 02/14/25 @ 10:30am
Finished: @ 11:05am 
-------------------------
Started #16 @ 11:07am
Finished #16 @ 11:15am 
*/

#include<iostream>
#include<vector>
#include<cstdlib>
#include<iomanip>
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
(#16)
Name: v_sum()
Objective: Add all the numbers in the vector
Pre-Cond: Vector filled with random numbers
Post-Cond: The sum of the random number vector is returned
*/

int v_sum(vector<int> vector)   //No &vector because we dont want to modify the vector random[]!
{   
    //Declare and init local obj.
    int sum(0);

    for(int i=0; i < vector.size(); i++)
    {
        sum += vector[i];
    }

    return sum;
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

    // //Before 
    // cout << "BEFORE" << endl;
    // for(int i=0; i < n; i++)
    // {
    //     cout << random[i] << endl;
    // }

    //Fill vector with random numbers
    assign_rand(random,n,a,b);

    //Print vector to check
    cout << "AFTER" << endl;
    for(int i=0; i < n; i++)
    {
        cout << random[i] << endl;
    }

    //Sum of vector
    cout << "The sum of the vector = " << v_sum(random) << endl;

    //Exit
    return 0;

}