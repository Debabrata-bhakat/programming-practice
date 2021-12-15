// https://codeforces.com/contest/1610/problem/0
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
    int n,m; cin >> n>> m;
    if(m==1 and n==1){
        cout << "0\n";
        return;
    }
    if (min(n,m)==1){
        cout << "1\n" ;
        return;
    }
    cout << "2\n";
}