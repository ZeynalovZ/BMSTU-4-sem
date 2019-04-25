#ifndef MATH_MODULE_H
#define MATH_MODULE_H
double get_Tz_temperature(double T0, double Tw, double m, double z);
double my_pow(double z, int m);
double* get_nt_array(double p, double T0, double Tw, int m);
double sum_nt(double* nt);
void print_array(double* nt);
double get_P_integral(double T0, double Tw, int m, double p, double coef);
double get_p_result(double Pbeg, double Tbeg, double T0, double Tw, int m);
#endif // MATH_MODULE_H
