#include <iostream>
#include <string>
#include "List.hpp"
#include "Operations.hpp"

int main()
{
    List list1;
    List list2;

    Operations::runInsert(list1, list2);
    Operations::runDelete(list1, list2);

    return 0;
}
