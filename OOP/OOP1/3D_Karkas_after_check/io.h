#ifndef IO_H
#define IO_H
#include "edges.h"
#include "points.h"
int read_model_from_file(char *filename, points_t **points, edges_t **edges, int *n, int *m);
void print_points(points_t *points, int n);
void print_edges(edges_t *edges, int n);
int save_changes(char *filename, points_t *points, edges_t *edges, int n, int m);
#endif // IO_H
