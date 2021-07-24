#include <iostream>
using namespace std;
#include "Student.cpp"

int main(){
    // Create objects statically
    Student s1;
    Student s2;

    Student s3, s4, s5;
    // s1.age = 20;
    s1.rollNumber = 30;

    // cout << s1.age << endl;
    cout << s1.rollNumber << endl;
    s1.display();


    // Create objects dynamically
    Student *s6 = new Student;

    // (*s6).age = 23;
    (*s6).rollNumber = 104;

    //can also be written as
    // s6->age = 23;
    s6->rollNumber = 104;
    s6->display();





    cout << "parameterised constructor demo" << endl;
    Student s7(10,90);
    s7.display();

    Student *s8 = new Student(101,90);
    s8 -> display();




}