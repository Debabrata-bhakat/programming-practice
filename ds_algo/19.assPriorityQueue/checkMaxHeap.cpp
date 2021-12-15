#include <iostream>
using namespace std;

bool checkMaxHeap(int *a, int n){
    for (int i = 0; i < n; i++)
    {
        int parentIndex = i;
        int leftChildIndex = 2*i + 1;
        int rightChildIndex = 2*i + 2;
        if(leftChildIndex<n and a[leftChildIndex]>a[parentIndex]) return false;
        if(rightChildIndex<n and a[rightChildIndex]>a[parentIndex]) return false;
    }
    return true;
}

int main(){
    int n; cin >> n;
    int *a = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout << checkMaxHeap(a,n) << endl;
}