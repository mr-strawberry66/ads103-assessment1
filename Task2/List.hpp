#ifndef LIST
#define LIST

#include <stdexcept>
#include <iostream>
#include "Node.hpp"

/**
 * @brief A class to represent a linked List.
 *
 * @param head The pointer to the first Node in the List.
 */
class List
{
public:
    Node *head = nullptr;

    int length();
    void printValues();

    int operator[](int index);
    int get(int index, int defaultValue = -1);

    void insert(int value);
    void append(int value);
    void insert(int value, int index);

    void shift();
    void pop();
    void pop(int index);
};

#endif
