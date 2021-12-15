// https://codeforces.com/contest/1618/problem/0
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
    vector<ull> a;
    for (int i = 0; i < 7; i++)
    {
        ull temp; cin >> temp;
        a.push_back(temp);
    }
    cout << a[0] << " " << a[1] << " " << (a[6] - (a[0]+a[1])) << '\n';
}