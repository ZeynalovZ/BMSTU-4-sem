#include "errors.h"
#include "points.h"
#include "func.h"
#include "edges.h"
#include "io.h"
#include <QDebug>
#include <stdlib.h>

static void free_all(points_t *points, edges_t *edges)
{
    if (points)
    {
        free(points);
    }
    if (edges)
    {
        free(edges);
    }
}

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

FILE* file_openning_read(char *filename)
{
    FILE *file;
    file = fopen(filename, "r");
    if (file)
        return file;
    else
        return NULL;
}

FILE* file_openning_save(char *filename)
{
    FILE *file;
    file = fopen(filename, "w");
    if (file)
        return file;
    else
        return NULL;
}

int read_model_from_file(model_t &model, parameters_t &parameters)
{
    int code_error = OK;

    FILE *file = file_openning_read(parameters.filename);
    points_t *p_tmp = NULL;
    edges_t *e_tmp = NULL;
    int tmp_count_of_points = 0;
    int tmp_count_of_edges = 0;
    if (file == NULL)
    {
        code_error = ERR_OPEN;
        return code_error;
    }
    code_error = read_counts_from_file(file, &tmp_count_of_points, &tmp_count_of_edges);
    if (code_error != OK)
    {
        fclose(file);
        return code_error;
    }
    p_tmp = (points_t*)malloc(tmp_count_of_points * sizeof(points_t));
    e_tmp = (edges_t*)malloc(tmp_count_of_edges * sizeof(edges_t));
    if (p_tmp != NULL && e_tmp != NULL)
    {
        code_error = read_points_from_file(file, p_tmp, tmp_count_of_points);
        if (code_error != OK)
        {
            free_all(p_tmp, e_tmp);
            fclose(file);
            return code_error;
        }
        code_error = read_edges_from_file(file, e_tmp, tmp_count_of_edges);
        if (code_error != OK)
        {
            free_all(p_tmp, e_tmp);
            fclose(file);
            return code_error;
        }
        else
        {
            model.points = p_tmp;
            model.edges = e_tmp;
            model.count_of_points = tmp_count_of_points;
            model.count_of_edges = tmp_count_of_edges;
            fclose(file);
        }
    }
    else
    {
        free_all(p_tmp, e_tmp);
        code_error = ERR_MEMORY;
        fclose(file);
        return code_error;
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
    f = file_openning_save(parameters.filename);
    if (f)
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
