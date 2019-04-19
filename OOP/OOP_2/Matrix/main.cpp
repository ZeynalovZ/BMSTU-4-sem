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

    Matrix<int> mtr(5, 5);
    mtr.print_matrix();

    Matrix<int> mtr1(5, 5);
    mtr1.print_matrix();

    Matrix<int> mtr2(mtr1);
    mtr2.print_matrix();

    Matrix<int> mtr3({{1, 2, 3},
                      {5, 6, 7},
                      {8, 9, 10}});

    mtr3.set_value_by_indexes(0, 0, 10);
    int value = mtr3.get_value_by_indexes(0, 0);
    mtr3.print_matrix();
    std::cout << "value is " << value << std::endl;
    bool yes_or_not = mtr3.is_square();
    std::cout << "Is square? - " << (yes_or_not ? "yes" : "not") << std::endl;

    std::cout << "==================\n";

    mtr2 += mtr1;
    mtr2 -= mtr1;
    mtr2.print_matrix();

    Matrix <int> mtr4({{1, 2},
                       {2, 4},
                       {5, 6}});
    mtr4.print_matrix();
    Matrix <int> mtr5({{1, 2},
                       {2, 4}});
    mtr2 = mtr4 * mtr5;
    mtr2.print_matrix();

    Matrix <int> mtr6({{1, 1, 1, 1, 1},
                       {2, 2, 2, 2, 2},
                       {3, 3, 3, 3, 3},
                       {4, 4, 4, 4, 4},
                       {5, 5, 5, 5, 5}});
    mtr6.transposition();
    mtr6.print_matrix();

    // get by indexes
    int value1 = mtr6(0, 00);
    std::cout << value1 << " Is outputed mtr[6,6]" << std::endl << std::endl;
    Matrix<int> mtr7 = mtr6.transposition();
    cout << mtr7;

    cout << mtr3;

    Matrix<int> mtr8_gauss = {{5, 1},
                              {1, 5}};
    value1 = mtr8_gauss.get_gauss_determinant();
    std::cout << value1 << std::endl << std::endl;

    Matrix<int> mtr9(5, 5);
    mtr9.create_identity_matrix();
    std::cout << mtr9;
    /*
    auto iter = mtr9.begin();
    for (; iter != mtr9.end(); iter++)
    {
        std::cout << 1 << " ";
    }
    */
    return 0;
}

