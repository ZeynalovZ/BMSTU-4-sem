#ifndef MATRIX_IMPLEMENTATION_H
#define MATRIX_IMPLEMENTATION_H
#include "matrix.h"
#include <math.h>
template <typename T>
Matrix<T>::Matrix(unsigned int n, unsigned int m)
{
    if (n == 0 || m == 0) throw mtr_wrong_sizes_exception("on line 8 in \"matrix_implementation\"");
    this->elements_count = n * m;
    this->n = n;
    this->m = m;

    try
    {
        this->mtr = new T[elements_count];
        this->auto_fill();
    }
    catch (std::bad_alloc)
    {
        throw memory_allocate_exception("on line 20 in \"matrix_implementation\"");
    }
}

template <typename T>
Matrix<T>::Matrix(const Matrix<T> &mtr):base_container()
{
    this->n = mtr.get_n();
    this->m = mtr.get_m();
    this->elements_count = mtr.size();

    try
    {
        this->mtr = new T[elements_count];
    }
    catch(std::bad_alloc)
    {
        throw memory_allocate_exception("on line 37 in \"matrix_implementation\"");
    }
    for (unsigned int i = 0; i < this->n; ++i)
    {
        for (unsigned int j = 0; j < this->m; ++j)
        {
            this->mtr[i * m + j] = mtr.mtr[i * m + j];
        }
    }
}
template<typename T>
Matrix<T>::Matrix(Matrix<T>&& mtr)
{
    this->n = mtr.get_n();
    this->m = mtr.get_m();
    this->elements_count = mtr.size();
    try
    {
        this->mtr = new T[n * m];
    }
    catch (std::bad_alloc)
    {
        throw memory_allocate_exception("on line 59 in \"matrix_implementation\"");
    }

    for (unsigned int i = 0; i < n; ++i)
    {
        for (unsigned int j = 0; j < m; ++j)
        {
            this->mtr[i * m + j] = mtr.mtr[i * m + j];
        }
    }
}

template<typename T>
Matrix<T>::Matrix(unsigned int n, unsigned int m, T **matrix)
{
    if (n == 0 || m == 0) throw mtr_wrong_sizes_exception("on line 74 in \"matrix_implementation\"");
    this->elements_count = n * m;
    this->n = n;
    this->m = m;

    try
    {
        this->mtr = new T[elements_count];
        this->auto_fill();
        *matrix = this->mtr;
    }
    catch (std::bad_alloc)
    {
        throw memory_allocate_exception("on line 87 in \"matrix_implementation\"");
    }
}

template<typename T>
Matrix<T>::Matrix(std::initializer_list<std::initializer_list<T>> lst)
{
    this->n = lst.size();
    this->m = lst.begin()->size();
    this->elements_count = n * m;
    auto iter_i = lst.begin();
    try
    {
        this->mtr = new T[n * m];
    }
    catch (std::bad_alloc)
    {
        throw memory_allocate_exception("on line 104 in \"matrix_implementation\"");
    }
    for (unsigned int i = 0; iter_i != lst.end(); i++, iter_i++)
    {
        if (this->m != iter_i->size()) throw mtr_size_exception("on line 108 in \"matrix_implementation\"");
        else
        {
            auto iter_j = iter_i->begin();
            for (unsigned int j = 0; iter_j != iter_i->end(); ++j, ++iter_j)
            {
                this->mtr[i * this->m + j] = *iter_j;
            }
        }
    }
}

template<typename T>
const T& Matrix<T>::get_value_by_indexes(unsigned int i, unsigned int j) const
{
    if (i >= this->n || j >= this->m)
    {
        throw mtr_index_out_exception("on line 125 in \"matrix_implementation\"");
    }
    else
    {
        if (this->mtr)
        {
            return mtr[i * this->m + j];
        }
        else
        {
            throw memory_allocate_exception("on line 135 in \"matrix_implementation\"");
        }
    }
}

