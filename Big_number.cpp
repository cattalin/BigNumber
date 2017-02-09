#include "Big_number.h"


Big_number::Big_number()
{
    pozitive=true;
    this->digits.push_back(0);
}
Big_number::Big_number(int number)
{
    pozitive=true;
    unsigned short digit=0;
    if (number<0)
    {
        pozitive=false;
        number*=-1;
    }
    if (number==0)
    {
        this->digits.push_back(0);
    }
    while (number)
    {
        digit=number%10;
        number/=10;
        this->digits.push_back(digit);
    }
}
Big_number::Big_number(string number)
{
    if (number.length()<1)
        return;
    int i=0;
    pozitive=true;
    if(number[i]=='-')
    {
        if(number.length()>1)
        {
            pozitive=false;
            i++;
        }
        else return;
    }


    while (i<number.length())
    {
        if (number[i]>='0'&&number[i]<='9')
        this->digits.push_front((int)(number[i]-'0'));
        i++;
    }

}
Big_number::Big_number(const Big_number& b)
{
    digits=b.digits;
    pozitive=b.Pozitive();
}


void Big_number::Show()
{
    if (!pozitive)
        cout<<"-";
    this->digits.Show_reversed();
}
void Big_number::Show(ostream& out) const
{
    if (!pozitive)
        out<<"-";
    this->digits.Show_reversed(out);
}


bool Big_number::Pozitive() const
{
    return pozitive;
}
int Big_number::Sign() const
{
    if (pozitive)
        return 1;
    else return -1;
}
int Big_number::Size() const
{
    return digits.Size();
}
unsigned short Big_number::get_digit(int pos) const
{
    Node* peak=this->digits.peak(pos);
    if (peak!=NULL)
    return peak->get_info();
}
List Big_number::get_digits() const
{
    return digits;
}








int Big_number::Sign(int x)
{
    if(x<0)return-1;
    return 1;
}
int Big_number::operation_sign(int x,const Big_number& number) const
{
    int sign=this->Sign();          //true
    if (this->Sign()!=number.Sign()*x)
    {
        if(this->lower_than_abs_val(number))
            sign=(-1);      //false
        else sign=1;

    }
    //sign*=x;
    return sign;
}






bool Big_number::equals(const Big_number& number)
{
    if(this->Size()!=number.Size()||this->Sign()!=number.Sign())
        return false;
    int parser=Size();
    while (parser>=1)
    {
        if(this->get_digit(parser)!=number.get_digit(parser))
            return false;
        parser--;
    }
    return true;
}
bool Big_number::lower_than(const Big_number& number)
{
    if (this->Sign()>number.Sign())
        return false;
    else if (this->Sign()<number.Sign())
        return true;

    if(this->Size()<number.Size())
        return (true==this->Pozitive())?1:0;
    if(this->Size()>number.Size())
        return (false==this->Pozitive())?1:0;
    int parser=Size();

    while (parser>=1)
    {
        if(this->get_digit(parser)<number.get_digit(parser))
            return (true==this->Pozitive())?1:0;
        if(this->get_digit(parser)>number.get_digit(parser))
            return (false==this->Pozitive())?1:0;
        parser--;
    }
    return false;
}
bool Big_number::greater_than(const Big_number& number)
{
    if (this->Sign()>number.Sign())
        return true;
    else if (this->Sign()<number.Sign())
        return false;

    if(this->Size()<number.Size())
        return (false==this->Pozitive())?1:0;
    if(this->Size()>number.Size())
        return (true==this->Pozitive())?1:0;
    int parser=Size();

    while (parser>=1)
    {
        if(this->get_digit(parser)<number.get_digit(parser))
            return (false==this->Pozitive())?1:0;
        if(this->get_digit(parser)>number.get_digit(parser))
            return (true==this->Pozitive())?1:0;
        parser--;
    }
    return false;
}
bool Big_number::equals_abs_val(const Big_number& number)
{
    if(this->Size()!=number.Size());
    int parser=Size();
    while (parser>=1)
    {
        if(this->get_digit(parser)!=number.get_digit(parser))
            return false;
        parser--;
    }
    return true;
}
bool Big_number::lower_than_abs_val(const Big_number& number) const
{
    if(this->Size()<number.Size())
        return (true==this->Pozitive())?1:0;
    if(this->Size()>number.Size())
        return (false==this->Pozitive())?1:0;
    int parser=Size();

    while (parser>=1)
    {
        if(this->get_digit(parser)<number.get_digit(parser))
            return (true==this->Pozitive())?1:0;
        if(this->get_digit(parser)>number.get_digit(parser))
            return (false==this->Pozitive())?1:0;
        parser--;
    }
    return false;
}
bool Big_number::greater_than_abs_val(const Big_number& number)
{
    if(this->Size()<number.Size())
        return (false==this->Pozitive())?1:0;
    if(this->Size()>number.Size())
        return (true==this->Pozitive())?1:0;
    int parser=Size();

    while (parser>=1)
    {
        if(this->get_digit(parser)<number.get_digit(parser))
            return (false==this->Pozitive())?1:0;
        if(this->get_digit(parser)>number.get_digit(parser))
            return (true==this->Pozitive())?1:0;
        parser--;
    }
    return false;
}


void Big_number::add(int number)
{
    /*
    bool poz=true;
    unsigned short digit=0;
    if (number<=0)
        ;
    while (number)
    {
        digit=number%10;
        number/=10;
        this->push_back(digit);
    }*/
    Big_number a(number);
    add(a);
}
void Big_number::add(const Big_number& number)
{
    additive_operation(number, 1);
}

void Big_number::substract(int number)
{
    Big_number a(number);
    substract(a);
}
void Big_number::substract(const Big_number& number)
{
    additive_operation(number, -1);
}



