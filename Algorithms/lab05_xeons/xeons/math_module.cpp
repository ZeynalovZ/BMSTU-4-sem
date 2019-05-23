#include "errors.h"
#include "math_module.h"
#include "interpolate.h"}
#include <cmath>
#define N 40
#define STEP 1 / N
#define K_BOLCMAN 1.38e-23
#define KOEF 7243
#define P1 3
#define P2 25
#define EPS 0.001
#include <iostream>
#define A_MATRIX_SIZE 6
#define XEONS_COUNT 5
using namespace std;

#define TABLE_Q_SIZE 13
#define DEGREE 2

static double Q_table[][TABLE_Q_SIZE] = { { 2000, 4000, 6000, 8000, 10000, 12000, 14000, 16000, 18000, 20000, 22000, 24000, 26000 },\
                                { 1.0000, 1.0000, 1.0000, 1.0001, 1.0025, 1.0198, 1.0895, 1.2827, 1.6973, 2.4616, 3.6552, 5.3749, 7.6838 },\
                                { 4.0000, 4.0000, 4.1598, 4.3006, 4.4392, 4.5661, 4.6817, 4.7923, 4.9099, 5.0511, 5.2354, 5.4841, 5.8181 },\
                                { 5.5000, 5.5000, 5.5116, 5.9790, 6.4749, 6.9590, 7.4145, 7.8370, 8.2289, 8.5970, 8.9509, 9.3018, 9.6621 },\
                                { 11.0, 11.0, 11.0, 11.0, 11.0, 11.0, 11.0, 11.0, 11.0, 11.0, 11.0, 11.0, 11.0 },\
                                { 15.0, 15.0, 15.0, 15.0, 15.0, 15.0, 15.0, 15.0, 15.0, 15.0, 15.0, 15.0, 15.0 }
                              };


static double x_initial[] = { 2, -1, -10, -25, 35 };
static double v_initial = -1;
static double alpha_coef = 0.285e-11;
static double Z_table[] = { 0.0, 1.0, 2.0, 3.0, 4.0 };

static double E_table[] = { 12.13, 20.98, 31.00, 45.00 };

double res_gamma;
double res_n[6];
void print_array(double* nt)
{
    for (int i = 0; i < N; i++)
    {
        cout << nt[i] << " ";
    }
    cout << endl;
}
void print_matrix(double mtr[][A_MATRIX_SIZE])
{
    for (int i = 0; i < A_MATRIX_SIZE; i++)
    {
        for (int j = 0; j < A_MATRIX_SIZE; j++)
            cout << mtr[i][j] << " ";
        cout << endl;
    }
}
double calculate_gamma(double gamma, double *v_x, double T)
{
    double sum = exp(v_x[0]) / (1 + 0.5 * gamma);
    double z2;
    for (int i = 1; i < XEONS_COUNT; i++)
    {
        z2 = Z_table[i] * Z_table[i];
        sum += ((exp(v_x[i + 1]) * z2) / (1 + z2 * gamma * 0.5));
    }
    double T3 = T * T * T;
    double coef = 5.87 * 1e10 / T3;
    return gamma * gamma - coef * sum;
}

void fill_r(double *r_vector, double *x, double *k, double v, double coef, double alpha)
{
    for (int i = 0; i < 4; i++)
        r_vector[i] = -(v + x[i + 1] - x[i] - log(k[i]));
    double tmp = 0;
    for (int i = 1; i < XEONS_COUNT; i++)
        tmp += Z_table[i] * exp(x[i]);
    r_vector[4] = -exp(v) + tmp;
    tmp = 0;
    for (int i = 0; i < XEONS_COUNT; i++)
        tmp += exp(x[i]);
    r_vector[5] = coef + exp(v) + tmp - alpha;
}

char xi_bigger_eps(double *dx, double *x)
{
    char ret = 0;
    for (int i = 0; i < XEONS_COUNT; i++)
        if (fabs(dx[i] / x[i]) >= EPS)
            ret = 1;
    return ret;
}


void get_A_matrix(double A[][A_MATRIX_SIZE], double *x, double v)
{
    for (int i = 0; i < 4; i++)
    {
        A[i][0] = 1; // coeff before x in linelize
    }
    int j = 1;
    for (int i = 0; i < 4; i++)
    {
        A[i][j] = -1;
        A[i][j + 1] = 1;
        j++;
    }
    A[4][0] = exp(v);
    A[4][1] = 0;
    for (int i = 1; i < XEONS_COUNT; i++)
        A[4][i + 1] = Z_table[i] * exp(x[i]);
    A[5][0] = -exp(v);
    for (int i = 0; i < XEONS_COUNT; i++)
    {
        A[5][i + 1] = -exp(x[i]);
    }
}
void gauss(double *result, double (*mtr)[6], double *r_vector, int n)
{
    int i = 0;
    while ( i < n)
    {
        double max_elem = 0.0;
        int max_index = 0;
        for (int k = i; k < n; k++)
        {
            if (fabs(mtr[k][i]) >= max_elem)
            {
                max_elem = fabs(mtr[k][i]);
                max_index = k;
            }
        }
        if (max_index != i)
        {
            double tmp;
            for (int k = 0; k < n; k++)
            {
                tmp = mtr[i][k];
                mtr[i][k] = mtr[max_index][k];
                mtr[max_index][k] = tmp;
            }
            tmp = r_vector[i];
            r_vector[i] = r_vector[max_index];
            r_vector[max_index] = tmp;
       }
        double tmp = mtr[i][i];
        for (int k = i + 1; k < n; k++)
        {
            double coef = mtr[k][i] / tmp;
            for (int h = i; h < n; h++)
                mtr[k][h] -= coef * mtr[i][h];
            r_vector[k] -= coef * r_vector[i];
        }
        i++;
    }
    for (int i = n - 1; i > -1; i--)
    {
        for (int j = n - 1; j > i; j--)
            r_vector[i] -= result[j] * mtr[i][j];
        result[i] = r_vector[i] / mtr[i][i];
    }
}

