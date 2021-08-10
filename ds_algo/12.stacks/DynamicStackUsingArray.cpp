#include <climits>
template <typename T>
class StackUsingArray{
    T *data;
    int nextIndex;
    int capacity;

    public:

    StackUsingArray(){
        capacity = 4;
        data = new T[capacity];
        nextIndex = 0;
    }

    int size(){
        return nextIndex;
    }
    
    bool isEmpty(){
        return nextIndex==0;
    }

    void push(T element){
        if(nextIndex == capacity){
            T *newData = new T[capacity*2];
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

    T pop(){
        if(isEmpty()){
            cout << "Stack is empty\n";
            return 0;
        }
        return data[--nextIndex];
    }

    T top(){
        if(isEmpty()){
            cout << "Stack is empty\n";
            return 0;
        }
        return data[nextIndex-1];
    }
};