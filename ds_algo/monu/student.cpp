#include <iostream>
using namespace std;

class Student{
    private:
    int age;
    int marks;
    
    public:


    void printAge(int age){
        cout << "inside printAge first" << endl;
    }
    int getAge(){
        return this->age;
    }

    void setAge(int age){
        if(age<0) {
            this->age = 0;
        }
        else this->age = age;
    }

    void printAge(int age1, int age2){
        cout << "inside printAge second" << endl;
    }

    void area(int s){
        cout << s*s << endl;
    }

    void area(int l, int b){
        cout << l*b << endl;
    }
};

int main(){
    Student monu;
    int a;
    cout << "Input age of monu: " ;
    cin >> a;
    monu.printAge(23);
}