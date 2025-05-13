#include "../headers/node.h"

void Node::print_node()
{
    std::cout << "\nNode id = " << id << " node data = " << data << " next node id = " << (next == nullptr ? 0 : next->id) << '\n';
}

Node* Node::get_next_node()
{
    return next;
}

int Node::get_id()
{
    return id;
}

void Node::set_next(Node* next_node)
{
    next = next_node;
}