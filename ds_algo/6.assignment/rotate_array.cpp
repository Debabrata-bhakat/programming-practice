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

void rot_arr(int *arr, int *res, int size, int rot){
    int c = 0;
    for (int i = rot; i < size; i++)
    {
        res[c++] = arr[i];
    }
    for (int i = 0; i < rot; i++)
    {
        res[c++] = arr[i];
    }
    
    
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
    rot_arr(arr, arr_rot, n, rot);
    for (int i = 0; i < n; i++)
    {
        cout << arr_rot[i] << " ";
    }
    cout << '\n';
}