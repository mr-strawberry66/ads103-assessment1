#include "Operations.hpp"

void Operations::insertFromFront(List &list)
{
    for (int i = 0; i < 50000; i++)
    {
        list.insert(i);
    }
}

void Operations::insertFromEnd(List &list)
{
    for (int i = 0; i < 50000; i++)
    {
        list.append(i);
    }
}

void Operations::deleteFromFront(List &list)
{
    for (int i = 0; i < 50000; i++)
    {
        list.shift();
    }
}

void Operations::deleteFromEnd(List &list)
{
    for (int i = 0; i < 50000; i++)
    {
        list.pop();
    }
}

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
