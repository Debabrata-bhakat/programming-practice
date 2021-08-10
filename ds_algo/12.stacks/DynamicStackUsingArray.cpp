#include <climits>
class StackUsingArray{
    int *data;
    int nextIndex;
    int capacity;

    public:

    StackUsingArray(){
        capacity = 4;
        data = new int[capacity];
        nextIndex = 0;
    }

    int size(){
        return nextIndex;
    }
    
    bool isEmpty(){
        return nextIndex==0;
    }

    void push(int element){
        if(nextIndex == capacity){
            int *newData = new int[capacity*2];
            for (int i = 0; i < capacity; i++)
            {
                newData[i] = data[i];
            }
            capacity = capacity*2;
            delete [] data;
            data = newData;
        }
        data[nextIndex++] = element;
    }

    int pop(){
        if(isEmpty()){
            cout << "Stack is empty\n";
            return INT_MIN;
        }
        return data[--nextIndex];
    }

    int top(){
        if(isEmpty()){
            cout << "Stack is empty\n";
            return INT_MIN;
        }
        return data[nextIndex-1];
    }
};