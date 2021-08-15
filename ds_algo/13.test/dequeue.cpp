#include <iostream>
using namespace std;

template <typename T>
class Dequeue{
    T *data;
    int firstIndex;
    int nextIndex;
    int size;
    int capacity;

    public:
    Dequeue(int capacity){
        data = new T[capacity];
        firstIndex = -1;
        nextIndex = 0;
        size = 0;
        this->capacity = capacity;
    }

    void insertFront(T element){
        // TODO
        if(size==capacity){
            cout << "Queue is full\n";
            return;
        }
        if(size==0){
            firstIndex = capacity -1 ;
        }
        else{
            firstIndex--;
            if(firstIndex<0) firstIndex = firstIndex+capacity;
        }
        data[firstIndex] = element;
        size++;
    }

    void insertRear(T element){
        // TODO
        if(size==capacity){
            cout << "Queue is full\n";
            return;
        }
        if(size==0){
            firstIndex = 0;
        }
        data[nextIndex++] = element;
        size++;

    }

    void deleteFront(){
        // TODO
        if(size==0){
            cout << "Queue is empty\n";
            return;
        }
        firstIndex++;
        if(firstIndex>=capacity) firstIndex = firstIndex%capacity;
        size--;
        if(size==0){
            firstIndex = -1;
            nextIndex = 0;
        }
    }

    void deleteRear(){
        // TODO
        if(size==0){
            cout << "Queue is empty\n";
            return;
        }
        nextIndex--;
        if(nextIndex<0) nextIndex += capacity;
        size--;
        if(size==0){
            firstIndex = -1;
            nextIndex = 0;
        }
    }
    T getFront(){
        if(size==0){
            cout << "Cannot get front\n";
            return 0;
        }
        return data[firstIndex];
    }

    T getRear(){
        if(size==0){
            cout << "Cannot get rear\n";
            return 0;
        }
        int curr = nextIndex-1;
        if (curr<0) curr += capacity;
        return data[curr];
    }
};

int main(){
    Dequeue<int> d(10);
    d.insertFront(10);
    d.insertFront(20);
    d.insertFront(30);
    d.insertRear(40);
    d.insertRear(50);
    d.insertRear(60);
    cout << d.getFront() << endl;;
    d.deleteFront();
    cout << d.getRear() << endl;
    d.deleteRear();
    d.deleteRear();
    d.deleteRear();
    d.deleteRear();
    d.deleteRear();
    d.deleteRear();
}