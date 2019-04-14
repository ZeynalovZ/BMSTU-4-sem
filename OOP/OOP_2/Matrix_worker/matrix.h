#ifndef MATRIX_H
#define MATRIX_H
#include "base_container.h"
#include "exceptions.h"
template <typename T>
class Matrix : public container_core::base_container
{
public:
    Matrix(unsigned int n, unsigned int m);
    Matrix(const Matrix<T> &mtr);
    Matrix(Matrix<T>&& mtr);
    explicit Matrix(std::initializer_list<std::initializer_list<T>> lst);

    ~Matrix();

    Matrix<T>& operator =(const Matrix<T> &mtr);
    Matrix<T>& operator +=(const Matrix<T>& mtr);
    Matrix<T>& operator -=(const Matrix<T>& mtr);
    template<typename _T>
    friend Matrix<_T> operator *(const Matrix<_T>& mtr1, const Matrix<_T>& mtr2);
    template<typename _T>
    friend Matrix<_T> operator +(const Matrix<_T>& mtr1, const Matrix<_T>& mtr2);
    template<typename _T>
    friend Matrix<_T> operator -(const Matrix<_T>& mtr1, const Matrix<_T>& mtr2);

    void print_matrix();
    void transposition();

    unsigned int get_n() const;
    unsigned int get_m() const;

    T get_value_by_indexes(unsigned int i, unsigned int j) const;
    void set_value_by_indexes(unsigned int i, unsigned int j, const T& value) const;


    bool is_square();

private:
    unsigned int n;
    unsigned int m;
    T* mtr;
    void auto_fill();


};




#include "matrix_implementation.h"


#endif // MATRIX_H
