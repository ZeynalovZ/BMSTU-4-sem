#include "interpolate.h"

void sort_inc(data_d *table)
{
    double tmp; // сортировка с флагом
    int flag = 1;
    while (flag)
    {
        flag = 0;
        for (int i = 1; i < table->count; i++)
        {
            if (table->data_x[i] < table->data_x[i - 1])
            {
               tmp = table->data_x[i];
               table->data_x[i] = table->data_x[i - 1];
               table->data_x[i - 1] = tmp;
               tmp = table->data_y[i];
               table->data_y[i] = table->data_y[i - 1];
               table->data_y[i - 1] = tmp;
               flag = 1;
            }
        }
    }
}

int search_place(double *row, int len, double search, int *left, int *right)
{
    int mid;
    *left = 0, *right = len;
    while (*left <= *right)
    {
        mid = (*left + *right) / 2;
        if (IS_EQUAL(row[mid], search))
        {
            *left = mid;
            *right = mid;
            return IN_TABLE; // искомый элемент уже есть в массиве узлов
        }
        if (row[mid] > search)
            *right = mid - 1;
        else
            *left = mid + 1;
    }
    if (*left > *right)
    {
        int tmp = *left;
        *left = *right;
        *right = tmp;
    }
    if (*right >= len || *left < 0)
        return EXTRAPOLATION; // экстраполяция

    return FOUND; // найдены индексы ближайших элементов
}

int take_dots(double *init_x, double *init_y, int size, data_d *d_select, int pos_l, int pos_r)
{
    int index = 0;
    while ((index < d_select->count) && (pos_l >= 0 || pos_r < size))
    {
        if (pos_l >= 0)
        {
            d_select->data_x[index] = init_x[pos_l];
            d_select->data_y[index] = init_y[pos_l];
            pos_l--;
            index++;
        }
        if (pos_r < size && index < d_select->count)
        {
            d_select->data_x[index] = init_x[pos_r];
            d_select->data_y[index] = init_y[pos_r];
            pos_r++;
            index++;
        }
    }
    if (index != d_select->count)
        return NOT_ENOUGH_DATA;
    return OK;
}

double find(double *argument, double *value, int size, int degree, double search, int *rc)
{
    *rc = OK;
    double div;
    double res = 0.0;
    double *coefficients = (double*)calloc(degree + 1, sizeof(double));
    if (coefficients)
    {
        coefficients[0] = value[0];
        int n = degree;
        for (int i = 1; i < degree + 1 && *rc == OK; i++)
        {
            for (int j = 0; j < n && *rc == OK; j++)
            {
                div = argument[0] - argument[degree + 1 - n];
                if (fabs(div) <= EPS_DOUBLE)
                    *rc = ZERO_DEVISION;
                else
                    value[j] = (value[j] - value[j + 1]) / (div);
            }
            coefficients[i] = value[0];
            n--;
        }
        if (*rc == OK)
        {
            res = coefficients[0];
            int c = 0;
            double mult = 1.0;
            for (int i = 1; i < degree + 1 && c < size; i++)
            {
                mult *= (search - argument[c]);
                res += mult * coefficients[i];
                c++;
            }
        }
        free(coefficients);
    }
    else
        *rc = MEMORY_ERROR;
    return res;
}

double interpolate(double *argument, double *value, int size, int degree, double search)
{
    data_d selected;
    selected.count = degree + 1;
    selected.data_x = (double*)calloc(selected.count, sizeof(double));
    selected.data_y = (double*)calloc(selected.count, sizeof(double));
    if (!(selected.data_x) || !(selected.data_y))
        return 0.0;
    int right, left;
    int rc = OK;
    double result = 0.0;
    rc = search_place(argument, size, search, &left, &right);
    if (rc == IN_TABLE)
        result = value[left];
    else if (rc == FOUND)
    {
        rc = take_dots(argument, value, size, &selected, left, right);
        if (rc == OK)
        {
            sort_inc(&selected);
            result = find(selected.data_x, selected.data_y, selected.count, degree, search, &rc);
        }
        if (rc != OK)
            result = 0.0;
    }
    free(selected.data_x);
    free(selected.data_y);
    return result;
}
