#include "Time.hpp"

int Time::timeFunction(void (*func)(List& list), List& list) {
    std::chrono::steady_clock::time_point start =
        std::chrono::steady_clock::now();

    func(list);

    std::chrono::steady_clock::time_point end =
        std::chrono::steady_clock::now();

    return std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
}
