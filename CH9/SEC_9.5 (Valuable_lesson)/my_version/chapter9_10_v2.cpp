/*
File: chapter9_10_v2.cpp
Desc: To solve the Seismic Event detection problem. Use dynamic memory allocation. My version
but updated to be more general and using vector class
Author: spoonais
Date: 01/28/25 @ 3:40pm
Finished: @ 4:20pm
*/

/*--------- 
Self Feedback:

1/28/25
Comparing my code to the books version, I can see my code is specifc for this problem that uses a short window of 2 and 
long window of 5...there is no generalizing to other window sizes

Version 2 udpate:
Essentially did the modify 1 and 3 problems and pretty much used the same technique (for starting from a 
value and go backwards through the window) as the book did. My initial technique did not work too well 
when designing a progam that has variable window sizes.

I also understand why the book made them functions since they operate the exact same way but only 
change based on if its a short window or long window.

Takeaway: 
On the next problem, try to solve it just to get the correct answer BUT then try to generalize 
because that will probably break your inital design...

getting the CORRECT answer doesnt mean that 
the progam will ALWAYS give you the correct answer

----------*/

#include<iostream>
#include<fstream>
#include<cmath>
#include<vector>
using namespace std;

int main()
{
    //Decalre and init
    int npts(0), shrt_win(0), long_win(0);
    double interval(0), pwr_short(0), pwr_long(0), ratio(0), threshold(0);
    ifstream fin;

    //Get threshold from user 
    cout << "Please provide the threshold value that signals a seismic event" << endl;
    cin >> threshold;

    //Get short window and long window
    cout << "Enter # of points for short window" << endl;
    cin >> shrt_win;
    cout << "Enter # of points for long window" << endl;
    cin >> long_win;

    //Associate filestream with input file and open
    fin.open("seismic.txt");
    if(fin.fail())
    {
        cerr << "ERROR! Input file failed to open. Exiting program..." << endl;
        exit(1);
    }

    //Read in first lines of input file
    fin >> npts >> interval;

    //Create vector
    vector<int> power(npts,0);      //Fill with 11 datapoints of value zero

    //Populate vector with input file data
    for(int i=0; i < npts; ++i)
    {
        fin >> power[i];
    }

    // //TRBLSHT: Print array to check it is populated
    // for(int i=0; i < npts; ++i)
    // {
    //     cout << power[i] << " ";
    // }
    // cout << endl;
    
    //Determine locations of possible seimic events 
    //Output to user should be the time interval
    for(int i=long_win-1; i < npts; ++i)
    {
        //Short term power
        double shrt_sum(0);
        for(int j=0; j < shrt_win; ++j)
        {
            shrt_sum += pow(power[i-j],2);
        }
        pwr_short = shrt_sum/shrt_win;
               
        //Long term power
        double long_sum(0);
        for(int j=0; j < long_win; ++j)
        {
            long_sum += pow(power[i-j],2);
        }
        pwr_long = long_sum/long_win;
       
        //Ratio
        ratio = pwr_short/pwr_long;

        //Compare ratio to threshold.
        if(ratio > threshold)
        {
            cout << "Event at " << (i*interval) << " seconds " << endl;
        }

    } 

    //close filestream
    fin.close();

    //Exit
    return 0;
}