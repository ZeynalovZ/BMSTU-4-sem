#include <stdio.h>
#include "io.h"
#include "err.h"
#include <assert.h>
#include <stdlib.h>

double func(double x)
{
    return x*x*x;
}
void print_in_file()
{
    int start = -5;
    int end = 5;
    //int step = 0.3;
    FILE *f;
    f = fopen("in1.txt", "w");
    if (f)
    {
        for (double i = start; i <= end; i+= 1)
        {
            fprintf(f, "%lf %lf\n", i, func(i));
        }
        fclose(f);
    }

}

int user_input(double *num)
{
    char string[MAX_LEN_OF_STR];
    if (fgets(string, MAX_LEN_OF_STR, stdin) != NULL)
    {
        int i = 0;
        int flag = 0;
        while (string[i + 1] != '\0')
        {
            if (string[i] == '-' || string[i] == '.')
            {
                i++;
                continue;
            }
            if (string[i] > '9' || string[i] < '0')
            {
                flag = 1;
                break;
            }
            i++;
        }
        if (flag == 1)
        {
            return ERR_IO;
        }
        *num = atof(string);
        return OK;
    }
    return ERR_IO;
}

int count_of_points_in_file(FILE *f, int *n)
{
    float dummy1;
    float dummy2;
    *n = 0;
    if (f)
    {
        while (fscanf(f, "%f %f", &dummy1, &dummy2) == 2)
        {
            *n = *n + 1;
        }
        if (*n == 0)
        {
            return ERR_EMPTY;
        }
        return OK;
    }
    else
    {
        return ERR_READ;
    }
}

int read_coordinates_from_file(FILE *f, coordinates *points, int *count)
{
    int code_error = OK;
    int count_of_points;
    if (f && points)
    {
         code_error = count_of_points_in_file(f, &count_of_points);
         if (code_error == OK)
         {
            if (count_of_points <= 2)
            {
                return ERR_EMPTY;
            }
            else
            {
                assert(count_of_points <= MAX_COUNT_OF_POINTS);
                rewind(f);
                for (int i = 0; i < count_of_points; i++)
                {
                    if (fscanf(f, "%lf %lf", &points[i].x, &points[i].y) != 2)
                    {
                        return ERR_READ;
                    }
                }
                *count = count_of_points;
                return OK;
            }
         }
         else
         {
             return code_error;
         }
    }
    else
    {
        return ERR_READ;
    }
}
