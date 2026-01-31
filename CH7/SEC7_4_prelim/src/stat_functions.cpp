#include "stat_lib.h"
#include<cmath>

double mean(const double x[], int n)
{
    double sum(0);

    //Sum array
    for(int i=0; i<n; ++i)
    {
        sum = sum + x[i];
    }

    //Divide sum by # of elements
    return {sum/n};
}

double median(const double x[], int n)
{
    //Determine if the array have an even or odd # of elements
    double mid1(0), mid2(0), mid3(0);

    if(n%2 == 0)                            
    {
        //Find the 2 middle numbers
        mid1 = x[n/2];
        mid2 = x[(n/2)-1];

        //Find the median
        return {(mid1+mid2)/2};

    }
        else
        {
            //Find the middle number
            return x[(int)floor(n/2)];       
        }

}

double variance(const double x[], int n)
{   
    double sum(0), mu(0);
    mu = mean(x,n);                  
    //Sum all of the variances
    for (int j=0; j<n; ++j)
    {
       sum = sum + ((x[j] - mu) * (x[j] - mu));

    }

    return {sum/(n-1)};
}

double std_dev(const double x[], int n)
{
    return sqrt(variance(x,n));
}