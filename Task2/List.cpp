#include "List.hpp"

int List::length()
{
    int length = 0;
    Node* iterator = this->head;

    while (iterator != nullptr)
    {
        length++;
        iterator = iterator->next;
    }

    return length;
}

void List::printValues()
{
    Node* iterator = this->head;
    std::cout << "[";

    while (iterator != nullptr)
    {
        std::cout << iterator->value;
        iterator = iterator->next;

        if (iterator != nullptr)
            std::cout << ", ";

        else
            std::cout << "]\n";
    }
}

/** Insert at front of list. */
void List::insert(int value)
{
    Node* newHead = new Node(value);
    newHead->next = this->head;
    this->head = newHead;
}

/** Insert at back of list. */
void List::append(int value)
{
    Node* endNode = new Node(value);
    Node* iterator = head;

    if (this->head == nullptr)
    {
        this->insert(value);
        return;
    }
    
    while (iterator->next != nullptr) 
    {
        iterator = iterator->next;
    }
    iterator->next = endNode;
}

/** Overload to insert at index. */
void List::insert(int value, int index)
{
    if (this->head == nullptr)
    {
        this->insert(value);
        return;
    }

    if (index >= this->length())
    {
        this->append(value);
        return;
    }

    if (index == 0)
    {
        this->insert(value);
        return;
    }

    Node* newNode = new Node(value);
    Node* previous = this->head;
    Node* iterator = this->head;

    for (int i = 0; i < index; i++)
    {
        previous = iterator;
        iterator = iterator->next;
    }

    previous->next = newNode;
    newNode->next = iterator;
}

void List::shift()
{
    if (this->head == nullptr)
        return;

    Node* previous = this->head;
    this->head = this->head->next;

    delete previous;
    previous = nullptr;
}

void List::pop()
{
    if (this->head == nullptr)
        return;

    Node* previous = this->head;
    Node* iterator = this->head;

    while (iterator->next != nullptr)
    {
        previous = iterator;
        iterator = iterator->next;
    }

    previous->next = nullptr;

    if (iterator == this->head)
        this->head = nullptr;

    delete iterator;
}

void List::pop(int index)
{
    if (this->head == nullptr)
        return;

    if (index == 0)
    {
        this->shift();
        return;
    }

    if (index >= this->length() - 1)
    {
        this->pop();
        return;
    }

    Node* previous = this->head;
    Node* iterator = this->head;

    for (int i = 0; i < index; i++)
    {
        previous = iterator;
        iterator = iterator->next;
    }

    previous->next = iterator->next;

    delete iterator;
}
