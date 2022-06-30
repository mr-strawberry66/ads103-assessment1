#ifndef TIME
#define TIME

#include <chrono>
#include <vector>
#include "List.hpp"

namespace Time {
    int timeFunction(void (*func)(List& list), List& list);
}

#endif
