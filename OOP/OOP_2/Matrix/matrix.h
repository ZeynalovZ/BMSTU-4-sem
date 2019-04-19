#ifndef MATRIX_H
#define MATRIX_H
# include <memory>
#include "base_container.h"
#include "excepctions.h"
#include "base_iterator.h"
#include "matrix_iterator.h"
#include "const_matrix_iterator.h"
// в этом пока не вижу смысла !
// в exceptions добавить конкатенацию итогого сообщения
// избавиться максимально от friend
using namespace container_core;

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
    T& operator [](unsigned int i);
    const T& operator [](unsigned int i) const;


    template<typename _T>
    Matrix<_T> operator -(const Matrix<_T>& mtr1);
    template<typename _T>
    const Matrix<_T> operator -(const Matrix<_T>& mtr1, const _T& num);

    template<typename _T>
    friend Matrix<_T> operator +(const Matrix<_T>& mtr1, const Matrix<_T>& mtr2);
    template<typename _T>
    friend Matrix<_T> operator +(const Matrix<_T>& mtr1, _T num);

    template<typename _T>
    friend Matrix<_T> operator *(const Matrix<_T>& mtr1, const Matrix<_T>& mtr2);
    template<typename _T>
    friend Matrix<_T> operator *(const Matrix<_T>& mtr1, _T num);

    template<typename _T>
    friend Matrix<_T> operator /(const Matrix<_T>& mtr1, _T num);

    Matrix<T>& operator +=(const Matrix<T>& mtr);
    Matrix<T>& operator -=(const Matrix<T>& mtr);

    template<typename _T>
    friend std::ostream& operator <<(std::ostream& os, const Matrix<_T>& matr);

    matrix_iterator<T> begin();
    matrix_iterator<T> end();

    const_matrix_iterator<T> begin() const;
    const_matrix_iterator<T> end() const;

   // virtual void print_matrix();

    static Matrix<T> create_identity_matrix();

    template <typename _T>
    Matrix<_T> create_inverse_matrix();

    T get_gauss_determinant();

    Matrix<T>& transposition();

    void set_value_by_indexes(unsigned int i, unsigned int j, const T& value);

    bool is_square();
    template <typename _T>
    class Array
    {
    public:
        Array() = delete;
        Array(_T *array1, unsigned int size1)
            :array(array1), size(size1){}

        Array<_T> operator[](unsigned int index)
        {
            if (index >= this->n) throw mtr_index_out_exception();

            return Array<_T>(this->mtr + index * this->m, this->m);
        }

        Array<_T> operator[](unsigned int index) const
        {
            if (index >= this->n) throw mtr_index_out_exception();

            return Array<_T>(this->mtr + index * this->m, this->m);
        }
    private:
        unsigned int size;
        _T *array = nullptr;
    };

private:
    unsigned int n;
    unsigned int m;
    T* mtr;
    void auto_fill();
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
