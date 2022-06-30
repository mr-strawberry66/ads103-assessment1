#include "Node.hpp"

/** @brief Default constructor for a new Node object. */
Node::Node()
{
    this->value = 0;
}

/**
 * @brief Constructor for a new Node object.
 *
 * @param value The integer value to store in the Node.
 */
Node::Node(int value)
{
    this->value = value;
}
