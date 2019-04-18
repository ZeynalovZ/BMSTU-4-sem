#ifndef CONST_MATRIX_ITERATOR_IMPLEMENTATION_H
#define CONST_MATRIX_ITERATOR_IMPLEMENTATION_H
#include "base_iterator.h"
using namespace iterator_core;
template<typename ValueType>
    const ValueType& const_matrix_iterator<ValueType>::operator *() const
    {
        return *(this->ptr);
    }

    template<typename ValueType>
    const ValueType* const_matrix_iterator<ValueType>::operator ->() const
    {
        return this->ptr;
    }

    template<typename ValueType>
    const_matrix_iterator<ValueType>::const_matrix_iterator(const const_matrix_iterator<ValueType>& iter)
        : base_iterator<ValueType>(iter.ptr) {}

    template<typename ValueType>
    const_matrix_iterator<ValueType>::const_matrix_iterator(ValueType* ptr)
        : base_iterator<ValueType>(ptr) {}
#endif // CONST_MATRIX_ITERATOR_IMPLEMENTATION_H
