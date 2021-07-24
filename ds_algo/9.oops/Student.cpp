#include <iostream>
#include <string.h>
using namespace std;

class Student{
    private:
    int age;

    public:
    char *name;
    Student(int age, char *name){
        this ->age = age;
        // Shallow copy
        // this ->name = name;

        //Deep copy
        this ->name = new char[strlen(name) + 1];
        strcpy(this ->name, name);
    }

    // Copy constructor
    Student(Student s){
        this ->age = s.age;

        // this ->name = s.name;  Shallow copy
        // Deep copy
        this ->name = new char[strlen(s.name) + 1];
        strcpy(this ->name, s.name);
    }

    void display(){
        cout << name << " " << endl;
    }
};