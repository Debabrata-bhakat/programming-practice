#include <bits/stdc++.h>
#define ull unsigned long long 
#define ll long long
using namespace std;
int mod = 1e9+7;
const int N = 1000005;
int arr[N];
void solve();
void preFix(int n);
int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    ull n,t;
    cin>>n;
    cin >> t;
    for (int i = 0; i < n; ++i)
    {
        cin>>arr[i];
    }
    preFix(n);
    while(t--)
    {
        solve();
    }
}

void preFix(int n){
    for (int i = 1; i < n; ++i)
    {

        arr[i] = (arr[i-1] + arr[i])%mod;
        if(arr[i]<0) arr[i] += mod;
    }
}

void solve(){
    int l,r; cin>>l>>r;
    l--;r--;
    if(l==0) cout << arr[r] << endl;
    else cout << arr[r] - arr[l-1] << endl;
}
