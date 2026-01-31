/*
File: CH9EOC_19_myver.cpp
Desc: To solve the EOC problems
Author: spoonais
Date: 02/17/25 @ 2:40pm
Finished: @ 
*/

#include<iostream>
#include<vector>
using namespace std;

/*--------- PROGRAMMER DEFINED FUNCTIONS -------------*/

/*
Name: repeat()
Objective: 
Pre-Cond: 
Post-Cond: 
*/

int repeat(char *ptr)
{
    //Hold ptr
    char *ptr2 = ptr + 1;
    int count2(0);

    for(int i=0; i < 11; i++ )
    {   
        int count(0);

        for(int j=i+1; j < 11; j++)
        {
            cout << *ptr << " = " << *ptr2 << endl;
            if(*ptr == *ptr2)
            {
                count++;    //Determines if a character is repeated
            }

            ptr2++;
        }

        cout << "---------------" << endl;

        if(count > 1)
        {
            count2++;       //How many characters repeated
        }

        ptr++;
        ptr2 = ptr + 1;
    }

    return count2;
}



/*----------------------------------------------------*/

int main()
{
    //Declare and init objects
    char cstring[] = "hisssssssss";
    char *ptr = cstring;    

    //Call the function
    cout << repeat(ptr) << endl;

    //Exit
    return 0;

}