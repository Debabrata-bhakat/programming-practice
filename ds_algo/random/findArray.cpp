// https://codeforces.com/contest/1608/problem/A
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
    int n; cin >> n;
    for (int i = 2; i <= n+1; i++)
    {
        cout << i << " ";
    }
    cout << '\n';
}