/*
File: SEC9.6_Prac.cpp
Desc: To solve the practice problems for 9.6
Author: spoonais
Date: 01/29/25 @ 11:10am
Finished @ 12:42pm

*/

/*--------- 
Self Feedback:


----------*/

#include<iostream>
#include<fstream>
#include<cmath>
using namespace std;

/*--------- PROGRAMMER DEFINED FUNCTIONS ----------*/


/*-------------------------------------------------*/

int main()
{
    //Decalre and init objects
    int *iptr, *jptr, *arr_ptr;
    iptr = new int(10);
    arr_ptr = new int[5];

    // //#1
    // jptr = iptr;                                        //jptr = 10 
    // cout << *iptr << ' ' << *jptr << endl;              //*iptr = 10, *jptr = 10
    // cout << iptr << ' ' << jptr << endl;                //same address #
    // delete iptr;                                        //delete iptr address from heap
    // cout << iptr << ' ' << jptr << endl;                //iptr = ???, jptr = same address
    // cout << *iptr << ' ' << *jptr << endl;
    
    /*After running code
    I realized what happens is that iptr value is deleted (removed from heap) BUT the pointer still holds the 
    same memory address...its just the value there is invalid
    */

    // //#2
    // cout << arr_ptr << endl;                                //address of the first element array
    // for(int i=0; i < 4; ++i)                                //arr_ptr = {0,1,2,3,random}
    //     arr_ptr[i] = i;                                     //
    // for(int i=0; i < 4; ++i)                                    
    //     cout << *(arr_ptr)++ << ' ';                        // 1 2 3 4 (INCORRECT)
    // cout << endl << arr_ptr << endl;                        // address same as first address
    // arr_ptr = arr_ptr - 4;                                  //I added this to see how to get back to the original mem addresses
    // cout << endl << arr_ptr << endl;
    // for(int i=0; i < 4; ++i)                                //
    //     cout << arr_ptr[i] << ' ';                          // 0 1 2 3 (INCORRECT)        

    /*After running code
    I initally was confused by the *(arr_ptr)++ statement because op precedence says that ++ goes before *
    so I thought it would increment arr_ptr to the next address and print that value...
    
    *(arr_ptr) = *(arr_ptr) + 1 so the first iteration is 1, then 2 then 3...etc

    BUT what actually happens is that ++ is done on arr_ptr BUT it returns the TEMPORARY value (or inital value 
    before incrementing) then it is * to th value to zero, THEN the pointer is incremented

    This article describes: 
    https://stackoverflow.com/questions/15295226/c-operator-precedence?rq=1

    My lack of understanding was in how the POSTFIX operation works

    */

    //#3
    for(int i=0; i<4; ++i)
        arr_ptr[i] = i;                                             //arr_ptr[] = {0,1,2,3}
    jptr = &arr_ptr[2];                                             //jptr = address of arr_ptr[2]
    cout << arr_ptr << ' ' << jptr << endl;                         //address of arr_ptr[0], address of arr_ptr[2]
    cout << *arr_ptr << ' ' << *jptr << endl;                       //0 2
    delete [] arr_ptr;                                              //deletes VALUES of array from memory
    cout << arr_ptr << ' ' << jptr << ' ' << *jptr << endl;         //address of arr_ptr[0], address of arr_ptr[2], invalid #           


    /*After running code
    Got it correct!

    The takeaway can be summarized by the book on pg 466:arr_ptr

    "After the delete operator is used with a pointer to return memeory to the heap, the pointer will 
    point to an invalid memeory space or, depending on the compiler, it may retain the memeory address
    of the deleted memory"

    The second case is what applies to my compiler (g++)

    */

    //EXIT 
    return 0;
}