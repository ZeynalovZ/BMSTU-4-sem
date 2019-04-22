#ifndef MATRIX_ITERATOR_H
#define MATRIX_ITERATOR_H
#include "base_iterator.h"
using namespace iterator_core;
template<typename ValueType>
class matrix_iterator : public base_iterator<ValueType>
{
public:
    matrix_iterator(const matrix_iterator<ValueType>&);
    //shared
    ValueType &operator *();
    ValueType *operator ->();
    const ValueType &operator *() const;
    const ValueType *operator ->() const;

    matrix_iterator(ValueType *);
private:
};
#endif // MATRIX_ITERATOR_H
