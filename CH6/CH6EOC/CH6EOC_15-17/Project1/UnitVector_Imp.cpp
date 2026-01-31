#include "Header.h"

UnitVector::UnitVector()
{
	x = y = 1;
	orientation = 3.141;
}

UnitVector::UnitVector(double x_val, double y_val, double o)
{
	x = x_val;
	y = y_val;
	orientation = o;
}


