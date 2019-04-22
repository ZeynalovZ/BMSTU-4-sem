#ifndef MATRIX_H
#define MATRIX_H
# include <memory>
#include "base_container.h"
#include "excepctions.h"
#include "base_iterator.h"
#include <time.h>
#include <typeinfo>
#include "const_matrix_iterator.h"
#include "matrix_iterator.h"
#include "matrix_iterator_implementation.h"
#include "const_matrix_iterator_implementation.h"

template <typename T>
class Matrix : public container_core::base_container
{
public:
    Matrix(unsigned int n, unsigned int m);
    Matrix(unsigned int n, unsigned int m, T** matrix);
    Matrix(const Matrix<T> &mtr);
    Matrix(Matrix<T>&& mtr);
    Matrix(std::initializer_list<std::initializer_list<T>> lst);

    ~Matrix();

    Matrix<T>& operator =(const Matrix<T> &mtr);
    Matrix<T>& operator =(Matrix<T> &&mtr);
    Matrix<T>& operator =(std::initializer_list<std::initializer_list<T>> lst);

    unsigned int get_n() const;
    unsigned int get_m() const;

    const T& get_value_by_indexes(unsigned int i, unsigned int j) const;
    T& operator ()(unsigned int i, unsigned int j);
    const T& operator ()(unsigned int i, unsigned int j) const;

    Matrix<T> operator -(const Matrix<T> &mtr1) const;
    Matrix<T> operator -(const T& num) const;

    Matrix<T> operator +(const Matrix<T>& mtr1) const;
    Matrix<T> operator +(const T& num) const;

    Matrix<T> operator *(const Matrix<T>& mtr1) const;
    Matrix<T> operator *(const T& num) const;

    Matrix<T> operator /(const T& num) const;

    Matrix<T>& operator +=(const Matrix<T>& mtr);
    Matrix<T>& operator -=(const Matrix<T>& mtr);
    Matrix<T>& operator *=(const Matrix<T>& mtr);

    template<typename _T>
    friend std::ostream& operator <<(std::ostream& os, const Matrix<_T>& matr);

    matrix_iterator<T> begin();
    matrix_iterator<T> end();
    const_matrix_iterator<T> begin() const;
    const_matrix_iterator<T> end() const;

    Matrix<T> &create_identity_matrix();
    Matrix<T> &create_inverse_matrix();
    Matrix<T> &transposition();
    T get_gauss_determinant();

    void set_value_by_indexes(unsigned int i, unsigned int j, const T& value);

    bool is_square();

    void auto_fill();

    template <typename _T>
    class Array
    {
    public:
        friend class Matrix;
        Array() = delete;
        Array(_T *array1, unsigned int size1)
            :array(array1), size(size1){}

        Array<_T> operator[](unsigned int index)
        {
            time_t t_time;
            t_time = time(NULL);
            if (index >= this->n) throw mtr_index_out_exception(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time), "INDEX OUT OF RANGE");

            return Array<_T>(this->mtr + index * this->m, this->m);
        }

        Array<_T> operator[](unsigned int index) const
        {
            time_t t_time;
            t_time = time(NULL);
            if (index >= this->n) throw mtr_index_out_exception(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time), "INDEX OUT OF RANGE");

            return Array<_T>(this->mtr + index * this->m, this->m);
        }

    private:
        unsigned int size;
        _T *array = nullptr;
    };


private:

    unsigned int n;
    unsigned int m;
    std::shared_ptr<T> mtr;
};

#include "matrix_implementation.h"
#endif // MATRIX_H











/*
_T operator [](unsigned int index) const
{
    if (index >= elements_count) throw mtr_index_out_exception();
    return this->mtr[index];
}
_T& operator [](unsigned int index)
{
    if (index >= elements_count) throw mtr_index_out_exception();
    return *(this->mtr[index]);
}
*/

/*
T& operator [](unsigned int i);
const T& operator [](unsigned int i) const;

std::shared_ptr<T> mtr;
*/
