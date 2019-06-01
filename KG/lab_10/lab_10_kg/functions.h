#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <cmath>

typedef double(*FuncPointer)(double, double);
class Functions
{
public:
    Functions()
    {
        Arr[0] = &f1;
        Arr[1] = &f2;
        Arr[2] = &f3;
    }

    FuncPointer GetFunc(int FuncIndex)
    {
        return Arr[FuncIndex];
    }

private:
    FuncPointer Arr[3];
    static double f1(double x, double z)
    {
        return cos(x) * cos(x) - sin(z) * sin(z);
    }
    static double f2(double x, double z)
    {
        return cos(x) * sin(z);
    }
    static double f3(double x, double z)
    {
        return x * z;
    }
};
#endif // FUNCTIONS_H
