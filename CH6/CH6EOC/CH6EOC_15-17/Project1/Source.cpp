/*
Filename: CH6EOC_15-17.cpp
Desc: To test problems 15-17
Author: spooanis
Date: 11/22/24 @ 3:53 pm
*/

#include<iostream>
#include "C:\Users\banjo\OneDrive\Documents\Learning_C++\Engineering_Problem_Solving_Book\CH6\CH6EOC\CH6EOC_15-17\Project1\Header.h"
using namespace std;

int main()
{
	//Problem 15:
	/*UnitVector v1, v2;
	cout << "v1.x = " << v1.getX() << endl;
	cout << "v1.y = " << v1.getY() << endl;
	cout << "v1.orientation = " << v1.getOrientation() << endl;*/

	//Problem 16:
	//Tackle this next
	/*UnitVector v1(0,0,0), v2;
	cout << "(v1.x, v1.y) = " << v1.getX() << " , " << v1.getY() << endl;
	cout << "v1.orientation = " << v1.getOrientation() << endl; 
	cout << "(v2.x, v2.y) = " << v2.getX() << " , " << v2.getY() << endl;
	cout << "v2.orientation = " << v2.getOrientation() << endl;*/


	//Problem 17:
	//The final problem, interested to see what the v1 = v2 will result in
	UnitVector v1(2.1, 3.0, 1.6), v2; v1 = v2;
	cout << "(v1.x, v1.y) = " << v1.getX() << " , " << v1.getY() << endl;
	cout << "v1.orientation = " << v1.getOrientation() << endl;
	cout << "(v2.x, v2.y) = " << v2.getX() << " , " << v2.getY() << endl;
	cout << "v2.orientation = " << v2.getOrientation() << endl;


	//exit
	return 0;


}