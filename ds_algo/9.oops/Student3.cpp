class Student{
    private:
    static int totalStudents;  //total number of students persent

    public:

    int rollNumber;
    int age;

    Student(){
        totalStudents ++;
    }

    static int getTotalStudents(){ // 1. only access static properties 2. cannot use this keyword
        return totalStudents;
    }

};

int Student ::totalStudents = 0; //intialize static members