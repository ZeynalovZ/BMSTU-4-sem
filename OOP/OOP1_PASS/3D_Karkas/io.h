#ifndef IO_H
#define IO_H
#include "model.h"
#include "errors.h"
#include "func.h"
#include <QDebug>
#include <stdlib.h>
int read_model_from_file(model_t &model, parameters_t &parameters);
int save_changes(model_t &model, parameters_t &parameters);
typedef struct STREAM stream_t;
struct STREAM
{
    FILE *file;
};
#endif // IO_H
