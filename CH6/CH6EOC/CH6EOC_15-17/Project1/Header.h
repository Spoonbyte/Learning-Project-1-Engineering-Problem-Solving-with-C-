/*
Unit Vector chapter 6
Filename: UnitVector.h
Date: 11/22/24 @ 3:41pm
*/

#ifndef _UNITVECTOR_H
#define _UNITVECTOR_H

class UnitVector
{

private:
	double x, y;       //vector anchor point
	double orientation; //vector orientation
//Constructor functions
public:
	UnitVector(); //default constructor
	UnitVector(double x_val, double y_val, double o); //paramaterized constructor

	//Accessor function
	double getX() const { return x; }
	double getY() const { return y; }
	double getOrientation() const { return orientation; }


};

#endif // !_UNITVECTOR_H


#pragma once
