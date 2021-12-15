// https://codeforces.com/contest/1614/problem/B
#include <bits/stdc++.h>
#define ull unsigned long long 
#define ll long long
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

void solve(){
    ll n; cin >> n;
    vector<pair<ll,ll>> a;
    for (ll i = 0; i < n; i++)
    {
        ll t; cin >> t;
        pair<ll,ll> pt;
        pt.first = t;
        pt.second = i+1;
        a.push_back(pt);
    }
    sort(a.rbegin(), a.rend());
    ll *res = new ll[n+1];
    res[0] = 0;
    ll x = 1;
    ll sum_time = 0;
    for (ll i = 0; i < n; i++)
    {
        ll in = a[i].second;
        res[in] = x;
        sum_time += (a[i].first)*abs(x)*2;
        if(x>0) x = -x;
        else x = -x + 1;
    }
    cout << sum_time << '\n';
    for (ll i = 0; i < n+1; i++)
    {
        cout << res[i] << " ";
    }
    cout << '\n';
    
}