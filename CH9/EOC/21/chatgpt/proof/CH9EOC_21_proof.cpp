/*
File: CH9EOC_21_proof.cpp
Desc: To solve the EOC problems
Author: spoonais
Date: 02/19/25 @ 3:51pm
Finished: @ 
*/

#include<iostream>
#include<cstring>
using namespace std;

/*--------- PROGRAMMER DEFINED FUNCTIONS -------------*/

/*
Name: 
Objective:
Pre-Cond: 
Post-Cond: 
*/

void func1(int *ptr)     //Will make a copy of *num so the address of *ptr != *num
{
    cout << "Func1 Pass by Value" << endl;
    cout << "address of ptr  =\t"       << &ptr << endl;
    cout << "address stored in ptr =\t" << (void*)ptr << endl;
    cout << "value stored in ptr = \t"  << *ptr << endl;
}

void func2(int *&ptr)    //Will use *num directly so the address of *ptr == *num
{
    cout << "Func2 Pass by Ref" << endl;
    cout << "address of ptr  =\t"       << &ptr << endl;
    cout << "address stored in ptr =\t" << (void*)ptr << endl;
    cout << "value stored in ptr = \t"  << *ptr << endl;
}


/*---------------------------------------------------------------------*/

int main() 
{
    //Declare and init objects
    int a = 5;
    int *num = &a;

    cout << "Main Function" << endl;
    cout << "address of num  =\t"       << &num << endl;
    cout << "address stored in num =\t" << (void*)num << endl;
    cout << "address of a = \t\t"          << &a << endl;
    cout << "value stored in num = \t"  << *num << endl;
    cout << "-------------------" << endl;

    //Call function

    func1(num);
    cout << "-------------------" << endl;
    func2(num);

    return 0;
}
