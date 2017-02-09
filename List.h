#ifndef LIST_H
#define LIST_H
#include <iostream>
#include "Node.h"

using namespace std;

class List                  //functionally class customized for working with digits, *needs throw statements
{
    int size;
    Node* first;
    Node* last;

public:
    List();
    List(const List& l);
    ~List();

    void pop_back();
    void pop_front();
    void push_back(unsigned short value);
    void push_front(unsigned short value);
    void pop(int pos);
    Node* peak(int pos) const;      //probably should change this to a int return type
    void set_info(int pos, unsigned short value);


    int Size()  const;
    void Show();
    void Show_reversed();
    void Show(ostream& out) const;
    void Show_reversed(ostream& out) const;
    void remove_useless_zeros();

    List& operator=(const List &l);
    bool operator==(const List &l);

private:
    void copy(const List& l);
};

#endif // LIST_H
