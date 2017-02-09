#include <iostream>
#include "Big_number.h"
#include "Vector_big_number.h"
#include "BigNumberEven.h"
#include "BigNumberFibo.h"
//#include "BigNumberEvenFibo.h"
#include <fstream>


using namespace std;




int main()
{
    /*try
    {
        BigNumberEven a(2412);
        BigNumberFibo b(5);
        cout<<a<<" "<<b;
    }
    catch (exception& e)
    {
        cout << e.what() << '\n';
    }*/




    /*ifstream in("numere mari.txt");
    Big_number a(2), b(3);
    Vector_big_number vct1(3), vct2(3);


    vct1.set_element(Big_number(-5), 0);
    vct1.set_element(b, 1);
    vct1.set_element(a, 2);

    in>>vct2;
    cout<<vct1<<endl<<vct2<<endl;

    cout<<vct1*vct2<<endl;
    cout<<vct1<<endl<<vct2<<endl;
    cout<<vct1.Max();*/


    Big_number a(1234321), b, c(123);
    b=c;
    cout<<a+b<<'\n'<<c<<'\n';
    Big_number big(100000);
    cout<<big*big*big*132123<<'\n';
    cout<<big+55667788<<'\n';
    Big_number x;
    cout<<x<<'\n';
    x+=1234321;
    cout<<x<<'\n';





}
