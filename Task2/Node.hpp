#ifndef NODE
#define NODE

class Node
{
public:
    int value;
    Node* next = nullptr;

    Node();
    Node(int value);
};

#endif
