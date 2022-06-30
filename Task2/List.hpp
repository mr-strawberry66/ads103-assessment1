#ifndef LIST
#define LIST

#include <iostream>
#include "Node.hpp"

class List
{
public:
    // Points to the first item of the linked list.
    Node* head = nullptr;

    int length();
    void printValues();

    void insert(int value);
    void append(int value);
    void insert(int value, int index);

    void shift();
    void pop();
    void pop(int index);
};

#endif
