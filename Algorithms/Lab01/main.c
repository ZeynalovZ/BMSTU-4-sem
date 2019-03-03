#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include "stdbool.h"

#define MAX_COUNT_OF_POINTS 20
#define MAX_LEN_OF_STR 100
#define OK 0
#define ERR_READ -1
#define ERR_EMPTY -2
#define ERR_IO -3
//todo
// Добавить экстраполяцию для дробны
// изменять столбцы и прогонять тот же алгоритм для отсортированного points[i].x
//
//
//

typedef struct COORDINATES coordinates;

struct COORDINATES
{
    double x;
    double y;
};

double func(double x)
{
    return x*x;
}
void print_in_file()
{
    int start = -5;
    int end = 5;
    //int step = 0.2;
    FILE *f;
    f = fopen("input4.txt", "w");
    if (f)
    {
        for (double i = start; i <= end; i++)
        {
            fprintf(f, "%lf %lf\n", func(i), i);
        }
        fclose(f);
    }

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
            if (count_of_points == 0)
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

bool value_existance(double x_value, coordinates *points, int count, int *pos)
{
    //printf("points[count].x is %f\n", points[count - 1].x);
    double eps = 0.5;
    for (int i = 0; i < count; i++)
    {
        //printf("x_value is %f points.x is %f\n", x_value, points[i].x);
        if (fabs((x_value - points[i].x)) <= eps)
        {
            *pos = i;

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

int select_interval(int pos, int count, int n_order, int *start, int *end)
{
    //assert(n_order + 1 < count);
    //printf("n_order is %d\n", n_order);
    *start = pos;
    *end = pos;
    int flag = 0;
    // идем в цикле до порядок + 1
    for (int i = 0; i < n_order; i++)
    {
        if (flag == 0 )
        {
            flag = 1;
            if (*start - i > 0)
            {
                *start -= 1;
            }
        }
        if (flag == 1 && *end + 1 < count)
        {
            flag = 0;
            if (*end  < count)
            {
                *end += 1;
            }
        }
        /*
        if (*end + 1 == count)
        {
            *start = *start - 1;
        }
        else
        {
            *end = *end + 1;
        }
        */
    }
    //printf("in select====\n");
    //printf("start is %d, end is %d\n", *start, *end);
    //printf("start is %d, end is %d\n", *start, *end);
    return 0;
}

double get_x_part(double x_value, int counter, int curr_pos, coordinates *points)
{
    double res = 1;
    for (int i = 0; i <= counter; i++)
    {
        res *= x_value - points[curr_pos + i].x;
    }
    //printf("res x_part is %lf\n", res);
    return res;
}



double get_y_part1(int start, int end, coordinates *points, double (*mat_y)[10], int count)
{
    int n_order = end - start;
    printf("n is %d\n", n_order);
    for (int i = 0; i < count; i++)
    {
        mat_y[i][0] = points[i].x;
        mat_y[i][1] = points[i].y;
        printf("mat[i][1] & [2] are %lf, %lf\n", mat_y[i][0], mat_y[i][1]);
    }
    int j = 2;
    int i;
    for (i = 0; i < n_order; i++)
    {
        printf("!!! %lf & %lf\n", mat_y[i + start][j - 1], mat_y[i + start + 1][j - 1]);
        mat_y[i][j] = (mat_y[i + start][j - 1] - mat_y[i + start + 1][j - 1]) / (mat_y[i + start][j - 2] - mat_y[i + start + 1][j - 2]);
        printf("mat_y n = 1 %lf\n", mat_y[i][j]);
    }
    int count1 = i;
    int k;
    for (int i = 0; i < n_order - 1; i++)
    {
        double res = 0;
        for (k = 0; k < count1 - 1; k++)
        {
            if (k == 0)
            {
                res += mat_y[k][j];
            }
            else
            {
                res -= mat_y[k][j];
            }
        }
        res = res / (points[start].x - points[start + j - 1].x);
        count1 = k;
        j++;
        mat_y[i][j] = res;
    }
    return 0;
}
int interpolation_func(double x_value, int start, int end, coordinates *points)
{
    double result = 0;
    //printf("start is %d!\n", start);
    result += points[start].y;

    int n = end - start;
    double razn[n + 1];
    double a[n + 1];
    //double mat_y[10][10];
    //get_y_part1(start, end, points, mat_y, count);
    for (int i = 0; i < n + 1; i++)
    {
        a[i] = points[start + i].y;
    }
    int count = 0;
    int pos = 0;
    int j = 0;
    int flag = 1;

    for (int i = 0; i < n && flag; i++)
    {
        pos = 0;
        for (count = 0; count < n - i; count++)
        {
            if (points[start + count + i + 1].x - points[start + count].x == 0)
            {
                flag = 0;
                return ERR_EMPTY;
            }
            a[count] = (a[pos + 1] - a[pos]) / (points[start + count + i + 1].x - points[start + count].x);
            pos++;
        }
        razn[j] = a[0];
        j++;
    }
    for (int i = 0; i < n; i++)
    {
        result += get_x_part(x_value, i, start, points) * razn[i];
        //printf("result !! is %lf\n", result);
        //get_y_part(i, start, i + 1, points);
                //get_x_part(x_value, i, start, points) *
    }
    printf("result is %lf\n", result);
    return 0;
}

int main(void)
{
    setbuf(stdout, NULL);
    int code_error = OK;
    bool interpolation = false;
    int count, pos, start, end;
    double x_value;
    double n_order;
    //char c;
    FILE *f;
    coordinates points[MAX_COUNT_OF_POINTS];
    print_in_file();
    f = fopen("input.txt", "r");
    if (!f)
    {
        printf("Check out file named \"input.txt\"");
        return ERR_READ;
    }
    code_error = read_coordinates_from_file(f, points, &count);
    if (code_error == OK)
    {
        printf("file consists of:\n");
        for (int i = 0; i < count; i++)
        {
            printf("points.x and points.y: %lf, %lf\n", points[i].x, points[i].y);
        }

        //printf("Input x watching the table above this\n");
        // Сделать проверку на входные данные, порядок не может быть больше чем кол-во узлов в файле! Выдавать ошибки
        // Обработать все else'ы
        int cou = 0;
        do
        {
            if (cou > 0)
            {
               printf("===== EXTRAPOLATION =====\n");
            }
            cou++;
            printf("Input x watching the table above this\n");

            code_error = user_input(&x_value);
        }
        while ((interpolation = value_existance(x_value, points, count, &pos)) == false);

        if (code_error == OK)
        {
            printf("input n order\n");
            code_error = user_input(&n_order);
            if (n_order + 1 > count)
            {
                printf("Order is greater than count in files\n");
                return ERR_READ;
            }
            else if (n_order < 0)
            {
                printf("Order couldn't be less than 0\n");
                return ERR_READ;
            }
            else
            {
                if (code_error == OK)
                {

                    if (interpolation == false)
                    {
                        printf("Here could be extrapolation\n");
                    }
                    else
                    {

                        select_interval(pos, count, n_order, &start, &end);
                        printf("start and end are %d %d\n", start, end);
                        interpolation_func(x_value, start, end, points);

                        printf("expected result: %lf\n", func(x_value));
                        /*
                        printf("Do you want to get the root ?\n  Input Y/n:\n ");
                        if (scanf("%c", &c) == 1)
                        {
                            if (c == 'Y')
                            {
                                printf("Y was choosed\n");
                            }
                            else
                            {
                                printf("bye\n");
                            }
                        }
                        else
                        {
                            printf("bye\n");
                        }
                        */
                    }
                }
                else
                {
                    printf("order param is not right\n");
                }
            }
        }
        else
        {
           printf("x value is not right\n");
        }
    }
    else if (code_error == ERR_EMPTY)
    {
        printf("File consists of unacceptable input data");
    }
    else
    {
        printf("Can't read from File\n");
    }

    fclose(f);
    return code_error;
}
