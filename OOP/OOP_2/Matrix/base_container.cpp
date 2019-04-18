#include "base_container.h"

using namespace container_core;
base_container::base_container()
    : elements_count(0){}

base_container::base_container(size_t count)
    : elements_count(count){}

base_container::~base_container()
{
    this->elements_count = 0;
}
bool base_container::is_empty() const
{
    return elements_count == 0;
}

size_t base_container::size() const
{
    return elements_count;
}
