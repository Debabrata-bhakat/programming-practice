// https://codeforces.com/contest/1614/problem/C?locale=en
#include <bits/stdc++.h>
#define ull unsigned long long 
#define ll long long 
const ll mod = (ll) 1000000007 ;
using namespace std;
void solve();
int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    int t;
    cin >> t;
    while(t--)
    {
        solve();
    }
}

ll power(ll n,ll m){
if (m==0)return 1;
if (m==1)return n%mod;
ll r=(power(n%mod,m/2));
if (m%2) return (((r*r)%mod)*(n%mod))%mod;
else return (r*r)%mod;
}

void solve(){
    int n,m; cin >> n >> m;
    int sum_or = 0;
    for (int i = 0; i < m; i++)
    {
        int a,b,c; cin >> a >> b >> c;
        sum_or |= c;
    }
    sum_or %= mod;
    cout << sum_or*power(2,(n-1))%mod << '\n';
}