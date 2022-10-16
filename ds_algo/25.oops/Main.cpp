#include <iostream>
using namespace std;
#include "Student.cpp"
#include "Teacher.cpp"
#include "TA.cpp"

int main(){
	TA a;
	// --> creates ambiguity
	a.print();
	// a.Student :: print();
}