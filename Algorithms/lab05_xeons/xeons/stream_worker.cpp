#include "stream_worker.h"
#include <iostream>
#include "errors.h"

using namespace std;


int read_data(double *Pbeg, double *Tbeg, double *T0, double *Tw, int *m, const char *filename)
{
    int code_error = OK;
    FILE *f;
    f = fopen(filename, "r");
    if (f)
    {
        if (fscanf(f, "%lf %lf %lf %lf %d", Pbeg, Tbeg, T0, Tw, m) != 5)
        {
            code_error = ERR_READ;
        }
        cout << Pbeg << Tbeg << T0 << Tw << m << "data" << endl;
    }
    else
    {
        code_error = ERR_FILE_OPENING;
    }
    return code_error;
}
