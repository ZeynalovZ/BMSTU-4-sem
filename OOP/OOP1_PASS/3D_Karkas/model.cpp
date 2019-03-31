#include "model.h"
model_t init()
{
    model_t model;
    model.edges = nullptr;
    model.points = nullptr;
    model.count_of_edges = 0;
    model.count_of_points = 0;
    return  model;
}
