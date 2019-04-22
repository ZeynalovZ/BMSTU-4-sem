#include <iostream>
#include <cstdlib>

#include "matrix.h"
#include "base_container.h"
using namespace std;

#define OK 0
#define ERR_MEM -1
int main()
{
    // here try_cathes
    try
    {
        Matrix<int> mtr(5, 5);
        cout << mtr;

        Matrix<int> mtr1(5, 5);
        cout << mtr1;

        Matrix<int> mtr2(mtr1);
        cout << mtr2;

        std::cout << "==================\n";

        mtr2 += mtr1;
        mtr2 -= mtr1;
        cout << mtr2;
        Matrix<int> mtr3({{1, 2, 3},
                          {5, 6, 7},
                          {8, 9, 10}});

        int value = mtr3.get_value_by_indexes(0, 0);
        cout << mtr3;

        std::cout << "value is " << value << std::endl;
        bool yes_or_not = mtr3.is_square();
        std::cout << "Is square? - " << (yes_or_not ? "yes" : "not") << std::endl;

        Matrix <int> mtr4({{1, 2},
                           {2, 4}});
        cout << mtr4;

        Matrix <int> mtr5({{1, 2},
                           {2, 4}});

        mtr2 = mtr4 * mtr5;
        cout << mtr2;

        Matrix <int> mtr6({{1, 1, 1, 1, 1},
                           {2, 2, 2, 2, 2},
                           {3, 3, 3, 3, 3},
                           {4, 4, 4, 4, 4},
                           {5, 5, 5, 5, 5}});
        mtr6.transposition();
        cout << mtr6;
        Matrix<int> mtr7 = mtr6.transposition();
        cout << mtr7;

        cout << mtr3;

        Matrix<int> mtr8_gauss = {{5, 1},
                                  {1, 5}};
        int value1 = mtr8_gauss.get_gauss_determinant();
        std::cout << value1 << std::endl << std::endl;

        Matrix<int> mtr9(5, 5);
        std::cout << mtr9;
    }
    catch (base_exception &exception)
    {
        std::cout << exception.what();
    }

    try
    {
        Matrix<int> mtr3({{1, 2, 3},
                          {5, 6, 7},
                          {8, 9, 10}});
        Matrix <int> mtr6({{1, 1, 1, 1, 1},
                           {2, 2, 2, 2, 2},
                           {3, 3, 3, 3, 3},
                           {4, 4, 4, 4, 4},
                           {5, 5, 5, 5, 5}});
        mtr3.set_value_by_indexes(0, 0, 10);
        int value = mtr3.get_value_by_indexes(0, 0);
        int value1 = mtr6(0, 00);
        std::cout << value1 << " Is outputed mtr[6,6]" << std::endl << std::endl;
        std::cout << value << " Is outputed mtr3[0,0]" << std::endl << std::endl;
    }
    catch(base_exception &exception)
    {
        std::cout << exception.what();
    }
    try
    {
        Matrix<int> mtr4(2, 2);
        mtr4.create_identity_matrix();
        Matrix<int> mtr5(2, 2);
        mtr5.auto_fill();
        cout << mtr5;
        mtr5 += mtr4;
        cout << mtr5 - mtr4;

        auto iter = mtr5.begin();
        for (; iter != mtr5.end(); iter++)
        {
            std::cout << *iter << " ";
        }
        cout << endl;

        Matrix<int> mtr1 ({{1, 2}, {2, 5}});
        Matrix<int> mtr2 ({{2, 5}, {1, 2}, {2, 5}});
        Matrix<int> mtr3 = mtr2 + mtr1;
        cout << mtr3;
    }
    catch(base_exception &exception)
    {
        std::cout << exception.what();
    }

    // get by indexes


    /*
    auto iter = mtr9.begin();
    for (; iter != mtr9.end(); iter++)
    {
        std::cout << 1 << " ";
    }
    */
    return 0;
}

