#ifndef MATRIX_ITERATOR_IMPLEMENTATION_H
#define MATRIX_ITERATOR_IMPLEMENTATION_H
#include "matrix_iterator.h"
using namespace iterator_core;
template<typename ValueType>
ValueType& matrix_iterator<ValueType>::operator *()
{
    return *(this->ptr);
}

template<typename ValueType>
ValueType* matrix_iterator<ValueType>::operator ->()
{
    return this->ptr;
}

template<typename ValueType>
const ValueType& matrix_iterator<ValueType>::operator *() const
{
    return *(this->ptr);
}

template<typename ValueType>
const ValueType* matrix_iterator<ValueType>::operator ->() const
{
    return this->ptr;
}

template<typename ValueType>
matrix_iterator<ValueType>::matrix_iterator(const matrix_iterator<ValueType> &iter)
    : base_iterator<ValueType>(iter.ptr)
{

}

template<typename ValueType>
matrix_iterator<ValueType>::matrix_iterator(ValueType *ptr)
    : base_iterator<ValueType>(ptr)
{

}
#endif // MATRIX_ITERATOR_IMPLEMENTATION_H