template<typename T>
void Matrix<T>::set_value_by_indexes(unsigned int i, unsigned int j, const T &value) const
{
    if (i >= this->n || j >= this->m)
    {
        throw mtr_index_out_exception("on line 145 in \"matrix_implementation\"");
    }
    else
    {
        if (this->mtr)
        {
            this->mtr[i * this->m + j] = value;
        }
        else
        {
            throw memory_allocate_exception("on line 155 in \"matrix_implementation\"");
        }
    }
}
// i'm thinking about this
template<typename T>
Matrix<T>& Matrix<T>::operator =(const Matrix<T> &mtr)
{
    unsigned int n_mtr = mtr.get_n();
    unsigned int m_mtr = mtr.get_m();
    this->n = n_mtr;
    this->m = m_mtr;
    this->elements_count = mtr.elements_count;
    try
    {
        this->mtr = new T[n * m];
    }
    catch (std::bad_alloc)
    {
        throw memory_allocate_exception("on line 174 in \"matrix_implementation\"");
    }
    if (this->m == m_mtr && this->n == n_mtr)
    {
        for (unsigned int i = 0; i < n_mtr; i++)
        {
            for (unsigned int j = 0; j < m_mtr; j++)
            {
                this->mtr[i * m + j] = mtr.mtr[i * m + j];
            }
        }
    }
    else
    {
        throw mtr_wrong_sizes_exception("on line 188 in \"matrix_implementation\"");
    }
    return *this;
}
template<typename T>
Matrix<T> &Matrix<T>::operator =(Matrix<T> &&mtr)
{
    unsigned int n_mtr = mtr.get_n();
    unsigned int m_mtr = mtr.get_m();
    this->n = n_mtr;
    this->m = m_mtr;
    this->elements_count = mtr.elements_count;
    try
    {
        this->mtr = new T[n * m];
    }
    catch (std::bad_alloc)
    {
        throw memory_allocate_exception("on line 206 in \"matrix_implementation\"");
    }
    if (this->m == m_mtr && this->n == n_mtr)
    {
        for (unsigned int i = 0; i < n_mtr; i++)
        {
            for (unsigned int j = 0; j < m_mtr; j++)
            {
                this->mtr[i * m + j] = mtr.mtr[i * m + j];
            }
        }
    }
    else
    {
        throw mtr_wrong_sizes_exception("on line 220 in \"matrix_implementation\"");
    }
    return *this;
}


template<typename T>
Matrix<T> &Matrix<T>::operator +=(const Matrix<T> &mtr)
{
    unsigned int n_mtr = mtr.get_n();
    unsigned int m_mtr = mtr.get_m();
    if (this->m == m_mtr && this->n == n_mtr)
    {
        for (unsigned int i = 0; i < n_mtr; i++)
        {
            for (unsigned int j = 0; j < m_mtr; j++)
            {
                this->mtr[i * m + j] += mtr.mtr[i * m + j];
            }
        }
    }
    else
    {
        throw mtr_wrong_sizes_exception("on line 243 in \"matrix_implementation\"");
    }
    return *this;
}
template<typename T>
Matrix<T> &Matrix<T>::operator -=(const Matrix<T> &mtr)
{
    unsigned int n_mtr = mtr.get_n();
    unsigned int m_mtr = mtr.get_m();
    if (this->m == m_mtr && this->n == n_mtr)
    {
        for (unsigned int i = 0; i < n_mtr; i++)
        {
            for (unsigned int j = 0; j < m_mtr; j++)
            {
                this->mtr[i * m + j] -= mtr.mtr[i * m + j];
            }
        }
    }
    else
    {
        throw mtr_wrong_sizes_exception("on line 264 in \"matrix_implementation\"");
    }
    return *this;
}


template<typename _T>
Matrix<_T> operator +(const Matrix<_T> &mtr1, const Matrix<_T> &mtr2)
{
    if (mtr1.get_n() == mtr2.get_n() && mtr1.get_n() == mtr2.get_m())
    {

        Matrix<_T> res(mtr1.get_n(), mtr1.get_m());
        for (unsigned int i = 0; i < res.get_n(); ++i)
        {
            for (unsigned int j = 0; j < res.get_m(); ++j)
            {
                res.mtr[i * mtr1.get_m() + j] = mtr1.mtr[i * mtr1.get_m() + j] + mtr2.mtr[i * mtr1.get_m() + j];
            }
        }
        return res;

    }
    else
    {
        throw mtr_wrong_sizes_exception("on line 289 in \"matrix_implementation\"");
    }
}
template<typename _T>
Matrix<_T> operator +(const Matrix<_T> &mtr1, _T num)
{
    unsigned int n = mtr1.get_n();
    unsigned int m = mtr1.get_m();
    Matrix<_T> res = Matrix<_T>(n, m);
    for (unsigned int i = 0; i < n; i++)
    {
        for (unsigned int j = 0; j < m; j++)
        {
            res.mtr[i * m + j] = mtr1.mtr[i * m + j] + num;
        }
    }
    return res;
}

