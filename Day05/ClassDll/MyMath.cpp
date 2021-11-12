#include "MyMath.h"

#define DLLMYMATH_EXPORTS 

int MyMath::Add(int a, int b)
{
    return a+b;
}

int MyMath::Mul(int a, int b)
{
    return a*b;
}

int MyMath::Sub(int a, int b)
{
    return a-b;
}
