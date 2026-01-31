/*
Objective to figure out why:

fin >> time >> altitude >> velocity >> accelration;

works in problems #20-23 in CH5_EOC

*/

#include<iostream>
#include<fstream>
using namespace std;

int main ()
{
    //Declare and init
    int data1(0), data2(0);
    ifstream fin;

    //Associate filestream with file
    fin.open("text.txt");

    //Get first set of data
    fin >> data1 >> data2;


    //close
    fin.close();
    return 0;    
    

}