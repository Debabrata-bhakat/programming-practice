#include <iostream>
using namespace std;

class Fraction{

    private:
    int numerator;
    int denominator;

    public:

    Fraction(){

    }

    Fraction(int numerator, int denominator){
        this ->numerator = numerator;
        this ->denominator = denominator;
    }


    // Mark functions as constant which do not change the current object. So they can be called by constant objects
    int getNumerator() const{
        return numerator;
    }

    int getDenominator() const{
        return denominator;
    }

    void setNumerator(int numerator){
        this ->numerator = numerator;
    }

    void setdenominator(int denominator){
        this ->denominator = denominator;
    }

    void print(){
        cout << this -> numerator << "/" << this -> denominator << endl;
    }

    void simplify(){
        int gcd = 1;
        int j = min(this ->denominator, this ->numerator);
        for (int i = 1; i <= j; i++)
        {
            if(this ->numerator % i == 0 and this ->denominator % i == 0){
                gcd = i;
            }
        }
        this ->numerator = this ->numerator/gcd;
        this ->denominator = this ->denominator/gcd;
    }

    void add(Fraction const &f2){ //f2 is a reference to a constant Fraction
        int lcm = (this -> denominator) * f2.denominator;
        int x = lcm/(this -> denominator);
        int y = lcm/(f2.denominator);
        this ->numerator = x*(this ->numerator) + y*f2.numerator;
        this ->denominator = lcm;

        simplify(); 
    }

    void multiply(Fraction const &f2){
        this ->numerator = this ->numerator * f2.numerator;
        this ->denominator = this ->denominator * f2.denominator;
        simplify();
    }


    /////////////////////////////////////////Operator overloading
    Fraction add2(Fraction const &f2){ //f2 is a reference to a constant Fraction
        int lcm = (this -> denominator) * f2.denominator;
        int x = lcm/(this -> denominator);
        int y = lcm/(f2.denominator);

        Fraction fnew;
        fnew.numerator = x*(this ->numerator) + y*f2.numerator;
        fnew.denominator = lcm;

        fnew.simplify(); 
        return fnew;
    }
    Fraction operator+(Fraction const &f2) const{ //f2 is a reference to a constant Fraction
        int lcm = (this -> denominator) * f2.denominator;
        int x = lcm/(this -> denominator);
        int y = lcm/(f2.denominator);

        Fraction fnew;
        fnew.numerator = x*(this ->numerator) + y*f2.numerator;
        fnew.denominator = lcm;

        fnew.simplify(); 
        return fnew;
    }
    Fraction operator*(Fraction const &f2)const{
        int n = this ->numerator * f2.numerator;
        int d = this ->denominator * f2.denominator;
        Fraction fnew(n,d);
        fnew.simplify();
        return fnew;
    }

    bool operator==(Fraction const &f2)const{
        if(this ->numerator == f2.numerator and this ->denominator == f2.denominator) return true;
        else return false;
    }


    // Pre-increment
    Fraction& operator++(){
        this ->numerator = this ->numerator + this ->denominator;
        simplify();
        return *this;
    }

    Fraction operator++(int){
	Fraction fNew(numerator, denominator);
	numerator = numerator + denominator;
	simplify();
	fNew.simplify();
	return fNew;
    }

    Fraction operator+= (Fraction const &f2){
        int lcm = denominator*f2.denominator;
        int x = lcm/denominator;
        int y = lcm/f2.denominator;

        int num = x*numerator+(y*f2.numerator);

        numerator = num;
        denominator = lcm;
        simplify();
    }






};
