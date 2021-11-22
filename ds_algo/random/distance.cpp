// https://codeforces.com/contest/1612/problem/0
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
    int x,y;
    cin >> x >> y;
    if (((x+y)>>1)<<1!=(x+y)) {
        cout << "-1 -1" << '\n';
        return;
    }
    int m, n;
    if(x<y){
        m = x;
        n = (x+y)/2 - x;
    }else{
        n = y;
        m = (x+y)/2 - y;
    }
    cout << m << " " << n << '\n';
}