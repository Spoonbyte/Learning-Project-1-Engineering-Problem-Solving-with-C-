/*
File: CH9EOC_21.cpp
Desc: To solve the EOC problems
Author: spoonais
Date: 02/18/25 @ 12:06pm
Finished: @ 3:26pm (after taking a lunch break)
*/

/*
Self feedback:

My method seemed to work below but I'm not sure if it is generalizable to all cases of 
trying to find one string within another.

*/

#include<iostream>
#include<cstring>
using namespace std;

/*--------- PROGRAMMER DEFINED FUNCTIONS -------------*/

/*
Name: findwithin(ptr2,ptr1)
Objective: To find instances of ptr2 withing ptr1
Pre-Cond: 
Post-Cond: 
*/

int findwithin(char *ptr2, char *ptr1)
{
    //Declare and init local objs:
    int count(0);
    char **s1,**s2,**s3;    //Stores a pointers address

    for(int i=0; i < 5; ++i)
    {
        if(ptr1[i] == ptr2[0] && ptr1[i+1] == ptr2[1] && ptr1[i+2] == ptr2[2])
        {
            // cout << "Match" << endl;
            if(count == 0)
            {
                count++;
            }
                else    //After count is > 0 check for overlapping matches
                {
                    if(&ptr1+(i) != s1 && &ptr1+(i) != s2 && &ptr1+(i) != s3)
                    {
                        cout << &ptr1+(i) << " != " << s1 << endl;
                        cout << &ptr1+(i) << " != " << s2 << endl;
                        cout << &ptr1+(i) << " != " << s3 << endl;
                        cout << "-------------" << endl;
                        count++;
                    }
                }
            
            //This logic keeps the s1,s2,s3 values the same for the length of 1 window
            if(i == 0)
            {
                //Initial match store
                s1 = &ptr1+(i);
                s2 = &ptr1+(i+1);
                s3 = &ptr1+(i+2);
            }
                else if(i%3 == 0)
                {
                    s1 = &ptr1+(i);
                    s2 = &ptr1+(i+1);
                    s3 = &ptr1+(i+2);
                }
            
        }
    }

    return count;
}



/*----------------------------------------------------*/

int main()
{
    //Declare and init objects
    char cstrg1[] = "110101";
    char cstrg2[] = "101";
    char *ptr1 = cstrg1;
    char *ptr2 = cstrg2;

    //Trying to understand how to get the memory addresses
    // cout << &ptr1 << " = "   << *ptr1 << endl;
    // cout << &ptr1+1 << " = " << *(ptr1+1) << endl;
    // cout << &ptr1+2 << " = " << *(ptr1+2) << endl;
    // cout << &ptr1+3 << " = " << *(ptr1+3) << endl;
    // cout << &ptr1+4 << " = " << *(ptr1+4) << endl;
    // cout << &ptr1+5 << " = " << *(ptr1+5) << endl;
    // cout << "----------" << endl;
    // cout << &ptr2 << endl;

    //Pass to function
    cout << findwithin(ptr2,ptr1) << endl;

    //Exit
    return 0;

}