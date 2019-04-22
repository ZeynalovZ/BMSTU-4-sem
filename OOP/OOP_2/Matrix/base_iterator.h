#ifndef BASE_ITERATOR_H
#define BASE_ITERATOR_H
using namespace std;
namespace iterator_core
{
    template<typename ValueType>
    class base_iterator
    {
    public:
        base_iterator();
        base_iterator(const base_iterator<ValueType>&);
        base_iterator(ValueType*);
        virtual ~base_iterator();

        base_iterator<ValueType>& operator =(const base_iterator<ValueType>&);

        base_iterator<ValueType>& operator ++();
        base_iterator<ValueType> operator ++(int);
        base_iterator<ValueType>& operator --();
        base_iterator<ValueType> operator --(int);

        operator bool() const;


        bool operator ==(const base_iterator<ValueType>&) const;
        bool operator !=(const base_iterator<ValueType>&) const;
    protected:
        //std::weak_ptr<ValueType> ptr;
        unsigned int count;
        int index;
        ValueType *ptr;
    };
}

#include "base_iterator_implementation.h"
#endif // BASE_ITERATOR_H
