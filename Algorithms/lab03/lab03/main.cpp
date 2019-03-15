#include <iostream>
#include "process.h"
#include <math.h>
#include <assert.h>
#define MAX_COUNT_OF_POINTS 20
#define MAX_LEN_OF_STR 100
#define OK 0
#define ERR_READ -1
#define ERR_EMPTY -2
#define ERR_IO -3
#define ERR_CREATE -4

typedef struct COORDINATES coordinates;

struct COORDINATES
{
    double x;
    double y;
};

double func(double x, double y)
{
    return x * x + y * y;
}
using namespace std;

int count_of_points_in_file(FILE *f, int *n)
{
    float dummy1;
    float dummy2;
    float dummy3;
    int dummy0;
    *n = 0;
    if (f)
    {
        if (fscanf(f, "%d", &dummy0) != 1)
        {
            return ERR_READ;
        }
        while (fscanf(f, "%f %f %f", &dummy1, &dummy2, &dummy3) == 3)
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

void free_matrix(double **matrix, int n)
{
    for (int i = 0; i < n; i++)
    {
        free(matrix[i]);
    }
    free(matrix);
}

double **allocate_matrix(int n)
{
    double **matrix = (double**)malloc(n * sizeof(double *));
    if (matrix != NULL)
    {
        for (int i = 0; i < n; i++)
        {
            matrix[i] = (double*)malloc(n * sizeof(double));
            if (matrix[i] == NULL)
            {
                if (matrix != NULL)
                {
                    free_matrix(matrix, i);
                }
                else
                {
                    return NULL;
                }
            }
        }
    }
    return matrix;
}



int read_coordinates_from_file(FILE *f, double ***matrix, int *count)
{
    int count_repeats = 0;
    float dummy1;
    float dummy2;
    float dummy3;
    int flag = 0;
    double **matrix_temp = NULL;
    if (f )
    {
        if (fscanf(f, "%d", &count_repeats) != 1)
        {
            return ERR_READ;
        }
        matrix_temp = allocate_matrix(count_repeats + 1);
        if (matrix_temp != NULL)
        {
            //rewind(f);
            matrix_temp[0][0] = -1;
            for (int i = 0; i < count_repeats; i++)
            {
                for (int j = 0; j < count_repeats; j++)
                {
                    if (fscanf(f, "%f %f %f", &dummy1, &dummy2, &dummy3) != 3)
                    {
                        return ERR_READ;
                    }
                    if (flag == 0)
                    {
                        //printf("%f", dummy2);
                        matrix_temp[0][j + 1] = dummy2;
                    }
                    matrix_temp[i + 1][j + 1] = dummy3;
                    //printf("%f %f %f\n", matrix_temp[i + 1][0], matrix_temp[0][i + 1], matrix_temp[i + 1][j + 1]);
                }
                flag = 1;
                matrix_temp[i + 1][0] = dummy1;
            }
            *count = count_repeats + 1;
            *matrix = matrix_temp;
            return OK;
        }
        else
        {
            return ERR_CREATE;
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
bool value_existance_x(double x_value, double **matrix, int count, int *pos)
{
    //printf("points[count].x is %f\n", points[count - 1].x);
    double eps = 0.5;
    for (int i = 0; i < count - 1; i++)
    {
        //printf("x_value is %f points.x is %f\n", x_value, points[i].x);
        if (fabs((x_value - matrix[i + 1][0])) <= eps)
        {
            *pos = i + 1;
            return true;
        }
    }
    if (x_value < matrix[1][0] || x_value > matrix[count - 1][0])
    {
        return false;
    }
    else
    {
        return true;
    }
    return false;
}

bool value_existance_y(double y_value, double **matrix, int count, int *pos)
{
    //printf("points[count].x is %f\n", points[count - 1].x);
    double eps = 0.5;
    for (int i = 0; i < count - 1; i++)
    {
        //printf("x_value is %f points.x is %f\n", x_value, points[i].x);
        if (fabs((y_value - matrix[0][i + 1])) <= eps)
        {
            //printf("y pos is %f\n", matrix[0][i + 1]);
            *pos = i + 1;
            return true;
        }
    }
    if (y_value < matrix[0][1] || y_value > matrix[0][count - 1])
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
    *start = pos + 1;
    *end = pos + 1;
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
        else if (flag == 1 && *end + 1 < count)
        {
            flag = 0;
            if (*end  < count)
            {
                *end += 1;
            }
        }
    }
    return 0;
}


void print_matrix(double **matrix, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%f ", matrix[i][j]);
        }
        printf("\n");
    }
}

void get_points_for_y(coordinates *points, double **matrix, int start_x, int end_x, int start_y, int num)
{
    for (int i = 0; i < end_x - start_x + 1; i++)
    {
        points[i].x = matrix[0][start_y + i];
        points[i].y = matrix[start_x + num][start_y + i];
    }
}

void get_points_for_x(coordinates *points, double **matrix, double *zets, int start_x, int end_x)
{
    for (int i = 0; i < end_x - start_x + 1; i++)
    {
        points[i].x = matrix[start_x + i][0];
        points[i].y = zets[i];
    }
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


double interpolation_func(double x_value, int start, int end, coordinates *points)
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
    //printf("result is %lf\n", result);
    return result;
}

void print_array(double *array, int count)
{
    for (int i = 0; i < count; i++)
    {
        printf("%f ", array[i]);
    }
    printf("\n");
}

void print_points(coordinates *points, int count)
{
    for (int i = 0; i < count; i++)
    {
        printf("%f  %f \n", points[i].x, points[i].y);
    }
    printf("\n");
}

int main()
{
    setbuf(stdout, NULL);
    int code_error = OK;
    int count, pos;
    double x_value;
    double y_value;
    double nx_order;
    double ny_order;
    int start_x, end_x;
    int start_y, end_y;
    //char c;
    FILE *f;
    coordinates points[MAX_COUNT_OF_POINTS];
    double zets[MAX_COUNT_OF_POINTS];
    double **matrix = NULL;
    f = fopen("C:\\Users\\user-lab01\\Desktop\\Zeynal\\BMSTU-4-sem\\Algorithms\\lab03\\lab03\\input.txt", "r");
    if (!f)
    {
        printf("Check out file named \"input.txt\"");
        return ERR_READ;
    }
    code_error = read_coordinates_from_file(f, &matrix, &count);
    if (code_error == OK)
    {
        printf("Please input x value\n");
        code_error = user_input(&x_value);
        if (code_error == OK)
        {
            printf("Please input y value\n");
            code_error = user_input(&y_value);
            if (code_error == OK)
            {
                printf("Please input nx value\n");
                code_error = user_input(&nx_order);
                if (code_error == OK)
                {
                    printf("Please input ny value\n");
                    code_error = user_input(&ny_order);
                    if (code_error == OK)
                    {
                        print_matrix(matrix, count);
                        if (value_existance_x(x_value, matrix, count, &pos) == true)
                        {
                           // printf("pos is %d\n", pos);
                            code_error = select_interval(pos, count, nx_order, &start_x, &end_x);
                            if (code_error == OK)
                            {
                                if (value_existance_y(y_value, matrix, count, &pos) == true)
                                {
                                    code_error = select_interval(pos, count, ny_order, &start_y, &end_y);
                                    if (code_error == OK)
                                    {
                                       //printf("start x and end x %d %d\n", start_x, end_x);
                                       //printf("start y and end y %d %d\n", start_y, end_y);
                                       //printf("pos is %d\n", pos);
                                        int count_zets = end_x - start_x + 1;
                                        //printf("counts zets = %d\n", count_zets);
                                        //for (int i = start_x; i < count_zets; i++)
                                        for (int i = 0; i < count_zets; i++)
                                        {
                                            get_points_for_y(points, matrix, start_x, end_x, start_y, i);
                                            //printf("------\n");
                                            //print_points(points, count);
                                            //printf("------");
                                            zets[i] = interpolation_func(y_value, 0, end_y - start_y, points);

                                        }
                                        printf("zets--\n");
                                        print_array(zets, count_zets);
                                        //for (int i = start_x; i < count_zets; i++)
                                        //{
                                        //    printf("%f ", zets[i]);
                                        //}
                                        //printf("\n");

                                        get_points_for_x(points, matrix, zets, start_x, end_x);
                                        //print_points(points, count);
                                        double z = interpolation_func(x_value, 0, end_x - start_x, points);
                                        printf("Z is %f  !!!!\n", z);

                                        printf("Expected result is %f\n", func(x_value, y_value));
                                    }
                                    else
                                    {
                                        printf("ERROR\n");
                                    }
                                }
                                else
                                {
                                    printf(" y doesn't exist\n");
                                }
                            }
                            else
                            {
                                printf("Interval selection error\n");
                            }
                        }
                        else
                        {
                            printf("X doesn't exist\n");
                        }
                    }
                    else
                    {
                        printf("ERROR\n");
                    }
                }
                else
                {
                    printf("ERROR\n");
                }
            }
            else
            {
                printf("ERROR\n");
            }
        }
        else
        {
            printf("ERROR\n");
        }
        //print_matrix(matrix, count);
        free(matrix);
    }
    fclose(f);
    return code_error;
}
