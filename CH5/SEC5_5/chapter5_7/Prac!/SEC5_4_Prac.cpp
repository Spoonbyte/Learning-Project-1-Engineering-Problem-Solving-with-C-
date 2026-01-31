/*
File: SEC5_4_Prac.cpp
Desc: 
Author: spoonais
Date: 08/07/24 @1:37pm
*/

#include<iostream>
#include<cmath>
using namespace std;

int main()
{

     // //1. 
     // int i(0), j(0);
     // cin >> i >> j;

     //What I think the Memory snap will look like 
     /*
     i = 1
     j = 0
     Reason: The "," will not count as an int so it will throw an error
     badbit  = 0
     failbit = 1
     eofbit  = 0
     goodbit = 0
     */
    
     //Actual output 
     // cout << "i = " << i << "\n"
     //      << "j = " << j << endl;
     // cout << "badbit  = " << cin.bad()  << "\n"
     //      << "failbit = " << cin.fail() << "\n"
     //      << "eofbit  = " << cin.eof()  << "\n"
     //      << "goodbit = " << cin.good() << endl;
     // //CORRECT!

     // //2.
     // double x(0), y(0);
     // cin >> x >> y;


     // //What I think the Memory snap will look like 
     // /*
     // x = 1
     // y = 0
     // Reason: The "," will not count as an int so it will throw an error
     // badbit  = 0
     // failbit = 1
     // eofbit  = 0
     // goodbit = 0
     // */

     // //Actual output 
     // cout << "x = " << x << "\n"
     //      << "y = " << y << endl;
     // cout << "badbit  = " << cin.bad()  << "\n"
     //      << "failbit = " << cin.fail() << "\n"
     //      << "eofbit  = " << cin.eof()  << "\n"
     //      << "goodbit = " << cin.good() << endl;
     // //CORRECT!


     // //3.
     // char ch1, ch2, ch3, ch4, ch5;
     // cin >> ch1 >> ch2 >> ch3 >> ch4 >> ch5;

     // //What I think the Memory snap will look like 
     // /*
     // ch1 = 0
     // ch2 = 0
     // Reason: The "," will count as a char but the numbers will not be recognized as characters so the 
     // input stream buffer will not be modified.
     // badbit  = 0
     // failbit = 1
     // eofbit  = 0
     // goodbit = 0
     // */

     // //Actual output 
     // cout << "ch1 = " << ch1 << "\n"
     //      << "ch2 = " << ch2 << "\n"
     //      << "ch3 = " << ch3 << "\n"
     //      << "ch4 = " << ch4 << "\n"
     //      << "ch5 = " << ch5 << endl;
     // cout << "badbit  = " << cin.bad()  << "\n"
     //      << "failbit = " << cin.fail() << "\n"
     //      << "eofbit  = " << cin.eof()  << "\n"
     //      << "goodbit = " << cin.good() << endl;

     //INCORRECT... Actual terminal output
     /*
     1,2.3
     ch1 = 1
     ch2 = ,
     badbit  = 0
     failbit = 0
     eofbit  = 0
     goodbit = 1

     If I added variables ch3, ch4 and ch5 I could get "2" "." and "3"
     Should be:
     1,2.3
     ch1 = 1
     ch2 = ,
     ch3 = 2
     ch4 = .
     ch5 = 3
     badbit  = 0
     failbit = 0
     eofbit  = 0
     goodbit = 1

     CORRECT!!!
     Seems like even when you enter a number for a char variable it sees it as a char and not a number
     
     */

     //4.
     char ch;
     double x, y;
     cin >> x >> ch >> y;

     
     //What I think the Memory snap will look like 
     /*
     x = 1
     ch = ,
     y = 2.3
     Reason: The "," will count as a char but the numbers will not be recognized as characters so the 
     input stream buffer will not be modified.
     badbit  = 0
     failbit = 0
     eofbit  = 0
     goodbit = 1
     */

     //Actual output 
     cout << "x  = " << x  << "\n"
          << "ch = " << ch << "\n"
          << "y  = " << y  << endl;
     cout << "badbit  = " << cin.bad()  << "\n"
          << "failbit = " << cin.fail() << "\n"
          << "eofbit  = " << cin.eof()  << "\n"
          << "goodbit = " << cin.good() << endl;

     /*
     CORRECT!
     The input stream buffer was modified by storing the 1 as a float, "," as a char and 2.3 as a float
     */

}