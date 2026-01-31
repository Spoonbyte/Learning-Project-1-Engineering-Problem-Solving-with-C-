/*
File: chapter8_6.cpp
Desc: Try to solve section 8.6 problem my way
Author: spoonais
Date: 1/10/24 @ 3:35pm
Finished @ 
*/

/*-------- SELF FEEDBACK -----------

-----------------------------------*/
#include<iostream>
using namespace std;

const int N = 3;

/*------------ PROGRAMMER DEFINED FUNCTIONS -------------*/

/*
Funtion: eliminate()
Objective: To implement Gaussian elimination algorithm
-------------
Pre-Cond:

Post-Cond:

*/


void eliminate(int x[][N+1], int y[][N+1])
{   
    //In reality would need to add some logic to check every element per row (equation)
    //And check if any == 0, since that equation would not need to be "eliminated"
    //Eliminate i1 from 1st and 2nd eqn
    for(int i=0; i < N+1; ++i)
    {
        //Multiply equation 2 by 2
        x[1][i] = x[1][i] * 2;
        
        //Add eqn 1 to eqn 2
        for(int j=0; j < N+1; ++j)
        {
            y[0][j] = x[0][j] + x[1][j];
        }

        //place third equation in elimination matrix
        for(int k=0; k < N+1; ++k)
        {
            y[1][k] = x[2][k];
        }
    }

    //Void return
    return;
}


/*-------------------------------------------------------*/

int main()
{
    //Decalare and Init objects:
    // int value(0);
    // int R1(value), R2(value), R3(value), R4(value), R5(value);   //Not sure why this doesnt work???  
    int R1(0), R2(0), R3(0), R4(0), R5(0);                          //The resistor values
    int V1(0), V2(0);                                               //Voltages
    int elim[2][N+1] = {0};                                                
    char answer;
    int R[N][N+1] = {0};

    //Get the resistor values from the user
    cout << "Are all resistor values the same? Y for yes, N for no " << endl;
    cin >> answer;
    if(answer == 'Y')
    {
        //set all resistors to same value
        cin >> R1;
        R2 = R3 = R4 = R5 = R1;
    }
        else 
        {
            for(int i=0; i < 5; ++i)
            {
                cout << "Resistor " << i+1 << " value " << endl;
                switch(i)
                {
                    case 0:
                        cin >> R1;
                        break;
                    case 1:
                        cin >> R2;
                        break;
                    case 2:
                        cin >> R3;
                        break;
                    case 3:
                        cin >> R4;
                        break;
                    case 4:
                        cin >> R5;
                        break;
                }
            }
        }

    //Get voltages from user
    cout << "Please provide the voltage 1" << endl;
    cin >> V1;
    cout << "Please provide the voltage 2" << endl;
    cin >> V2;

    //Populate the Resistor array
    R[0][0] = R1 + R2;
    R[0][1] = R[1][0] = -R2;
    R[1][1] = R2 + R3 + R4;
    R[1][2] = R[2][1] = -R4;
    R[2][2] = R4 + R5;
    R[0][3] = V1;
    R[2][3] = V2;

    // //Check that the vector stored the input file correctly
    // cout << "Resistor Matrix" << endl;
    // for(int i=0; i < N; ++i)
    // {
    //     for(int j=0; j < N+1; ++j)
    //     {
    //         cout << R[i][j] << '\t';
    //     }
    //     cout << endl;
    // }

    //Solve for the currents
    eliminate(R,elim);

    //Check that the vector stored the input file correctly
    cout << "Eliminated Matrix" << endl;
    for(int i=0; i < 2; ++i)
    {
        for(int j=0; j < N+1; ++j)
        {
            cout << elim[i][j] << '\t';
        }
        cout << endl;
    }

    //Pause
    system("Pause");
    
    //Exit
    return 0;

}