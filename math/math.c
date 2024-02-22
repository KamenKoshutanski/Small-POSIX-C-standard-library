#include "math.h"

#define LN10 (2.3025850929940456840179914546844)
#define M_PI (3.1415927)
#define M_PI_2 (M_PI/2.0)
#define M_PI_M_2 (M_PI*2.0)
#define E (2.71828182846)

//Needs testing

double pow(double x, double y) //doenst work with doubles
{
    int yIsNegative = 0;
    if(y < 0){
        y = -y;
        yIsNegative = 1;
    }
    double ans = 1;
    int i;
    for(i = 0; i < y; i++)
    {
        ans = ans * x;
    }
    if(yIsNegative == 1)
    {
        return 1/ans;
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

    //return pow(2, 0.5 * log2(x)); //pow not working with doubles yet
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

int compare_float(double f1, double f2)
{
    double precision = 0.00000000000000000001;
    if ((f1 - precision) < f2)
    {
        return -1;
    }
    else if ((f1 + precision) > f2)
    {
        return 1;
    }
        else
    {
        return 0;
    }
}

double cos(double x){
    if(x < 0.0)
    { 
        x = -x;
    }

    if (0 <= compare_float(x, M_PI_M_2)) 
    {
        do {
            x -= M_PI_M_2;
        }while(0 <= compare_float(x, M_PI_M_2)); 
    }
    if ((0 <= compare_float(x, M_PI)) && (-1 == compare_float(x, M_PI_M_2)))
    {
        x -= M_PI;
        return ((-1)*(1.0 - (x*x/2.0) * (1.0 - (x*x/12.0) * (1.0 - (x*x/30.0) * (1.0 - (x*x/56.0) * (1.0 - (x*x/90.0) * (1.0 - (x*x/132.0) * (1.0 - (x*x/182.0)))))))));
    } 
        return 1.0 - (x*x/2.0) * (1.0 - (x*x/12.0) * (1.0 - (x*x/30.0) * (1.0 - (x*x/56.0) * (1.0 - (x*x/90.0) * (1.0 - (x*x/132.0) * (1.0 - (x*x/182.0)))))));
}

double sin(double x)
{
    return cos(x - M_PI_2);
}

double exp(double x)
{
    return pow(E, x); //doesnt work with doubles
}