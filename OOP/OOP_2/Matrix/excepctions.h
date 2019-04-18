#ifndef EXCEPCTIONS_H
#define EXCEPCTIONS_H
#include <exception>
#include <string>
class base_exceptions: public std::exception
{
public:
    virtual const char* what();

    explicit base_exceptions() = default;

    explicit base_exceptions(const char* message, const char* add_message)
        :message(message), additional_message(add_message){}
    explicit base_exceptions(const std::string& message, const std::string& add_message)
        :message(message), additional_message(add_message){}

private:
    std::string message;
    std::string additional_message;
};

class memory_allocate_exception: public base_exceptions
{
  public:
    explicit memory_allocate_exception(const std::string& add_message)
        :base_exceptions("Bad memory allocation", add_message){}
};

class mtr_size_exception: public base_exceptions
{
  public:
    explicit mtr_size_exception(const std::string& add_message)
        :base_exceptions("Matrixes sizes are not equal", add_message){}
};

class mtr_index_out_exception : public base_exceptions
{
public:
    explicit mtr_index_out_exception(const std::string& add_message)
        :base_exceptions("Index out of range", add_message){}
};

class mtr_wrong_sizes_exception: public base_exceptions
{
public:
    explicit mtr_wrong_sizes_exception(const std::string& add_message)
        :base_exceptions("mtr size couldn't be zero", add_message){}
};
#endif // EXCEPCTIONS_H



