#ifndef BASE_CONTAINER_H
#define BASE_CONTAINER_H
#include <iostream>
namespace container_core
{
    class base_container
    {
    public:
        explicit base_container();
        explicit base_container(size_t);
        virtual ~base_container();

        bool is_empty() const;
        size_t size() const;
    protected:
        size_t elements_count;


    };
}
#endif // BASE_CONTAINER_H
