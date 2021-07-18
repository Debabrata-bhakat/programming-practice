#include <iostream>
using namespace std;


int solve(int *arr, int size){
    int sum_n_2 = ((size-2)*(size-1))/2;
    int sum_arr = 0;
    for (int i = 0; i < size; i++)
    {
       sum_arr += arr[i];
    }
    // cout << sum_n_2 << endl;
    // cout << sum_arr << endl;
   return (sum_arr - sum_n_2); 
}

int main(){
    int n;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int res = solve(arr,n);
    cout << res << endl;
    
}