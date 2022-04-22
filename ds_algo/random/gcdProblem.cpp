// https://codeforces.com/contest/1617/problem/B
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
    ull n; cin >> n;
    n--;
    if(n%2==1){
        cout << n/2 << " " <<  n/2 +1 << " 1\n";
        return;
    }
    ull temp = n/2;
    if(temp%2==1){
        cout << temp-2 << " " << temp+2 << " " << " 1\n";
    }else{
        cout << temp-1 << " " << temp+1 << " " << " 1\n";
    }
}