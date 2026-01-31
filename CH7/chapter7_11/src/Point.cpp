/*
File: Point.cpp
Desc: Class implementation for Point. This is where the methods for a class are defined. Methods essentially do work on the data members. 
      All of the constructors and overload operators must be defined here.
Author: spoonais
Created: 04/16/24 @ 2:57pm
*/

#include "C:/Users/sanja/Documents/Local_Cpp_Workspace/CH7/chapter7_11/include/Point.h"
#include <iostream>
#include<fstream>
#include <cmath>
using namespace std;

//Parameterized constructor
Point::Point(double x, double y)
{
      
    //input parameter x,y
    cout << "Constructing Point object, parameterized: \n";
    cout << "Input parameters: " << x << " ," << y << endl;
    xCoord = x;
    yCoord = y;
}

//Default constructor
Point::Point()
{
    cout << "Constructing Point object, default: \n";
    cout << "Initialize to zero" << endl;
    xCoord = 0.0;
    yCoord = 0.0;
}

/*
This method returns the distance between 2 points on the plane
*/

//Realization: 12/18/24
/*I understand a little more on how "rhs" works...for this problem chapter7_11 in particular.
It seems that the overload operator is using the Point class (self ref). So in this case rhs = origin
so now rhs = (0.0,0.0) and it can accomodate this because its of the point data type.
So now rhs.xCoord == 0.0 and rhs.yCoord == 0.0

*/
double Point::operator-(const Point& rhs) const
{
    double diffX, diffY, distance;
    diffX = rhs.xCoord - xCoord;
    cout << "rhs.xCoord = " << rhs.xCoord << endl;
    cout << "xCoord = " << xCoord << endl;
    diffY = rhs.yCoord - yCoord;
    distance = sqrt(pow(diffX, 2) + pow(diffY, 2));
    return distance;
}
/*
This method returns:
*   true if 2 points are equal
*   false if 2 points are not equal
*   equal means that all corresponding data members are equal
*/
bool Point::operator==(const Point& rhs) const
{
    if (rhs.xCoord == xCoord && rhs.yCoord == yCoord)
    {
        return true;
    }
    else 
    {
        return false;
    }
}

//Mutator implementation
//Seems that mutators are for error handling

void Point::setX(double xVal)
{
    xCoord = xVal;
}

void Point::setY(double yVal)
{
    yCoord = yVal;
}

void Point::setXY(double xVal, double yVal)
{
    xCoord = xVal;
    yCoord = yVal;
}

//Input File Stream implementation
void Point::input(istream& in)
{
    in >> xCoord >> yCoord;
}

//Output File Stream Implementation
void Point::print(std::ostream&) const
{
    cout << "(" << xCoord << "," << yCoord << ")";

}











