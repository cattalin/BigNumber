#ifndef BIGNUMBERFIBO_H
#define BIGNUMBERFIBO_H
#include "Big_number.h"
#include <cmath>
class fiboException: public exception
{
  virtual const char* what() const throw()
  {
    return "the number you introduced is not fibo";
  }
};

class BigNumberFibo:virtual public Big_number
{
public:
    BigNumberFibo();
    BigNumberFibo(int number);
    BigNumberFibo(string number);
    BigNumberFibo(const BigNumberFibo& b);

    void Show();
    void Show(ostream& out) const;
    void showFibo();
    bool lower_than(const BigNumberFibo& number);

    BigNumberFibo& operator=(const BigNumberFibo &b);
    BigNumberFibo& operator=(const int b);
    bool operator==(const BigNumberFibo &b);

    BigNumberFibo  operator+ (const BigNumberFibo& number);

    friend ostream& operator<<(ostream& out, const BigNumberFibo& obj);


protected:
    template<class T> bool checkNumberFibo(T n);
    template<class T> bool checkSquare(T n);
};

#endif // BIGNUMBERFIBO_H
