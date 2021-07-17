#include <iostream>
using namespace std;

int solve(int *arr, int n, int k, int **res){
    // Base case
    if(n==0){
        if(k==0){
            res[0][0] = 0;
            return 1;
        }
        else{
            return 0;
        }
    }

    // Take the first element in the subset
    int **out1 = new int*[n];
    for (int i = 0; i < n; i++)
    {
        out1[i] = new int[n];
    }
    int smallOutput1 = solve(arr+1, n-1, k-arr[0], out1);

    // Do not include the first element in the subset
    int **out2 = new int*[n];
    for (int i = 0; i < n; i++)
    {
        out2[i] = new int[n];
    }
    int smallOutput2 = solve(arr+1, n-1, k, out2);

    // Merge the two outputs
    for (int i = 0; i < smallOutput1; i++)
    {
        int row_length = out1[i][0];
        res[i][0] = row_length+1;
        res[i][1] = arr[0];
        for (int j = 2; j <= res[i][0]; j++)
        {
            res[i][j] = out1[i][j-1];
        }        
    }
    
    for (int i = 0; i < smallOutput2; i++)
    {
        int row_length = out2[i][0];
        res[i+smallOutput1][0] = row_length;
        for (int j = 1; j <= res[i+smallOutput1][0]; j++)
        {
            res[i+smallOutput1][j] = out2[i][j];
        }
        
    }
    
    return smallOutput1+smallOutput2;
}

int main(){
    int n;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int sum;
    cin >> sum;

    int **res = new int*[n];
    for (int i = 0; i < n; i++)
    {
        res[i] = new int[n];
    }
    int output = solve(arr,n,sum,res);
    for (int i = 0; i < output; i++)
    {
        int row_length = res[i][0];
        for (int j = 1; j <= row_length; j++)
        {
            cout << res[i][j] <<" ";
        }
        cout << endl;
    }
    
    
    
    
}