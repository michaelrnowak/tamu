#include "utilities.h"
#include <iostream>

void log(void * address, std::string msg)
{
    std::cerr << "[" << address << "] " << msg << std::endl;
}