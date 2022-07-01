#include "Time.hpp"

/**
 * @brief Time how long a function takes to execute in milliseconds.
 *
 * @param func The function to time.
 * @param list A reference to the list to add or remove items from/to.
 * @return int The time taken to execute the function in milliseconds.
 */
int Time::timeFunction(void (*func)(List &list), List &list)
{
    using namespace std::chrono;

    steady_clock::time_point start = steady_clock::now();

    func(list);

    steady_clock::time_point end = steady_clock::now();

    return duration_cast<milliseconds>(end - start).count();
}
