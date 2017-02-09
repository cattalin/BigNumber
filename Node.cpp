#include "Node.h"

Node::Node()
{
    info=0;
    next=NULL;
    prev=NULL;
}
Node::Node(int nr)
{
    info=nr;
    next=NULL;
    prev=NULL;
}
Node::Node(int nr, Node* prev, Node* next)
{
    info=nr;
    this->next=next;
    this->prev=prev;
}
Node::Node(const Node& node)
{
    info=node.info;
    next=node.next;
    prev=node.prev;
}
/*Node::~Node()
{
    info=0;
    delete next;
}*/
void Node::set_info(unsigned short nr)
{
    this->info=nr;
}
unsigned short Node::get_info()
{
    return info;
}
void Node::set_next(Node* next)
{
    this->next=next;
}
Node* Node::get_next() const
{
    return this->next;
}
void Node::set_prev(Node* prev)
{
    this->prev=prev;
}
Node* Node::get_prev() const
{
    return prev;
}
