#ifndef FUNC_H
#define FUNC_H
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
        Arr[3] = &f4;
    }

    FuncPointer GetFunc(int FuncIndex)
    {
        return Arr[FuncIndex];
    }

private:
    FuncPointer Arr[4];
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
        return cos(x) * cos(x) * z * z;
    }
    static double f4(double x, double z)
    {
        return exp(cos(x)) + sin(z) * x;
    }
};

#endif // FUNC_H
