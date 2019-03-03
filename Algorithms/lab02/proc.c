#include "io.h"
#include "proc.h"
#include "err.h"



bool value_existance(double x_value, coordinates *points, int count)
{
    //printf("points[count].x is %f\n", points[count - 1].x);
    //double eps = 0.1;
    for (int i = 0; i < count; i++)
    {
        //printf("x_value is %f points.x is %f\n", x_value, points[i].x);
        if (fabs((x_value - points[i].x)) <= 0)
        {
            //printf("i is %d\n", i);
            return true;
        }
    }
    if (x_value < points[0].x || x_value > points[count - 1].x)
    {
        return false;
    }
    else
    {
        return true;
    }
    return false;
}

void get_h_massive(int count, double *h_array, coordinates *points)
{
    for (int i = 1; i < count; i++)
    {
        h_array[i] = points[i].x - points[i - 1].x;
    }
}

void get_A_massive(int count, double *A_array, double *h_array)
{
    for (int i = 2; i < count; i++)
    {
        A_array[i] = h_array[i - 1];
    }
}

void get_B_massive(int count, double *B_array, double *h_array)
{
    for (int i = 2; i < count; i++)
    {
        B_array[i] = -2 * (h_array[i - 1] + h_array[i]);
    }
}

void get_D_massive(int count, double *D_array, double *h_array)
{
    for (int i = 2; i < count; i++)
    {
        D_array[i] = h_array[i];
    }
}

void get_F_massive(int count, double *F_array, double *h_array, coordinates *points)
{
    for (int i = 2; i < count; i++)
    {
        F_array[i] = -3 * ((points[i].y - points[i - 1].y) / h_array[i] - \
                (points[i - 1].y - points[i - 2].y) / h_array[i - 1]) ;
    }
}

void print_array(double *array, int count)
{
    for (int i = 0; i < count; i++)
    {
        printf("%f ", array[i]);
    }
    printf("\n");
}

int get_pos_x_interval(int x_value, coordinates *points, int count)
{
    for (int i = 0; i < count - 1; i++)
    {
        if (points[i].x <= x_value && x_value < points[i + 1].x)
        {
            return i + 1;
        }
    }
    return count - 1;
}



int main_process(int count, coordinates *points, double x_value)
{
    double h_array[count];
    double A_array[count];
    double B_array[count];
    double D_array[count];
    double F_array[count];
    double ETA[count];
    double KSI[count];
    double U[count];
    double a[count], d[count], b[count];
    U[count] = 0;
    U[0] = 0;
    get_h_massive(count, h_array, points);
    get_A_massive(count, A_array, h_array);
    get_B_massive(count, B_array, h_array);
    get_D_massive(count, D_array, h_array);
    get_F_massive(count, F_array, h_array, points);
    //print_array(h_array, count);
    //print_array(A_array, count);
    //print_array(B_array, count);
    //print_array(D_array, count);
    //print_array(F_array, count);

    KSI[3] = D_array[2] / B_array[2];
    ETA[3] = F_array[2] / B_array[2];

    for (int i = 3; i < count; i++)
    {
        KSI[i + 1] = D_array[i] / (B_array[i] - A_array[i] * KSI[i]);
    }

    for (int i = 3; i < count; i++)
    {
        ETA[i + 1] = (A_array[i] * ETA[i] + F_array[i]) / (B_array[i] - A_array[i] * KSI[i]);
    }

    for (int i = count - 1; i > 0; i--)
    {
        U[i] = KSI[i + 1] * U[i + 1] + ETA[i + 1];
    }
    //printf("KSI and ETA are\n");
    //print_array(KSI, count);
    //print_array(ETA, count);

    for (int i = 1; i < count; i++)
    {
        a[i] = points[i - 1].y;
    }

    for (int i = 1; i < count; i++)
    {
        d[i] = (U[i + 1] - U[i]) / (3 * h_array[i]);
    }

    for (int i = 1; i < count; i++)
    {
        b[i] = (points[i].y - points[i - 1].y)/ h_array[i] - \
                (h_array[i] * (U[i + 1] + 2 * U[i])) / 3;
    }
    //printf("a[i], d[i], b[i], c[i] are\n");
    //print_array(a, count);
    //print_array(d, count);
    //print_array(b, count);
    //print_array(U, count);
    int i = get_pos_x_interval(x_value, points, count);
    //printf("pos is %d\n", i );
    double x_x1 = (x_value - points[i - 1].x);
    double result = a[i] + b[i] * x_x1 + U[i] * x_x1 * x_x1 + d[i] * x_x1 * x_x1 * x_x1;
    printf("\n=== a = %f, b = %f, c = %f, d = %f===\n", a[i], b[i], U[i], d[i]);
    printf("\ny(%f) = %f\n", x_value, result);

    return result;

}


