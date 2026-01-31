/*
File: CH9EOC_18.cpp
Desc: To solve the EOC problems
Author: spoonais
Date: 02/17/25 @ 7:38am
Finished: @ 
*/

#include<iostream>
#include<vector>
#include<string>
#include<cstring>
using namespace std;

/*--------- PROGRAMMER DEFINED FUNCTIONS -------------*/

/*
Method 1:
Name: countchar()
Objective: 
Pre-Cond: 
Post-Cond: 
*/

// int countchar(char x[], char c)
// {
//     //Declare and init local objects
//     int count(0);

//     for(int i=0; i < strlen(x); i++ )
//     {
//         if(x[i] == c)
//         {
//             count++;
//         }
//     }
//     return count; 
// }

/*
Method 2:
Name: countchar()
Objective: 
Pre-Cond: 
Post-Cond: 
*/

int countchar(char *ptr, char c)
{
    //Declare and init local objects:
    int count(0);

    while(!(*ptr == '\0'))
    {
        if(*ptr == c || *ptr == toupper(c))
        {
            count++;
        }

        ptr++;
        cout << *ptr << endl;
    }
    return count;
}


/*----------------------------------------------------*/

int main()
{
    // //Method 1: Using a c-style string.
    // //Declare and init objects
    // char ch;
    // string string1 = "Hippopotamus";
    // char name[] = "Hippopotamus";

    // //Get user to enter char to find
    // cout << "Please enter the char you want to find" << endl;   
    // cin >> ch;

    // //print to user
    // cout << "The number of times " << ch << " occured was " << countchar(name,ch) << " times " << endl;

    //--------------------------------------------------------------------

    //Method 2: Using character string with pointers
    //Declare and init objects
    char ch;
    string string1 = "Hippopotamus";
    char name[] = "Hippopotamus";
    char *ptr = name;   //Stores the address of first char

    //Get user to enter char to find
    cout << "Please enter the char you want to find" << endl;   
    cin >> ch;

    //print to user
    cout << "The number of times " << ch << " occured was " << countchar(ptr,ch) << " times " << endl;




    //Exit
    return 0;

}