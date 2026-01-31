/*
File:
Desc:
Author: spoonais
Date: 05/23/24 @3:34am
*/

#include<iostream>
#include<cmath>
#include<string>
using namespace std;


//Define the user function to define the switch cases:
//I now know I need to keep my PDF (programmer defined func) OUTSIDE of the main routine
//in order for it to return values...I wonder what was happening when I had the PDF within my MAIN and 
//why it was bugging out when I tried to return the "taut" character


//Decalare and Init objects:
    bool A(0), B(0), C(0);
    char x;
    string value("Y");

//Define the tautological condition:
    char taut()
    {
        int AandBandC = (A&&B || B&&C);
            if (AandBandC == 1) 
            {
                x = '1';
            } else {
                x = '0';
            }
        return x;

    }
    
//Switch 
    char myfunc()
    { 
        char x1 = x;
        char taut;
        switch (x1)
        {
            case ('0'):
                taut = 'N';
                break;
            case ('1'):
                taut = 'Y';
                break;
        }
        return taut;
    }

int main()
{

    //Create the header 
    cout << "A\tB\tC\t   A&&B || B&&C\t   Tautology?" << endl;
    cout << "===================================================" << endl;
    taut();
    cout << A << "\t" << B << "\t" << C << "\t\t" << (A&&B || B&&C) << "\t\t" << myfunc() << endl;

    //Toggle C
    C = !C;
    taut();
    cout << A << "\t" << B << "\t" << C << "\t\t" << (A&&B || B&&C) << "\t\t" << myfunc() << endl;

    /*
    The additional idea I had was once you get to this first toggle C was for the code to "jump back" to recalculalte 
    line 21 and therefore update "taut". Not sure how to do this yet because it would seemingly make the code cleaner than 
    having a bunch of IF-ELSE statements
    */

    //Toggle C and B
    B = !B;
    C = !C;
    taut();
    cout << A << "\t" << B << "\t" << C << "\t\t" << (A&&B || B&&C) << "\t\t" << myfunc() << endl;

    //Toggle C
    C = !C;
    taut();
    cout << A << "\t" << B << "\t" << C << "\t\t" << (A&&B || B&&C) << "\t\t" << myfunc() << endl;

    //Toggle A, B, C
    A = !A;
    B = !B;
    C = !C;
    taut();
    cout << A << "\t" << B << "\t" << C << "\t\t" << (A&&B || B&&C) << "\t\t" << myfunc() << endl;

    //Toggle C
    C = !C;
    taut();
    cout << A << "\t" << B << "\t" << C << "\t\t" << (A&&B || B&&C) << "\t\t" << myfunc() << endl;

    //Toggle C and B
    B = !B;
    C = !C;
    taut();
    cout << A << "\t" << B << "\t" << C << "\t\t" << (A&&B || B&&C) << "\t\t" << myfunc() << endl;

    //Toggle C
    C = !C;
    taut();
    cout << A << "\t" << B << "\t" << C << "\t\t" << (A&&B || B&&C) << "\t\t" << myfunc() << endl;


}