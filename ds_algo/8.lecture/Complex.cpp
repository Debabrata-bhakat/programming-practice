#include <iostream>
using namespace std;

class Complex
{
private:
    int real;
    int imaginary;
public:
    Complex(int real, int imaginary){
        this ->real = real;
        this ->imaginary = imaginary;
    }

    void print(){
        cout << this ->real << " i" << this ->imaginary << endl;
        // cout << this ->real  << endl;
        // cout << this ->imaginary  << endl;
    }

    void add(Complex c1){
        this ->real = this ->real + c1.real;
        this ->imaginary = this ->imaginary + c1.imaginary;
    }

    void multiply(Complex c1){
        int a = this ->real * c1.real - this ->imaginary *c1.imaginary;
        int b = this ->imaginary * c1.real + this ->real * c1.imaginary;
        this ->real = a;
        this ->imaginary = b;
    }
};

