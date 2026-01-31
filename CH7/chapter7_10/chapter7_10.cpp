/*
File: 
Desc: To work with vector class
Author: 
Date: 12/17/24 @ 
Finished: 
*/

/*----------- SELF FEEDBACK -------------

Takeaways:

*/

#include<iostream>
#include<vector>
using namespace std;

/*-------------- PROGRAMMER DEFINED FUNCTION --------------------*/


/*---------------------------------------------------------------*/

int main()
{
    //Declare and init objects
    vector<int> A(5);            //An array A of capacity 5

    //Print
    cout << "---------- BEFORE ---------------" << endl;
    cout << "capacity = " << A.capacity() << endl;
    cout << "size = " << A.size() << endl;
   

    //Add 2 additional elemetns to the end of A
    A.push_back(10);
    A.push_back(20);
    A.push_back(22);
    A.push_back(23);
    A.push_back(18);
    A.push_back(18);

    //When 2 elements are added the capacity of the array is increased automatically to 10, how is this determined?

    //Print
    cout << "---------- AFTER ---------------" << endl;
    cout << "capacity = " << A.capacity() << endl;
    cout << "size = " << A.size() << endl;

    //TRBLSHT
    // for(int p=0; p<A.capacity(); p++)
    // {
    //     cout << A[p] << endl;
    // }

    //Exit
    return 0;

}