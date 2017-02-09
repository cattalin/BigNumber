#include "BigNumberEven.h"

BigNumberEven::BigNumberEven():Big_number()
{

}


BigNumberEven::BigNumberEven(int number):Big_number(number)
{
    if(!checkNumberEven(number))
    {
        throw evenException();
    }
}
BigNumberEven::BigNumberEven(string number):Big_number(number)
{

}

template<class T> bool BigNumberEven::checkNumberEven(T n)
{
    if(n%10%2==1)
    {
        return false;
    }
    return true;
}

