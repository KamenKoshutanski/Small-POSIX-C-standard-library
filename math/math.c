#include "math.h"

#define LN10 (2.3025850929940456840179914546844)
#define M_PI (3.1415927)
#define M_PI_2 (M_PI/2.0)

double log(double x)
{
    double oldSum = 0.0;
    double xmlxpl = (x - 1) / (x + 1);
    double xmlxpl_2 = xmlxpl * xmlxpl;
    double denom = 1.0;
    double frac = xmlxpl;
    double term = frac;               
    double sum = term;
    double tolerance = 1e-10;

    while(fabs(sum - oldSum) > tolerance)
    {
        oldSum = sum;
        denom += 2.0;
        frac *= xmlxpl_2;
        sum += frac / denom;
    }
    return 2.0 * sum;

}

double log10(double x) 
{
    return log(x) / LN10;    
}

double log2(double x){
    return log10(x) / log10(2);
}

double pow(double x, double y) 
{
    return exp(y * log(x));
}

double sqrt(double x)
{
    return pow(x, 0.5);
}

double ceil(double x)
{
    if(x >= 0) 
    {
        int intPart = (int)x;
        if(x == intPart) 
        {
            return x; 
        } 
        else 
        {
            return intPart + 1;
        }
    } 
    else 
    {
        int intPart = (int)x;
        return (double)(intPart);
    }
}

double fabs(double x)
{
    if(x < 0)
    {
        return x *= -1;
    }
    else
    {
        return x;
    }
}

double floor(double x)
{
    if(x >= 0) 
    {
        return (double)(int)x;
    } 
    else 
    {
        int intPart = (int)x;
        if(x == intPart) 
        {
            return x;
        } 
        else 
        {
            return (double)(intPart - 1); 
        }
    }
}

double fmod(double x, double y) //not correctly implemented
{
    return x - y * floor(x / y);
}

double log_base(int base, double x)
{
    return log10(x) / log10(base);
}

double cos(double x) {
    while(x < 0.0) 
    {
        x += 2 * M_PI;
    }
    while(x >= 2 * M_PI) 
    {
        x -= 2 * M_PI;
    }

    if(x > M_PI)
    {
        x = 2 * M_PI - x;
    }

    double result = 1.0;
    double term = 1.0;
    int i;
    for(i = 1; i < 10; i++) 
    {
        term *= -x * x / ((2 * i - 1) * (2 * i));
        result += term;
    }

    return result;
}

double sin(double x)
{
    return cos(x - M_PI_2);
}

double exp(double x)
{
    double result = 1.0;
    double term = 1.0;

    for(int i = 0; i < 10; i++)
    {
        term *= x / i;
        result += term;
    }
    
    return result;
}