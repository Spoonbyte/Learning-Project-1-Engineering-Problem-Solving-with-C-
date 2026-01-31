/*
File: molecwght.cpp
Desc: This file will be used to calculate the molecular weight of a amino acid
Author: spoonais
Created: 04/16/24 @ 4:31:00 PM
*/

#include<iostream>
#include<cmath>
#include<fstream>
#include<string>
using namespace std;

int main()
{
    //Delcare and Init objects
    const double O_mw = 15.9994, C_mw = 12.011, N_mw = 14.00674,
        S_mw = 32.066, H_mw = 1.00794;
    double amino_mw, amino_mw_stod, a, b, c, d, e, range_h, range_l;
    string amino_name, amino_mw_csv;

    //Ask user to provide values
    cout << "Provide the # of oxygen atoms" << endl;
    cin >> a;
    cout << "Provide the # of carbon atoms" << endl;
    cin >> b;
    cout << "Provide the # of nitrogen atoms" << endl;
    cin >> c;
    cout << "Provide the # of sulfur atoms" << endl;
    cin >> d;
    cout << "Provide the # of hydrogen atoms" << endl;
    cin >> e;

    //Calculate the molecular weight of the amino acid
    amino_mw = a*O_mw + b*C_mw + c*N_mw + d*S_mw + e*H_mw;

    //Range for amino_mw 
    range_h = amino_mw + 0.01;
    range_l = amino_mw - 0.01;

    //Create the filestream
    ifstream inFile;

    //Direct the filestream to the file where the data is stored
    inFile.open("Amino_Acid_MW_TXT.txt");

    //ERROR CHECK: 
    //Check to make sure the file is opened
    if (inFile.is_open()) {
    cout << "File has been opened" << endl;
    }
    else {
    cout << "FILE NOT OPENED!" << endl;
    }

    // Open the excel doc and read in the data from the file
    while (!inFile.eof()) 
    {
        getline(inFile,amino_name,',');
        getline(inFile,amino_mw_csv);
        amino_mw_stod = stod(amino_mw_csv); //stod is "string to double" function

        // if (amino_mw >= amino_mw_stod)
        //     cout << "It matches" << endl;
        // // cout << "Amino Acid: " << amino_name << "\n";
        // // cout << "Molecular Weight: " << amino_mw_csv << "\n";
        
        if (range_h >= amino_mw_stod && amino_mw_stod >= range_l)
        {
            cout << "Amino Acid: " << amino_name << "\n";
            cout << "Molecular Weight: " << amino_mw_csv << "\n";
        } 
        //else {
        //     cout << "No Match" << endl;
        // }

       
        
    }

    //Close the file stream
    inFile.close();
    
    cin.get();
}


