#ifndef CONST_MATRIX_ITERATOR_H
#define CONST_MATRIX_ITERATOR_H
#include "base_iterator.h"
using namespace iterator_core;
template <typename ValueType>
class const_matrix_iterator : public base_iterator<ValueType>
{
public:
    const_matrix_iterator(const const_matrix_iterator<ValueType>&);

    const ValueType& operator *() const;
    const ValueType* operator ->() const;

    //friend class csl::matrix<ValueType>;

    const_matrix_iterator(ValueType*);
};
#include "const_matrix_iterator_implementation.h"
#endif // CONST_MATRIX_ITERATOR_H
