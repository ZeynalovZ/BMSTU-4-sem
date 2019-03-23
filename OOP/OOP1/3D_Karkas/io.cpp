#include "errors.h"
#include "points.h"
#include "edges.h"
#include <stdlib.h>
#include <stdio.h>
#include "io.h"
#include <iostream>
#include <QDebug>
using namespace std;
int read_counts_from_file(FILE *file, int *n, int *m)
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

int read_points_from_file(FILE *file, points_t *points, int n)
{
    if (file)
    {
        for (int i = 0; i < n; i++)
        {
            if (fscanf(file, "%d %d %d", &points[i].x, &points[i].y, &points[i].z) != 3)
            {
                return ERR_READ;
            }
            //qDebug() << points[i].x << " " << points[i].y << " " << points[i].z << endl;

        }
    }
    else
    {
        return ERR_READ;
    }
    return OK;
}

int read_edges_from_file(FILE *file, edges_t *edges, int m)
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

int read_model_from_file(char *filename, points_t **points, edges_t **edges, int *n, int *m)
{
    int code_error = OK;
    FILE *file;
    file = fopen(filename, "r");
    points_t *p_tmp = NULL;
    edges_t *e_tmp = NULL;
    if (file)
    {
        code_error = read_counts_from_file(file, n, m);
        if (code_error == OK)
        {
            qDebug() << "n and m " << *n << *m << endl;
            p_tmp = (points_t*)malloc(*n * sizeof(points_t));
            e_tmp = (edges_t*)malloc(*m * sizeof(edges_t));
            if (points && edges)
            {

                code_error = read_points_from_file(file, p_tmp, *n);
                if (code_error == OK)
                {

                    code_error = read_edges_from_file(file, e_tmp, *m);
                    if (code_error == OK)
                    {
                        *points = p_tmp;
                        *edges = e_tmp;
                        return OK;
                    }
                }
            }
            else
            {
                return ERR_MEMORY;
            }
        }
        fclose(file);
    }
    else
    {
        qDebug() << "There is no such file";
        return ERR_READ;
    }
    return code_error;
}

void print_points(points_t *points, int n)
{
    for (int i = 0; i < n; i++)
    {
        qDebug() << points[i].x << " " << points[i].y << " " << points[i].z << endl;
    }
}
void print_edges(edges_t *edges, int n)
{
    for (int i = 0; i < n; i++)
    {
        qDebug() << edges[i].first << " " << edges[i].second << endl;
    }
}


int save_changes(char *filename, points_t *points, edges_t *edges, int n, int m)
{
    if (!points || !edges)
    {
        return ERR_SAVE;
    }
    FILE *f;
    f = fopen(filename, "w");
    if (f)
    {
        fprintf(f, "%d %d", n, m);
        for (int i = 0; i < n; i++)
        {
            fprintf(f, "%d %d %d", points[i].x, points[i].y, points[i].z);
        }
        for (int i = 0; i < m; i++)
        {
            fprintf(f, "%d->%d", edges[i].first, edges[i].second);
        }
        fclose(f);
    }
    else
    {
        return ERR_SAVE;
    }
    return OK;
}
