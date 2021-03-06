#ifndef MATRIX_IMPLEMENTATION_H
#define MATRIX_IMPLEMENTATION_H
#include "matrix.h"
template <typename T>
Matrix<T>::Matrix(unsigned int n, unsigned int m)
{
    if (n == 0 || m == 0) throw mtr_wrong_sizes_exception();
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
        throw memory_allocate_exception();
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
        throw memory_allocate_exception();
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
        this->mtr = new T[n*m];
    }
    catch (std::bad_alloc)
    {
        throw memory_allocate_exception();
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
        throw memory_allocate_exception();
    }
    for (unsigned int i = 0; iter_i != lst.end(); i++, iter_i++)
    {
        if (this->m != iter_i->size()) throw mtr_size_exception();
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
T Matrix<T>::get_value_by_indexes(unsigned int i, unsigned int j) const
{
    if (i >= this->n || j >= this->m)
    {
        throw mtr_index_out_exception();
    }
    else
    {
        if (this->mtr)
        {
            return mtr[i * this->m + j];
        }
        else
        {
            throw memory_allocate_exception();
        }
    }
}

template<typename T>
void Matrix<T>::set_value_by_indexes(unsigned int i, unsigned int j, const T &value) const
{
    if (i >= this->n || j >= this->m)
    {
        throw mtr_index_out_exception();
    }
    else
    {
        if (this->mtr)
        {
            this->mtr[i * this->m + j] = value;
        }
        else
        {
            throw memory_allocate_exception();
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
        throw memory_allocate_exception();
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
        throw mtr_wrong_sizes_exception();
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
        throw mtr_wrong_sizes_exception();
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
        throw mtr_wrong_sizes_exception();
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
        throw mtr_wrong_sizes_exception();
    }
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
        throw mtr_wrong_sizes_exception();
    }
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
        throw mtr_wrong_sizes_exception();
    }
}

template<typename T>
void Matrix<T>::transposition()
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
    }
    else
    {
        throw mtr_wrong_sizes_exception();
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
#endif // MATRIX_IMPLEMENTATION_H
