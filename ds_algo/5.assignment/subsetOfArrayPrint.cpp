#include <iostream>
using namespace std;

void solve(int *in_arr, int in_size, int * out_arr, int out_size)
{
    // Base case
    if(in_size == 0){
        for (int i = 0; i < out_size; i++)
        {
            cout << out_arr[i] << " " ;
        }
        cout << endl;
        return;
    }

    solve(in_arr+1, in_size-1, out_arr, out_size);
    out_arr[out_size] = in_arr[0];
    solve(in_arr+1, in_size-1, out_arr, out_size+1);


}
int main(){
    int size;
    cin >> size;
    int *in_arr = new int[size];
    for(int i = 0; i<size; i++){
        cin >> in_arr[i];
    }
    int *out_arr = new int[size];
    solve(in_arr, size, out_arr, 0);
}