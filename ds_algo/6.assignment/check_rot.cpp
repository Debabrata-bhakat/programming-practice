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

int check_rot(int *arr, int size){
    for (int i = 0; i < size-1; i++)
    {
        if(arr[i]>arr[i+1]){
            return (i+1);
        }
    }
    return 0;
}

void solve(){
    int n;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << check_rot(arr, n) << '\n';
}