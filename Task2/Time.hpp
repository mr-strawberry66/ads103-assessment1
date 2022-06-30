#ifndef TIME
#define TIME

#include <chrono>
#include <vector>
#include "List.hpp"

/** @brief Time how long a function takes to execute in milliseconds. */
namespace Time
{
    int timeFunction(void (*func)(List &list), List &list);
}

#endif
