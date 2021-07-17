#include <iostream>
using namespace std;

void solve(int *input, int input_size, int *output, int output_size, int sum){
    // Base case
    if(input_size==0){
        if(sum==0){
            for (int i = 0; i < output_size; i++)
            {
                cout << output[i] << " ";
            }
            cout << endl;
        }
        return;
    }

    // Do not Include the first element
    solve(input+1, input_size-1, output, output_size, sum);
    output[output_size] = input[0];
    solve(input+1, input_size-1, output, output_size+1, sum-input[0]);
}


int main(){
    int n;
    cin >>n;
    int *arr = new int [n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int *arr_out = new int [n];
    int sum;
    cin >> sum;

    solve(arr,n,arr_out,0,sum);
}
