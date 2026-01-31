/*
Purpose: To test how the for loop works by adding a series of numbers together.
Date: 07/12/24
*/
#include<iostream>
using namespace std;

int main()
{
    //Declare and init objects
    double num(0),sum(0);

    //Create the loop
    for (int i=1; i<=5; ++i)
    {
        // cout << "Please provide number to add" << endl;
        cin >> num;

        sum += num;
    }

    cout << "The sum is " << sum << endl;

    //System pause
    system("pause");

    //Exit program
    return(0);

}