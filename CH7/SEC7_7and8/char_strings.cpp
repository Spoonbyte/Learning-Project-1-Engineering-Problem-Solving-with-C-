/*
File: char_strings.cpp
Desc: To work with arrays of characters
Author: spoonais
Date: 12/16/24 @ 12:32pm
Finished: 
*/

/*----------- SELF FEEDBACK -------------

Takeaways:

*/
#include<iostream>
#include<cmath>
#include<fstream>
using namespace std;

/*-------------- PROGRAMMER DEFINED FUNCTION --------------------*/


/*---------------------------------------------------------------*/

int main()
{
    //#1
    char cstring1[60], cstring2[] = "Cheese";
    cin >> cstring1;
    cout << cstring1 << ' ' << cstring2 << endl;

    // //#2
    // char cstring1[10], cstring2[] = "Cheese";
    // cin.getline(cstring1,10);
    // cout << cstring1 << cstring2 << endl;

    // //#3
    // char cstring1[50], cstring2[50];
    // cin.getline(cstring1,50);
    // cin.getline(cstring2,50);
    // cout << cstring1 << cstring2 << endl;

    //Pause system
    system("pause");

    //Exit
    return 0;

}