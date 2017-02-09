#ifndef BIGNUMBEREVEN_H
#define BIGNUMBEREVEN_H
#include "Big_number.h"

class evenException: public exception
{
  virtual const char* what() const throw()
  {
    return "the number you introduced is not even";
  }
};



class BigNumberEven:virtual public Big_number
{
public:
    BigNumberEven();
    BigNumberEven(int number);
    BigNumberEven(string number);
    BigNumberEven(const BigNumberEven& b);


    BigNumberEven& operator=(const BigNumberEven &b);
    BigNumberEven& operator=(const int b);
    bool operator==(const BigNumberEven &b);

protected:
    template<class T> bool checkNumberEven(T n);
};

#endif // BIGNUMBEREVEN_H
