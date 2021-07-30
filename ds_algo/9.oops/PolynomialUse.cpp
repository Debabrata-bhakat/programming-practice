#include <iostream>
using namespace std;
#include "Polynomial.cpp"

int main(){
    Polynomial p1;
    p1.setCoefficient(10,0);
    p1.setCoefficient(-4,5);
    // p1.setCoefficient(9,9);
    // p1.setCoefficient(-4,2);
    // p1.setCoefficient(0,20);
    p1.print();
}