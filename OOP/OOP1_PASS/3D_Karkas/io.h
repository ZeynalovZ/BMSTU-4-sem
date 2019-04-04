#ifndef IO_H
#define IO_H
#include "edges.h"
#include "points.h"
#include "model.h"
int read_model_from_file(model_t &model, parameters_t &parameters);
int save_changes(model_t &model, parameters_t &parameters);
typedef struct STREAM stream_t;
struct STREAM
{
    FILE *file = NULL;
};
#endif // IO_H
