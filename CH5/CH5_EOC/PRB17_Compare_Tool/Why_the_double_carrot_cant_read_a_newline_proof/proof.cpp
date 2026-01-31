/*
File: proof.cpp

Desc: To show that a fin >> char skips over a newline character. Motivation was that I was trying to use the "\n" as a singal 
to increment a counter based on a new line of a text file. It was not working so I had to use fin.get(char) to store the "\n"
into char.

This is a good way to be able to look into the input buffer to see what is really going on.

Author: spoonais
Date: 09/07/24 @6:22pm
*/

#include<iostream>
#include<cmath>
using namespace std;

int main()
{   
    //This code is copied from chatgpt. It was able to answer my question on this

    int x;
    cout << "Enter a number: ";
    cin >> x;  // The newline after the number is ignored.
    cout << "You entered: " << x << endl;

    // To verify, let's print out the character that remains in the input buffer.
    char ch, ch2, ch3;
    cin.get(ch);
    cin.get(ch2);
    cin.get(ch3);
    cout << ch << ch2 << ch3 << endl;

    if(ch3 == '\n')
    {
        cout << "There is a newline character in the input buffer" << endl;
    }

    return 0;
}
