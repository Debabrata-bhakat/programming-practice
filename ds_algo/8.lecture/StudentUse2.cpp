#include <iostream>
using namespace std;
#include "Student.cpp"

int main(){

    // Copy constructor
    Student s9(12,23);
    Student s10(s9);
    s9.display();
    s10.display();

    Student *s11 = new Student(20,2011);
    cout << "S3: ";
    s11 -> display();

    Student s4(*s11);

    Student *s5 = new Student(*s11);
    Student *s6 = new Student(s9);

    // Copy assignment operator
    Student s1(10,1001);
    Student s2(20,2001);
    Student *s3 = new Student(30,3001);
    s2 = s1;
    *s3 = s1;
    s2 = *s3;
    delete s3;
    // Destructor
    
}