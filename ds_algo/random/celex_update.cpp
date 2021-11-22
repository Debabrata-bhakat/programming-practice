// https://codeforces.com/problemset/problem/1358/C
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
    ull x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    cout << (x2-x1)*(y2-y1) + 1 << '\n';
}