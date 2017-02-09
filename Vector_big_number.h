#ifndef VECTOR_BIG_NUMBER_H
#define VECTOR_BIG_NUMBER_H
#include "Big_number.h"

class Vector_big_number
{
    Big_number elements[101];
    int size;


public:
    Vector_big_number(int size);


    Big_number get_element(int pos) const;
    void set_element(Big_number element, int pos);
    int Size() const;
    void set_size(int size);

    void Show();
    void Show(ostream& out) const;

    Big_number Max();

    Big_number operator*(const Vector_big_number& v);
    friend ostream& operator<<(ostream& out, const Vector_big_number& obj);
    friend istream& operator>>(istream& in, Vector_big_number& obj);

};

#endif // VECTOR_BIG_NUMBER_H
