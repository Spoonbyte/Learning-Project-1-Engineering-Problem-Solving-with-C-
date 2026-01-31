/*
File: chapter9_11.cpp
Desc: To solve the practice problems for 9.8
Author: spoonais
Date: 2/7/25 @ 9:20am
Finished @ 

*/

/*--------- 
Self Feedback:

The inital way that I did the for loop to print values seemed a little slower than the 
way the book did it using "!astack.empty()". Not entirely sure why it did.

----------*/

#include<iostream>
#include<stack>
using namespace std;


int main()
{
    //Decalre and init objects
    stack<int> astack;
    int value(0);

    //Add values to stack using while loop
    cout << "Provide values to the stack. End using S." << endl;
    while(cin >> value)
    {
        astack.push(value);
    }

    // //Print values 
    // while(astack.top() != -1)
    // {
    //     //Print value of top
    //     cout << astack.top() << endl;

    //     //Pop
    //     astack.pop();
    // }

    //OR
    while(!astack.empty())
    {
        //Print value of top
        cout << astack.top() << endl;

        //Cout address
        cout << "address = " << &astack.top() << endl;

        //Pop
        astack.pop();
    }


    //EXIT 
    return 0;
}