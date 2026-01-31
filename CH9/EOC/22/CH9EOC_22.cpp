/*
File: CH9EOC_22.cpp
Desc: To solve the EOC problems
Author: spoonais
Date: 02/20/25
Finished: @ 
*/

/*
Self feedback:

*/

#include<iostream>
#include<cstring>
using namespace std;

/*--------- PROGRAMMER DEFINED FUNCTIONS -------------*/

/*
Name: overlap_yes()
Objective: To find instances of ptr2 withing ptr1, this time allowing overlap
Pre-Cond: 
Post-Cond: 
*/

int overlap_yes(const char* ptr1, const char* ptr2 )
{
    //Declare and init local obj:
    int count(0);

    //Search throught main string and count occurrences
    while(*ptr1 != '\0')
    {
        //Store address of the start of match
        const char *found = strstr(ptr1,ptr2);

        if(found)
        {
            count++;
            //Set ptr1 to found
            ptr1 = found+1;
        }
            else  
            {
                break;
            }

    }

    return count;
}



/*----------------------------------------------------*/

int main()
{
    //Declare and init objects
    char cstrng1[] = "110101";
    char cstrng2[] = "101";
    char *str1 = cstrng1;
    char *str2 = cstrng2;

    //Call the function
    cout << "Occurrences: " << overlap_yes(str1,str2) << endl;
   
    //Exit
    return 0;

}