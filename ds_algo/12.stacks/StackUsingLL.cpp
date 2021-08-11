#include <iostream>
using namespace std;

template <typename T>

class Node{
    public:
    T data;
    Node<T> *next;

    Node(T data){
        this ->data = data;
        next = NULL;
    }
};

template <typename T>
class Stack{
    Node<T> *head;
    int size;

    public:
    Stack(){
        head = NULL;
        size = 0;
    }

    int getSize(){
        return size;
    }

    void push(T element){
        Node<T> *newNode = new Node<T>(element);
        
    }

    T pop(){

    }

    T top(){

    }

    
};