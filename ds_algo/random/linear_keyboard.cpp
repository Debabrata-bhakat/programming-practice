// https://codeforces.com/contest/1607/problem/A
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
    string keys, s; cin >> keys>> s;
    unordered_map <char, int> key_dist;
    for (int i = 0; i < keys.size(); i++)
    {
        key_dist[keys[i]] = i+1;
    }
    int ans = 0;
    // cout << s << '\n';
    for (int i = 1; i < s.size(); i++)
    {
        // cout << s[i-1] << '\n';
        ans += abs(key_dist[s[i]] - key_dist[s[i-1]]);
        // cout << abs(key_dist[s[i]] - key_dist[s[i-1]]) << '\n';
    }
    cout << ans << '\n';
    
}