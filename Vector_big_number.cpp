#include "Vector_big_number.h"

Vector_big_number::Vector_big_number(int size)
{
    if (size<100)
        this->size=size;
    else size=100;
}

Big_number Vector_big_number::get_element(int pos) const
{
    if (pos<size)
        return elements[pos];
    cout<<"out of array bounds";
    return Big_number(0);
}
void Vector_big_number::set_element(Big_number element, int pos)
{
    if (pos<size)
        elements[pos]=element;
    else
        cout<<"out of array bounds";
}

void Vector_big_number::Show()
{
    for (int i=0;i<size;i++)
        cout<<elements[i]<<" ";
}
void Vector_big_number::Show(ostream& out) const
{
    for (int i=0;i<size;i++)
        out<<elements[i]<<" ";
}
int Vector_big_number::Size() const
{
    return size;
}
void Vector_big_number::set_size(int size)
{
    if (size<100)
        this->size=size;
    else size=100;
}


Big_number Vector_big_number::Max()
{
    Big_number aux;
    for(int i=0;i<size;i++)
        if (elements[i].greater_than(aux))
            aux=elements[i];
    return aux;
}


Big_number Vector_big_number::operator*(const Vector_big_number& v)
{
    if (size!=v.Size())
    {
        cout<<"you can't multiply vectors of different sizes";
        return Big_number(0);
    }
    int i=0;
    Big_number result;
    while(i<size)
    {
        result+=elements[i]*v.get_element(i);
        i++;
    }
    return result;
}








ostream& operator<<(ostream& out, const Vector_big_number& obj)
{
    obj.Show(out);
    return out;
}
istream& operator>>(istream& in, Vector_big_number& obj)
{
    Big_number aux;
    int i=0;
    while(in>>aux&&i<obj.Size())
    {
        obj.set_element(aux, i);
        i++;
    }
}


