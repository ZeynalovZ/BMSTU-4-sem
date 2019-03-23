#include "process.h"
#include "math.h"

void rotate_x(points_t *points, int n, float angle, points_t center)
{
    float sina, cosa;
    float z, y;
    cosa = cos(angle * M_PI / 180);
    sina = sin(angle * M_PI / 180);
    for (int i = 0; i < n; i++)
    {
        y = points[i].y * cosa - points[i].z * sina;
        z = points[i].y * sina + points[i].z * cosa;
        points[i].y = y;
        points[i].z = z;
    }
}

void rotate_y(points_t *points, int n, float angle, points_t center)
{
    float sina, cosa;
    float z, x;
    cosa = cos(angle * M_PI / 180);
    sina = sin(angle * M_PI / 180);
    for (int i = 0; i < n; i++)
    {
        x = points[i].x * cosa - points[i].z * sina;
        z = points[i].x * sina + points[i].z * cosa;
        points[i].x = x;
        points[i].z = z;
    }
}

void rotate_z(points_t *points, int n, float angle, points_t center)
{
    float sina, cosa;
    float x, y;
    cosa = cos(angle * 180 / M_PI);
    sina = sin(angle * 180 / M_PI);
    for (int i = 0; i < n; i++)
    {
        x = points[i].x * cosa - points[i].y * sina;
        y = points[i].x * sina + points[i].y * cosa;
        points[i].x = x;
        points[i].y = y;
    }
}

void transform_point(points_t *points, int n, double dx, double dy, double dz)
{
    for (int i = 0; i < n; i++)
    {
        points[i].x += dx;
        points[i].y += dy;
        points[i].z += dz;
    }
}

void scale(points_t *points, int n, double koef)
{
    for (int i = 0; i < n; i++)
    {
        points[i].x = points[i].x * koef;
        points[i].y = points[i].y * koef;
        points[i].z = points[i].z * koef;
    }
}
