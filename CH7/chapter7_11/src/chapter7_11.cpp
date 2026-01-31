/*
File: chapter7_11.cpp
Desc: This program inputs a collection of points and finds the Point that is closest to the origin.
Author: spoonais
Date: 12/17/24 @ 
Finished: 
*/

/*----------- SELF FEEDBACK -------------

Takeaways:

*/
#include<iostream>
#include<fstream>
#include<cmath>
#include<string>
#include<vector>
#include "C:/Users/sanja/Documents/Local_Cpp_Workspace/CH7/chapter7_11/include/Point.h"
using namespace std;

//Function Prototypes
void readPointFile(istream& in, vector<Point>& v);      //Pass by ref
Point closeToOrigin(vector<Point> v);                   //Pass by Value

/*-------------- PROGRAMMER DEFINED FUNCTION --------------------*/

void readPointFile(istream& in, vector<Point>& v)
{
    //Declare and init local objects
    int npts(0);        //count the data points in file

    //Read in data points
    in >> npts;
    v.resize(npts);
    Point p;

    //Read in the points from input file:
    //points are formatted as (X,Y)
    double x,y;
    char comma;
    for(int i=0; i<npts; i++)
    {
        in >> x >> comma >> y;
        p.setX(x);
        p.setY(y);
        v[i] = p;
    }

    // //TRBLSHT:
    // //Check array was written to
    // for(int c=0; c<npts; ++c)
    // {
    //     cout << v[c].getX() << "," << v[c].getY() << endl;
    // }

}

//This functions returns the point closest to the origin
Point closeToOrigin(vector<Point> v)
{
    Point origin(0.0,0.0);
    int closest(0);                 //Offset of closest
    for(int i=1; i<v.size(); ++i)
    {
        if(v[i] - origin < v[closest] - origin)
        {
            closest = i;
        }

    }

    return v[closest];

}

/*---------------------------------------------------------------*/


int main()
{
    //Declare and init objects
    Point p;
    string filename;
    ifstream file1;

    //Prompt user for file name and open file
    cout << "Enter filename" << endl;
    cin >> filename;
    file1.open(filename.c_str());           //I think what the ".c_str()" does is convert the input stream into an array
    if(file1.fail())
    {
        cerr << "Error opening file " << filename << endl;
        exit(1);
    }

    //Build point vector:
    vector<Point> v;            //Use "v" to hold an array of points, capacity not defined yet
    readPointFile(file1,v);
    

    //Find point closest to origin
    p = closeToOrigin(v);

    // //Print
    // cout << "(" << p.getX() << "," << p.getY() << ")" << " is the closest to the ORIGIN" << endl;
    //Modify1 with the new print method
    p.print(cout); 
    cout << " is the closest to the ORIGIN" << endl;

    //Exit
    return 0;

}