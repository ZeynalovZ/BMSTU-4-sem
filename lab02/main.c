#include <stdio.h>
#include <stdlib.h>

#include "io.h"
#include "err.h"
#include "proc.h"


int main(int argc, char **argv)
{
    print_in_file();
    setbuf(stdout, NULL);
    int code_error = OK;
    FILE *f;
    coordinates points[MAX_COUNT_OF_POINTS];
    int count = 0;
    double x_value = 0;
    if (argc != 2)
    {
        printf("Input like this: <app.exe input.txt>");
        code_error = ERR_READ;
    }
    else
    {
        f = fopen(argv[1], "r");
        if (f)
        {
             code_error = read_coordinates_from_file(f, points, &count);
             if (code_error == OK)
             {
                 for (int i = 0; i < count; i++)
                 {
                     printf("%f %f\n", points[i].x, points[i].y);
                 }
                 printf("input x_value\n");
                 code_error = user_input(&x_value);
                 if (code_error == OK)
                 {
                    printf("x_value is %f\n", x_value);
                    main_process(count, points, x_value);
                    printf("expected result is %f\n", func(x_value));
                 }

             }
            fclose(f);
        }
        else
        {
            printf("can't read from file\n");
            code_error = ERR_READ;
        }
    }

    return code_error;
}
