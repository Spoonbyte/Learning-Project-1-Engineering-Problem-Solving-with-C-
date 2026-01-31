/*This program is to determine the overflow and underflow limits*/

#include<iostream>
// #include<iomanip>
using namespace std;

int main()
{
    //Declare and Init objects 
    float x(1e18), y(1e20), z;

    //Calc Z
    z = x*y;

    //Print Z
    cout << z << endl;

return(0);
}
