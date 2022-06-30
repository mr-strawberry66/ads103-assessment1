#ifndef OPERATIONS
#define OPERATIONS

#include <iostream>
#include <string>
#include "Node.hpp"
#include "List.hpp"
#include "Time.hpp"

namespace Operations {
    void insertFromFront(List& list);
    void insertFromEnd(List& list);
    void deleteFromFront(List& list);
    void deleteFromEnd(List& list);

    void runInsert(List& list1, List& list2);
    void runDelete(List& list1, List& list2);
}

#endif
