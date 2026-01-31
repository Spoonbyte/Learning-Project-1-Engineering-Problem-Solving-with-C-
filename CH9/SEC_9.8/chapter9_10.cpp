/*
File: chapter9_10.cpp
Desc: To solve the practice problems for 9.8
Author: spoonais
Date: 01/30/25 @ 12:30pm
Finished @ 

*/

/*--------- 
Self Feedback:


----------*/

#include<iostream>
#include<list>
#include<iterator>
using namespace std;

/*--------- PROGRAMMER DEFINED FUNCTIONS ----------*/


/*-------------------------------------------------*/

int main()
{
    //Decalre and init objects
    list<int>::iterator iter;               //Had to add this before the "list<int> list" statement for some reason?
    list<int> list;
    int ivalue;

    //Set iter to beginning of list
    iter = list.begin();

    cout << "Enter integer values. 'S' to stop " << endl;

    //While
    while(cin >> ivalue)
    {
        list.insert(iter,ivalue);
        ++iter;
    }
    
    // //Sort the list in ascending order
    // list.sort();

    //Print the list to standard output
    cout << "------- OUTPUT -------" << endl;
    for(iter = list.begin(); iter != list.end(); ++iter)
    {
        cout << *iter << endl;
        cout << "Address = " << &(*iter) << endl;               //This is how I get the address of each element? Learned this notation from here : https://stackoverflow.com/questions/69235904/print-address-of-iterator
        cout << "Iterator address = " << &iter << endl;
        cout << "---------------" << endl;
    }

    //EXIT 
    return 0;
}