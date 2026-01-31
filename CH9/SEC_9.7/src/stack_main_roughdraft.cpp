/*
File: stack_main.cpp
Desc: To try and create a stack structure without OOP
Author: spoonais
Date: 01/30/25 @ 12:30pm
Finished @ 

*/

/*--------- 
Self Feedback:


----------*/

#include<iostream>
#include<iomanip>
using namespace std;

const int MAX_SIZE = 100;

/*--------- PROGRAMMER DEFINED FUNCTIONS ----------*/

class stack
{
    private:
        int top;
        double arr[MAX_SIZE];
    
    public:
        stack() : top(-1) {}            //Init the stack to -1 (empty)

        bool isEmpty()  
        {
            return top == -1;
        }

        bool isFull()
        {
            return top == MAX_SIZE -1;
        }

        void push(double x)
        {
            if(isFull()) 
            {
                cout << "Stack overflow" << endl;
                return;
            }
            arr[++top] = x;
            cout << "Value: " << arr[top] << " Address = " << &arr[top] << endl;
        }

        int pop()
        {
            if(isEmpty())
            {
                cout << "Stack Underflow" << endl;
                return -1;
            }
            return arr[top--];
        }

        int peek()
        {
            if(isEmpty())
            {
                cout << "Stack is empty" << endl;
                return -1;
            }
            return arr[top];
        }

};



/*-------------------------------------------------*/

int main()
{

    stack s;

    //cout 
    cout << fixed << setprecision(1) << endl;

    s.push(1.4);
    s.push(2.3);
    s.push(4.3);

    cout << s.peek() << endl;
    s.pop();
    cout << s.peek() << endl;

    //EXIT 
    return 0;
}