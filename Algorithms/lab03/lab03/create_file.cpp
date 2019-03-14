#include <iostream>
using namespace std;

int func(int x, int y)
{
    return x * x + y * y;
}

int main(void)
{
    int count = 5;
    FILE *f;
    f = fopen("input.txt", "w");
    fprintf(f, "%d\n", count);
    for (int i = 0; i < count; i++)
    {
        for (int j = 0; j < count; j++)
        {
            fprintf(f, "%d %d %d\n", i, j, func(i, j));
        }
    }
    fclose(f);
    return 0;
}
