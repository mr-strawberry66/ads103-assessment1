#ifndef NODE
#define NODE

/**
 * @brief Class to represent a node of a linked List.
 *
 * @param value The integer value to store in the Node.
 * @param next The pointer to the next Node in the List.
 */
class Node
{
public:
    int value;
    Node *next = nullptr;

    Node();
    Node(int value);
};

#endif
