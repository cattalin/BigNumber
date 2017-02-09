#ifndef BIGNUMBEREVENFIBO_H
#define BIGNUMBEREVENFIBO_H
#include "BigNumberEven.h"
#include "BigNumberFibo.h"
class fiboEvenException: public exception
{
  virtual const char* what() const throw()
  {
    return "the number you introduced is not fibo";
  }
};

class BigNumberEvenFibo:public BigNumberEven, BigNumberFibo
{

};

#endif // BIGNUMBEREVENFIBO_H
