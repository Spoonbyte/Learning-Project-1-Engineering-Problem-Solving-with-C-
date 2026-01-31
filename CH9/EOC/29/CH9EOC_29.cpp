/*
File: CH9EOC_29.cpp
Desc: To solve #29
Author: spoonais
Date: 02/27/25 @5:20pm
Finished: @ 5:40pm
*/

/*
Self feedback:


*/

const int MAX_ELEM = 20;

#include<iostream>
#include<cstdlib>
using namespace std;

//Prototype
void assignRand(double *x, int n);

/*---------- PROGRAMMER DEFINED FUNCTIONS -------------*/

/*
Name: assignRand()
Objective: To assign random #s to the first n elements of array x
Pre-Cond:
Post-Cond:
*/

void assignRand(double *x, int n)
{
    for(int i=0; i < n; i++)
    {   
        //Generate rand number
        srand(i);         //Seed the rand()
        *(x+i) = rand();
    }
}

/*------------------------------------------------------*/

int main()
{
    //Decalare and Init objects:
    double array[MAX_ELEM] = {0};
    int num_elem(0);

    //Ask user for the number of elements to add to the array NOT EXCEEDING THE ARRAY MAX
    do
    {
        cout << "Provide the number of elements to fill. Must be less than " << MAX_ELEM << endl;
        cin >> num_elem;

    } while (num_elem > MAX_ELEM);

    //Call the function
    assignRand(array,num_elem);

    //Print the array
    for(int p=0; p < MAX_ELEM; p++)
    {
        cout << array[p] << " ";
    }
    cout << endl;
    
    return 0;

}