template <typename _T>
Matrix<_T> operator -(const Matrix<_T> &mtr1, const Matrix<_T> &mtr2)
{
    if (mtr1.get_n() == mtr2.get_n() && mtr1.get_n() == mtr2.get_m())
    {
        Matrix<_T> res = Matrix<_T>(mtr1.get_n(), mtr1.get_m());
        for (unsigned int i = 0; i < res.get_n(); ++i)
        {
            for (unsigned int j = 0; j < res.get_m(); ++j)
            {
                res.mtr[i * mtr1.get_m() + j] = mtr1.mtr[i * mtr1.get_m() + j] - mtr2.mtr[i * mtr1.get_m() + j];
            }
        }
        return res;

    }
    else
    {
        throw mtr_wrong_sizes_exception("on line 326 in \"matrix_implementation\"");
    }
}

template<typename _T>
Matrix<_T> operator -(const Matrix<_T> &mtr1, _T num)
{
    unsigned int n = mtr1.get_n();
    unsigned int m = mtr1.get_m();
    Matrix<_T> res = Matrix<_T>(n, m);
    for (unsigned int i = 0; i < n; i++)
    {
        for (unsigned int j = 0; j < m; j++)
        {
            res.mtr[i * m + j] = mtr1.mtr[i * m + j] - num;
        }
    }
    return res;
}

template <typename _T>
Matrix<_T> operator *(const Matrix<_T> &mtr1, const Matrix<_T> &mtr2)
{
    if (mtr1.get_m() == mtr2.get_n())
    {
        unsigned int n = mtr1.get_n();
        unsigned int m = mtr2.get_m();
        unsigned int l = mtr1.get_n();
        Matrix<_T> res = Matrix<_T>(n, m);
        for (unsigned int i = 0; i < n; i++)
        {
            for (unsigned int j = 0; j < m; j++)
            {
                double sum = 0;
                for (unsigned int k = 0; k < l; k++)
                {
                    sum += mtr1.mtr[i * m + k] * mtr2.mtr[k * m + j];
                }
                res.mtr[i * m + j] = sum;
            }
        }
        return res;
    }
    else
    {
        throw mtr_wrong_sizes_exception("on line 371 in \"matrix_implementation\"");
    }
}

template<typename _T>
Matrix<_T> operator *(const Matrix<_T> &mtr1, _T num)
{
    unsigned int n = mtr1.get_n();
    unsigned int m = mtr1.get_m();
    Matrix<_T> res = Matrix<_T>(n, m);
    for (unsigned int i = 0; i < n; i++)
    {
        for (unsigned int j = 0; j < m; j++)
        {
            res.mtr[i * m + j] = mtr1.mtr[i * m + j] * num;
        }
    }
    return res;
}

template<typename _T>
Matrix<_T> operator /(const Matrix<_T> &mtr1, _T num)
{
    unsigned int n = mtr1.get_n();
    unsigned int m = mtr1.get_m();
    Matrix<_T> res = Matrix<_T>(n, m);
    for (unsigned int i = 0; i < n; i++)
    {
        for (unsigned int j = 0; j < m; j++)
        {
            res.mtr[i * m + j] = mtr1.mtr[i * m + j] / num;
        }
    }
    return res;
}

template<typename T>
T Matrix<T>::operator()(unsigned int i, unsigned int j) const
{
    if (this->n <= i || this->m <= j) throw mtr_index_out_exception("on line 410 in \"matrix_implementation\"");

    return this->mtr[i * this->m + j];
}


template<typename T>
T &Matrix<T>::operator ()(unsigned int i, unsigned int j)
{
    if (this->n <= i || this->m <= j) throw mtr_index_out_exception("on line 419 in \"matrix_implementation\"");

    return this->mtr[i * this->m + j];
}

template<typename T>
T &Matrix<T>::operator [](unsigned int i)
{
    if (this->n <= i ) throw mtr_index_out_exception("on line 427 in \"matrix_implementation\"");

    return this->mtr[i];
}
template<typename T>
T Matrix<T>::operator [](unsigned int i) const
{
    if (this->n <= i) throw mtr_index_out_exception("on line 434 in \"matrix_implementation\"");

    return this->mtr[i];
}

