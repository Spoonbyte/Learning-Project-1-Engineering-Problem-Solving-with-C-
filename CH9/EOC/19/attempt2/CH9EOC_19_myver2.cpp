/*
File: CH9EOC_19_myver2.cpp
Desc: To solve the EOC problems
Author: spoonais
Date: 02/21/25 @ 10:30am
Finished: @ 
*/

#include<iostream>
#include<cstring>
using namespace std;

/*--------- PROGRAMMER DEFINED FUNCTIONS -------------*/

/*
Name: repeat()
Objective: 
Pre-Cond: 
Post-Cond: 
*/

// int repeat(char *ptr)
// {
//     int length = strlen(ptr);   //Returns the length to use in for loop
//     int count(0), instance(0);

//     for(int i=0; i < length; i++)
//     {   
//         for(int j=i+1; j < length; j++)
//         {
//             // cout << ptr[i] << ", " << ptr[j] << endl;
//             if(ptr[i] == ptr[j])
//             {   
//                 count++;
//             }
//         }

//         if(count >= 1)
//         {
//             instance++;
//         }

//         //Reset count 
//         count = 0;
//     }
    
//     return instance;
// }


/*----------------------------------------------------*/

int main()
{
    //Declare and init objects
    // char cstring[] = "alligator";
    // char *str = cstring;    

    // //Call the function
    // cout << "Repeated characters = " << repeat(str) << endl;

    for(int i =(int)'!'; i <= (int)'~'; i++)
    {
        cout << (char)i << endl;

    }

    //Exit
    return 0;

}