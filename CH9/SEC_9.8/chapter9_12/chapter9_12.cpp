/*
File: chapter9_12.cpp
Desc: To solve the practice problems for 9.8
Author: spoonais
Date: 2/7/25 @ 11:14am
Finished @ 
*/

/*--------- 
Self Feedback:


----------*/

#include<iostream>
#include<queue>
using namespace std;

int main()
{
    //Decalre and init objects
    queue<int> aqueue;
    int value(0);

    //Add values to stack using while loop
    cout << "Provide values to the stack. End using S." << endl;
    while(cin >> value)
    {
        aqueue.push(value);
    }

    //Print to console
    while(!aqueue.empty())
    {
        //Print value of top
        cout << aqueue.front() << endl;

        //Pop
        aqueue.pop();
    }


    //EXIT 
    return 0;
}