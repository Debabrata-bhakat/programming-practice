#include<bits/stdc++.h>
using namespace std;

int profit_max(int *arr, int size){
    int max = 0;
    sort(arr, arr+size);
    for (int i = 0; i < size; i++)
    {
        int curr = arr[i] * (size-i);
        if (curr > max)
        {
            max = curr;
        }
         
    }
    return max;
}

int main(){
    int n;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << profit_max(arr, n) << '\n';
}