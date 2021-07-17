#include <iostream>
using namespace std;

int solve(int *arr,int start, int end, int aim){
    // Base case
    if (start == end and arr[start] == aim ){
        return start;
    }
    if(start == end and arr[start] != aim) return -1;
    // Getting small outputs
    int mid = (start + end)/2;
    int smallOutput1 = solve(arr, start, mid, aim);
    int smallOutput2 = solve(arr, mid+1, end, aim);
    if (smallOutput1 != -1)
    {
        return smallOutput1;
    }
    else if (smallOutput2 != -1)
    {
        return smallOutput2;
    }
    return -1;
    


}

int main(){
    int n, tar;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cin >> tar;
    int in = solve(arr,0,n-1, tar);
    if (in == -1)
    cout << "-1\n";
    else
    cout << in << endl;
}