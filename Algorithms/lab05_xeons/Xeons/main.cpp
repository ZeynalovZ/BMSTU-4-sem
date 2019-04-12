#include <iostream>
#include <clocale>
#include <cmath>
using namespace std;
#define OK 0
#define N 40
#define STEP 1 / N
#define K_BOLCMAN 1.38e-23
#define KOEF 7243
#define P1 -3
#define P2 5
#define EPS 0.00001

double get_Tz_temperature(double T0, double Tw, double m, double z)
{
    return T0 + (Tw - T0) * pow(z, m);
}

double my_pow(double z, int m)
{
    double res = 1;
    for (int i = 0; i < m; i++)
    {
        res *= z;
    }
    return res;
}

double* get_nt_array(double p, double T0, double Tw, int m)
{
    double *nt = new double[N];
    for (int i = 0; i < N; i++)
    {
        nt[i] = KOEF * p / (T0 + (Tw - T0) * my_pow(i * STEP, m));
    }
    return nt;
}

double sum_nt(double* nt)
{
    double sum = 0;
    for (int i = 1; i < N - 1; i++)
    {
        sum += nt[i] * i * STEP;
    }
    return sum;
}

void print_array(double* nt)
{
    for (int i = 0; i < N; i++)
    {
        cout << nt[i] << " ";
    }
    cout << endl;
}

double get_P_integral(double Pbeg, double Tbeg, double T0, double Tw, int m, double p)
{
    double *nt = get_nt_array(p, T0, Tw, m);
    print_array(nt);
    double integral_res = STEP * (nt[1] / 2 + sum_nt(nt));
    double tmp_res = KOEF * Pbeg / Tbeg - 2 * integral_res;
    return tmp_res;
}


double get_p_result(double Pbeg, double Tbeg, double T0, double Tw, int m)
{
    double p1 = P1;
    double p2 = P2;
    double p = (p2 + p1) / 2;
    double deltaP = fabs(p2 - p1);
    cout << "current p " << p << endl;
    while (fabs(p2 - p1) - EPS > 0)
    {
        double fp = get_P_integral(Pbeg, Tbeg, T0, Tw, m, p);
        double fp1 = get_P_integral(Pbeg, Tbeg, T0, Tw, m, p2);
        if (fp * fp1 < 0)
        {
            p2 = p;
        }
        else
        {
            p1 = p;
        }
        p = (p1 + p2) / 2;
    }
    cout << p << " is result" << endl;
    return p;
}

int main()
{
    setlocale(LC_ALL, "ru");
    int code_error = OK;
    // Объявим T0 Tw m Tbeg Pbeg
    double T0, Tw, Tbeg, Pbeg;
    double P_result = 0;
    int m;
    cout << "Input T0:" << endl;
    cin >> T0;

    cout << "Input Tw:" << endl;
    cin >> Tw;

    cout << "Input m:" << endl;
    cin >> m;

    cout << "Input Tbeg:" << endl;
    cin >> Tbeg;

    cout << "Input Pbeg:" << endl;
    cin >> Pbeg;

    if (code_error == OK)
    {
        P_result = get_p_result(Pbeg, Tbeg, T0, Tw, m);
    }



    cout << T0 << " " << Tw << " "  << m << " "  << Tbeg << " "  << Pbeg << " "  << endl;
    return 0;
}
