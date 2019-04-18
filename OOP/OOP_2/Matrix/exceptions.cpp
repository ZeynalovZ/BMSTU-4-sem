#include "excepctions.h"
const char *base_exceptions::what()
{
    return message.c_str();
}
