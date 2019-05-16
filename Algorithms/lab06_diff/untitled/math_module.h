#ifndef __MATH_MODULE_H__
#define __MATH_MODULE_H__

#define OK 0
#define ERR_ALLOCATION -1
#define ERR_CREATION -2
#define COLUMN_COUNT 8
typedef struct TABLE table_t;
struct TABLE
{
    double **table = nullptr;
    unsigned int rowCount;
    unsigned int columnCount = COLUMN_COUNT;
};

void fillTable(table_t &table, double h, unsigned int r);
int CreateTable(table_t &table, int begin, int end, double step);
void print_table(table_t table);

#endif
