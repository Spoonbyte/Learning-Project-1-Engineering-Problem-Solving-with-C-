/*The increment/decrement function*/

#include<iostream>
using namespace std;

int main()
{
    //Declare & Init objects
    int pp_x(1), x_pp(1), y(2), z_pp, pp_z;

    //Calculate
    pp_z = ++pp_x - y; //uses the incremented x value
    z_pp = x_pp++ - y; //uses the init x value

    //Print to console
    cout << pp_z << "\n" << z_pp << endl;

return(0);
}