#include "math_module.h"
#include <cmath>
#include <iostream>

using namespace std;

static double a0 = 1;
static double a1 = 2;
static double a2 = 3;

double f(double x)
{    
    return (a0 * x) / (a1 + a2 * x);
}


double diffFunc(double x)
{
    // f'(x);
    return (a0 * a1) / pow((a1 + a2 * x), 2);
}

int CreateTable(table_t &table, int begin, int end, double step)
{
    if (begin >= end || step <= 0) return ERR_CREATION;
    if (table.table == nullptr)
    {
        table.rowCount = (end - begin) / step;
        double **mtr = (double**) malloc(table.rowCount * sizeof(double *));

        for (unsigned int i = 0; i < table.rowCount; i++)
        {
            mtr[i] = (double*) calloc(table.columnCount, sizeof(double));
        }
        table.table = mtr;

        if (table.table == nullptr)
        {
            return ERR_ALLOCATION;
        }

        double currentX = begin;
        for (unsigned int i = 0; i < table.rowCount; i++)
        {
            cout << currentX << endl;
            table.table[i][0] = currentX;
            table.table[i][1] = f(currentX);
            currentX += step;
        }

    }
    return OK;
}

void print_table(table_t table)
{
    printf("|------------------------------------------------------------------------|\n");
    printf("|   x       y      y'(x)   Accurate    Mid    Runge   Alignment  Pure    |\n");
    printf("|------------------------------------------------------------------------|\n");
    for (unsigned int i = 0; i < table.rowCount; i++)
    {
        for (unsigned int j = 0; j < table.columnCount; j++)
        {
            if (j == 0)
            {
                printf("|");
            }
            printf("%-8.4f ", table.table[i][j]);
            if (j == table.columnCount - 1)
            {
                printf("|");
            }
        }
        cout << endl;
        printf("|________________________________________________________________________|\n");
    }
}



double rightDiff(double y, double yNext, double h)
{
    // Правая разность
    return (yNext - y) / h;
}

double midDdiff(double yPrev, double yNext, double h)
{
    return (yNext - yPrev) / (2.0 * h);
}

double RungeDiff(double yNext, double y, double yNnext, double r, double h)
{
    /*
        double y1 = (yNext - yPREV) / ( 2 * h);
        double y2 = (yNr - yPr) / (2 * h * r);
        return y1 + (y1 - y2) / (pow(r, 2) - 1);
    */
    double y1 = (yNext - y) / h;
    double y2 = (yNnext - y) / (h * r);
    return y1 + (y1 - y2) / (pow(r, 2) - 1);
}
// С повышенной точностью на границах
double border_accuracy_first(double y0, double y1, double y2, double h)
{
    return (-3 * y0 + 4 * y1 - y2) / (2 * h);
}

double border_accuracy_last(double y0, double y1, double y2, double h)
{
    return (3 * y0 - 4 * y1 + y2) / (2 * h);
}
double func(int *a, double x)
{
    return (a[0] * x) / (a[1] + a[2] * x);
}
double getH(double x1, double x2)
{
    return fabs(x1 - x2);
}


double ksi(double x)
{
    return 1 / x;
}

double eta(double x)
{
    return 1 / f(x);
}

double ksiDiff(double x)
{
    return -1 / pow(x, 2);
}

double etaDiff(double y)
{
    return -1 / pow(y, 2);
}

double EtaKsiDiff()
{
    return a1 / a0;
}

double getAlignment(double x, double y, double rightX, double rightY)
{
    return ((y * y) / (x * x)) * rightDiff(diffFunc(rightY), diffFunc(y), getH(diffFunc(x), diffFunc(rightX)));
}

void fillTable(table_t &table, double h, unsigned int r)
{
    for (unsigned int i = 0; i < table.rowCount; i++)
    {
        // 1
        if (i != table.rowCount - 1)
        {
            table.table[i][2] = rightDiff(table.table[i][1], table.table[i + 1][1], getH(table.table[i + 1][0], table.table[i][0]));
        }

        // 2 С повышенной точностью на границах
        if (i == 0)
        {
            //double h = getH(table.table[0][0], table.table[0][1]);
            table.table[i][3] = border_accuracy_first(table.table[0][1], table.table[1][1], table.table[2][1], h);
        }
        if (i == table.rowCount - 1)
        {
            //double h = getH(table.table[i][0], table.table[i - 1][1]);
            table.table[i][3] = border_accuracy_last(table.table[i][1], table.table[i - 1][1], table.table[i - 2][1], h);
        }
        // 3 Центральная разность
        if (i != 0 && i != table.rowCount - 1)
        {
            table.table[i][4] = midDdiff(table.table[i - 1][1], table.table[i + 1][1], h);
        }
        // 4. 2-я формула Рунге
        if (i < table.rowCount - r)
        {
            table.table[i][5] = RungeDiff(table.table[i + 1][1], table.table[i][1], table.table[i + r][1], r, h);
        }
        // 5
        /*
        if (i == table.rowCount - 1)
        {
            table.table[i][6] = -getAlignment(table.table[i][0], table.table[i][1], table.table[i - 1][0], table.table[i - 1][1]);
        }
        else
        {
            table.table[i][6] = getAlignment(table.table[i][0], table.table[i][1], table.table[i + 1][0], table.table[i + 1][1]);
        }
        */
        table.table[i][6] = EtaKsiDiff() * ksiDiff(table.table[i][0]) / etaDiff(table.table[i][1]);
        table.table[i][7] = diffFunc(table.table[i][0]);
    }
    /*
    for (unsigned int i = 0; i < table.rowCount; i++)
    {
        if (i != 0 && i != table.rowCount - 1)
        {
            ksi_strih_x = midDdiff(ksi(table.table[i - 1][0]), ksi(table.table[i + 1][0]), h);
            ksi_array[i] = ksi_strih_x;
        }
    }
    for (unsigned int i = 0; i < table.rowCount; i++)
    {
        if (i != 0 && i != table.rowCount - 1)
        {
            eta_shtrih_y = midDdiff(eta(table.table[i - 1][1]), eta(table.table[i + 1][1]), h);
            table.table[i][6] = midDdiff(eta(ksi_array[i - 1]), eta(ksi_array[i + 1]), h) * ksi_array[i] / eta_shtrih_y;
        }

    }
    */

}
