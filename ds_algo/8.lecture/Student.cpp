#include <iostream>
using namespace std;

class Student{
    public:
    int rollNumber;

    private:
    int age;

    public:

    // Default constructor
    Student(){
        cout << "Default constructor called" << endl;
    }
    //Parameterised constructor
    Student(int rollNumber){
        cout << "Constructor 2 called" << endl;
        // This keyword holds the address of current object. It is a pointer therefore it is addressed like this.
        this -> rollNumber = rollNumber;
    }
    Student(int rollNumber, int age){
        cout << "Constructor 3 called" << endl;
        // This keyword holds the address of current object. It is a pointer therefore it is addressed like this.
        this -> rollNumber = rollNumber;
        this -> age = age;
    }

    // Destructor
    ~Student(){
        cout << "Destructor called" <<endl;
    }

    void display(){
        cout << age << " " << rollNumber << endl;
    }

    int getAge(){
        return age;
    }

    void setAge(int a, int password){
        if(password != 123) return;
        if(a<0) return;
        age = a;
    }
};