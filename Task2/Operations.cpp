#include "Operations.hpp"

/**
 * @brief Insert 50,000 integers into the front of a List.
 *
 * @param list The list to insert the data into.
 */
void Operations::insertFromFront(List &list)
{
    for (int i = 0; i < 50000; i++)
    {
        list.insert(i);
    }
}

/**
 * @brief Append 50,000 integers to a List.
 *
 * @param list The list to append the data to.
 */
void Operations::insertFromEnd(List &list)
{
    for (int i = 0; i < 50000; i++)
    {
        list.append(i);
    }
}

/**
 * @brief Delete 50,000 integers from the front of a List.
 *
 * @param list The list to delete the data from.
 */
void Operations::deleteFromFront(List &list)
{
    for (int i = 0; i < 50000; i++)
    {
        list.shift();
    }
}

/**
 * @brief Delete 50,000 integers from the end of a List.
 *
 * @param list The list to delete the data from.
 */
void Operations::deleteFromEnd(List &list)
{
    for (int i = 0; i < 50000; i++)
    {
        list.pop();
    }
}

/**
 * @brief Test inserting 50,000 integers into a List by appending to one list and inserting into another.
 *
 * @param list1 The list to insert data into the front of.
 * @param list2 The list to append data to.
 */
void Operations::runInsert(List &list1, List &list2)
{
    std::string insertMessage;
    int iFromStartTime = Time::timeFunction(Operations::insertFromFront, list1);
    int iFromEndTime = Time::timeFunction(Operations::insertFromEnd, list2);

    if (iFromStartTime > iFromEndTime)
        insertMessage = "Appending to the List was more efficient!\n";

    else
        insertMessage = "Inserting from the head was more efficeint!\n";

    std::cout
        << "Appending to the list took " << iFromEndTime << " [ms]\n"
        << "Inserting from the head took " << iFromStartTime << " [ms]\n"
        << "\n"
        << insertMessage << "\n\n";
}

/**
 * @brief Test deleting 50,000 integers from a List by deleting from the front of one and the back of another.
 *
 * @param list1 The list to delete data from the front of.
 * @param list2 The list to delete data from the back of.
 */
void Operations::runDelete(List &list1, List &list2)
{

    std::string deleteMessage;
    int delFromStartTime = Time::timeFunction(Operations::deleteFromFront, list1);
    int delFromEndTime = Time::timeFunction(Operations::deleteFromEnd, list2);

    if (delFromStartTime > delFromEndTime)
        deleteMessage = "Deleting from the end of the list was more efficient!\n";

    else
        deleteMessage = "Deleting from the head of the list was more efficeint!\n";

    std::cout
        << "Deleting from the end of the list took " << delFromEndTime << " [ms]\n"
        << "Deleting from the head of the list took " << delFromStartTime << " [ms]\n"
        << "\n"
        << deleteMessage << "\n\n";
}
