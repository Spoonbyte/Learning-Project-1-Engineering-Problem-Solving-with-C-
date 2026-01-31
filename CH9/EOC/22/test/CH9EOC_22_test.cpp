/*
File: CH9EOC_22_test.cpp
Desc: To solve the EOC problems
Author: spoonais
Date: 02/21/25 @ 9:59am
Finished: @ 
*/

/*
Self feedback:

So the Second Part of the program I wanted to test whether strstr() will find 
all the instances of the substring but it seems that the way it operates is that 
it returns the first found instance. So if you want it to keep searching that's why 
we need to use the while(*str1 != '\0').

*/

#include<iostream>
#include<cstring>
using namespace std;

/*--------- PROGRAMMER DEFINED FUNCTIONS -------------*/

/*----------------------------------------------------*/

int main()
{
    //Declare and init objects
    char cstrng1[] = "110101";
    char cstrng2[] = "101";
    char *str1 = cstrng1;
    char *str2 = cstrng2;
    int count(0);
    int i(0);

    // //Search throught main string and count occurrences
    // while(*str1 != '\0')
    // {
    //     //Store address of the start of match
    //     char *found = strstr(str1,str2);
    //     if(found)
    //     {
    //         count++;
    //     }
    //         else  
    //         {
    //             break;
    //         }
    // }

    //Second Part
    //Store address of the start of match
    char *found = strstr(str1,str2);

    if(found)
    {
        count++;
    }
        else  
        {
            cout << "No match" << endl;
        }

    cout << "count = " << count << endl;
    
   
    //Exit
    return 0;

}