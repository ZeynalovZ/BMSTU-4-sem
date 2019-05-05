#include <iostream>

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
    for (unsigned int i = 0; i < table.rowCount; i++)
    {
        for (unsigned int j = 0; j < table.columnCount; j++)
        {
            printf("%-7.4f ", table.table[i][j]);
        }
        cout << endl;
    }
}

double first(double y, double yNext, double h)
{
    return (yNext - y) / h;
}

void fillTable(table_t &table, int h)
{
    for (unsigned int i = 0; i < table.rowCount; i++)
    {
        if (i != 0)
        {
            table.table[i][2] = first(table.table[i - 1][1], table.table[i][1], h);
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
        fillTable(table, step);
        print_table(table);
    }

    return 0;
}
