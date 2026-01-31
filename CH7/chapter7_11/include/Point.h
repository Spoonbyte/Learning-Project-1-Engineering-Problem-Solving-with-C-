/*  Point class chapter 2-3 */
/*  Filename: Point.h   */

#ifndef _POINT_H
#define _POINT_H
#include <iostream> //needed to include this in the header file to allow it to build.

class Point
{
    //Type declaration statements for data members.
private:
    double xCoord, yCoord; //Class attributes

public:
    //Declaration statements for class methods
    //Constructors for Point class
    Point(); //default constructor
    Point(double x, double y); //parameterized constructor

    //Overload Operators 
    double operator - (const Point& rhs) const;
    bool operator ==(const Point& rhs) const;

    //Accessor Methods
    double getX() const { return xCoord; }
    double getY() const { return yCoord; }

    //Mutator Methods
    void setX(double newX); //Allow main program to modify the xCoord class member
    void setY(double newY); //Allow main program to modify the yCoord class member
    void setXY(double newX, double newY); //Allow main program to modify both the xCoord and yCoord class members

    //Input File Stream Methods
    void input(std::istream& in);

    //Output File Stream Methods
    void print(std::ostream&) const;
    

};

#endif // !_POINT_H
