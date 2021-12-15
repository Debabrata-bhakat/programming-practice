// https://codeforces.com/contest/1614/problem/A
#include <bits/stdc++.h>
#define ull unsigned long long 
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
    int n,l,r,k; cin >> n >> l >> r >> k;
    vector<int> a;
    for (int i = 0; i < n; i++)
    {
        int t; cin >> t;
        if(t>=l and t<=r)
        a.push_back(t);
    }
    sort(a.begin(), a.end());
    int ans=0;
    for (int i = 0; i < a.size(); i++)
    {
        if(k>=a[i]) {
            k -= a[i];
            ans++;
        }else break;
    }
    cout << ans << '\n';
}