double dichotomy(double a, double b, double *v_x, double T, double (*function)(double, double *, double))
{
    double f_a = function(a, v_x, T);
    double f_b = function(b, v_x, T);
    double c = (a + b) * 0.5;
    double f_c = function(c, v_x, T);
    while (fabs(f_c) > EPS)
    {
        if (f_a * f_c < 0.0)
        {
            b = c;
            f_b = f_c;
        }
        else if (f_b * f_c < 0.0)
        {
            a = c;
            f_a = f_c;
        }
        else
            break;
        c = (a + b) * 0.5;
        f_c = function(c, v_x, T);
    }
    return c;
}
void calculate_Q(double *Q, double T)
{
    for (int i = 0; i < XEONS_COUNT; i++)
    {
        double tmp = interpolate(Q_table[0], Q_table[i + 1], TABLE_Q_SIZE, DEGREE, T);
        Q[i] = tmp;
    }
}
void calculate_Delta_E(double *E, double T, double gamma)
{
    double k = 8.61 * 1e-5;
    gamma *= 0.5;
    for (int i = 0; i < 4; i++)
    {
        double top = k * T * log(1 + Z_table[i + 1] * Z_table[i + 1] * gamma) * (1 + gamma);
        double down = 1 + Z_table[i] * Z_table[i] * gamma;
        E[i] = top / down;
    }
}

void calculate_k(double *K, double T, double gamma)
{
    double cur_Q[XEONS_COUNT] = { 0 };
    double cur_delta_E[4] = { 0 };
    double power = 11603.0 / T;
    double coef = 4.83 * 1e-3;
    double T_32 = pow(T, 1.5);
    calculate_Q(cur_Q, T);
    calculate_Delta_E(cur_delta_E, T, gamma);
    for (int i = 0; i < XEONS_COUNT; i++)
        K[i] = coef * (cur_Q[i + 1] / cur_Q[i]) * T_32 * exp((cur_delta_E[i] - E_table[i]) * power);
}

double systemSolver(double T, double P)
{
    double gamma = 0;
    double alpha = 0;
    double A[A_MATRIX_SIZE][A_MATRIX_SIZE] = { 0 };
    double K_table[6];
    double r_vector[6];
    double coef = -KOEF * P / T;

    double v_x[6];
    v_x[0] = v_initial;
    for (int i = 1 ; i < 6; i++)
        v_x[i] = x_initial[i - 1];

    double delta[6] = { 0 };

    get_A_matrix(A, x_initial, v_initial);
    calculate_k(K_table, T, gamma);
    fill_r(r_vector, x_initial, K_table, v_initial, coef, alpha);
    printf("A:\n");
    print_matrix(A);
    do
    {
        gauss(delta, A, r_vector, 6);
        for (int i = 0; i < 6; i++)
            v_x[i] += delta[i];
        gamma = dichotomy(0.0, 3.0, v_x, T, calculate_gamma);
        alpha = alpha_coef * pow(gamma * T, 3);
        calculate_k(K_table, T, gamma);
        get_A_matrix(A, v_x + 1, v_x[0]);
        fill_r(r_vector, v_x + 1, K_table, v_x[0], coef, alpha);
        //printf("A:\n");
        //print_matrix(A);
    }
    while (fabs(delta[0] / v_x[0]) >= EPS || xi_bigger_eps(delta + 1, v_x + 1));

    double result = 0;
    double tmp;
    res_n[0] = exp(v_x[0]);
    for (int i = 1; i < 6; i++)
    {
        tmp = exp(v_x[i]);
        result += tmp;
        res_n[i] = tmp;
    }
    res_gamma = gamma;
    return result;
}

double get_Tz_temperature(double T0, double Tw, double m, double z)
{
    return T0 + (Tw - T0) * pow(z, m);
}

double find_nt(double p, double t)
{
    //systemSolver();
    return systemSolver(t, p);
    //return ((KOEF * p) / t);
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
        z += (double)1 / N;
    }
    return nt;
}

double find_integral(double T0, double Tw, int m, double p)
{
    double step = 1.0 / (double)N;
    double *nt_array = get_nt_array(p, T0, Tw, m);
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
