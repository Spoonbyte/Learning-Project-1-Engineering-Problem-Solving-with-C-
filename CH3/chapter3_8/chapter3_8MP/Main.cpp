/*
File: Main.cpp
Desc: To create a currency converter program
Author: spoonais
Date: 05/15/24
*/

#include<iostream>
#include<stdlib.h>
using namespace std;

/*
Program chapter3_8
This program performs currency conversion from dollars (D) to 
E => euros
P => pesos
S => pounds sterling
based on what the user wants
*/

int main()
{
	//Declare and init objects
	char type;
	float dollars;
	double euros, pesos, lbs;
	

	//User to provide value in dollars AND the conversion they want
	cout << "Please provide the conversion type" << endl;
	cout << "E => euros\nP => pesos\nS = pounds sterling\n" << endl;
	cin >> type;
	cout << "Please provide the dollar value" << endl;
	cin >> dollars;

	//Provide the cases
	switch (toupper(type))
	{
		case 'E':
			euros = dollars * 0.92;
			cout << euros << endl;
			break;
		case 'P':
			pesos = dollars * 16.69;
			cout << pesos << endl;
			break;
		case 'S':
			lbs = dollars * 0.79;
			cout << lbs << endl;
			break;
		default:
			cout << "Currency conversion type not recognized" << endl;
			break;

	}




}