/*
File: ifelse.cpp
Desc: The original CH3.7 example to compare to
Author: spoonais            
Date: 05/13/24
*/

#include<iostream>
using namespace std;

int main()
{
    //Declare and init objects:
    short code;

    //Get code value from user:
    cout << "Provide the operation code value" << endl;
    cin >> code;

    //Create code logic
    if (code == 10) 
    {
        cout << "Too hot - turn equipment off." << endl;
    }
        else {
    
            if (code == 11)
            {
                cout << "Caution - recheck in 5 minutes." << endl;
            }
                else {
                
                    if (code == 13)
                    {
                        cout << "Turn on circulating fan" << endl;
                    }   
                        else {  
                            cout << "Normal state of operation" << endl;
                        }

                    }
        }   


}