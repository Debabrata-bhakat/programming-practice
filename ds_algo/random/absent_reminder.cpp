// https://codeforces.com/contest/1613/problem/B
#include <bits/stdc++.h>
#define ull unsigned long long 
#define ll long long
using namespace std;
void solve();
int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    ull t;
    cin >> t;
    while(t--)
    {
        solve();
    }
}

void solve(){
    int n; cin >>n;
    vector<int> a;
    for (int i = 0; i < n; i++)
    {
        int t; cin >> t;
        a.push_back(t);
    }
    sort(a.begin(), a.end());
    for (int i = 1; i <= n/2; i++)
    {
        cout << a[i] << " " << a[0] << '\n';
    }
    
}