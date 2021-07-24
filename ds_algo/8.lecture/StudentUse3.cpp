#include <iostream>
using namespace std;
#include "Student.cpp"

int main(){
    Student s1; //Constructor 1 called
    Student s2(10);  //Constructor 2 called
    Student s3(10,100);  //Constructor 3 called
    Student s4(s3); //Copy constructor
    s1 = s2; //Copy assignment operator
    Student s5 = s4; //Looks like constructor 1 + copy costructor, but actually just copy assignment operator
    
}