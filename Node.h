#ifndef NODE_H
#define NODE_H
#include <iostream>
using namespace std;

class Node              //functionally independent class for storing digits(unsigned short)
{
    unsigned short info;
    Node* next;
    Node* prev;
public:
    Node();
    Node(int nr);
    Node(int nr, Node* prev, Node* next);
    Node(const Node& node);     //copy constructor
   // ~Node();
    void set_info(unsigned short nr);
    unsigned short get_info();
    void set_next(Node* next);
    Node* get_next() const;
    void set_prev(Node* prev);
    Node* get_prev() const;
};

#endif // NODE_H
