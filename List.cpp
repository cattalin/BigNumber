#include "List.h"


List::List()
{
    size=0;
    first=last=NULL;
}
List::List(const List& l)
{
    copy(l);
}

List::~List()
{
    //for (int i=0;i<size;i++)
        ;//delete
}
void List::pop_back()
{
    if (first==NULL)
        return;
    if (first==last)
    {
        first=last=NULL;
        size=0;
        delete first;
        return;
    }
    Node* aux=first->get_next();
    aux->set_prev(NULL);
    delete first;
    first=aux;
    size--;

}
void List::pop_front()
{
    if (first==NULL)
        return;
    if (first==last)
    {
        first=last=NULL;
        size=0;
        delete first;
        return;
    }
    Node* aux=last->get_prev();
    aux->set_next(NULL);
    delete last;
    last=aux;
    size--;
}
void List::push_front(unsigned short value)
{
    if(value>=10)                //cant be smaller than 0 and shouldn't be bigger than 10
    {
        cout<<"ERROR: trying to introduce non-digits\n";
        return;
    }
    if (first==NULL)        //if the list is empty
    {
        first=last=new Node(value);
        size=1;
        return;
    }

    Node* aux=first;
    first=new Node(value,NULL,aux);
    aux->set_prev(first);
    size++;

}
void List::push_back(unsigned short value)
{
    if(value>=10)
    {
        cout<<"ERROR: trying to introduce non-digits\n";
        return;
    }
    if (first==NULL)
    {
        first=last=new Node(value);
        size=1;
        return;
    }

    Node* aux=new Node(value,last,NULL);
    last->set_next(aux);
    last=aux;
    size++;
}
List::Size()    const
{
    return size;
}
void List::Show()
{
    if (first==NULL)
    {
        cout<<"0";
        return;
    }
    Node*aux=first;
    while (aux!=NULL)
    {
        cout<<aux->get_info();
        aux=aux->get_next();
    }
}
void List::Show_reversed()
{
    if (first==NULL)
    {
        cout<<"0";
        return;
    }
    Node*aux=last;
    while (aux!=NULL)
    {
        cout<<aux->get_info();
        aux=aux->get_prev();
    }
}
void List::Show(ostream& out) const
{
    if (first==NULL)
    {
        out<<"0";
        return;
    }
    Node*aux=first;
    while (aux!=NULL)
    {
        out<<aux->get_info();
        aux=aux->get_next();
    }
}
void List::Show_reversed(ostream& out) const
{
    if (first==NULL)
    {
        out<<"0";
        return;
    }
    Node*aux=last;
    while (aux!=NULL)
    {
        out<<aux->get_info();
        aux=aux->get_prev();
    }
}
void List::remove_useless_zeros()               //utility method for maintaining a clean number
{
    if (first==last)
    {
        return;
    }
    while (last->get_info()==0)
    {
        if (last==first)return;
        pop_front();
    }
}
Node* List::peak(int pos) const       //this method offers the possibility to crack the program. TO DO: delete it. it also needs iterator for it uses too much precessing speed.
{
    if (pos<1)
        return NULL;
    if (pos>size)
        return NULL;
    if (first==NULL)
        return NULL;
    Node* aux=first;
    int i=1;
    while (i<pos&&aux!=NULL)
    {
        i++;
        aux=aux->get_next();
    }
    //if (aux!=NULL)
        return aux;
}
void List::set_info(int pos, unsigned short value)
{
    if (pos<1)
        return;
    if (pos>size)
        return;
    if (first==NULL)
        return;
    Node* aux=first;
    int i=1;
    while (i<pos&&aux!=NULL)
    {
        i++;
        aux=aux->get_next();
    }
    if (aux!=NULL)
        aux->set_info(value);
    return;
}

List& List::operator=(const List &l)
{
    copy(l);
    return *this;
}
bool List::operator==(const List &l)
{
    if (size!=l.Size())
        return false;
    if (size==0)return true;
    int i=1;
    Node* aux1=first;
    Node* aux2=l.peak(1);
    while (i<=size&&aux1!=NULL)
    {
        if (aux1->get_info()!=aux2->get_info())
            return false;
        i++;
        aux1=aux1->get_next();
        aux2=aux2->get_next();
    }
    return true;

}
void List::copy(const List& l)
{
    //cout<<" ia cu porc ";
    size=l.Size();
    Node* aux1,* aux2;
    for (int i=1;i<=size;i++)
    {
        if(i==1)
        {
            first=new Node(l.peak(i)->get_info(), NULL, NULL);
            aux1=first;
            if(i==size)
            {
                last=first;
            }
        }
        else if(i==size)
        {
            last=new Node(l.peak(i)->get_info(), aux1, NULL);
            aux1->set_next(last);
        }
        else
        {
            aux2=new Node(l.peak(i)->get_info(),aux1, NULL);
            aux1->set_next(aux2);
            aux1=aux2;
        }
    }
}
