#include "BigNumberFibo.h"
#include <math.h>

BigNumberFibo::BigNumberFibo():Big_number()
{

}


BigNumberFibo::BigNumberFibo(int number):Big_number(number)
{
    if(!checkNumberFibo(number))
    {
        throw fiboException();
    }
}
BigNumberFibo::BigNumberFibo(string number):Big_number(number)
{

}
BigNumberFibo::BigNumberFibo(const BigNumberFibo& b):Big_number(b)
{

}


void BigNumberFibo::Show()
{
    //BigNumberFibo::showFibo();
    Big_number::Show();
    cout<<"sunt fibonacci";
}
void BigNumberFibo::Show(ostream& out) const
{
    Big_number::Show(out);
    cout<<"sunt fibonacci";
}
void BigNumberFibo::showFibo()
{
    BigNumberFibo firstTerm = 1, secondTerm = 1, nextTerm;

    cout << "Fibonacci Series: " << firstTerm << " + " << secondTerm << " + ";
    while (nextTerm.lower_than(*this)) {
        nextTerm = firstTerm + secondTerm;
        cout << nextTerm << " + ";
        firstTerm = secondTerm;
        secondTerm = nextTerm;
    }
}
bool BigNumberFibo::lower_than(const BigNumberFibo& number)
{
    Big_number::lower_than(number);
}
BigNumberFibo  BigNumberFibo::operator+ (const BigNumberFibo& number)
{
    BigNumberFibo result=*this;
    result.add(number);
    return result;
}
BigNumberFibo& BigNumberFibo::operator=(const BigNumberFibo &b)
{

}

ostream& operator<<(ostream& out, const BigNumberFibo& obj)
{
    obj.Show(out);
    return out;
}




template<class T> bool BigNumberFibo::checkNumberFibo(T n)
{
    if(checkSquare(5*(n*n)+4))
        return true;
    if (checkSquare(5*(n*n)-4))
        return true;
    return false;
}

template<class T> bool BigNumberFibo::checkSquare(T n)
{
    if (sqrt(n)==floor(sqrt(n)))
    {
        return true;
    }
    return false;
}

