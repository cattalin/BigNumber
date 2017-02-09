#ifndef BIG_NUMBER_H
#define BIG_NUMBER_H
#include "List.h"
#include <iostream>
#include <cmath>
using namespace std;



class Big_number
{
    List digits;
    bool pozitive;

public:
    Big_number();
    Big_number(int number);
    Big_number(string number);
    Big_number(const Big_number& b);
    virtual void Show();
    virtual void Show(ostream& out) const;
    bool Pozitive() const;
    int Sign() const;
    int Size() const;
    unsigned short get_digit(int pos) const;
    List get_digits() const;



private:
    int Sign(int x);
    int operation_sign(int x,const Big_number& number)const;


public:
    bool equals(const Big_number& number);
    bool lower_than(const Big_number& number);
    bool greater_than(const Big_number& number);
    bool equals_abs_val(const Big_number& number);
    bool lower_than_abs_val(const Big_number& number) const;
    bool greater_than_abs_val(const Big_number& number);

    template<class T>  bool checkBigNumber(T n);//used to validate data in the derived classes

protected:
    void add(int number);               //these two methods require a [] operator overload on the List class
    void add(const Big_number& number);
    void substract(int number);               //these two methods require a [] operator overload on the List class
    void substract(const Big_number& number);

    void multiply(int number);
    void multiply(const Big_number& number);


    void additive_operation(const Big_number& number, int sign);
    void multiplicative_operation(const Big_number& number);
    void multiplicative_operation_by_10(int zeros);
    void multiplicative_operation_by_digit(int digit);


public:
    Big_number  operator+ (const Big_number& number);
    Big_number& operator+=(const Big_number& number);
    Big_number  operator- (const Big_number& number);
    Big_number& operator-=(const Big_number& number);

    Big_number  operator* (const Big_number& number);
    Big_number& operator*=(const Big_number& number);

    Big_number& operator=(const Big_number &b);
    Big_number& operator=(const int b);
    bool operator==(const Big_number &b);

    friend ostream& operator<<(ostream& out, const Big_number& obj);
    friend istream& operator>>(istream& in, Big_number& obj);
};


#endif // BIG_NUMBER_H