void Big_number::additive_operation(const Big_number& number, int OP)
{
    int sign=this->Sign();          //true, the sign of the result
    if (this->Sign()!=number.Sign()*OP)
    {
        if(this->lower_than_abs_val(number))
            sign=(-1);      //false
        else sign=1;

    }
    int i=1, result=0, keep=0;

    while (i<=this->Size()&&i<=number.Size())
    {
        result=this->Sign()*this->get_digit(i)+number.Sign()*OP*number.get_digit(i)+keep;
        keep=0;
        //cout<<"x"<<result<<"x";
        if(Sign(result)==sign)
        {
            //cout<<"r1"<<result;
            if(result>9){result%=10, keep=1;}
            else if(result<-9){result%=10, keep=-1;}
        }
        else
        {
            //cout<<"x"<<result<<"x";
            keep=Sign(result);      //POSIBIL SA FIE FARA -1
            if(result!=0)
                result=10-std::abs(result);
            else keep=0;
        }
        this->digits.set_info(i, abs(result));
        i++;
    }
    while (i<=this->Size())
    {
        result=this->Sign()*this->get_digit(i)+keep;
        keep=0;
        if(result>9){result%=10, keep=1;}
        else if(result<-9){result%=10, keep=-1;}
        this->digits.set_info(i, abs(result));
        i++;
    }
    while (i<=number.Size())
    {
        result=number.Sign()*OP*number.get_digit(i)+keep;
        keep=0;
        if(result>9){result%=10, keep=1;}
        else if(result<-9){result%=10, keep=-1;}
        this->digits.push_back(abs(result));
        i++;
    }
    if (keep!=0)
        this->digits.push_back(abs(keep));
    if (sign==-1)
        this->pozitive=false;
    else this->pozitive=true;
    digits.remove_useless_zeros();
}

void Big_number::multiply(int number)
{
    multiplicative_operation(Big_number(number));
}
void Big_number::multiply(const Big_number& number)
{
    multiplicative_operation(number);
}
void Big_number::multiplicative_operation(const Big_number& number)
{
    int sign=Sign()*number.Sign();
    if (sign==1)pozitive=true;
    else pozitive=false;

    Big_number aux, result;
    int i=1, j=1;
    while (i<=number.Size())
    {
        aux=*this;
        aux.multiplicative_operation_by_digit(number.get_digit(i));
        aux.multiplicative_operation_by_10(i-1);
        result+=aux;
        i++;
    }
    (*this)=result;
}
void Big_number::multiplicative_operation_by_10(int zeros)
{
    for (int i=1;i<=zeros;i++)
        digits.push_front(0);
}
void Big_number::multiplicative_operation_by_digit(int digit)
{
    int i=1, result=0, keep=0;
    while (i<=this->Size())
    {
        result=this->get_digit(i)*digit+keep;
        keep=result/10;
        result=result%10;
        digits.peak(i)->set_info(result);
        i++;
    }
    if(keep!=0)
        digits.push_back(keep);
}




Big_number Big_number::operator+(const Big_number& number)
{
    Big_number result=*this;
    result.add(number);
    return result;
}
Big_number& Big_number::operator+=(const Big_number& number)
{
    if(!checkBigNumber(number))
    return *this;
    add(number);
}
Big_number Big_number::operator-(const Big_number& number)
{
    Big_number result=*this;
    result.substract(number);
    return result;
}
Big_number& Big_number::operator-=(const Big_number& number)
{
    if(!checkBigNumber(number))
    return *this;
    substract(number);
}


Big_number Big_number::operator*(const Big_number& number)
{
    Big_number result=*this;
    result.multiply(number);
    return result;
}
Big_number& Big_number::operator*=(const Big_number& number)
{
    if(!checkBigNumber(number))
        return *this;
    multiply(number);
}

template<class T>  bool Big_number::checkBigNumber(T n)
{
    return true;
}



Big_number& Big_number::operator=(const Big_number &b)
{
    if(!checkBigNumber(b))
    return *this;
    pozitive=b.Pozitive();
    digits=b.get_digits();
    return *this;
}
bool Big_number::operator==(const Big_number &b)
{
    if(pozitive==b.Pozitive())
        if(digits==b.get_digits())
            return true;
    return false;
}













ostream& operator<<(ostream& out, const Big_number& obj)
{
    obj.Show(out);
    return out;
}
istream& operator>>(istream& in, Big_number& obj)
{
    obj=Big_number(0);
    string number;
    in>>number;
    if (number.length()<1)
        return in;
    int i=0;
    obj.pozitive=true;
    if(number[i]=='-')
    {
        if(number.length()>1)
        {
            obj.pozitive=false;
            i++;
        }
        else return in;
    }


    while (i<number.length())
    {
        if (number[i]>='0'&&number[i]<='9')
        obj.digits.push_front((int)(number[i]-'0'));
        else {obj=Big_number(0); return in;}        //sa nu se introduca litere
        i++;
    }
    obj.digits.remove_useless_zeros();
    return in;
}




/*              //ATTEMPT OF EFFICIENT MULTIPLICATION
void Big_number::multiply(int number)
{
    Big_number aux, result;
    int i=1, res=0, keep=0;

    while (i<=this->Size())
    {
        res=this->get_digit(i)*number+keep;
        keep=result/10;
        result=result%10;

            if(result>9){result%=10, keep=1;}
            else if(result<-9){result%=10, keep=-1;}
        }
        else
        {
            keep=Sign(result);
            if(result!=0)
                result=10-std::abs(result);
            else keep=0;
        }
        this->digits.set_info(i, abs(result));
        i++;
    }
}*/



