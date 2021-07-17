#include <iostream>
using namespace std;

int solve (int *arr, int size, int **output){
    if(size == 0){
        output[0][0] = 1;
        output[0][1] = -1;
        return 1;
    }

    int smallOutput = solve(arr+1, size-1, output);
    for (int i = smallOutput; i < smallOutput*2; i++)
    {
        output[i][0] = output[i-smallOutput][0] + 1;
        output[i][1] = arr[0];
        for (int j = 2; j <= output[i][0]; j++)
        {
            output[i][j] = output[i-smallOutput][j-1];
        }
        
    }
    return smallOutput*2;
}

int main(){
    int n;
    cin >> n;
    int *arr = new int[n];
    int **output = new int *[100];
    for (int i = 0; i < 100; i++)
    {
        output[i] = new int [100];
    }
    
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for (int i = 0; i < 100; i++)
    {
        output[i][0] = 0;
    }
    
    int res = solve(arr, n, output);
    for (int i = 0; i < res; i++)
    {
        int cur_size = output[i][0];
        for (int j = 1; j <=cur_size; j++)
        {
            cout << output[i][j] << " ";
        }
        cout << endl;
    }
    
    
}