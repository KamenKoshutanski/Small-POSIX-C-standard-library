#include "math.h"

#define LN10 2.3025850929940456840179914546844

//Needs testing

double pow(double x, int y)
{
    double ans = 1;
    int i;
    for(i = 0; i < y; i++)
    {
        ans = ans * x;
    }

    return ans;
}

double ln(double x)
{
    double old_sum = 0.0;
    double xmlxpl = (x - 1) / (x + 1);
    double xmlxpl_2 = xmlxpl * xmlxpl;
    double denom = 1.0;
    double frac = xmlxpl;
    double term = frac;               
    double sum = term;

    while ( sum != old_sum )
    {
        old_sum = sum;
        denom += 2.0;
        frac *= xmlxpl_2;
        sum += frac / denom;
    }
    return 2.0 * sum;
}

double log10(double x) 
{
    return ln(x) / LN10;    
}

double log2(double x){
    return log10(x)/log10(2);
}

double sqrt(double x)
{
    int start = 0, end = x;
    int mid;
    float ans;

    while (start <= end) {
        mid = (start + end) / 2;
        if (mid * mid == x) {
            ans = mid;
            break;
        }
        if (mid * mid < x) {
            ans=start;
            start = mid + 1;
        }
 
        else {
            end = mid - 1;
        }
    }
 
    float increment = 0.1;
    for (int i = 0; i < 5; i++) {
        while (ans * ans <= x) {
            ans += increment;
        }
 
        ans = ans - increment;
        increment = increment / 10;
    }
    return ans;

    //return pow1(2, 0.5 * log2(x)); //pow not working with doubles yet
}

double ceil(double x)
{
    return ((double)(int)x) + 1;
}

double fabs(double x)
{
    if(x < 0){
        return x *= -1;
    }
    else
    {
        return x;
    }
}

double floor(double x)
{
    return (double)(int)x;
}

double fmod(double x, double y) //not correctly implemented
{
    double result = x / y;
    if(result * y == x)
    {
        return 0;
    }
    else
    {
        double remainder = x - (result * y);
        return remainder;
    }
}

double log(int base, double x)
{
    return log10(x)/log10(base);
}
