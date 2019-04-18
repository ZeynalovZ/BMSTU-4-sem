#ifndef MATRIX_H
#define MATRIX_H
# include <memory>
#include "base_container.h"
#include "excepctions.h"
// в этом пока не вижу смысла !
using namespace container_core;

template <typename T>
class Matrix : public container_core::base_container
{
public:
    Matrix(unsigned int n, unsigned int m);
    //Matrix(unsigned int n, unsigned int m, T** matrix = nullptr);
    Matrix(const Matrix<T> &mtr);
    Matrix(Matrix<T>&& mtr);
    Matrix(std::initializer_list<std::initializer_list<T>> lst);

    ~Matrix();

    Matrix<T>& operator =(const Matrix<T> &mtr);
    //Matrix<T>& operator =(Matrix<T>&& mtr);
    Matrix<T>& operator =(std::initializer_list<std::initializer_list<T>> lst);

    unsigned int get_n() const;
    unsigned int get_m() const;
    const T& get_value_by_indexes(unsigned int i, unsigned int j) const;
    //T& get_value_by_indexes(unsigned int i, unsigned int j);
    T& operator ()(unsigned int i, unsigned int j);
    T operator ()(unsigned int i, unsigned int j) const;
    T& operator [](unsigned int i);
    T operator [](unsigned int i) const;


    template<typename _T>
    friend Matrix<_T> operator -(const Matrix<_T>& mtr1, const Matrix<_T>& mtr2);
    template<typename _T>
    friend Matrix<_T> operator -(const Matrix<_T>& mtr1, _T num);

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

    template<typename _T>
    friend std::ostream& operator <<(std::ostream& os, const Matrix<_T>& matr);



    Matrix<T>& operator +=(const Matrix<T>& mtr);
    Matrix<T>& operator -=(const Matrix<T>& mtr);

//      Перегрузить вместо этого <<
    void print_matrix();
    void create_identity_matrix();

    template <typename _T>
    Matrix<_T> create_inverse_matrix();

    T get_gauss_determinant();

    Matrix<T>& transposition();

    void set_value_by_indexes(unsigned int i, unsigned int j, const T& value) const;

    bool is_square();

    // Добавить класс для Спросить у Тассова

private:
    unsigned int n;
    unsigned int m;
    T* mtr;
    void auto_fill();
};














#include "matrix_implementation.h"
#endif // MATRIX_H
