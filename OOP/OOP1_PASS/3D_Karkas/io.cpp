#include "errors.h"
#include "points.h"
#include "func.h"
#include "edges.h"
#include "io.h"
#include <QDebug>
#include <stdlib.h>


static int read_counts_from_file(FILE *file, int *n, int *m)
{
    if (file)
    {
        if (fscanf(file, "%d %d", n, m) != 2)
        {
            return ERR_READ;
        }
    }
    else
    {
        return ERR_READ;
    }
    return OK;
}

static int read_points_from_file(FILE *file, points_t *points, int n)
{
    if (file)
    {
        for (int i = 0; i < n; i++)
        {
            if (fscanf(file, "%lf %lf %lf", &points[i].x, &points[i].y, &points[i].z) != 3)
            {
                return ERR_READ;
            }
        }
    }
    else
    {
        return ERR_READ;
    }
    return OK;
}

static int read_edges_from_file(FILE *file, edges_t *edges, int m)
{
    if (file)
    {
        for (int i = 0; i < m; i++)
        {
            if (fscanf(file, "%d->%d", &edges[i].first, &edges[i].second) != 2)
            {
                return ERR_READ;
            }
        }
    }
    else
    {
        return ERR_READ;
    }
    return OK;
}

int file_openning_read(FILE **file, char *filename)
{
    *file = fopen(filename, "r");
    if (*file)
    {
        return OK;
    }
    else
        return ERR_OPEN;
}

int file_openning_save(FILE **file, char *filename)
{
    *file = fopen(filename, "w");
    if (*file)
        return OK;
    else
        return ERR_OPEN;
}


void clear_model(model_t model)
{
    if (model.edges != NULL)
        free(model.edges);
    if (model.points != NULL)
        free(model.points);
}

void copy_model(model_t &dist, model_t source)
{
    dist = source;
}

int read_model(model_t &model, FILE *file)
{
    int code_error = read_counts_from_file(file, &model.count_of_points, &model.count_of_edges);

    if (code_error != OK) return code_error;

    model.points = (points_t*)malloc(model.count_of_points * sizeof(points_t));
    model.edges = (edges_t*)malloc(model.count_of_edges * sizeof(edges_t));

    if (model.points != NULL && model.edges != NULL) return code_error;

    {
        code_error = read_points_from_file(file, model.points, model.count_of_points);
        if (code_error != OK)
        {
            clear_model(model);
            return code_error;
        }
        code_error = read_edges_from_file(file, model.edges, model.count_of_edges);
        if (code_error != OK)
        {
            clear_model(model);
            return code_error;
        }
    }
    else
    {
        clear_model(model);
        code_error = ERR_MEMORY;
        return code_error;
    }
    return code_error;
}

int read_model_from_file(model_t &model, parameters_t &parameters)
{
    FILE *file;
    int code_error = file_openning_read(&file, parameters.filename);

    if (code_error != OK) return code_error;

    model_t tmp = init();
    code_error = read_model(tmp, file);
    fclose(file);
    if (code_error == OK)
    {
        clear_model(model);
        copy_model(model, tmp);
    }

    return code_error;
}

int save_changes(model_t &model, parameters_t &parameters)
{
    int code_error = OK;
    if (!model.points || !model.edges)
    {
        code_error = ERR_SAVE;
        return code_error;
    }
    FILE *f;
    code_error = file_openning_save(&f, parameters.filename);
    if (code_error == OK)
    {
        int n = get_count_of_points(model);
        int m = get_count_of_edges(model);
        fprintf(f, "%d %d\n", n, m);
        for (int i = 0; i < n; i++)
        {
            fprintf(f, "%lf %lf %lf\n", get_x_index_point(model, i), get_y_index_point(model, i), get_z_index_point(model, i));
        }
        for (int i = 0; i < m; i++)
        {
            fprintf(f, "%d->%d\n", get_first_index_edge(model, i), get_second_index_edge(model, i));
        }
        fclose(f);
    }
    else
    {
        code_error = ERR_SAVE;
        return code_error;
    }
    return code_error;
}
