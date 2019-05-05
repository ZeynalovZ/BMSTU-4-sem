#include "errors.h"
#include "math_module.h"
#include <cmath>
#define N 40
#define STEP 1 / N
#define K_BOLCMAN 1.38e-23
#define KOEF 7243
#define P1 3
#define P2 25
#define EPS 0.0001
#include <iostream>
using namespace std;


void print_array(double* nt)
{
    for (int i = 0; i < N; i++)
    {
        cout << nt[i] << " ";
    }
    cout << endl;
}

double get_Tz_temperature(double T0, double Tw, double m, double z)
{
    return T0 + (Tw - T0) * pow(z, m);
}

double find_nt(double p, double t)
{
    return ((KOEF * p) / t);
}

double* get_nt_array(double p, double T0, double Tw, int m)
{
    double *nt = (double*) malloc(N * sizeof(double));
    double z = 0.0;
    double tmp_T;
    for (int i = 0; i <= N; i++)
    {
        tmp_T = get_Tz_temperature(T0, Tw, m, z);
        nt[i] = find_nt(p, tmp_T);
        z += 1 / N;
    }
    return nt;
}

double find_integral(double T0, double Tw, int m, double p)
{
    double step = 1.0 / (double)N;
    double *nt_array = get_nt_array(p, T0, Tw, m);
    cout << "nt[32]" << nt_array[32] << endl;
    double result = 0.0;
    double z = step;
    double temp_res = (step * nt_array[0]) / 2.0;
    for (int i = 1; i < N; i++)
    {
        result += nt_array[i] * z;
        z += step;
    }
    result *= step;
    result += temp_res;
    cout << result << endl;
    free(nt_array);
    return result;
}
double get_P_integral(double T0, double Tw, int m, double p, double coef)
{
    return coef - 2.0 * find_integral(T0, Tw, m, p);
}


double get_p_result(double Pbeg, double Tbeg, double T0, double Tw, int m)
{
    double coef = KOEF * (Pbeg / Tbeg);
    double p1 = P1;
    double p2 = P2;
    double p_mid = (p2 + p1) / 2;
    //double deltaP = fabs(p2 - p1);
    double fp1 = get_P_integral(T0, Tw, m, p1, coef);
    double fp2 = get_P_integral(T0, Tw, m, p2, coef);
    double fp_mid = get_P_integral(T0, Tw, m, p_mid, coef);
    while (fabs(fp_mid) - EPS > 0)
    {
        cout << endl;
        if (fp1 * fp_mid < 0)
        {
            p2 = p_mid;
        }
        else if (fp2 * fp_mid < 0)
        {
            p1 = p_mid;
        }
        else
        {
            cout << "not found" << endl;
            break;
        }
        p_mid = (p1 + p2) / 2;
        fp1 = get_P_integral(T0, Tw, m, p1, coef);
        fp2 = get_P_integral(T0, Tw, m, p2, coef);
        fp_mid = get_P_integral(T0, Tw, m, p_mid, coef);
    }
    return p_mid;
}
