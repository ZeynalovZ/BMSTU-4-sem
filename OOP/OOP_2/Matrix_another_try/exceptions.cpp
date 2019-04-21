#include "exceptions.h"
const char *base_exceptions::what()
{
    return message.c_str();
}
