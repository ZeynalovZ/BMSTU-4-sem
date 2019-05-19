#include <QDebug>
#include "algorithm.h"

int CheckDirection(QVector<int> signs)
{
    int size = signs.size();
    int CountOfPositive = 0;
    for (int i = 0; i < size; i++)
    {
        if (signs[i] >= 0)
        {
            CountOfPositive++;
        }
    }
    if (CountOfPositive == size)
    {
        return 1; // Right
    }
    else
    {
        return -1; // Left
    }
}
bool CheckSigns(QVector<int> signs)
{
    int size = signs.size();
    int curr;
    int prev = signs[0];
    int CountOfZeroSigns = 0;
    if (prev == 0)
    {
        CountOfZeroSigns++;
    }
    bool flag = true; // is equal
    for (int i = 1; i < size; i++)
    {
        curr = signs[i];
        if (curr != prev && curr != 0 && prev != 0)
        {
            flag = false; // not equal
        }
        else if (curr == 0)
        {
            CountOfZeroSigns++;
        }
        prev = curr;
    }
    if (CountOfZeroSigns == size)
    {
        flag = false; // all of signs are zero
    }
    return flag;
}

int sign(int VectorMult)
{
    if (VectorMult == 0)
    {
        return 0;
    }
    else
    {
        return VectorMult / abs(VectorMult);
    }
}

bool IsConvex(QVector<edge_t> rect, int &obhod)
{
    int size = rect.size();
    QVector<int> signs;
    bool flag = false;
    if (size > 2)
    {
        for (int i = 0; i < size - 1; i++)
        {
            edge_t first = rect[i];
            edge_t second = rect[i + 1];
            int xVector1 = first.x2 - first.x1;
            int yVector1 = first.y2 - first.y1;

            int xVector2 = second.x2 - second.x1;
            int yVector2 = second.y2 - second.y1;

            int VectorMult = xVector1 * yVector2 - yVector1 * xVector2;
            int MultSign = sign(VectorMult);
            signs.append(MultSign);
        }
        // не забываем про последнюю вершину
        edge_t first = rect[size -1];
        edge_t second = rect[0];
        int xVector1 = first.x2 - first.x1;
        int yVector1 = first.y2 - first.y1;

        int xVector2 = second.x2 - second.x1;
        int yVector2 = second.y2 - second.y1;

        int VectorMult = xVector1 * yVector2 - yVector1 * xVector2;
        int MultSign = sign(VectorMult);
        signs.append(MultSign);
        flag = CheckSigns(signs);
        // if is convex
        if (flag == true)
        {
            obhod = CheckDirection(signs);
        }
    }
    return flag;
}


int scalar(QPoint Vector1, QPoint Vector2)
{
    return Vector1.x() * Vector2.x() + Vector1.y() * Vector2.y();
}

void CyrusBekaAlgorithm(QPoint P1, QPoint P2, int obhod, QVector<edge_t> rect, QPainter &painter)
{
    double tb = 0;
    double te = 1;
    double t_curr = 0;
    QPoint D;
    D.setX(P2.x() - P1.x());
    D.setY(P2.y() - P1.y());
    for (int i = 0; i < rect.size(); i++)
    {
        QPoint W;
        W.setX(P1.x() - rect[i].x1);
        W.setY(P1.y() - rect[i].y1);

        QPoint nVector;
        if (i == rect.size() - 1)
        {
            if (obhod == 1)
            {
                nVector.setX(-(rect[0].y1 - rect[i].y1));
                nVector.setY((rect[0].x1 - rect[i].x1));
            }
            else
            {
                nVector.setX((rect[0].y1 - rect[i].y1));
                nVector.setY(-(rect[0].x1 - rect[i].x1));
            }
        }
        else
        {
            if (obhod == 1)
            {
                nVector.setX(-(rect[i + 1].y1 - rect[i].y1));
                nVector.setY((rect[i + 1].x1 - rect[i].x1));
            }
            else
            {
                nVector.setX((rect[i + 1].y1 - rect[i].y1));
                nVector.setY(-(rect[i + 1].x1 - rect[i].x1));
            }
        }
        int Dscalar = scalar(D, nVector);
        int Wscalar = scalar(W, nVector);
        // проверка на вырожденость отрезка в точку
        if (Dscalar == 0)
        {
            //qDebug() << "Dscalar == 0";
            // отрезок выродился в точку
            if (Wscalar < 0)
            {
                //qDebug() << "Wscalar == 0";
                // Точка видима относительно текущей границы
                return;
            }
        }
        else
        {
            t_curr = -(double)Wscalar / Dscalar;
            if (Dscalar > 0)
            {
                if (t_curr > 1)
                {
                    return;
                }
                else
                {
                    tb = qMax(t_curr, tb);
                }
            }
            else if (Dscalar < 0)
            {
                if (t_curr < 0)
                {
                    return;
                }
                else
                {
                    te = qMin(t_curr, te);
                }
            }
        }
    }
    if (tb <= te)
    {
        painter.drawLine(P1.x() + (P2.x() - P1.x()) * te,
                         P1.y() + (P2.y() - P1.y()) * te,
                         P1.x() + (P2.x() - P1.x()) * tb,
                         P1.y() + (P2.y() - P1.y()) * tb);
    }
    else
    {
        qDebug() << "else";
    }
    return;
}
int signVis(double w)
{
    if (w < 0)
    {
        return -1;
    }
    else if (w == 0)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}
