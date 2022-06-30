#include "List.hpp"

/**
 * @brief Return the current length of the List.
 *
 * @return int How many items are in the List.
 */
int List::length()
{
    int length = 0;
    Node *iterator = this->head;

    while (iterator != nullptr)
    {
        length++;
        iterator = iterator->next;
    }

    return length;
}

/** @brief Print the values of the List. */
void List::printValues()
{
    Node *iterator = this->head;
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

/**
 * @brief The operator[] to get the value of the List at the given index.
 *
 * @param index The index of the value to get.
 * @return int The value at the given index.
 * @throws std::out_of_range If the index is out of range.
 */
int List::operator[](int index)
{
    Node *iterator = this->head;
    int i = 0;

    while (iterator != nullptr)
    {
        if (i == index)
            return iterator->value;

        i++;
        iterator = iterator->next;
    }

    throw std::out_of_range("Index out of range.");
}

/**
 * @brief Safely get the value of the List at the given index.
 *
 * @param index The index of the value to get.
 * @param defaultValue The value to return if the index is out of range.
 * @return int The value at the provided index, or the default value.
 */
int List::get(int index, int defaultValue)
{
    try
    {
        return this->operator[](index);
    }
    catch (std::out_of_range)
    {
        return defaultValue;
    }
}

/**
 * @brief Insert a value into the front of the List.
 *
 * @param value The integer to insert into the List.
 */
void List::insert(int value)
{
    Node *newHead = new Node(value);
    newHead->next = this->head;
    this->head = newHead;
}

/**
 * @brief Add a value to the end of the List.
 *
 * @param value The integer value to append to the List.
 */
void List::append(int value)
{
    Node *endNode = new Node(value);
    Node *iterator = head;

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

/**
 * @brief Insert a value into the List at a specific index.
 *
 * @param value The integer value to insert.
 * @param index The index to insert the value at.
 */
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

    Node *newNode = new Node(value);
    Node *previous = this->head;
    Node *iterator = this->head;

    for (int i = 0; i < index; i++)
    {
        previous = iterator;
        iterator = iterator->next;
    }

    previous->next = newNode;
    newNode->next = iterator;
}

/** @brief Remove the first value from the List. */
void List::shift()
{
    if (this->head == nullptr)
        return;

    Node *previous = this->head;
    this->head = this->head->next;

    delete previous;
    previous = nullptr;
}

/** @brief Remove the last item from the List. */
void List::pop()
{
    if (this->head == nullptr)
        return;

    Node *previous = this->head;
    Node *iterator = this->head;

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

/**
 * @brief Remove the item at a specific index from the List.
 *
 * @param index The index of the item to remove.
 */
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

    Node *previous = this->head;
    Node *iterator = this->head;

    for (int i = 0; i < index; i++)
    {
        previous = iterator;
        iterator = iterator->next;
    }

    previous->next = iterator->next;

    delete iterator;
}
