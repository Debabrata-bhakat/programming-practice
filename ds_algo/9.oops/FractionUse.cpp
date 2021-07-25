#include <iostream>
using namespace std;
#include "Fraction.cpp"

int main(){
    Fraction f1(10,2);
    Fraction f2(15,4);

    Fraction const f3;
    cout << f3.getNumerator() << " " << f3.getDenominator() << endl;
    // f3.setdenominator(10);
    Fraction f4 = f1.add2(f2);
    Fraction f5 = f1 + f2;
    f1.print();
    f2.print();
    f4.print();
    f5.print();

    Fraction f6 = f1*f2;
    f6.print();

    if(f1==f2){
        cout << "Equal" << endl;
    }
    else cout << "Not equal" << endl;

    f1.print();
    ++f1;
    f1.print();
    Fraction f7 = ++f1;
    f7.print();
}