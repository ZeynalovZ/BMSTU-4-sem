#ifndef EXCEPCTIONS_H
#define EXCEPCTIONS_H
#include <exception>
#include <string>
class base_exceptions: public std::exception
{
public:
    explicit base_exceptions() = default;

    explicit base_exceptions(const char* message)
        :message(message){}
    explicit base_exceptions(const std::string& message)
        :message(message){}

private:
    std::string message;
};

class memory_allocate_exception: public base_exceptions
{
  public:
    explicit memory_allocate_exception()
        :base_exceptions("Bad memory allocation"){}
};

class mtr_size_exception: public base_exceptions
{
  public:
    explicit mtr_size_exception()
        :base_exceptions("Matrixes sizes are not equal"){}
};

class mtr_index_out_exception : public base_exceptions
{
public:
    explicit mtr_index_out_exception()
        :base_exceptions("Index out of range"){}
};

class mtr_wrong_sizes_exception: public base_exceptions
{
public:
    explicit mtr_wrong_sizes_exception()
        :base_exceptions("mtr size couldn't be zero"){}
};
#endif // EXCEPCTIONS_H
