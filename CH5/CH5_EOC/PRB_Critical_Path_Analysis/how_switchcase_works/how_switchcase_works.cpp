// Type your code here, or load an example.
//I want to analyze this program in compiler explorer to see how the switch case works
#include<iostream>
using namespace std;

int main ()
{
    //Declare and Init
    int case1(0);

    //User input
    cout << "Please provide a 1 or 2" << endl;
    cin >> case1;

    //Understand how switch
    switch(case1)
    {
        case 1:
            cout << "Hello world" << endl;
            break;
        case 2:
            cout << "Goodbye" << endl;
            break;
    }

    return 0;

}