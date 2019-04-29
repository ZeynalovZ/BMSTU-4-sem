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