template<typename T>
T Matrix<T>::get_gauss_determinant()
{
    double del = 1;
    double max = this->mtr[0];
    int max_pos = 0;
    int pos_n = 0;
    int pos_m = 0;
    T determinant = 1;
    double eps = 0.000001;
    if (n != m) throw mtr_wrong_sizes_exception("on line 449 in \"matrix_implementation\"");
    for (unsigned int i = 0; i < n - 1; i++)
    {
        max = mtr[i * m + i];
        for (unsigned int l = i + 1; l < n; l++)
        {
            if (fabs(mtr[l * m + i] - max) > eps)
            {
                max = mtr[l * m + i];
                pos_n = i;
                pos_m = l;
                max_pos = l;
            }
        }
        if ((unsigned int)max_pos > i)
        {
            determinant *= -1;
            double tmp;
            for (unsigned int i = 0; i < m; i++)
            {
                tmp = mtr[pos_n * m + i];
                mtr[pos_n * m + i] = mtr[pos_m * m + i];
                mtr[pos_m * m + i] = tmp;
            }

        }
        for (unsigned int j = i + 1; j < n; j++)
        {
            if (mtr[i * m + i] != 0)
            {
                del = mtr[j * m + i] / mtr[i * m + i];
            }
            for (unsigned int k = i; k < n; k++)
            {
                mtr[j * m + k] -= (mtr[i * m + k] * del);
            }
        }
    }
    for (unsigned int i = 0; i < n; i++)
    {
        determinant = determinant * mtr[i * m + i];
    }
    return determinant;

}

template<typename T>
void Matrix<T>::create_identity_matrix()
{
    if (n != m) throw mtr_wrong_sizes_exception("on line 498 in \"matrix_implementation\"");
    for (unsigned int i = 0; i < n; i++)
    {
        for (unsigned int j = 0; j < m; j++)
        {
            if (i == j)
            {
                mtr[i *m + j] = 1;
            }
            else
            {
                mtr[i *m + j] = 0;
            }
        }
    }
}


template<typename T>
Matrix<T>& Matrix<T>::transposition()
{
    if (this->get_m() == this->get_n())
    {
        for (unsigned int i = 0; i < 4; i++)
        {
            for (unsigned int j = i + 1; j <= 4; j++)
            {
                T symbol = this->mtr[i * m + j];
                this->mtr[i * m + j] = this->mtr[j * m + i];
                this->mtr[j * m + i] = symbol;
            }
        }
        return *this;
    }
    else
    {
        throw mtr_wrong_sizes_exception("on line 534 in \"matrix_implementation\"");
    }

}

template<typename T>
bool Matrix<T>::is_square()
{
    if (this->n == this->m)
    {
        return true;
    }
    else
    {
        return false;
    }
}


template<typename T>
unsigned int Matrix<T>::get_n() const
{
    return this->n;
}


template<typename T>
unsigned int Matrix<T>::get_m() const
{
    return this->m;
}

template <typename T>
Matrix<T>::~Matrix()
{
    delete this->mtr;
    this->n = 0;
    this->m = 0;
}

template <typename T>
void Matrix<T>::print_matrix()
{
    std::cout << "Matrix is\n" << std::endl;
    if (n == 0 || m == 0) std::cout << "n or m is zero!\n";
    for (unsigned int i = 0; i < this->n; i++)
    {
        for (unsigned int j = 0; j < this->m; j++)
        {
            std::cout << mtr[i * m + j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}
template<typename T>
void Matrix<T>::auto_fill()
{
    for (size_t i = 0; i < this->n; i++)
        for (size_t j = 0; j < this->m; j++)
            mtr[i * m + j] = rand() % 9 + 1;
}
template<typename _T>
std::ostream& operator <<(std::ostream& os, const Matrix<_T>& matr)
{
    for (unsigned int i = 0; i < matr.get_n(); i++)
    {
        for(unsigned int j = 0; j < matr.get_m(); j++)
        {
            os << matr.mtr[i * matr.get_m() + j] << " ";
        }
        os << std::endl;
    }
    os << std::endl;
    return os;
}

#endif // MATRIX_IMPLEMENTATION_H
