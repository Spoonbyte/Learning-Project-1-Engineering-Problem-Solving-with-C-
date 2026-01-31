/*Program chapter 1_1*/
/*This program computes the distance between 2 points*/

#include <iostream> 
#include <cmath>
using namespace std;

int main( )
{
    // Declare and initialize objects.
    double x1(15), y1(11), x2(21), y2(19), S1, S2, d;  //"double" idicates the c++ data type of double precision floating point.

    //Define the sides:
    S1 = x2 - x1;
    S2 = y2 - y1;
    d = sqrt(S1*S1+S2*S2);

    //Outut result to user screen:
    cout << "The distace between the 2 points is "<<d<< endl;

    //Exit program:
    return 0;
}


