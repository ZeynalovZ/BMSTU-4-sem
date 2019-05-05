#include <iostream>
#include <cmath>

#define OK 0
#define ERR_ALLOCATION -1
#define ERR_CREATION -2
#define COLUMN_COUNT 8

using namespace std;



typedef struct TABLE table_t;
struct TABLE
{
    double **table = nullptr;
    unsigned int rowCount;
    unsigned int columnCount = COLUMN_COUNT;
};

double f(double x)
{
    return x * x;
}

int CreateTable(table_t &table, int begin, int end, int step)
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

        int currentX = begin;
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
    printf("|   x       y      y'(x)    unknown    Mid     Runge  Alignment  Pure    |\n");
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

double RungeDiff(double yNext, double yPREV, double yNr, double yPr, double r, double h)
{
        double y1 = (yNext - yPREV) / ( 2 * h);
        double y2 = (yNr - yPr) / (2 * h * r);
        return y1 + (y1 - y2) / (pow(r, 2) - 1);
}

double func(int *a, double x)
{
    return (a[0] * x) / (a[1] + a[2] * x);
}
double getH(double x1, double x2)
{
    return fabs(x1 - x2);
}
double getAlignment(double x, double y, double rightX, double rightY)
{
    return -((y*y) / (x*x)) * rightDiff(f(rightY), f(y), getH(f(x), f(rightX)));
}
void fillTable(table_t &table, int h, unsigned int r)
{
    int a[3] = {1, 2, 3};
    for (unsigned int i = 0; i < table.rowCount; i++)
    {
        // 1
        if (i != 0)
        {
            table.table[i][2] = rightDiff(table.table[i - 1][1], table.table[i][1], h);
        }

        // 2

        // 3 Центральная разность
        if (i != 0 && i != table.rowCount - 1)
        {
            table.table[i][4] = midDdiff(table.table[i - 1][1], table.table[i + 1][1], h);
        }
        // 4. 2-я формула Рунге
        if (i > r - 1 && i < table.rowCount - r)
        {
            table.table[i][5] = RungeDiff(table.table[i + 1][1], table.table[i - 1][1],
                    table.table[i + r][1], table.table[i - r][1], r, h);
        }
        // 5
        //table.table[i][6] = func(a, table.table[i][0]);

        if (i == table.rowCount - 1)
        {
            table.table[i][6] = -getAlignment(table.table[i][0], table.table[i][1], table.table[i - 1][0], table.table[i - 1][1]);
        }
        else
        {
            table.table[i][6] = getAlignment(table.table[i][0], table.table[i][1], table.table[i + 1][0], table.table[i + 1][1]);
        }
    }
}

int main()
{
    int begin_x = 0;
    int end_x = 10;
    int step = 1;
    table_t table;
    int code_error = CreateTable(table, begin_x, end_x, step);
    if (code_error == OK)
    {
        fillTable(table, step, 2);
        print_table(table);
    }

    return 0;
}
