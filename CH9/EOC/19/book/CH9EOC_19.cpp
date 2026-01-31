/*
File: CH9EOC_19_book.cpp
Desc: To solve the EOC problems
Author: spoonais
Date: 02/17/25 @ 2:40pm
Finished: @ 
*/

#include<iostream>
#include<cstring>
#include<vector>
using namespace std;

/*--------- PROGRAMMER DEFINED FUNCTIONS -------------*/

/*
Name: repeat()
Objective: 
Pre-Cond: 
Post-Cond: 
*/

void repeat(char *ptr)
{
    //Declare and init local objects
    int length(0), length2(0);
    char store[5] = {0,1,2,3,4};       //Remembers the characters that have been stored
    int count2(0);
    bool state;

    length = strlen(ptr);       //Length of string
    length2 = strlen(store);

    char *str = store;          //str == &store[0]

    for(int i = 0; i < length2; ++i)
    {
        cout << *str << endl;
        cout << "Hello" << endl;
    }

    // for(int i=0; i < length; ++i)
    // {
    //     int count(0);

    //     //Add char to store if not in store
    //     for(int s=0; s < length2; ++s )
    //     {
    //         cout  << ptr[i] << " = " << store[s] << endl;
    //         if(!(ptr[i] == store[s]))
    //         {
    //             *str = ptr[i];
    //             str++;          //Keep track where last char was added
                
    //         } 
    //     }
        
    //     for(int j=i+1; j < length; ++j)
    //     {
    //         // cout << ptr[i] << " = " << ptr[j] << endl;
    //         if(ptr[i] == ptr[j])
    //         {
    //             count++;
    //         }
    //     }

    //     //Determine if current char is in the store array
    //     //If it is and the count is > 1 then DONT increment
    //     for(int q=0; q < length2; ++q)
    //     {
    //         if(!(ptr[i] == store[q]))
    //         {
    //             state = 1;
    //         }
    //     }

    //     if(count > 1 && state == 1 )
    //     {
    //         count2++;
    //     }

    // }
    
}

/*----------------------------------------------------*/

int main()
{
    //Declare and init objects
    char cstring[] = "Mississippi";
    char *ptr = cstring;    

    //Call the function
    repeat(ptr);

    //Exit
    return 0;

}