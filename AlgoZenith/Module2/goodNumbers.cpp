#include <bits/stdc++.h>
#define ull unsigned long long 
#define ll long long
using namespace std;
void solve();
void partialSum(int n);
void preFix(int n, int k);
const int N = 1000005;
int arr[N];
int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    int n,k,q;cin>>n>>k>>q;
    int temp=n;
    for (int i = 0; i < N; ++i)
    {
        arr[i]=0;
    }
    while(temp--){
        partialSum(n);
    }
    preFix(n,k);
    while(q--){
        solve();
    }
}

void solve(){
    int l,r;cin>>l>>r;
    cout << arr[r]-arr[l-1] << '\n';
}

void partialSum(int n){
    int l,r;
    
    cin>>l>>r;
    arr[l]++; arr[r+1]--;
    
}

void preFix(int n, int k){
    n=N;
    for (int i = 1; i < n; ++i)
    {
        arr[i] += arr[i-1];
    }
    for (int i = 0; i < n; ++i)
    {
        if(arr[i]>=k)arr[i]=1;
        else arr[i]=0;
    }
    for (int i = 1; i < n; ++i)
    {
        arr[i] += arr[i-1];
    }
}