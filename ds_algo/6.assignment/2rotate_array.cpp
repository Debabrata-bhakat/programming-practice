#include<bits/stdc++.h>
using namespace std;
void solve();
int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }
}

void reverse(int *arr, int size){
    for (int i = 0; i < size/2; i++)
    {
        int temp = arr[i];
        arr[i] = arr[size-i-1];
        arr[size-i-1] = temp;
    }
}

void rot_arr(int *arr, int size, int rot){
   //First reverse full array
    reverse(arr, size);
    // Reverse leaving size - rot array
    reverse(arr, size - rot);
    // Reverse last rot array
    reverse(arr+size-rot,rot);
    
    
}

void solve(){
    int n;
    cin >> n;
    int *arr = new int[n];
    int *arr_rot = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int rot;
    cin >> rot;
    rot_arr(arr,n,rot);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << '\n';
}