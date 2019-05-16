#include <iostream>
#include "math_module.h"

int main()
{
    int begin_x = 2;
    int end_x = 11;
    double step = 1;
    table_t table;
    int code_error = CreateTable(table, begin_x, end_x, step);
    if (code_error == OK)
    {
        fillTable(table, step, 2);
        print_table(table);
    }

    return 0;
}
