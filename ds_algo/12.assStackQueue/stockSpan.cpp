#include <iostream>
#include <stack>
using namespace std;

int* solve(int *arr, int size){
    stack<int> s;
    int *res = new int[size];
    for (int i = 0; i < size; i++)
    {

        while(!s.empty() and arr[s.top()] < arr[i] ){
            s.pop();
        }
        if(s.empty()){
            s.push(i);
            res[i] = i+1;
            continue;
        }
        res[i] = i - s.top();
        s.push(i);

    }
    return res;
}

int main(){
    int size;
    cin >> size;
    int *arr = new int[size];
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
    int *res = solve(arr, size);
    for (int i = 0; i < size; i++)
    {
        cout << res[i] << " ";
    }
    cout <<'\n';
}