#include <iostream>
#include <cstdlib>

using namespace std;

#define OK 0
#define ERR_MEM -1

class Matrix
{
  public:
    // returns code_error;
    int create_matrix(int n, int m)
    {
        int **tmp_mtr = NULL;
        int code_error = OK;
        if (n == 0 || m == 0) return ERR_MEM;
        tmp_mtr = (int**)malloc(n * sizeof(int*));
        if (!tmp_mtr) return ERR_MEM;
        int *line_of_mtr = NULL;
        for (int i = 0; i < n && code_error == OK; i++)
        {
            line_of_mtr = (int*)malloc(m * sizeof(int));
            if (line_of_mtr)
            {
                tmp_mtr[i] = line_of_mtr;
            }
            else
            {
                code_error = ERR_MEM;
            }
        }
        if (code_error == OK)
        {
            mtr = tmp_mtr;
            row_num = n;
            column_num = m;
        }
        else
        {
            delete_matrix(tmp_mtr, n);
        }
        return code_error;
    }

    void sum_matrix(Matrix mtr1, Matrix mtr2)
    {
        if (mtr1.row_num == mtr2.row_num && mtr1.column_num == mtr2.column_num)
        {
            row_num = mtr1.row_num;
            column_num = mtr1.column_num;
            create_matrix(row_num, column_num);
            for (size_t i = 0; i < row_num; i++)
                for (size_t j = 0; j < column_num; j++)
                    mtr[i][j] = mtr1.mtr[i][j] + mtr2.mtr[i][j];
        }
    }

    void close_matrix()
    {
        delete_matrix(mtr, column_num);
    }

    void auto_fill()
    {
        for (size_t i = 0; i < row_num; i++)
            for (size_t j = 0; j < column_num; j++)
                mtr[i][j] = rand() % 9 + 1;
    }
    void show_matrix()
    {
        cout << "Matrix is " << endl << endl;
        for (size_t i = 0; i < row_num; i++)
        {
            for (size_t j = 0; j < column_num; j++)
            {
                cout << mtr[i][j] << " ";
            }
            cout << endl;
        }
    }
  private:
    int **mtr = NULL;
    size_t row_num = 0;
    size_t column_num = 0;

    void delete_matrix(int **mtr, int n)
    {
        for (int i = 0; i < n; i++)
        {
            free(mtr[i]);
        }
        free (mtr);
    }

};

int main()
{

    Matrix mtr1, mtr2, m_res;
    mtr1.create_matrix(2, 2);
    mtr1.auto_fill();
    mtr1.show_matrix();


    mtr2.create_matrix(2, 2);
    mtr2.auto_fill();
    mtr2.show_matrix();

    m_res.sum_matrix(mtr1, mtr2);
    m_res.show_matrix();

    mtr1.close_matrix();
    mtr2.close_matrix();
    m_res.close_matrix();
    return 0;
}