int isVisible(QPoint P, QPoint P1, QPoint P2)
{
    double Worker1 = (P.x() - P1.x()) * (P2.y() - P1.y());
    double Worker2 = (P.y() - P1.y()) * (P2.x() - P1.x());
    double Worker3 = Worker1 - Worker2;
    return signVis(Worker3);
}
bool IsIntersectionExist(QPoint P, QPoint S, QPoint P1, QPoint P2)
{
    int vis1 = isVisible(P, P1, P2);
    int vis2 = isVisible(S, P1, P2);
    if (vis1 < 0 && vis2 > 0 || vis1 > 0 && vis2 < 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

QPoint SearchIntersection(QPoint P1, QPoint P2, QPoint Q1, QPoint Q2)
{
    /*
    double delta1 = (P2.x() - P1.x()) * (Q1.y() - Q2.y()) - (Q1.x() - Q2.x() * (P2.y() - P1.y()));
    double delta2 = (Q1.x() - P1.x()) * (Q1.y() - Q2.y()) - (Q1.x() - Q2.x() * (Q1.y() - P1.y()));
    if (abs(delta1) < 1e-6)
    {
        return P2;
    }
    double t = delta2 / delta1;

    QPoint I;
    I.setX(P1.x() + (P2.x() - P1.x()) * t);
    I.setY(P1.y() + (P2.y() - P1.y()) * t);
    return I;
    */
    double koef[2][2];
    koef[0][0] = P2.x() - P1.x();
    koef[0][1] = Q1.x() - Q2.x();
    koef[1][0] = P2.y() - P1.y();
    koef[1][1] = Q1.y() - Q2.y();
    double determinant = koef[0][0] * koef[1][1] - koef[1][0] * koef[0][1];

    double right[2][1];
    right[0][0] = Q1.x() - P1.x();
    right[1][0] = Q1.y() - P1.y();

    double tmp = koef[0][0];
    koef[0][0] = koef[1][1];
    koef[1][1] = tmp;

    tmp = -koef[1][0];
    koef[1][0] = -koef[0][1];
    koef[0][1] = tmp;
    //for (int i = 0; i < 2; i++)
    //{
    //    qDebug() << koef[i][0] << koef[i][1];
    //}
    double k = (double)1 / determinant;
    qDebug() << k << "Koef";
    koef[0][0] *= k;
    koef[1][1] *= k;
    koef[1][0] *= k;
    koef[0][1] *= k;

    double res[2][1];
    res[0][0] = koef[0][0] * right[0][0] + koef[0][1] * right[1][0];
    res[1][0] = koef[1][0] * right[0][0] + koef[1][1] * right[1][0];
    QPoint I;
    I.setX(P1.x() + (P2.x() - P1.x()) * res[0][0]);
    I.setY(P1.y() + (P2.y() - P1.y()) * res[1][0]);
    qDebug() << "===";
    qDebug() << I;
    return I;
}
void check_exist()
{
    QPoint P1(0, 0);
    QPoint P2(3, 2);
    QPoint P3(3, 0);
    QPoint P4(0, 2);
    int vis1 = isVisible(P3, P1, P2);
    int vis2 = isVisible(P4, P1, P2);
    QPoint I = SearchIntersection(P3, P4, P1, P2);
    qDebug() << I << "testtest";
    /*
    if (IsIntersectionExist(P3, P4, P1, P2))
    {
        qDebug() << "yeeeeeees";
    }
    else
    {
        qDebug() << "noo";
    }
    */
}

void Copy(QVector<QPoint> &dist, QVector<QPoint> source)
{
    dist.clear();
    for (int i = 0; i < source.size(); i++)
    {
        dist.append(source[i]);
    }
}

void SutherlandHodgman(QVector<QPoint> &polygon, QVector<QPoint> cutter)
{
    QVector<QPoint> result_polygon;
    check_exist();
    cutter.append(cutter[0]);
    QPoint F;
    QPoint S;
    QPoint I;
    for (int i = 1; i < cutter.size() - 1; i++)
    {
        for (int j = 0; j < polygon.size(); j++)
        {
            if (j != 1)
            {
                if (IsIntersectionExist(S, polygon[j], cutter[i], cutter[i + 1])) // params here
                {
                    I = SearchIntersection(S, polygon[j], cutter[i], cutter[i + 1]); // params here
                    result_polygon.append(I); // params here
                }
            }
            else
            {
                F = polygon[j];
            }
            S = polygon[j];
            if (isVisible(S, cutter[i], cutter[i + 1]) >= 0)
            {
                result_polygon.append(S);
            }
        }
        if (result_polygon.size() != 0)
        {
            if (IsIntersectionExist(S, F, cutter[i], cutter[i + 1]))
            {
                I = SearchIntersection(S, F, cutter[i], cutter[i + 1]);
                result_polygon.append(I);
            }
        }
        Copy(polygon, result_polygon);
        result_polygon.clear();
    }
}
