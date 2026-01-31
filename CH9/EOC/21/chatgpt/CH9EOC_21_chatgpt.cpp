/*
File: CH9EOC_21_chatgpt.cpp
Desc: To solve the EOC problems
Author: spoonais
Date: 02/19/25 @ 1:15pm
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
Name: 
Objective: To find instances of ptr2 withing ptr1
Pre-Cond: 
Post-Cond: 
*/

/*
This way passes the pointers from main() by reference...so the main pointers are directly used by the 
function.

You can see in the screenshot that the last compiled run was the pass by ref since the address
of ptr1 was the same as str1 (ff768)
*/

// int overlap(char *&ptr1, char *&ptr2) 
// {
//     int count = 0;
//     int len2 = strlen(ptr2);

//     cout << "address of ptr1 = " << &ptr1 << endl;
//     cout << "address stored in ptr1 = " << (void*)ptr1 << endl;
//     cout << "value stored in ptr1 = " << *ptr1 << endl;

//     if (len2 == 0) return 0;  // Edge case: Empty search string

//     const char *found = strstr(ptr1, ptr2);

//     while (*ptr1 != '\0') 
//     {
//         char *found = strstr(ptr1, ptr2);

//         if(found) 
//         {
//             count++;
//             ptr1 = found + len2;  // Move past the current match to avoid overlap
//         } 
//             else 
//             {
//                 break;
//             }
            
//     }

//     return count;
// }


/*
This way passes the pointers from main() by value...so a new pointer is made and the contents of 
the main pointers are copied to the new pointers. 
You can see in the screenshot that the first compiled run was the pass by value since the address
of ptr1 was different than str1 (ff7b0 vs ff7d0)
*/
int overlap(const char *ptr1, const char *ptr2) 
{
    int count = 0;
    int len2 = strlen(ptr2);

    for(int i=0; i < strlen(ptr1); i++)
    {
        cout << "ptr1[" << i << "] = " << (void*)(ptr1+i) << " | " << *(ptr1+i) << endl;
    }
    cout << "--------------------" << endl;

    if (len2 == 0) return 0;  // Edge case: Empty search string

    while (*ptr1 != '\0') 
    {
        const char *found = strstr(ptr1, ptr2);
        cout << "address stored in found = " << (void*)found << endl;

        if(found) 
        {
            count++;
            ptr1 = found + len2;  // Move past the current match to avoid overlap
            cout << "address stored in ptr1 = " << (void*)ptr1 << endl;
        } 
            else 
            {
                break;
            }        
    }
    return count;
}

/*---------------------------------------------------------------------*/

int main() {
    char cstrg1[] = "11010101";
    char cstrg2[] = "101";
    char *str1 = cstrg1;
    char *str2 = cstrg2;

    for(int i=0; i < strlen(str1); i++)
    {
        cout << "str1[" << i << "] = " << (void*)(str1+i) << " | " << *(str1+i) << endl;
    }
    cout << "--------------------" << endl;
    
    // cout << "address of str1[1] = " << &str1+1 << endl;
    // cout << "address stored in str1[1] = " << (void*)(str1+1) << endl;
    // cout << "value stoed in str1[1] = " << *(str1+1) << endl;
    // cout << "--------------" << endl;

    int result = overlap(str1, str2);
    cout << "Occurrences: " << result << endl;  // Output: 1

    return 0;
}
